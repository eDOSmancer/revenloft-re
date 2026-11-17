# Uninitialised data (_BSS)

The original programs defined their uninitialised variables in the C files.  `wcc386` does not write a module's `_BSS`
in the order of the definitions, so the layout depends on the names, which are not known.  This file states the rule
both compilers follow, the naming scheme that reproduces the original layout with it, what `tools/bssfit.py` does, and
what was learned about object extents and object-file boundaries.  Every uninitialised object of both programs is defined in C.

## The emission rule

Source: the front end of the 2002 Open Watcom release (`cc/c/csym.c`: `SymAdd`, `GetSymList`, `FreeSym`, `SymBucket`;
`cc/c/cgen2.c`: `EmitSyms`, `EmitSym`), which is the same code; every point below was then measured with probe compiles
of both compilers (9.5b and 10.0a, the module flag sets of this repository).

At the end of the file the compiler walks its global symbol table and threads the symbols into one list; `EmitSyms`
writes the list front to back, and each object without an initialiser goes to `_BSS` at the next free offset (the
source aligns it to the type's alignment first under `-ot`; no padding occurred in any probe or module, the order
below leaves nothing to pad).  The list order is:

1. **Size class**, highest first (`SymBucket`, by `sizeof` modulo 8):
   6 = multiple of 8, 5 = multiple of 4 that is not, 4 = even (not 2), 3 = exactly 2 bytes, 2 = odd (not 1), 1 = one byte.
   So a module's `_BSS` is: all 8k-byte objects, then the 4-byte ones, the even ones, the shorts, the odd-sized ones, the
   single bytes.  An array of unknown bound counts as size 0 (class 6).
2. Inside a class, **symbol buffer** of the symbol, last buffer first.  The table stores symbols in buffers of 25
   (10.0a) or 22 (9.5b) entries, in the order of their first declaration in the file (every symbol counts: functions,
   locals, externs; the first buffer starts with 20 resp. 18 entries of the compiler's own).
3. Inside a buffer, **hash chain** ascending.  The chain is `hash(name) % table size`:
   - 10.0a: the 12-bit hashpjw of `CalcHash` (`hash10` in `tools/bssfit.py`), table size 241;
   - 9.5b: `h = ((h << 4) + c) & 0xfff` over the characters, table size 211 - only the last three characters of a
     name count (`hash95`).  (Inferred by fitting: the measured order of about 220 names in 11 buffers fits no other
     multiplier / mask / modulus tried; confirmed by the 7 converted CODE.1 modules and a 70-name probe.)
4. Inside a chain, **last declared first**.

What decides is the *first* declaration of a name in the file (`extern` or not): a later definition does not move the
symbol.  `static` objects and objects no code references are emitted like the others.  The optimisation flags (`-oa`,
`-ox`, `-d2`, `-s`, ...) do not enter.  The size class is global to the file: the buffers order symbols only *inside* a class, so one
file never emits a lower class ahead of a higher one, however many symbols it has (probe with objects of three
classes in three buffers, both compilers).

**Function-local statics** are not in that list.  They follow all file-scope objects of the file, function by function
in the order of the functions, the objects of a block last declared first (the names do not matter), an outer block
ahead of its inner blocks, each aligned to its type; they are not sorted by class.  (Probes, both compilers.  No object
of the two programs needs this: every candidate is used by several functions that are not expanded inline.)

**Alignment of the segment.**  The object's `_BSS` segment is dword-aligned.  It is paragraph-aligned when the file has
a far pointer or a `double` *object* - a local variable of any function is enough (`void (__far *h)()` in FUN_0002a064
of CODE.2 `m29c80.c`), and so is a `typedef` of such a type; an `extern` declaration, a prototype, a structure member or
`<i86.h>` is not.  The segment keeps that alignment when it is empty.

One difference between the compilers matters: in **10.0a the last declaration gives the object its type**, so
`char x[12];` followed anywhere by `extern char x[];` is emitted as an object of unknown bound (one byte, in class 6).
9.5b keeps the size of the definition.  In the CODE.2 modules every later declaration of a defined array therefore
carries the bound.

Nothing else in the build depends on the names: renaming all 352 variables changed neither image (WLINK orders nothing
by name; the object records of the modules kept their cuts with names of unchanged length), and turning `extern`
declarations into definitions changed no function and no relocation record in any of the 22 converted modules.

## The naming scheme (STANDIN)

Every uninitialised variable is named `B<address>_<xx>`: the address it has in the original image and two characters
chosen so that the name lies in **chain 0** of the compiler's symbol table (`bssfit.py name`; with the 9.5b hash this is
the same suffix `_eu` for every name, with 10.0a it differs per name).  The names have the length of the `DAT_<address>`
names they replace.  With all names in one chain, rule 2-4 collapse to "last declared first", independent of where the
buffer boundaries fall.  The owning C file therefore starts with a block (`/* BSS: ... */` to `/* BSS end */`) that
defines its objects **from the highest address down**; the compiler sorts them into the size classes and emits each
class in ascending address order - which is the original layout, because the original obeys rule 1 as well.

