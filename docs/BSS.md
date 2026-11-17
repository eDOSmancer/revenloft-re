# Uninitialised data (_BSS)

The original programs defined their uninitialised variables in the C files.  `wcc386` does not write a module's `_BSS`
in the order of the definitions, so the layout depends on the names, which are not known.  This file states the rule
both compilers follow, the naming scheme that reproduces the original layout with it, what `tools/bssfit.py` does, and
what is still defined in assembler stand-ins (`src/<PROG>/b*.asm`).

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
variable of its own), C cannot define that name.  It becomes a macro in the files that use it, `#define B..x
(*(T *)((char *)&B..container + n))` or a member access (`bssfit.py view`); each is marked STANDIN.  Done for 0x38919
(find record), 0x37ff3/5/7 (CODE.1 colour tree root), 0x77106, 0x77150/2 (CODE.2).  None changed the code of its users.

## tools/bssfit.py

    tools/bssfit.py classes PROG                the labels left in b*.asm with declared size / bytes to the next label
    tools/bssfit.py rename  PROG                fitted names for every label of the b*.asm files, in all sources
    tools/bssfit.py view    PROG NAME CONTAINER OFFSET
    tools/bssfit.py convert PROG MODULE [--first NAME] [--last NAME] [--at TEXT] [--trim] [--size NAME=N] [--dry]
    tools/bssfit.py check   PROG                every built module object: its _BSS publics are in address-name order

`convert` takes the labels of `b<module>.asm` (address order, sizes = distance to the next label), finds each name's
declaration (the module's own `extern`, else the first other module's), measures `sizeof` with a probe compile, cuts
the range into objects with descending size classes (arrays of unknown bound take the room up to the next label; the
fewest fillers), writes the block, completes later empty bounds (CODE.2), compiles the module and compares the `_BSS`
publics of the object with the wanted offsets.  Only then does it write the C file, shrink or delete `b<module>.asm`
and update `link/<PROG>/order.txt`.  The build's SHA-1 comparison is the acceptance test of every step.

## State

| program | defined in C | still in `b*.asm` |
|---|---|---|
| CODE.1 | m15880 3337 (+3 alignment), m161c0 132, m172d0 72, m1cef0 64, m184d0 48, m17f50 24, m1b060 16 | b10010 7040, b150c0 2680, b15880 8 |
| CODE.2 | m3ac80 17712, m2af90 9880, m32e40 6128, m44bb0 320, m40d80 124, m3f960 72, m43aa0 64, m3e340 57, m106c0 32, m414b0 32, m38210 16, m3c800 16, m29c80 12, m40700 12, m270ac 8 | b13a78 9768, b186c4 10384, b1c704 41692, b1eee0 248, b26810 2124, b2c0c0 4124 |

Why the rest is not converted: `bssfit.py classes` shows that these ranges do not descend in size class as they are
labelled, i.e. the labels are not the objects.  Two things have to be worked out per range before `convert` applies:

- **Records with named members.** Large objects (the party records at 0x718e0, the level header at 0x75618, the entity
  and object tables at 0x64d80 ..., CODE.1's tables from 0x36808 on) carry labels on their members, declared with the
  member's type.  The object needs its real extent and the member labels need views (`bssfit.py view`), also in the
  assembler files that name them (`a42620.asm` names 45 such labels: there the view is `container + offset`).
- **Ownership.** The `b*.asm` ranges were assigned by references and link order only.  Rule 1 now gives a test: inside
  one module the size class never rises with the address, so every rise is a module boundary (or a label inside an
  object), and a 1-3 byte gap before a dword boundary is linker alignment between two modules.  CODE.1 `b10010` holds
  several modules' data by this test (class 6 objects 0x355f8-0x36808, then single bytes, then a rise at 0x36810, at
  0x36814, ...); `b15880.asm` keeps three shorts at 0x388fc that follow an odd-sized object and 3 alignment bytes, so
  they belong to a later object file although only m15880's functions name them (the module is probably two source
  files).

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
