#!/usr/bin/env python3
"""Uninitialised data (_BSS) in the C modules: names fitted to wcc386's emission order.  See docs/BSS.md for the rule.

usage: tools/bssfit.py classes PROG                 size classes of every label still in a b*.asm (where a module may end)
       tools/bssfit.py rename  PROG                 give every label of the b*.asm files its fitted name, in all sources
       tools/bssfit.py convert PROG MODULE [--first NAME] [--last NAME] [--at TEXT] [--trim] [--size NAME=N ...] [--dry]
                                                    move the labels of b<module>.asm (or the run NAME..NAME) into m<module>.c
       tools/bssfit.py view    PROG NAME CONTAINER OFFSET
                                                    NAME lies inside the object CONTAINER: declare it as a view of it
       tools/bssfit.py check   PROG                 _BSS of every compiled module object: publics in address-name order
       tools/bssfit.py name    PROG STEM            the fitted name for a 10-character stem (e.g. B0007b67c_)
PROG is CODE1 or CODE2.  `convert` compiles probes under DOSBox-X (build/bss/), verifies the layout of the module's object
first; then it rewrites m<module>.c, b<module>.asm and
link/<PROG>/order.txt.  --at: insert the block ahead of this text instead of at the top of the file; --trim: no filler for
the last 1-3 bytes of the module (the linker's alignment of the next piece); --size: NAME is an object of N bytes (a name the module itself does not
declare; other modules may declare only its first member).
"""
import sys, os, re, glob, struct, shutil, json
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))

# ---- the two symbol hashes ------------------------------------------------------------------------------------------
def hash10(s):
    """wcc386 10.0a: CalcHash (12-bit hashpjw, two characters per round), table of 241 chains"""
    b = s.encode() + b'\0'; h = b[0]; i = 1
    if h:
        c = b[i]; i += 1
        if c:
            h = (h << 4) + c
            while True:
                h &= 0xfff; c = b[i]; i += 1
                if not c: break
                h = (h << 4) + c; h = (h ^ (h >> 12)) & 0xfff
                c = b[i]; i += 1
                if not c: break
                h = (h << 4) + c; h = h ^ (h >> 12)
    return h % 241

def hash95(s):
    """wcc386 9.5b: ((h << 4) + c) & 0xfff over the name, table of 211 chains (only the last three characters count)"""
    h = 0
    for c in s.encode(): h = ((h << 4) + c) & 0xfff
    return h % 211

HASH = {'CODE1': hash95, 'CODE2': hash10}
TARGET = 0                                    # every fitted name lies in chain 0 of the compiler's symbol table
ALPHA = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

def fit(prog, stem):
    """stem + the first two characters (in ALPHA order) that put the name into chain TARGET"""
    for a in ALPHA:
        for b in ALPHA:
            if HASH[prog](stem + a + b) == TARGET: return stem + a + b
    raise SystemExit('no suffix for ' + stem)

def fitted(prog, name, letter='B'):
    """DAT_0007b67c -> B0007b67c_xx (same length); a fitted name is returned unchanged"""
    m = re.fullmatch(r'DAT_([0-9a-f]{8})', name)
    return fit(prog, letter + m.group(1) + '_') if m else name

# ---- sources --------------------------------------------------------------------------------------------------------
def src(prog, f=''): return os.path.join(ROOT, 'src', prog, f)

def labels(path):
    """[(name, bytes up to the next label)] of a b*.asm file, in file (= address) order"""
    L = []; cur = None
    for l in open(path):
        l = l.split(';')[0].strip()
        m = re.match(r'(\w+)\s+label\s+byte', l)
        if m: cur = [m.group(1), 0]; L.append(cur); continue
        m = re.match(r'db\s+(\d+)\s+dup\(\?\)', l)
        if m:
            if cur is None: cur = ['', 0]; L.append(cur)
            cur[1] += int(m.group(1))
    return [tuple(x) for x in L]

def write_asm(path, module, L, note):
    out = ['; %s - uninitialised data (_BSS) of module %s.c, %d bytes' % (os.path.basename(path), module, sum(s for n, s in L)),
           '; STANDIN: ' + note, '.386p', 'DGROUP group _BSS', "_BSS segment dword public use32 'BSS'"]
    for n, s in L:
        if n: out += ['public ' + n, n + ' label byte']
        out.append('    db %d dup(?)' % s)
    open(path, 'w').write('\n'.join(out + ['_BSS ends', 'end']) + '\n')

