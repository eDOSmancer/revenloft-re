# Ravenloft: Strahd's Possession - CODE.1 and CODE.2 from source

This repository holds reverse-engineered source code of the two 32-bit DOS programs of *Ravenloft: Strahd's
Possession* (1994), `CODE.1` and `CODE.2`, and a build that compiles, assembles and links it with the original
Watcom tools into files that are byte-identical to the originals:

| file   | bytes  | SHA-1                                      | compiler          | linker      |
|--------|--------|--------------------------------------------|-------------------|-------------|
| CODE.1 | 277787 | `ba6b19b88c6b787ffb0ba88700b3930bdb6af35d` | Watcom C32 9.5b   | WLINK 9.5   |
| CODE.2 | 558689 | `2487bd117223ba2865447fd8545ee9755227f10a` | Watcom C32 10.0a  | WLINK 10.0a |

`make` builds both and compares the SHA-1 values with `expected.sha1`; its exit status is 0 only if both match.
The original executables are not part of the repository and the build does not read them.

## What is linked

Every byte of the two LE images comes out of the Watcom linker, from ordinary object files:

- `src/CODE1/m*.c` (20 files), `src/CODE2/m*.c` (35 files): one C file per original module, compiled by `WCC386`.
- `src/CODE1/a*.asm` (5), `src/CODE2/a*.asm` (6): the modules that were written in assembler, assembled by `WASM`.
- `src/<PROG>/xib.asm`: a stand-in, see "Stand-ins".
- the modules of the Watcom C library named in `link/<PROG>/order.txt`, copied unchanged out of the installation's
  `.LIB` files (`tools/omflib.py`; the same bytes `wlib lib *module` extracts).

`WLINK` gets all of them as `FILE` objects in the order of `link/<PROG>/order.txt`. Two steps follow the link:

1. **bind**: the placeholder stub ahead of the LE header is replaced by the DOS/4GW Professional loader ("The loader").
2. **alignment bytes**: the bytes listed in `link/<PROG>/alignfix.csv` are patched into the data object.

There is no other post-processing: code, data, uninitialised data, the stack, the LE header, the page map and the
relocation (fixup) tables including the order of their records are WLINK's output.

## Building

You need Linux (or another system with the programs below), your own copies of the original Watcom tools, and a
copy of the game for one 160 KB third-party loader. Nothing third-party is in this repository.

### 1. Host programs

- **DOSBox-X** (`dosbox-x` in `PATH`, or `DOSBOX=/path/to/dosbox-x`): runs the DOS tools headless. Developed with
  2026.10.01.
- **Python 3** (standard library only), `make`, and `timeout` (coreutils).

### 2. Setting up the tools

Put the tools into the `tools/` subfolder of the checkout, in this layout (`tools/README.md` has the full list
with checksums; `tools/watcom/` and `tools/dos4gw/` are ignored by git):

    tools/watcom/w10a/          Watcom C/C++32 10.0a:  BIN/  H/  LIB386/DOS/CLIB3S.LIB
    tools/watcom/w95b/          Watcom C/C++32 9.5b:   BIN/  H/  LIB386/DOS/CLIB3S.LIB
    tools/watcom/w95b-patch/    3CSDL.A  3CSDL.B
    tools/dos4gw/4gwpro.bin     the DOS/4GW Professional loader

- **Watcom C/C++32 10.0a** (September 1994) compiles and links `CODE.2` and assembles the assembler files of both
  programs. Files the build opens: `BIN/WCC386.EXE`, `BIN/W32RUN.EXE`, `BIN/WASM.EXE`, `BIN/WLINK.EXE`, the headers
  in `H/`, and `LIB386/DOS/CLIB3S.LIB`.
- **Watcom C/C++32 9.5 with patch levels A and B** ("9.5b") compiles and links `CODE.1`. Files the build opens:
  `BIN/WCC386.EXE` (the patched compiler, 628178 bytes), `BIN/WLINK.EXE`, the headers in `H/`, and
  `LIB386/DOS/CLIB3S.LIB`.
- **The 9.5 C library patches.** The C library of `CODE.1` is the 9.5 library with the modules of patches A and B.
  The build takes the unpatched `LIB386/DOS/CLIB3S.LIB` and the two patch files `3CSDL.A` and `3CSDL.B` from the
  patch distributions (OMF libraries holding the replacement modules); `link/CODE1/order.txt` says for each module
  which of the three it comes from (72 / 9 / 4 modules). If your `CLIB3S.LIB` already has both patches applied,
  point `3CSDL.A` and `3CSDL.B` in `build.cfg` at it.
- **The loader.** With a copy of the game at hand:

      python3 tools/getloader.py /path/to/game/CODE.2

  writes `tools/dos4gw/4gwpro.bin` and checks its SHA-1 (see "The loader" below). This is the only time an
  original executable is read; the build itself never does.

Keep the upper-case file and directory names of the original media (`BIN`, `H`, `LIB386/DOS`, `WCC386.EXE`).
To keep the tools somewhere else, edit `build.cfg` or set an environment variable of the same name:

