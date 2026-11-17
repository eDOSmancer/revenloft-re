#!/usr/bin/env python3
"""Build CODE.1 and CODE.2 from the sources with the original Watcom tools and compare their SHA-1 with expected.sha1.

usage: tools/build.py [CODE.1|CODE.2|all] [--keep-going]

Per program (link/<PROG>/order.txt lists every object in link order):
  1. wcc386 compiles each C module (CODE.1: Watcom 9.5b, CODE.2: 10.0a), one DOSBox-X run per file;
  2. WASM (10.0a) assembles the .asm files;
  3. the C library modules are copied out of the installation's .LIB files;
  4. WLINK (CODE.1: 9.5, CODE.2: 10.0a) links all objects in the listed order (link/<PROG>/options.lnk) behind a
     placeholder stub;
  5. the placeholder stub is replaced by the DOS/4GW Professional loader (what 4GWBIND did);
  6. the bytes of link/<PROG>/alignfix.csv are patched in;
  7. SHA-1 of the result (build/<PROG>) against expected.sha1.
Configuration: build.cfg, each entry overridable by an environment variable of the same name.
"""
import sys, os, re, csv, hashlib, shutil, struct, configparser
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
import dos, omflib

PROGRAMS = {'CODE.1': dict(dir='CODE1', cc='WATCOM95', link='WATCOM95'),
            'CODE.2': dict(dir='CODE2', cc='WATCOM10A', link='WATCOM10A')}
ASM = 'WATCOM10A'                 # WASM is taken from the 10.0a installation for both programs
STUB_SIZE = 0x1EB8                # size of the stub the original was linked behind (see README, "The loader")

def config():
    cp = configparser.ConfigParser(); cp.optionxform = str
    cp.read(os.path.join(ROOT, 'build.cfg'))
    c = {k: os.environ.get(k, v) for k, v in cp['paths'].items()}
    c = {k: os.path.expanduser(os.path.expandvars(v)) for k, v in c.items()}
    return {k: v if os.path.isabs(v) else os.path.join(ROOT, v) for k, v in c.items()}   # relative: to the repository root

def order(prog):
    out = []
    for l in open(os.path.join(ROOT, 'link', PROGRAMS[prog]['dir'], 'order.txt')):
        l = l.split('#')[0].strip()
        if not l: continue
        kind, name, *rest = l.split(None, 2)
        out.append((kind, name, rest[0] if rest else ''))
    return out

def stamp_ok(path, key):
    return os.path.exists(path) and os.path.exists(path + '.stamp') and open(path + '.stamp').read() == key

def compile_c(cfg, prog, name, flags, work):
    """wcc386 <flags> -i=D:\\INC NAME.C in a fresh DOSBox-X (the result of one module depends on the compiler's run-time
    environment, see README "Caveats"; each compile therefore gets its own emulator run, as the sources were matched)."""
    src = os.path.join(ROOT, 'src', PROGRAMS[prog]['dir'], name + '.c'); N = name.upper()
    watcom = cfg[PROGRAMS[prog]['cc']]; obj = os.path.join(work, N + '.OBJ')
    h = hashlib.sha1(open(src, 'rb').read() + flags.encode() + watcom.encode())
    for f in sorted(os.listdir(os.path.join(ROOT, 'include'))): h.update(open(os.path.join(ROOT, 'include', f), 'rb').read())
    if stamp_ok(obj, h.hexdigest()): return obj
    for f in (obj, obj + '.stamp'):
        if os.path.exists(f): os.remove(f)
    shutil.copy(src, os.path.join(work, N + '.C'))
    dos.run(watcom, work, ['wcc386 %s -i=D:\\INC %s.C > %s.LOG' % (flags, N, N)], name=N, timeout=120)
    if not os.path.exists(obj):
        log = os.path.join(work, N + '.LOG')
        raise SystemExit('%s: compile failed\n%s' % (name, open(log, errors='replace').read() if os.path.exists(log) else '(no output)'))
    open(obj + '.stamp', 'w').write(h.hexdigest())
    return obj

def assemble(cfg, prog, files, work):
    """wasm <options> NAME.ASM for every (name, options), all in one DOSBox-X run"""
    watcom = cfg[ASM]; todo = []
    for name, opts in files:
        src = os.path.join(ROOT, 'src', PROGRAMS[prog]['dir'], name + '.asm'); N = name.upper(); obj = os.path.join(work, N + '.OBJ')
        key = hashlib.sha1(open(src, 'rb').read() + watcom.encode() + opts.encode()).hexdigest()
        if stamp_ok(obj, key): continue
        for f in (obj, obj + '.stamp'):
            if os.path.exists(f): os.remove(f)
        shutil.copy(src, os.path.join(work, N + '.ASM')); todo.append((name, N, obj, key, opts))
    if todo:
        dos.run(watcom, work, ['wasm %s %s.ASM > %s.LOG' % (opts, N, N) for _, N, _, _, opts in todo], name='WASM', timeout=300)
    for name, N, obj, key, opts in todo:
        log = open(os.path.join(work, N + '.LOG'), errors='replace').read() if os.path.exists(os.path.join(work, N + '.LOG')) else '(no output)'
        if not os.path.exists(obj) or ' 0 errors' not in log: raise SystemExit('%s.asm: assembly failed\n%s' % (name, log[-2000:]))
        open(obj + '.stamp', 'w').write(key)

def libpath(cfg, prog, lib):
    if lib in cfg: return cfg[lib]
    return os.path.join(cfg[PROGRAMS[prog]['link']], 'LIB386', 'DOS', lib)