def blank_comments(t):
    return re.sub(r'/\*.*?\*/', lambda m: re.sub(r'[^\n]', ' ', m.group(0)), t, flags=re.S)

def split_top(s):
    out = []; d = 0; cur = ''
    for ch in s:
        if ch in '([{': d += 1
        elif ch in ')]}': d -= 1
        if ch == ',' and d == 0: out.append(cur); cur = ''
        else: cur += ch
    return out + [cur]

def declarations(text):
    """{name: (base type, declarator with @ for the name)} from the file's first `extern` statement naming each object"""
    t = blank_comments(text); out = {}
    for m in re.finditer(r'\bextern\b', t):
        e = t.find(';', m.start()); st = t[m.end():e]
        if '{' in st: continue
        parts = split_top(st); base = None
        for i, p in enumerate(parts):
            mm = re.search(r'\b([A-Za-z_]\w*)\s*((\[[^\]]*\])*)\s*(\)\s*\(.*\))?\s*$', p, re.S)
            if not mm: break
            if i == 0:
                k = mm.start(1)
                while k > 0 and p[k - 1] in '*( \t\n': k -= 1
                base = ' '.join(p[:k].split()); decl = p[k:]
                if not base: break
            else: decl = p
            name = mm.group(1); decl = ' '.join(decl.split())
            decl = re.sub(r'\b%s\b' % name, '@', decl, count=1)
            if '(' in decl and not re.match(r'\(\s*\*+\s*@', decl) and not decl.startswith('*'): continue      # a function
            if '(' in decl and re.search(r'@\s*\(', decl): continue
            out.setdefault(name, (base, decl))
    return out

# ---- OMF ------------------------------------------------------------------------------------------------------------
def omf(path):
    """(segments [(name, class, length)], publics {name: (segment index, offset)}, data {segment index: bytearray})"""
    d = open(path, 'rb').read(); pos = 0; names = ['']; segs = [None]; pubs = {}; data = {}
    idx = lambda b, p: ((((b[p] & 0x7f) << 8) | b[p + 1], p + 2) if b[p] & 0x80 else (b[p], p + 1))
    while pos < len(d):
        t = d[pos]; ln = struct.unpack_from('<H', d, pos + 1)[0]; b = d[pos + 3:pos + 3 + ln - 1]; pos += 3 + ln; big = t & 1
        if t == 0x96:
            p = 0
            while p < len(b): names.append(b[p + 1:p + 1 + b[p]].decode('latin1')); p += 1 + b[p]
        elif t in (0x98, 0x99):
            p = 1 + (3 if (b[0] >> 5) == 0 else 0)
            n = struct.unpack_from('<I' if big else '<H', b, p)[0]; p += 4 if big else 2
            a, p = idx(b, p); c, p = idx(b, p); segs.append((names[a], names[c], n))
        elif t in (0x90, 0x91, 0xB6, 0xB7):
            g, p = idx(b, 0); s, p = idx(b, p)
            if s == 0: p += 2
            while p < len(b):
                n = b[p + 1:p + 1 + b[p]].decode('latin1'); p += 1 + b[p]
                o = struct.unpack_from('<I' if big else '<H', b, p)[0]; p += 4 if big else 2
                _, p = idx(b, p); pubs[n] = (s, o)
        elif t in (0xA0, 0xA1):
            s, p = idx(b, 0); o = struct.unpack_from('<I' if big else '<H', b, p)[0]; p += 4 if big else 2
            buf = data.setdefault(s, bytearray()); buf.extend(bytes(max(0, o + len(b) - p - len(buf)))); buf[o:o + len(b) - p] = b[p:]
    return segs, pubs, data

def bss_of(path):
    """(length of the object's _BSS, [(offset, public name)] sorted)"""
    segs, pubs, _ = omf(path)
    i = next((i for i, s in enumerate(segs) if s and s[0] == '_BSS'), None)
    if i is None: return 0, []
    return segs[i][2], sorted((o, n) for n, (s, o) in pubs.items() if s == i)

# ---- compiling ------------------------------------------------------------------------------------------------------
def flags_of(prog):
    import build
    return {n: a for k, n, a in build.order('CODE.1' if prog == 'CODE1' else 'CODE.2') if k == 'c'}