| name        | default                              | what                                                    |
|-------------|--------------------------------------|---------------------------------------------------------|
| `WATCOM10A` | `tools/watcom/w10a`                  | root of the 10.0a installation (`BIN`, `H`, `LIB386`)   |
| `WATCOM95`  | `tools/watcom/w95b`                  | root of the 9.5b installation                           |
| `3CSDL.A`   | `tools/watcom/w95b-patch/3CSDL.A`    | DOS C library patch file of 9.5 patch level A           |
| `3CSDL.B`   | `tools/watcom/w95b-patch/3CSDL.B`    | DOS C library patch file of 9.5 patch level B           |
| `LOADER`    | `tools/dos4gw/4gwpro.bin`            | the DOS/4GW Professional loader                         |

Relative paths are relative to the repository root. The build writes only below `build/`.

### 3. Build and verify

    make            # both programs, about two minutes from scratch
    make code1      # or code2
    make clean

A successful run ends with

    ba6b19b88c6b787ffb0ba88700b3930bdb6af35d  CODE.1  277787 bytes  OK
    2487bd117223ba2865447fd8545ee9755227f10a  CODE.2  558689 bytes  OK

and exit status 0. Output: `build/CODE.1`, `build/CODE.2`; work files in `build/CODE1`, `build/CODE2` (objects,
`link/LINK.LNK`, the WLINK map `link/CODE.MAP`). To run the result, copy the two files over those of an installed
copy of the game (they are identical to the originals, so nothing changes).

## The loader