def write_stub(path):
    """a DOS MZ program of STUB_SIZE bytes; only its size reaches the linked image (the LE header's page offset)"""
    h = bytearray(STUB_SIZE)
    struct.pack_into('<2s13H', h, 0, b'MZ', STUB_SIZE % 512, (STUB_SIZE + 511) // 512, 0, 4, 0, 0xffff, 0, 0xb8, 0, 0, 0, 0x40, 0)
    h[0x40:0x45] = bytes([0xb8, 0x01, 0x4c, 0xcd, 0x21])
    open(path, 'wb').write(h)

def patch(image, le, rows):
    """rows: (linear address, byte) -> patched into the pages of the LE image whose header is at offset le"""
    g = lambda o: struct.unpack_from('<I', image, le + o)[0]
    npages, pagesize, lastpage, objtab, nobj = g(0x14), g(0x28), g(0x2c), g(0x40), g(0x44)
    page0 = len(image) - ((npages - 1) * pagesize + lastpage)
    out = bytearray(image)
    for addr, byte in rows:
        for i in range(nobj):
            vsize, base, flags, pidx, pcount, _ = struct.unpack_from('<6I', image, le + objtab + 24 * i)
            if base <= addr < base + vsize: out[page0 + (pidx - 1) * pagesize + addr - base] = byte; break
        else: raise SystemExit('alignfix: address %08x is in no object' % addr)
    return bytes(out)

def build(prog, cfg):
    d = PROGRAMS[prog]['dir']; work = os.path.join(ROOT, 'build', d); cc = os.path.join(work, 'cc'); lk = os.path.join(work, 'link')
    for p in (cc, lk, os.path.join(cc, 'INC')): os.makedirs(p, exist_ok=True)
    for f in os.listdir(os.path.join(ROOT, 'include')): shutil.copy(os.path.join(ROOT, 'include', f), os.path.join(cc, 'INC', f))
    pieces = order(prog); files = []
    assemble(cfg, prog, [(n, a) for k, n, a in pieces if k == 'asm'], cc)
    libs = {}
    for kind, name, arg in pieces:
        N = name.upper() + '.OBJ'
        if kind == 'c': shutil.copy(compile_c(cfg, prog, name, arg, cc), os.path.join(lk, N))
        elif kind == 'asm': shutil.copy(os.path.join(cc, N), os.path.join(lk, N))
        elif kind == 'lib':
            if arg not in libs: libs[arg] = omflib.modules(libpath(cfg, prog, arg))
            if name.lower() not in libs[arg]: raise SystemExit('%s: no module %s' % (libpath(cfg, prog, arg), name))
            open(os.path.join(lk, N), 'wb').write(libs[arg][name.lower()])
        else: raise SystemExit('order.txt: unknown kind ' + kind)
        files.append(N)
    opts = [l.strip() for l in open(os.path.join(ROOT, 'link', d, 'options.lnk')) if l.strip() and not l.startswith('#')]
    write_stub(os.path.join(lk, 'STUB.EXE'))
    with open(os.path.join(lk, 'LINK.LNK'), 'w') as f:
        f.write('\r\n'.join(opts + ['option stub=STUB.EXE', 'option map'] + ['file ' + n for n in files]) + '\r\n')
    for f in ('CODE.EXE', 'CODE.MAP', 'LINK.LOG'):
        if os.path.exists(os.path.join(lk, f)): os.remove(os.path.join(lk, f))
    dos.run(cfg[PROGRAMS[prog]['link']], lk, ['wlink @LINK.LNK > LINK.LOG'], name='LINK', timeout=300)
    exe = os.path.join(lk, 'CODE.EXE'); log = open(os.path.join(lk, 'LINK.LOG'), errors='replace').read() if os.path.exists(os.path.join(lk, 'LINK.LOG')) else ''
    bad = [l.strip() for l in log.splitlines() if 'rror' in l or 'arning' in l]
    for l in bad[:30]: print('  wlink: ' + l)
    if not os.path.exists(exe): raise SystemExit('%s: WLINK wrote no executable\n%s' % (prog, log[-2000:]))
    image = open(exe, 'rb').read(); le = struct.unpack_from('<I', image, 0x3c)[0]
    if le != STUB_SIZE or image[le:le + 2] != b'LE': raise SystemExit('%s: no LE header behind the stub' % prog)
    loader = open(cfg['LOADER'], 'rb').read()
    want = dict(l.split()[::-1] for l in open(os.path.join(ROOT, 'expected.sha1')) if l.strip())
    if hashlib.sha1(loader).hexdigest() != want['LOADER']: raise SystemExit('%s is not the expected loader (SHA-1 %s)' % (cfg['LOADER'], want['LOADER']))
    image = loader + image[le:]                                    # bind
    rows = [(int(r['addr'], 16), int(r['byte'], 16)) for r in csv.DictReader(open(os.path.join(ROOT, 'link', d, 'alignfix.csv')))]
    image = patch(image, len(loader), rows)
    out = os.path.join(ROOT, 'build', prog); open(out, 'wb').write(image)
    sha = hashlib.sha1(image).hexdigest(); ok = sha == want[prog] and not bad
    print('%s  %s  %d bytes  %s' % (sha, prog, len(image), 'OK' if sha == want[prog] else 'MISMATCH (expected %s)' % want[prog]))
    return ok

if __name__ == '__main__':
    which = next((a for a in sys.argv[1:] if not a.startswith('--')), 'all')
    cfg = config(); ok = True
    for p in (['CODE.1', 'CODE.2'] if which == 'all' else [which]): ok &= build(p, cfg)
    sys.exit(0 if ok else 1)
