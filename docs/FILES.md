# Object files

Which C file of this repository corresponds to which object file of the original link.  The answer is "one object
file per module, in both programs, and none without code".  This file lists the kinds of evidence and what each says
at the places that were in doubt.  `docs/BSS.md` has the `_BSS` emission rule the first kind rests on.

## Kinds of evidence

| | evidence | what it shows |
|---|---|---|
| a | `_BSS` runs | one object file writes its uninitialised objects in descending size class; a rise at a dword boundary is a new file **or** a label inside a larger object |
| b | `CONST` padding | WCC386 pads each string literal to a dword with whatever its buffer holds (the bytes of `link/<PROG>/alignfix.csv`); WLINK pads between object files with zeros.  Non-zero padding between two literals puts their users in one file; zeros prove nothing (the residue can be zero) |
| c | code layout | functions inside a file follow each other dword-aligned with the compiler's filler (`90`, `8b c0`, `8d 40 00`); object files are paragraph-aligned and the linker fills with zeros.  A file boundary needs a paragraph-aligned function start that follows zeros or the exact end of the function ahead |
| d | fixup record chain | the order of the LE fixup records follows the object records; a new object file starts a new record (first cut about 172 bytes behind its start).  The build is byte-exact, so every module reproduces its chain; the earlier project (`impsim`, `modrec`) found 0x10010..0x150bf to fit as one object only, and 0x150c0 as the start of the next |
| e | inline expansion (`-oe`, CODE.2) | a call that is expanded puts caller and callee in one file, callee first.  CODE.1 is compiled without `-oe` |
| f | users | the functions that reference an address (`tools/bssxref.py`): private data lies at its module's link position |

## CODE.1

| place | a | b | c | d | result |
|---|---|---|---|---|---|
| 0x36814, 0x3682c, 0x36838, 0x36a54 (four "runs" in the range of m10010) | labels inside the table of four character records 0x367f8-0x37118 (`x[p * 0x248]`; 4 x 0x248 = 0x920 = the file CHARS); with the table as one object m10010 has one run: class 6 up to 0x37118, then ten ints | the literals of FUN_000138a4, 14978, 14cb0, 14d54, 14dc4, 14ef0 and `main` are chained by non-zero padding (0x30051 ... 0x3009a) | no zeros ahead of any function; five functions start on a paragraph right after a `ret` (0x104b0, 0x11cd0, 0x13020, 0x14b00, 0x14cb0; 3 expected by chance), the last two inside the chain of b | one object 0x10010..0x150bf | **m10010 is one file**; the data-only files d36814, d3682c, d36838, d36a54 were removed |
| 0x371dc (a "run" behind m150c0's mouse flag) | the cursor record 0x371d4 is shape, y, x, flag and the 522-byte image (530 bytes, even class); then four shorts, then 2049 bytes | - | m150c0's two paragraph starts (0x15230, 0x15780) follow compiler filler | 0x150c0 starts an object (cut at 0x1516c); the window 0x1516d..0x151dc needs the cursor data under few names | **m150c0 is one file**; d371dc was removed |
| 0x37140 (56-byte text buffer, first object of m150c0's run) | class 6 behind m10010's ints: cannot be m10010's unless it is 53-55 bytes | - | - | - | stays with m150c0 although only m10010 uses it (f); undecided |
| m15d90 (FUN_00015f4c is the only user of record members 0x36838.., 0x36a54, 0x36a80) | members of the record table of m10010; m15d90 defines nothing | - | no boundary | one object | one file |

## CODE.2

Consistency test only: every module is one object file by all kinds of evidence.

- a: `tools/bssfit.py check CODE2` - 23 modules with `_BSS`, each one descending run at its link position (private
  data 0x62740-0x64580 in link order, the shared data in m2c0c0 and m307e8).  The party records 0x718e0 are one object.
- c: no function inside a C module follows zero filler; the zero-filled paragraph starts are the assembler and
  library modules of `link/CODE2/order.txt` (0x39930, 0x43de0, 0x45680, 0x476f0).
- d: byte-exact fixup tables with one object per module; the earlier project's simulation found every region to fit
  as one object (0x186c4 with FUN_0001b950, 0x2c0c0 with 0x2cd48) and 0x3e340 / 0x3f960 as two.
- e: the expanded calls stay inside their modules (FUN_0001ccf4 in m1c704, FUN_00033e1c in m33df0, FUN_0002c1dc in m2c0c0).
- No disagreement was found; nothing was changed for this test.

Not decided by any evidence: whether 0x7b6d0 (find record and path buffer, used by m411e0 only) belongs to m40d80 or
m40700, and the int 0x7b63c at the end of m3c800 (`docs/BSS.md`, open points).
