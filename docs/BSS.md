# Uninitialised data (_BSS)

The original programs defined their uninitialised variables in the C files.  `wcc386` does not write a module's `_BSS`
in the order of the definitions, so the layout depends on the names, which are not known.  This file states the rule
both compilers follow, the naming scheme that reproduces the original layout with it, what `tools/bssfit.py` does, and
what was learned about object extents and object-file boundaries, and the one object still defined in assembler.

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
`-ox`, `-d2`, `-s`, ...) do not enter.  The object's `_BSS` segment is dword-aligned; it is paragraph-aligned when the
file has an object of 8-byte alignment (a `double` in a probe) and in the object of CODE.2 `m29c80.c`, with or without
contents.

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

- CODE.2: 51 members of the party records (container 0x718e0), 8 members of the monster table 0x64d80 (100 x 22 bytes),
  0x6761a, 0x6761e, 0x68fe4, 0x698e1, 0x748e6, 0x748ea, 0x75606, 0x75612 (the high word or a later element of the object
  ahead), and from the first round 0x77106, 0x77150/2.
- CODE.1: 0x3681e, 0x36903, 0x36907, 0x373ef, and from the first round 0x38919, 0x37ff3/5/7.
- `selfview`: where the owning module itself declares only the first member (`extern unsigned char x;` for a table of
  248 bytes), the object is declared as bytes and those declarations become views of offset 0 (CODE.1 m10010: 0x35a00,
  0x363f8, 0x36808).

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

The answer in every case but the last was not to make that label a view: **a label stays an object of its own wherever
the class rule lets adjacent definitions reproduce the layout**, and it turned out that this is nearly always so - which
says that these labels are the original objects.  The party records are the exception: they are defined as seven
adjacent pieces (16 / 568 / 16 / 568 / 16 / 584 / 568 bytes, all class 6) cut at the names of the 2nd and 3rd record and at
the four flag words, so that these six labels keep an object (STANDIN, noted in `m1ea90.c`).

## tools/bssfit.py

    tools/bssfit.py classes PROG                the labels left in b*.asm with declared size / bytes to the next label
    tools/bssfit.py rename  PROG                fitted names for every label of the b*.asm files, in all sources
    tools/bssfit.py view    PROG NAME CONTAINER OFFSET
    tools/bssfit.py contain PROG CONTAINER SIZE [--keep NAME ...]   every label inside the object becomes a view of it
    tools/bssfit.py selfview PROG MODULE NAME=SIZE ...               the module's first-member declarations become views
    tools/bssfit.py own     PROG MODULE START END                   move a range of labels to b<MODULE>.asm (link order too)
    tools/bssfit.py convert PROG MODULE [--first NAME] [--last NAME] [--at TEXT] [--trim] [--size NAME=N] [--dry]
    tools/bssfit.py check   PROG                every built module object: its _BSS publics are in address-name order

`convert` takes the labels of `b<module>.asm` (address order, sizes = distance to the next label), finds each name's
declaration (the module's own `extern`, else the first other module's), measures `sizeof` with a probe compile, cuts
the range into objects with descending size classes (arrays of unknown bound take the room up to the next label; the
fewest fillers), writes the block, completes later empty bounds (CODE.2), compiles the module and compares the `_BSS`
publics of the object with the wanted offsets.  Only then does it write the C file, shrink or delete `b<module>.asm`
and update `link/<PROG>/order.txt`.  The build's SHA-1 comparison is the acceptance test of every step.

## Object files and extents (second round)

Rule 1 is a test for object-file boundaries: inside one object file the classes never rise with the address, so a rise
is either a label inside an object or the start of another object file, and then the address is dword-aligned (the
linker's alignment; 1-3 unnamed bytes may lie ahead of it).  Applied to the remaining ranges (a search over the labels
for the cut with the fewest views, then corrected by what is known about the records):

- The ranges hold **more object files than the code has modules**: CODE.2 0x62760-0x718e0 has eight descending runs
  (starts 0x62760, 0x62b58, 0x62bb0, 0x63020, 0x640a0, 0x64580, 0x65a30, 0x68fe0) for four modules, 0x748e4-0x75900 has
  four (0x748e4, 0x74900, 0x755d8, 0x755f8); CODE.1 0x355f8-0x37bf0 has seven (0x355f8, 0x36814, 0x3682c, 0x36838,
  0x36a54, 0x37140, 0x371dc) for two.  The references do not follow the link order either (0x68fe0 is used only by
  m13810, the first module; 0x63020 by m23f70; 0x640a0 by m2af90 / m2c0c0): much of this data was defined in other
  files than the ones that use it.  One run each is defined in the module whose range it was (m13a78, m186c4, m1c704,
  m2c0c0, m307e8; CODE.1 m10010, m150c0), the others in data-only files `d<address>.c` linked at their place (STANDIN:
  the boundary is what the rule proves; that the file had no code is an assumption, the code boundaries are unknown).