def compile_text(prog, module, text):
    """compile `text` as the module (its flags, the repository's include directory) -> path of the object or None"""
    import build, dos
    cfg = build.config(); work = os.path.join(ROOT, 'build', 'bss'); inc = os.path.join(work, 'INC')
    os.makedirs(inc, exist_ok=True)
    for f in os.listdir(os.path.join(ROOT, 'include')): shutil.copy(os.path.join(ROOT, 'include', f), os.path.join(inc, f))
    for f in ('P.OBJ', 'P.LOG'):
        if os.path.exists(os.path.join(work, f)): os.remove(os.path.join(work, f))
    open(os.path.join(work, 'P.C'), 'w', encoding='latin1').write(text)
    dos.run(cfg['WATCOM95' if prog == 'CODE1' else 'WATCOM10A'], work,
            ['wcc386 %s -i=D:\\INC P.C > P.LOG' % flags_of(prog)[module]], name='P', timeout=120)
    obj = os.path.join(work, 'P.OBJ')
    if not os.path.exists(obj):
        print(open(os.path.join(work, 'P.LOG'), errors='replace').read()[-1500:]); return None
    return obj

def read(path): return open(path, encoding='latin1').read()

def sizes(prog, module, names):
    """{name: (declaration, size or element size, incomplete?)} for the names the module declares (cached per source text)"""
    text = read(src(prog, module + '.c')); D = declarations(text)
    for h in re.findall(r'#include\s+"(\w+\.h)"', text):                 # the project headers it includes
        for n, d in declarations(read(os.path.join(ROOT, 'include', h))).items(): D.setdefault(n, d)
    D = {n: D[n] for n in names if n in D}
    if not D: return {}
    cache = os.path.join(ROOT, 'build', 'bss', 'sizes.json'); os.makedirs(os.path.dirname(cache), exist_ok=True)
    C = json.load(open(cache)) if os.path.exists(cache) else {}
    import hashlib
    key = prog + module + hashlib.sha1((text + ' '.join(sorted(D))).encode('latin1')).hexdigest()
    if key not in C:
        order = sorted(D); add = ['']
        for n in order:
            base, decl = D[n]
            add.append('#undef %s' % n)
        inc = lambda n: re.match(r'@\s*\[\s*\]', D[n][1].lstrip('(* '))
        add.append('unsigned long ZZBSSSZ[] = { %s };' % ', '.join(
            '(sizeof(%s%s) << 8) | %d' % (n, '[0]' if inc(n) else '', i & 255) for i, n in enumerate(order)))
        obj = compile_text(prog, module, text + '\n'.join(add) + '\n')
        if not obj: raise SystemExit('size probe of %s failed' % module)
        segs, pubs, data = omf(obj); s, o = pubs['ZZBSSSZ']
        C[key] = {n: struct.unpack_from('<I', data[s], o + 4 * i)[0] >> 8 for i, n in enumerate(order)}
        json.dump(C, open(cache, 'w'))
    return {n: (D[n], C[key][n], bool(re.match(r'@\s*\[\s*\]', D[n][1]))) for n in D}

# ---- layout ---------------------------------------------------------------------------------------------------------
def cls(size):
    """the compiler's size class (objects are emitted class 6 first, class 1 last)"""
    m = size % 8
    if m == 0: return 6
    if m == 4: return 5
    if m & 1: return 1 if size == 1 else 2
    return 3 if size == 2 else 4

def fillers(r, limit, depth=3):
    """ways to cut r filler bytes into at most `depth` objects of non-increasing class <= limit: [[size, ...]]"""
    if r == 0: return [[]]
    out = []
    if cls(r) <= limit: out.append([r])
    if depth > 1:
        for a in sorted(set(x for x in list(range(1, 9)) + [r - k for k in range(1, 9)] if 0 < x < r)):
            if cls(a) <= limit:
                out += [[a] + rest for rest in fillers(r - a, cls(a), depth - 1)]
    return out