The names are stand-ins: the original identifiers are unknown, and any set of names with the right chain order per
buffer would do.  They are ordinary global names used directly in every C and assembler file (a header of `#define
DAT_x B..` macros is not possible: about 350 places define views of the form `#define DAT_x ((T)&DAT_x)`).

Bytes that no code names (the rest of an object whose extent is unknown, or variables the programs never reference by
address) are defined as filler arrays `F<address of the object ahead>_<xx>` (`G...`, `H...` for further pieces), cut so
that the size classes still descend.  A filler of 1-3 bytes at the end of a module is not defined: the linker's dword
alignment of the next module's `_BSS` supplies it.

**Views.** Where the original image names an address *inside* an object (a member of a record that code addresses as a
variable of its own), C cannot define that name.  It becomes a macro in the files (and headers) that use it,
`#define B..x (*(T *)((char *)&B..container + n))`, marked `STANDIN: view`; assembler files name `container+n`.
`bssfit.py contain / view` write them: every `extern` declaration of the name is replaced by the macro with that
declaration's type (a file may redeclare a name with another type further down: the macro is redefined there), an array
whose address is taken becomes `(*(T (*)[n])...)`, and local macros that reused an object's name
(`#define B.. ((struct PC *)&B..)` ... `#undef`) were renamed `M...` so that the object's name always means the object
(same preprocessed text).  Views in the sources:

- CODE.2: the members of the party records (container 0x718e0; the flag words and names as struct members), 8 members of the monster table 0x64d80 (100 x 22 bytes),
  the members of record 0 of the tables 0x65a18 (256 x 28 bytes) and 0x67618 (300 x 22), 0x6994c (row 0 of the map
  0x698e0), 0x74900 (in the 150 x 22 table 0x748ec), the high words 0x755d2 / 0x755d6 of the party position and
  0x755ea ... 0x755f6 (assembler only), the level header's members (assembler only), element -1 of the tables 0x63020 and
  0x64024 (0x6301e, 0x64018: the code indexes from 1), and from the first round 0x77106, 0x77150/2.
- CODE.1: the members of character record 0 (container 0x367f8: 0x36808 ... 0x36a80), 0x373ef (a member), 0x38919, the node members 0x37ff3/5/7 and 0x388fc/fe/900 (node 257).
- `selfview`: where the owning module itself declares only the first member (`extern unsigned char x;` for a table of
  248 bytes), the object is declared as bytes and those declarations become views of offset 0 (CODE.1 m10010: 0x35a00,
  0x363f8, 0x36808; CODE.2: the party flag word 0x718f0 in m2c0c0, the party position in m307e8).

What a view changes in the compiler (all found by the SHA-1 test, each a function that no longer matched):

- **Inline expansion (`-oe`).** The front end expands a function inline when its expression trees have at most 20 nodes
  (2002 source: `Inline_Threshold` against `NodeCount`); a plain global is one node, a view several (measured: with the
  views FUN_0001ccf4 is expanded only from `-oe=32` on, where other functions are expanded as well).  FUN_0001ccf4 and FUN_00033e1c (four and two flag words of the party records)
  stopped being expanded in their callers.
- **Register ties under `-oa`.** A global of its own is a memory node the allocator may keep in a register; a view (and
  a struct member) is not.  FUN_0001d550, FUN_0002538c (0x64020), FUN_00019368 / FUN_0001aed8 / FUN_00030a24 and two more (0x755d2,
  0x755d6) and FUN_0002bbd8 (0x75619) came out with swapped registers or frame slots.
- **m26810.c.** FUN_00026d04 depends on the compiler's state (README, Caveats); after the views its two copy chains had
  to be refitted (3 and 14 temporaries).

The second round answered this by keeping such a label an object of its own wherever adjacent definitions could
reproduce the layout.  That cut tables into pieces and produced object-file boundaries that do not exist (below).  The
third round gives the objects the extents the code shows and repairs the function instead: the pass-1 conflict list of
the view form is the original list minus the label's memory node (compared entry by entry in the allocator trace of the
real compiler), and **a dead read of a scalar the function does not otherwise use** - `{ int d; d = G; }`, marked
`STANDIN` - adds a zero-savings node at the same place of the list.  One read per lost node restored FUN_0002bbd8
(0x75619), FUN_00016444 (0x62b44), FUN_00029464 (two ints it reads as bytes) and the seven users of 0x755d2 / 0x755d6
(FUN_0001083c, FUN_00010cb0, FUN_00012db0, FUN_00019368, FUN_0001aed8, FUN_0002b27c, FUN_00030a24).  Reading the lost
variable itself does not help: a read at another size than the object's removes the node.

