# Types of the data objects

The uninitialised objects were first defined by extent only (`unsigned char x[n]`).  This file lists the objects that
have a type now, the evidence for it, and what became of the cast views (`*(T *)((char *)&x + n)`) that addressed
their members.  The rule for every change was the build's SHA-1 comparison: a type or an access form stays only if
both programs come out unchanged.

Record types live in `include/records.h` (tables) and `include/world.h` (level header); `include/chars.h` declares
the party table.

## Typed objects

| object | type | evidence | accesses |
|---|---|---|---|
| CODE.2 0x718e0 `B000718e0_iO` | `struct PC [4]` (0x248 bytes each) | file CHARS = 0x920 bytes read / written as a block; `x + i * 0x248` everywhere; members by offset from about 30 functions (`records.h`) | 69 cast views of record 0 plus `i * 0x248` became `B000718e0_iO[i].member` (m13a78, m186c4, m1c704, m1eee0, m2af90, m32e40, m33df0), none rejected; 58 views kept (below) |
| CODE.1 0x367f8 `B000367f8_eu` | `struct PC [4]`, the same record | same file CHARS; every offset the CODE.1 code uses is a member of the CODE.2 record: +0x10 flag word, +0x13 sex, +0x14 race, +0x15 classes, +0x1a alignment, +0x1c / +0x1e hit points, +0x20 levels, +0x26 experience, +0x32 abilities, +0x40 inventory (+0x5c / +0x5e hands), +0x10b start of the run-time part (`memset` from there to the record end), +0x131 caster bits | 77 member accesses in m10010 / m15d90 (block operations included: `memset(&x[p].f32, 0, 14)`, `memset(x[p].r10b, 0, (char *)&x[p + 1] - (char *)x[p].r10b)`, `sizeof x`); 1 rejected (a level store in FUN_00013208, line 1125: the member form changes the function); 22 views kept in m10010 |
| CODE.2 0x72238 `B00072238_dL` | `struct OBJR [450]` (22 bytes each, 9900) | new extent: the labels 0x7223a, 0x7223c, 0x7223e, 0x72244, 0x72246, 0x7224c are all indexed `+ i * 0x16`; `memmove(tab + i * 0x16, tab + (i + 1) * 0x16, ...)` on delete; the level files hold `ndoor * 0x16` bytes from 0x72238 (FUN_000271fc, FUN_000281b4); 450 x 22 ends exactly at 0x748e4 where the next ints start | the six labels are views of record 0 (16 lines); no function changed |
| CODE.2 0x64d80 `B00064d80_ay` | `struct MONR [100]` | `nent` records of 0x16 bytes; members position, flags, cell, type, timer, hit points (`records.h`) | definition only; the files keep their own record types (below) |
| CODE.2 0x67618 `B00067618_e7` | `struct OBJR [300]` | `memmove(..., n * 0x16)`; 300 x 22 ends at 0x68fe0 | definition only |
| CODE.2 0x748ec `B000748ec_bk` | `struct OBJR [150]` | `memmove(..., n * 0x16)`; 150 x 22 ends at 0x755d0 | definition only |
| CODE.2 0x65a18 `B00065a18_cn` | `struct COL [256]` (7 ints) | FUN_00032894 reads +8, +0x10, +0x14 of record `win`; FUN_0003b088 walks 256 records reading +0x14 / +0x18; the renderer (a42620.asm) fills one per screen column | one type for m307e8, m3ac80, m186c4 (two local `struct W` and a cast view removed) |
| CODE.2 0x698e0 `B000698e0_b7` | `unsigned short [128 * 128]` | the map: one cell word per square, indexed `cell * 2`; 32768 bytes up to the party records | definition only: the files cut the cell word into bit-fields of their own (`struct CELL`, `struct T`) |
| CODE.2 0x68fe0 `B00068fe0_eN` | `char *[256]` | FUN_00013810 stores pointers at `off` (a multiple of 4), next to the int table 0x65618 of the same length | definition only |
| CODE.2 0x75618 `B00075618_b1` | `struct LEV` (`world.h`) | written to / read from the level files as a block of 0x2a4 bytes | members since the BSS round |
| CODE.1 0x371d4, 0x373ee | `struct MCUR` (530 bytes), `struct MSAVE` (2049) | cursor record: shape, y, x, mouse flag, 522-byte image; page byte with two 1024-byte save buffers | members since the files round |
| CODE.1 0x37ff0 `B00037ff0_eu` | `struct KD [258]` (9 bytes) | 0x388fc = node 257 + 3, the offsets of `idx`, `left`, `right` | `B00037ff0_eu[257].idx / .left / .right` instead of three views |
| 17 variables no code references | `int`, `int [3]`, `short` | the gap's size and the type of the neighbours in the run | - |

## What is kept as a cast view, and why

- **Per-function record types of the 22-byte tables.**  The files read the monster, object, door and missile tables
  through `struct` definitions of their own (`struct O`, `ENT`, `MOB`, `MS`, `FO`, ...), often several per file.  They
  agree on the frame (two 16.16 coordinates, four flag bytes, cell, type, timer, count, state word) and differ in how
  the state word and the flag bytes are cut into bit-fields - `lo : 3` in one function, `b0 : 1, st : 2` in another -
  which decides the instructions.  `struct MONR` and `struct OBJR` are the common frame; unifying the per-function
  types means re-fitting each function and was not done.  The 26 + 16 + 11 views of record 0 of these tables are
  indexed with `i * 0x16` and stay with them.
- **Party accesses with a byte offset** (58 in CODE.2, 22 in CODE.1): the function keeps `i * 0x248` in a variable
  (`off`) or adds a second scaled index, or reads a member at another signedness or width than `struct PC` declares
  (the bytes of the flag word, an `unsigned` read of an `int` timer).  The CODE.1 code indexes the abilities as seven
  pairs from +0x32 (`x[p * 0x248 + k * 2]`), which `struct PC` splits into `f32`, `ab[12]`, `f3f`.
- **The high words of the 16.16 party position** (0x755d2 / 0x755d6) and the other views listed in `docs/BSS.md`.
- **Initialised data**: the `#define` views of the Data round were not touched.

## How a conversion is tested

One candidate is one textual replacement of a cast view by a member access.  All candidates of a module are applied
and the module is rebuilt; if the program's SHA-1 no longer matches, the set is halved until the candidates that
change a function are isolated and left as they were.  For the character records nothing but one store was rejected,
in `-oa` modules as well: a cast view is no register candidate there and a member is none either, so the allocator
sees the same list.