def solve(items):
    """items: [(name, gap, size, flexible)] in address order -> [(name or None, size)] with non-increasing classes, fewest
    fillers; None if there is no such cut.  A flexible item is an array with unknown bound and element size `size`."""
    best = {6: (0, [])}                                       # class limit -> (fillers, objects)
    for name, gap, size, flex in items:
        new = {}
        if name is None: cands = [(None, 0)]
        elif flex: cands = [(name, n * size) for n in range(gap // size, 0, -1)][:1] + \
                           [(name, n * size) for n in sorted(set((gap - k) // size for k in range(1, 17)), reverse=True) if n > 0]
        else: cands = [(name, size)]
        for lim, (cost, objs) in best.items():
            for nm, sz in cands:
                if sz > gap: continue
                if nm is not None and cls(sz) > lim: continue
                l2 = cls(sz) if nm is not None else lim
                for f in fillers(gap - sz, l2):
                    l3 = cls(f[-1]) if f else l2
                    c = cost + len(f) + (0.01 if flex and sz != gap else 0)
                    if l3 not in new or c < new[l3][0]:
                        new[l3] = (c, objs + ([(nm, sz)] if nm is not None else []) + [(None, x) for x in f])
        best = new
        if not best: return None
    return min(best.values(), key=lambda v: v[0])[1]

def program_names(prog):
    out = {}
    for f in sorted(glob.glob(src(prog, 'b*.asm'))):
        for n, s in labels(f):
            if n: out[n] = 'm' + os.path.basename(f)[1:-4]
    return out

def gather(prog, module, L, force={}):
    """per label of L: the declaration to use and its size -> items for solve(), {name: (base, decl, from module)}"""
    names = [n for n, s in L if n]; info = {}
    own = sizes(prog, module, names)
    others = [m for m in flags_of(prog) if m != module]
    for n in names:
        if n in own: info[n] = own[n] + (module,); continue
        for m in others:
            if re.search(r'\b%s\b' % n, read(src(prog, m + '.c'))):
                s = sizes(prog, m, names)
                if n in s: info[n] = s[n] + (m,); break
    for n, v in force.items():                                # --size NAME=N: an object of N bytes, whatever is declared
        if n in info and info[n][3] == module: raise SystemExit('%s is declared in %s: change the declaration there' % (n, module))
        info[n] = (('unsigned char', '@[%d]' % v), v, False, module)
    items = []
    for n, gap in L:
        if not n: items.append((None, gap, 0, False)); continue
        if n not in info: items.append((n, gap, 1, True)); continue          # named by assembler files only: bytes
        (base, decl), size, flex, m = info[n]
        items.append((n, gap, size, flex))
    return items, info

# ---- commands -------------------------------------------------------------------------------------------------------
def cmd_classes(prog):
    for f in sorted(glob.glob(src(prog, 'b*.asm'))):
        module = 'm' + os.path.basename(f)[1:-4]; L = labels(f); items, info = gather(prog, module, L)
        row = []
        for n, gap, size, flex in items:
            if n is None: row.append('?%d' % gap)
            else: row.append('%s:%s%d/%d%s' % (n[-9:-3] if n[0] != 'D' else n[-5:], '' if flex else cls(size) * 0 or '', size, gap, '[]' if flex else ''))
        print('%s %d bytes, cut %s\n   %s' % (module, sum(s for n, s in L), 'ok' if solve(items) else 'NONE', ' '.join(row)))

def cmd_rename(prog):
    names = program_names(prog); new = {n: fitted(prog, n) for n in names}
    if len(set(new.values())) != len(new): raise SystemExit('fitted names collide')
    rx = re.compile(r'\b(%s)\b' % '|'.join(n for n in names if new[n] != n)) if any(new[n] != n for n in names) else None
    count = 0
    if rx:
        for f in sorted(glob.glob(src(prog, '*.c')) + glob.glob(src(prog, '*.asm')) + glob.glob(os.path.join(ROOT, 'include', '*.h'))):
            t = read(f); t2, k = rx.subn(lambda m: new[m.group(1)], t)
            if k: open(f, 'w', encoding='latin1').write(t2); count += k
    print('%s: %d names, %d replacements' % (prog, len(names), count))

BEGIN = '/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */'
END = '/* BSS end */'

def cmd_convert(prog, module, first=None, last=None, at=None, dry=False, trim=False, force={}):
    path = src(prog, 'b%s.asm' % module[1:]); L = labels(path); cpath = src(prog, module + '.c'); text = read(cpath)
    if BEGIN in text: raise SystemExit('%s already has a BSS block (convert the whole run in one step)' % module)
    names = [n for n, s in L]
    i0 = names.index(first) if first else 0; i1 = names.index(last) + 1 if last else len(L)
    head, mid, tail = L[:i0], L[i0:i1], L[i1:]
    items, info = gather(prog, module, mid, force); objs = solve(items)
    if objs is None: raise SystemExit('%s: no cut with non-increasing size classes' % module)
    # names and declarations, address order
    decls = []; expect = []; off = 0; prev = 'F' + module[1:].rjust(8, '0') + '_'; k = 0; dims = {}
    for n, size in objs:
        if n is None:
            k += 1; fn = fit(prog, 'FGHIJKLMNOPQRSTUVWXYZ'[k - 1] + prev[1:])
            decls.append('unsigned char %s[%d];' % (fn, size)); expect.append((off, fn))
        else:
            k = 0; prev = 'F' + n[1:10] if re.fullmatch(r'B[0-9a-f]{8}_\w\w', n) else 'F' + n[-8:] + '_'
            if n in info:
                (base, decl), sz, flex, m = info[n]
                if flex:
                    dims[n] = size // sz; decl = re.sub(r'@\s*\[\s*\]', '@[%d]' % dims[n], decl, count=1)
                if m != module and re.search(r'\b(struct|union)\b', base) or (m != module and not re.fullmatch(r'((un)?signed |volatile )*(char|short|int|long|void)', base)):
                    base, decl = 'unsigned char', '@[%d]' % size
                decls.append('%s %s;' % (base, decl.replace('@', n)))
            else: decls.append('unsigned char %s[%d];' % (n, size))
            expect.append((off, n))
        off += size
    if off != sum(s for n, s in mid): raise SystemExit('internal: sizes')
    if trim and not tail and objs[-1][0] is None and objs[-1][1] < 4:      # the linker's alignment of the next _BSS piece
        off -= objs[-1][1]; decls.pop(); expect.pop()
    block = BEGIN + '\n' + '\n'.join(decls[::-1]) + '\n' + END + '\n'
    if prog == 'CODE2' and dims:                 # 10.0a: a later declaration with an empty bound would shrink the object
        t = blank_comments(text); cuts = []
        for n, d in dims.items():
            for m in re.finditer(r'\b%s\s*\[\s*\]' % n, t):
                st = t.rfind(';', 0, m.start()); st2 = t.rfind('}', 0, m.start())
                if re.match(r'\s*extern\b', t[max(st, st2) + 1:m.start()]) : cuts.append((m.start(), m.end(), '%s[%d]' % (n, d)))
        for a, b, r in sorted(cuts, reverse=True): text = text[:a] + r + text[b:]
    if at:
        p = text.index(at); new = text[:p] + block + text[p:]
    else: new = block + text
    obj = compile_text(prog, module, new)
    if not obj: raise SystemExit('%s does not compile with the block' % module)
    length, pubs = bss_of(obj); got = [(o, n) for o, n in pubs]
    if got != expect or length != off:
        print('layout differs: _BSS %d bytes (want %d)' % (length, off))
        g = dict((n, o) for o, n in got)
        for o, n in expect:
            if g.get(n) != o: print('   %s at %s, want %d' % (n, g.get(n), o))
        raise SystemExit(1)
    print('%s: %d bytes, %d names, %d fillers; object layout ok%s' % (module, off, sum(1 for n, s in objs if n), sum(1 for n, s in objs if n is None), ' (dry run)' if dry else ''))
    if dry: return
    open(cpath, 'w', encoding='latin1').write(new)
    note = 'part of the module\'s uninitialised data that is not defined in the C file (see docs/BSS.md).'
    if tail: write_asm(path, module, tail, note)
    else: os.remove(path)
    if head: write_asm(src(prog, 'c%s.asm' % module[1:]), module, head, note + '  Linked ahead of the module.')
    op = os.path.join(ROOT, 'link', prog, 'order.txt'); o = open(op).read().split('\n'); b = 'b' + module[1:]
    i = next(i for i, l in enumerate(o) if l.split()[:2] == ['asm', b])
    if head: o.insert(next(i for i, l in enumerate(o) if l.split()[:2] == ['c', module]), o[i].replace(b, 'c' + module[1:])); i += 1
    if not tail: del o[i]
    open(op, 'w').write('\n'.join(o))
    print('   left in assembler: %d bytes ahead, %d bytes behind' % (sum(s for n, s in head), sum(s for n, s in tail)))

def cmd_view(prog, name, cont, off):
    """NAME is a label inside the object CONT: every C file that declares it sees it as a view of CONT instead, and the
    label is dropped from its b*.asm (its bytes go to the label ahead of it)"""
    for f in sorted(glob.glob(src(prog, 'm*.c'))):
        text = read(f); t = blank_comments(text)
        if not re.search(r'\b%s\b' % name, t): continue
        D = declarations(text)
        if name not in D: raise SystemExit('%s uses %s without a declaration' % (f, name))
        base, decl = D[name]; cuts = []; first = None
        if decl == '@': view = '(*(%s *)((char *)&%s + %d))' % (base, cont, off)
        elif re.fullmatch(r'@\s*\[[^\]]*\]', decl): view = '((%s *)((char *)&%s + %d))' % (base, cont, off)
        else: raise SystemExit('%s: no view for the declarator %s' % (f, decl))
        for m in re.finditer(r'\bextern\b', t):
            e = t.find(';', m.start()); st = t[m.start():e + 1]
            if not re.search(r'\b%s\b' % name, st): continue
            parts = split_top(st[len('extern'):-1]); keep = [q for q in parts if not re.search(r'\b%s\b' % name, q)]
            if len(keep) == len(parts): continue
            if first is None: first = m.start()
            if not re.search(r'\b%s\b' % name, parts[0]): new = 'extern' + ','.join(keep) + ';'
            elif keep:
                b0 = re.match(r'\s*((?:\w+\s+)+)', parts[0]).group(1); new = 'extern ' + b0 + ','.join(keep).lstrip() + ';'
            else: new = ''
            cuts.append((m.start(), e + 1, new))
        for s, e, new in sorted(cuts, reverse=True): text = text[:s] + new + text[e:]
        ls = text.rfind('\n', 0, first) + 1
        pre = '' if re.search(r'\b%s\b' % cont, blank_comments(text[:ls])) else 'extern unsigned char %s[]; ' % cont
        text = text[:ls] + '%s#define %s %s /* STANDIN: a name of its own in the original image, %d bytes into %s */\n' % (pre, name, view, off, cont) + text[ls:]
        open(f, 'w', encoding='latin1').write(text); print('view in', os.path.basename(f))
    for f in glob.glob(src(prog, 'b*.asm')):
        L = labels(f); k = next((i for i, (n, s) in enumerate(L) if n == name), None)
        if k is None: continue
        L[k - 1] = (L[k - 1][0], L[k - 1][1] + L[k][1]); del L[k]
        write_asm(f, 'm' + os.path.basename(f)[1:-4], L, "part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).")

def cmd_check(prog):
    work = os.path.join(ROOT, 'build', prog, 'cc'); bad = 0
    for f in sorted(glob.glob(os.path.join(work, 'M*.OBJ'))):
        length, pubs = bss_of(f); names = [n for o, n in pubs]
        key = [n[1:9] if re.fullmatch(r'[B-Z][0-9a-f]{8}_\w\w', n) else n[-8:] for n in names]
        ok = key == sorted(key)
        if length: print('%s _BSS %6d bytes %3d names %s' % (os.path.basename(f), length, len(names), 'address order' if ok else 'NOT in address order'))
        bad += not ok
    return bad

if __name__ == '__main__':
    a = sys.argv[1:]
    if len(a) < 2: raise SystemExit(__doc__)
    opt = lambda k: a[a.index(k) + 1] if k in a else None
    if a[0] == 'classes': cmd_classes(a[1])
    elif a[0] == 'rename': cmd_rename(a[1])
    elif a[0] == 'convert': cmd_convert(a[1], a[2], opt('--first'), opt('--last'), opt('--at'), '--dry' in a, '--trim' in a,
                                        {x.split('=')[0]: int(x.split('=')[1], 0) for i, x in enumerate(a) if i and a[i - 1] == '--size'})
    elif a[0] == 'view': cmd_view(a[1], a[2], a[3], int(a[4], 0))
    elif a[0] == 'check': sys.exit(1 if cmd_check(a[1]) else 0)
    elif a[0] == 'name': print(fit(a[1], a[2]))
    else: raise SystemExit(__doc__)