- **0x718e0-0x72238** (party records, 0x72200 and five words) is one run between m1c704 and m270ac; it is defined in
  `m1ea90.c`, the first module of that window, which names none of it.  m1eee0, m231dc, m23f70 or m26810 could own it as
  well.
- **0x755d0-0x755d6 and 0x755e8-0x755f6 are 2-byte objects**, not halves of ints: as such they close the runs that
  start at 0x74900 and 0x755d8, the ints behind them start new files, and every function matches unchanged; with
  0x755d2 / 0x755d6 as views of ints five functions changed.  Users that declare one of them `int` read two objects.
- **0x64018** is the address of element -1 of the 12-byte table at 0x64024 (the code indexes from 1); 8 bytes are
  defined there, 0x64020 is an int of its own.
- **CODE.1 0x388fc** (three words): m15880's node array is 257 x 9 = 2313 bytes (class 2), then 3 alignment bytes, then
  class 3: another object file.  FUN_00015880 uses both the array and the words, so m15880 is not two files split
  between its functions; the words are defined in `m15d90.c`, the next object file (STANDIN, ownership).
- Extents: monster table 0x64d80 = 100 x 22 and level header 0x75618 = 0x2a4 from the code; 0x68fe0 and 0x65618 are 1024
  bytes up to the next object (declared `int` by their users).  Objects written `unsigned char x[n]` in a `d*.c` file or by `--size` have the extent up to the next
  object; their element types are in the declarations of the users.

## State

| program | defined in C | still in `b*.asm` |
|---|---|---|
| CODE.1 | every object: m10010 4636, d36814 24, d3682c 11, d36838 540, d36a54 1772, m150c0 156, d371dc 2579, m15880 3337, m15d90 6, m161c0 132, m172d0 72, m17f50 24, m184d0 48, m1b060 16, m1cef0 64 | - |
| CODE.2 | m106c0 32, m13a78 1016, d62b58 88, d62bb0 1136, d63020 4224, d640a0 1246, m186c4 5296, m1c704 13743, d68fe0 35072, m1ea90 2392, m270ac 8, m29c80 12, m2af90 9880, d748e4 28, m2c0c0 3288, d755d8 32, m307e8 32, d758bc 68, m32e40 6128, and the 12 modules behind | b307e8 676 |

**Left: the level header 0x75618** (`struct LEV`, `include/world.h`; `src/CODE2/b307e8.asm`, 8 labels).  Its members
0x7561b ... 0x757a2 compile as views; the map width 0x75619 does not in FUN_0002bbd8 (m2af90.c): `xs = m[1] * width;
m[3]++; m[6] = xs + m[3];` puts `xs` in dx and the reloaded counter in ax in the original, and the other way round when
the width is a view or a `struct LEV` member.  0x75619 is at an odd address behind a 1-byte member, so it cannot be an
object of its own.  Tried without success: member / pointer / cast forms of the view, operand order, `+=`, copy chains
on either operand (one fixes this place and moves two frame slots).  Next step: a tie search for that function with the
width as `B00075618_b1.w`, then `contain CODE2 B00075618_b1 676` and `convert CODE2 m307e8` (the eight labels already
compile as views in every other user: the build with all of them was one place short of the image).

Special cases settled by this round:

- **0x72240 (m29c80).** The object of `m29c80.c` has a paragraph-aligned `_BSS` whether it is empty or not.  With 12
  bytes defined there (4 unnamed, the shorts 0x72244 / 0x72246, 4 unnamed) and the 9880-byte block at 0x7224c defined
  in `m2af90.c` (9880 is a multiple of 8: one class 6 object that the next module in link order can start with), the
  link reproduces the image.  The 12 bytes cannot be told apart from an empty contribution of m29c80 with m28d90 / m2af90
  owning them; no code of m28d90, m29c80 or m2af90 names any of these addresses.
- **0x7b6d0 (m40d80).** The find record (43 bytes) and the path buffer (81) must precede the library's `iob`; they are
  defined in `m40d80.c` as byte arrays although only m411e0 (linked after `iob`) uses them.  m40700 (12 bytes, class 5,
  directly ahead) could own them as well; the rule does not decide.
- `xib.asm` is unchanged.
