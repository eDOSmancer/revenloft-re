#!/usr/bin/env python3
"""Who references which uninitialised object: from the fixups of the built module objects (build/<PROG>/cc/*.OBJ).

usage: tools/bssxref.py PROG START END     per address in [START, END) (hex): module:function,... that reference it
PROG is CODE1 or CODE2; run after `make`.  The names carry the addresses (B<address>_xx); a view adds its offset, so a
label inside an object is listed at its own address.  See docs/BSS.md, "Object files and extents"."""
import sys, os, re, struct, bisect
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def idx(d, o): return (((d[o] & 0x7f) << 8) | d[o + 1], o + 2) if d[o] & 0x80 else (d[o], o + 1)

def load(path):
    """(functions [(offset, name)], references [(text offset, external name, addend)]) of an OMF object"""
    b = open(path, 'rb').read(); ln = ['']; segs = ['']; exts = ['']; funs = []; refs = []; last = None; o = 0
    while o < len(b):
        t = b[o]; n = struct.unpack_from('<H', b, o + 1)[0]; d = b[o + 3:o + 3 + n - 1]; o += 3 + n
        if t == 0x96:
            p = 0
            while p < len(d): ln.append(d[p + 1:p + 1 + d[p]].decode('latin1')); p += 1 + d[p]
        elif t in (0x98, 0x99):
            p = 1 + (3 if (d[0] >> 5) == 0 else 0) + (4 if t == 0x99 else 2); ni, p = idx(d, p); segs.append(ln[ni])
        elif t in (0x8c, 0xb4, 0xb5):
            p = 0
            while p < len(d): exts.append(d[p + 1:p + 1 + d[p]].decode('latin1')); p += 1 + d[p]; _, p = idx(d, p)
        elif t in (0x90, 0x91, 0xb6, 0xb7):
            g, p = idx(d, 0); si, p = idx(d, p)
            if si == 0: p += 2
            while p < len(d):
                name = d[p + 1:p + 1 + d[p]].decode('latin1'); p += 1 + d[p]
                off = struct.unpack_from('<I' if t & 1 else '<H', d, p)[0]; p += 4 if t & 1 else 2; _, p = idx(d, p)
                if si and segs[si] == '_TEXT': funs.append((off, name))
        elif t in (0xa0, 0xa1):
            si, p = idx(d, 0); off = struct.unpack_from('<I' if t == 0xa1 else '<H', d, p)[0]; p += 4 if t == 0xa1 else 2
            last = (segs[si], off, d[p:])
        elif t in (0x9c, 0x9d):
            p = 0
            while p < len(d):
                if d[p] & 0x80:
                    ro = ((d[p] & 3) << 8) | d[p + 1]; fd = d[p + 2]; p += 3; tgt = None
                    if not fd & 0x80 and ((fd >> 4) & 7) < 3: _, p = idx(d, p)
                    if not fd & 8:
                        ti, p = idx(d, p)
                        if fd & 3 == 2: tgt = exts[ti]
                    if not fd & 4: p += 4 if t == 0x9d else 2
                    if tgt and last and last[0] == '_TEXT' and ro + 4 <= len(last[2]):
                        refs.append((last[1] + ro, tgt, struct.unpack_from('<i', last[2], ro)[0]))
                else:
                    m = (d[p] >> 2) & 7; isf = d[p] & 0x40; p += 1
                    if not isf or m < 3: _, p = idx(d, p)
    return sorted(funs), refs

def table(prog):
    """{address: {(module, function)}}"""
    T = {}
    for l in open(os.path.join(ROOT, 'link', prog, 'order.txt')):
        p = l.split()
        if len(p) < 2 or p[0] not in ('c', 'asm'): continue
        funs, refs = load(os.path.join(ROOT, 'build', prog, 'cc', p[1].upper() + '.OBJ'))
        for off, name, add in refs:
            m = re.fullmatch(r'_?[B-Z]([0-9a-f]{8})_\w\w', name)
            if not m: continue
            k = bisect.bisect_right(funs, (off, '~')) - 1
            T.setdefault(int(m.group(1), 16) + add, set()).add((p[1], funs[k][1] if k >= 0 else '?'))
    return T

if __name__ == '__main__':
    if len(sys.argv) != 4: raise SystemExit(__doc__)
    a0 = int(sys.argv[2], 16); a1 = int(sys.argv[3], 16); T = table(sys.argv[1])
    for a in sorted(T):
        if a0 <= a < a1:
            mods = sorted(set(m for m, f in T[a]))
            print('%x %s' % (a, ' '.join('%s:%s' % (m, ','.join(sorted(f for mm, f in T[a] if mm == m))) for m in mods)))
