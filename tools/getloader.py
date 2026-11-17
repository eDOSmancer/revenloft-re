#!/usr/bin/env python3
"""Extract the DOS/4GW Professional loader from an executable that was bound with it (4GWBIND).

usage: tools/getloader.py <bound executable> <output file>

The loader is everything ahead of the LE header of the bound program.  Any program bound with the same loader
version gives the same bytes; the build checks the SHA-1 (expected.sha1, line LOADER).  The game's own CODE.1 or
CODE.2 are such programs: this script is the only place where one of them is read, and only for this prefix.
"""
import sys, struct, hashlib, os

def le_offset(d):
    i = d.find(b'LE\0\0')
    while i != -1:
        cpu, os_ = struct.unpack_from('<HH', d, i + 8)
        if cpu in (1, 2, 3, 4) and os_ in (1, 4): return i
        i = d.find(b'LE\0\0', i + 1)
    raise SystemExit('no LE header found')

if __name__ == '__main__':
    if len(sys.argv) != 3: raise SystemExit(__doc__)
    d = open(sys.argv[1], 'rb').read(); n = le_offset(d); sha = hashlib.sha1(d[:n]).hexdigest()
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    want = dict(l.split()[::-1] for l in open(os.path.join(root, 'expected.sha1')) if l.strip())['LOADER']
    print('%d bytes, SHA-1 %s (%s)' % (n, sha, 'as expected' if sha == want else 'NOT the expected %s' % want))
    if sha != want: sys.exit(1)
    open(sys.argv[2], 'wb').write(d[:n])