**The character records** (CODE.2 0x718e0, CODE.1 0x367f8) are one object of 4 x 0x248 bytes in both programs.  In
CODE.2 `include/chars.h` declares it `struct PCH B000718e0_iO[4]` (name, flag word, rest); the flag words and names of
the records are written as members (`B000718e0_iO[1].fl`).  A member with a constant index costs the front end no more
than a plain global, so FUN_0001ccf4 (four flag words) is expanded inline as in the original; a cast view was not
(the earlier rounds therefore kept seven adjacent pieces).  A member is still no `-oa` memory node: FUN_0001d550,
which expands FUN_0001ccf4, takes four dead reads (the original's pass-1 list has four zero-savings nodes at that
place; a struct of four records instead of an array gives none either).  FUN_00026d04's first copy chain went from 3
to 2 temporaries.

## tools/bssfit.py

    tools/bssfit.py classes PROG                the labels left in b*.asm with declared size / bytes to the next label
    tools/bssfit.py rename  PROG                fitted names for every label of the b*.asm files, in all sources
    tools/bssfit.py view    PROG NAME CONTAINER OFFSET
    tools/bssfit.py contain PROG CONTAINER SIZE [--keep NAME ...]   every label inside the object becomes a view of it
    tools/bssfit.py selfview PROG MODULE NAME=SIZE ...               the module's first-member declarations become views
    tools/bssfit.py own     PROG MODULE START END                   move a range of labels to b<MODULE>.asm (link order too)
    tools/bssfit.py convert PROG MODULE [--first NAME] [--last NAME] [--at TEXT] [--trim] [--size NAME=N] [--dry]
    tools/bssfit.py check   PROG                every built module object: its _BSS publics are in address-name order
    tools/bssxref.py PROG START END             who references the addresses of a range (module:function), from the built objects

`convert` takes the labels of `b<module>.asm` (address order, sizes = distance to the next label), finds each name's
declaration (the module's own `extern`, else the first other module's), measures `sizeof` with a probe compile, cuts
the range into objects with descending size classes (arrays of unknown bound take the room up to the next label; the
fewest fillers), writes the block, completes later empty bounds (CODE.2), compiles the module and compares the `_BSS`
publics of the object with the wanted offsets.  Only then does it write the C file, shrink or delete `b<module>.asm`
and update `link/<PROG>/order.txt`.  The build's SHA-1 comparison is the acceptance test of every step.

## Object files and extents

Rule 1 is a test for object-file boundaries: inside one object file the classes never rise with the address, so a rise
is either a label inside an object or the start of another object file, and then the address is dword-aligned.  The
second round applied it to the labels as they were and found more object files than modules; it defined the surplus in
data-only files `d<address>.c`.  Two more sources of evidence settle most of it:

**Who uses what.**  The fixups of the built objects give, for every address, the functions that reference it
(`tools/bssxref.py PROG START END`).  In CODE.2 the result is a plain picture: 0x62740-0x64580 is the *private* data of the modules in
link order - m106c0, m13a78, m186c4, m1ea90, m1eee0, m231dc, m23f70, m28d90, m29c80, m2af90, each piece used by that
module only - and 0x64580-0x75900 is the data everyone shares, lying where m2c0c0 (the module with `main`) and m307e8
are in the link order.  Then m32e40 and the modules behind follow with their own data again.

**Extents from the code.**  Every rise inside that picture disappeared once the object ahead of it had its real size:

| address | object | evidence |
|---|---|---|
| 0x62b30 | `void *[10]`, 40 bytes; 0x62b44 is element 5 | loops `for (k = 0; k < 10; k++)` over it |
| 0x62c20 | 4 x 256 bytes; 0x6301e is element -1 of the table behind | `buf + k * 0x100`, index from 1 |
| 0x63020 | 4096 bytes; 0x64018 is element -1 of the 5 x 12 table 0x64024 | index from 1 |
| 0x64090 | two ints | written as ints by FUN_00029888 |
| 0x65a18 | 256 records of 28 bytes (7168) | `struct W` of m307e8, 0x65a18 + 7168 = 0x67618 |
| 0x67618 | 300 records of 22 bytes (6600) | `memmove(..., n * 0x16)`, ends at 0x68fe0 |
| 0x698e0 | the map, 128 x 128 cells of 2 bytes (32768) | ends at the party records |
| 0x748ec | 150 records of 22 bytes (3300); 0x74900 is inside | `memmove(..., n * 0x16)`, ends at 0x755d0 |
| 0x755d0 / d4 | two ints (party position 16.16) | m307e8 passes `*(int *)&`; m2c0c0 declares 0x755e8-0x755f4 `int` |
| CODE.1 0x37ff0 | 258 nodes of 9 bytes (2322); 0x388fc-0x38900 are the links of node 257 | 0x388fc = node 257 + 3, the link offsets |

