"""Read the object modules of an OMF library (.LIB) as they are stored: name -> the module's bytes."""
import struct

def modules(path):
    d = open(path, 'rb').read()
    if d[0] != 0xF0: raise ValueError('%s: not an OMF library' % path)
    page = struct.unpack_from('<H', d, 1)[0] + 3
    end = struct.unpack_from('<I', d, 3)[0]          # dictionary offset
    pos = page; out = {}
    while pos < end and d[pos] != 0xF1:
        start = pos; name = None
        while True:
            t = d[pos]; n = struct.unpack_from('<H', d, pos + 1)[0]
            if t == 0x80 and name is None: name = d[pos + 4: pos + 4 + d[pos + 3]].decode('latin1')
            pos += 3 + n
            if t in (0x8A, 0x8B): break                # MODEND
        out.setdefault(name.lower(), d[start:pos])
        pos = (pos + page - 1) // page * page
    return out