Both originals are bound with the DOS/4GW Professional 1.9x run-time: the first 162780 bytes of each file (up to the LE
header) are that loader, SHA-1 `859e06e4d799b8f92e5ce2b412d12d621466a85b`, identical in both. It is a third-party
binary that is not in a Watcom installation (the `DOS4GW.EXE` of 9.5 and 10.0a is a different program) and it is not
in this repository. Provide it as the file `LOADER` points to; `tools/getloader.py <bound executable> [output]`
cuts it out of any program bound with it (the game's own `CODE.1` / `CODE.2` are such programs) and checks the SHA-1.

The LE headers of the originals show how they were made: the page offset in the header is 0x1EB8 more than the
distance of the pages from the header, i.e. WLINK wrote the image behind a 7864-byte stub and the binder (4GWBIND)
later replaced that stub with the loader without touching the header. The build does the same: it links with
`option stub=` naming a generated 7864-byte MZ program (only its size reaches the image) and then replaces it by the
loader.

## Inputs that are not source

| file | bytes | what it is and why it cannot be derived |
|------|-------|------------------------------------------|
| `link/CODE1/order.txt`, `link/CODE2/order.txt` | 3554, 4445 | The objects in link order with their compiler / assembler options and, for library modules, the library. The order is the order of the code in the image; the original was linked from object files and libraries whose division is not recoverable, so the order is listed instead of being the result of a library search. Module options are what each original module was compiled with (found by matching). |
| `link/CODE1/options.lnk`, `link/CODE2/options.lnk` | 206, 206 | The WLINK directives: output format, `nodefaultlibs`, module name `code`, stack size (4096 / 8192). |
| `link/CODE1/alignfix.csv`, `link/CODE2/alignfix.csv` | 853, 3057 | 44 and 160 bytes (address, value) in the string constants of 5 and 19 modules. WCC386 aligns the next string literal by advancing its output position without writing, so these bytes are whatever the compiler's heap held before - in the originals, fragments of the game's own header and source text, which no longer exists. |
| stub size 0x1EB8 (`tools/build.py`) | - | see "The loader". |
| `expected.sha1` | 147 | the three SHA-1 values the build checks. |
| `build.cfg` | - | locations of the external tools. |

Nothing else is stored: there is no table of addresses, no fixup order table and no copy of original bytes.

## Stand-ins

Constructs that exist only because they reproduce the original bytes, not because the original source looked so:

- **`STANDIN` lines in the C files and headers** (570 marks in 47 files): expressions, temporaries or declarations written so
  that the compiler makes the original's register choices or data layout. Each is marked with a comment. By kind:
  389 expression forms and temporaries in function bodies (register ties, operand order, copy chains), 168 views
  (below), 12 dead reads, 1 inferred typedef (`include/farproc.h`).
- **Names of the uninitialised variables** (`B<address>_xx`, 311 names) and the `/* BSS: ... */` block at the top
  of 32 C files. WCC386 writes a module's `_BSS` by size class and symbol-table order, not in definition order; the
  names are fitted so that every one lies in the same hash chain of the compiler's symbol table, and the block defines
  the module's objects from the highest address down, which then yields the original layout. Variables no code
  references are defined there as well (17, commented). The objects have their types: the tables are arrays of the
  record types of `include/records.h` / `include/world.h` (`docs/TYPES.md`). Names of the original image that lie
  inside a larger object (members of record 0 of a table, the high word of an int) are macros (views,
  `container + offset`) in the files that still address them so; 140 such accesses to the character records were
  turned into member accesses. Rule, scheme and tool (`tools/bssfit.py`): `docs/BSS.md`.
- **No data-only files.** Inside one object file the size classes of `_BSS` only descend, so a rise at a dword
  boundary is either another object file or a label inside an object. Every rise turned out to be the second: in both
  programs each C module defines exactly one run (`docs/FILES.md` has the evidence per module boundary).
- **Dead reads** (12 places, 11 of them from the naming of the uninitialised data; marked): `{ int d; d = G; }` of a scalar the function does not use. Under `-oa` a scalar
  global is an entry in the register allocator's list; where a name of the original image turned out to lie inside
  another object (an element of a table, the high word of an int) the function lost that entry and came out with other
  registers, and the dead read puts an entry back (`docs/BSS.md`).
- **`include/farproc.h`**: a typedef of a far function pointer that no code uses, included by every C module of CODE.2
  except m3f960, m40700 and m26810. In the original every module's `_BSS` except those of m3f960 and m40700 starts on a
  paragraph boundary wherever the image can show it; WCC386 aligns `_BSS` so when the file declares a far pointer or
  `double` object or typedef, so the game's modules shared such a declaration. Which one is not known (`docs/BSS.md`).
- **`xib.asm`**: an empty paragraph-aligned `XIB` segment. In both originals the C library's initialiser table starts
  on a paragraph boundary although every library object declares it word-aligned; some object of the original link
  aligned it, the image does not say which.
- **Assembler files.** `a*.asm` are transcriptions of modules that were written in assembler (video, drawing, timer
  and unpacking routines). Three things in them serve the byte-exact build:
  - instructions written as `db` with the instruction in a comment: the original assembler chose the other of two
    equivalent encodings (for example `03 /r` instead of `01 /r` for a register-to-register `add`), which WASM cannot
    be told to emit;
  - `org` lines: WLINK writes the relocation records of a page in the order in which it meets the object records,
    and takes the relocations of one record from the highest address down. The original objects were cut into
    records by another assembler; `org $` starts a new record at the same place, `org NNNh` continues at another
    address where the original's records are not in address order. The code is therefore laid out in the original's
    record order (5 of the 11 files have out-of-order parts); labels and jumps are unaffected;
  - a few data references of the form `NAME + NNh`: the address lies inside an object that a C module defines.
  The files are assembled with `-c` (no data-in-code records, which would cut a record at every `db`).
- Symbol names carry the original address (`FUN_0001c7a0`, `DAT_00032b28`). They are names only: the linker places
  everything, and no tool reads an address from a name.

## Caveats

- **Comments in the C files refer to things that are not here.** The files were matched function by function in a
  separate analysis project, and many comments name its tools, notes and working directories (`tools/realcc.py`,
  `docs/MODULES.md`, `build/var/...`, round numbers). They are history, not instructions; nothing in this repository
  depends on them. They are left in place because the source text is part of what the byte-exact build was verified
  with (see the next point).

- **One compile is sensitive to the compiler's run-time environment.** `FUN_00026d04` in CODE.2 module `m26810.c`
  contains two stand-in copy chains whose length was fitted to the behaviour of WCC386 10.0a under DOSBox-X: the
  compiler reads a field it never initialised when it splits an oversized block, so the result depends on memory
  contents. The build runs every C compile in its own fresh DOSBox-X (32 MB, see `tools/dos.py`) and the module
  matches there; under a different DOS environment or emulator this one function may come out different, and the
  SHA-1 check will say so.
- The alignment bytes (above) are a patch, not source.
- The build is tied to the exact tool versions listed; other patch levels of compiler or library give other bytes.
- Run one build at a time (each tool run starts a DOSBox-X process). DOSBox-X also reads the user's own
  configuration file (`~/.config/dosbox-x/`); the build passes its settings with `-conf` on top of it.

## Layout

    src/CODE1, src/CODE2     C modules (m*.c), assembler modules (a*.asm), stand-in definition (xib.asm)
    include/                 shared headers of the C modules
    link/CODE1, link/CODE2   order.txt, options.lnk, alignfix.csv
    tools/README.md          where the third-party tools go (tools/watcom, tools/dos4gw: not tracked)
    tools/build.py           the build driver          tools/dos.py        DOSBox-X runner
    tools/omflib.py          OMF library reader        tools/getloader.py  loader extraction helper
    tools/bssfit.py          uninitialised data: fitted names, definitions block, checks (docs/BSS.md)
    tools/bssxref.py         which functions reference which uninitialised object (docs/BSS.md)
    docs/BSS.md              how WCC386 orders a module's _BSS and how the sources reproduce it
    docs/FILES.md            the evidence for one object file per module
    docs/TYPES.md            the typed data objects and the evidence for each type
    expected.sha1, build.cfg, Makefile

## Ownership

This is reverse-engineered source of a commercial game, reconstructed for study and preservation of how the
program works. It contains no original binary: neither the game's executables nor its data, the Watcom tools and
libraries, or the DOS/4GW loader. All of those remain the property of their respective owners, and you need your own
copies to build.