With them **CODE.2 has no object file without code**: every module defines one run, in link order, and the two runs of
the shared data are m2c0c0's (0x64580-0x7224c: twelve class-6 objects, six ints, shorts) and m307e8's (0x7224c-0x75900:
the 9880-byte table, then 40 objects of class 5 with the level header among them, two shorts).  m1c704, m270ac and
m26810 define nothing.  Which of the two modules owns which shared run follows from the link order alone.

**Paragraph alignment.**  The pieces of m13a78, m1ea90, m1eee0, m231dc, m23f70, m29c80, m3ac80 and m43aa0 start on a
16-byte boundary with 8 or 12 unnamed bytes ahead (m186c4 uses 8 of 16 bytes, m1eee0 and m231dc 4 of 16).  That is the
alignment of their `_BSS` segment, not data of the module ahead: m29c80 has it by itself (the far pointer above); the
m43aa0 as well (its real-mode call takes segment and offset of a local far pointer); the
other six get it from `typedef void (__far *PARA_BSS)();` at the top of the file (STANDIN: their code shows no far
pointer and no `double`, no header of the repository is shared by exactly these files; a far-pointer *parameter* does
not align - m3e340 has one).  No filler object is left ahead of these modules.

**CODE.1** has no object file without code either (`docs/FILES.md`).  The "runs" that seemed to start at 0x36814,
0x3682c, 0x36838 and 0x36a54 are members of the first character record: 0x367f8 is the table of four records of 0x248
bytes (the code indexes `x[p * 0x248]`, FUN_00014ef0 writes it to the file CHARS, 0x920 bytes) and ends at 0x37118,
where ten ints follow - one run of m10010.  In m150c0 the cursor record 0x371d4 is 530 bytes (shape, y, x, the mouse
flag, the 522-byte cursor image: even class), followed by four shorts and the page byte with its two 1024-byte save
buffers (2049 bytes): one run as well.

## State

| program | defined in C |
|---|---|
| CODE.1 | m10010 6984, m150c0 2735, m15880 3346, m161c0 132, m172d0 72, m17f50 24, m184d0 48, m1b060 16, m1cef0 64 |
| CODE.2 | m106c0 24, m13a78 1088, m186c4 8, m1ea90 68, m1eee0 4, m231dc 4, m23f70 5232, m28d90 8, m29c80 16, m2af90 1230, m2c0c0 56524, m307e8 14004, m32e40 6128, m38210 4, m3ac80 17712, m3c800 16, m3e340 57, m3f960 72, m40700 12, m40d80 124, m414b0 24, m43aa0 64, m44bb0 320 |

No `b*.asm` is left.  `tools/bssfit.py check` reports every `_BSS` of both programs in address order.

Open points:

- **Fillers** (unnamed bytes inside a module's run, `F...` / `G...`).  None of them can be alignment, with one
  exception: they lie between objects of one run, so each is a variable no code references (or the unknown rest of
  the object ahead).  CODE.2 m2c0c0 5 (an int at 0x72228, shorts at 0x72240 / 42 / 48 / 4a), m3f960 6 (2 + 4 + 12 + 4 + 4 + 4 bytes
  among its ints), m43aa0 1 (2 bytes); CODE.1 m172d0 6, m1cef0 1, m1b060 1 (12 bytes behind the configuration
  pointer; the CODE.2 twin m38210 has the pointer alone, so three ints of an older version).  The exception is the int
  0x7b63c at the end of m3c800: m3e340 behind it starts on a paragraph boundary, and removing the filler fails only
  because m3e340's `_BSS` is not paragraph-aligned by its far-pointer parameter (FUN_0003f2e0) - undecided between an
  unreferenced int and an alignment whose cause is not in the code.
- **Dead reads**: twelve lines.  The object-file evidence gives no natural replacement: no file owns the high words
  0x755d2 / 0x755d6 or a table element as a scalar of its own, and a struct member is no memory node (tested with the
  party records, array and struct-of-records form).
- **Element types**: objects written `unsigned char x[n]` in the definitions block of m2c0c0 / m307e8 (tables whose
  record type is declared only by other modules) and in the CODE.1 `d*.c` files have the extent, not the type.
- **0x7b6d0 (m40d80).** The find record (43 bytes) and the path buffer (81) must precede the library's `iob`; they are
  defined in `m40d80.c` as byte arrays although only m411e0 (linked after `iob`) uses them.  m40700 (12 bytes, class 5,
  directly ahead) could own them as well; the rule does not decide.
- `xib.asm` is unchanged.
