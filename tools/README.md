# tools/

This directory holds the build scripts (tracked) and is also where you put the third-party tools the build
needs (not tracked: `tools/watcom/` and `tools/dos4gw/` are in `.gitignore`).

Expected layout after setup:

    tools/
      build.py  dos.py  omflib.py  getloader.py      build scripts (in the repository)
      bssfit.py  bssxref.py                          maintenance tools for the uninitialised data (docs/BSS.md)
      watcom/
        w10a/                                        Watcom C/C++32 10.0a
          BIN/WCC386.EXE  W32RUN.EXE  WASM.EXE  WLINK.EXE
          H/                                         the C headers (*.H, H/SYS)
          LIB386/DOS/CLIB3S.LIB
        w95b/                                        Watcom C/C++32 9.5, compiler at patch level B
          BIN/WCC386.EXE  WLINK.EXE
          H/
          LIB386/DOS/CLIB3S.LIB                      the unpatched 9.5 library
        w95b-patch/
          3CSDL.A                                    C library patch file of 9.5 patch level A
          3CSDL.B                                    C library patch file of 9.5 patch level B
      dos4gw/
        4gwpro.bin                                   the DOS/4GW Professional loader (tools/getloader.py writes it)

Only the files listed are opened by the build; a full installation tree works as well. File and directory names
are upper case, as on the original media (the build runs the tools in DOSBox-X, but reads headers and libraries
from the host file system, which is case-sensitive on Linux).

Reference checksums of the files this repository was verified with:

| file | bytes | SHA-1 |
|------|-------|-------|
| `watcom/w10a/BIN/WCC386.EXE` | 541364 | `fcfb894eacf3d9177e71904bb2b01013f1fe89ed` |
| `watcom/w10a/BIN/W32RUN.EXE` | 20300 | `495cbd29221f12e5c5fb0d67b1ba00837662d605` |
| `watcom/w10a/BIN/WASM.EXE` | 181668 | `1648dd19a84cc62e0d71bdf5c090989b9b3c627b` |
| `watcom/w10a/BIN/WLINK.EXE` | 406290 | `b10cf3cc25faa63152b2a7743fdb8b4e9ab2fc26` |
| `watcom/w10a/LIB386/DOS/CLIB3S.LIB` | | `47ff4bf2f41b1758806352990fdf3ba67a98bde1` |
| `watcom/w95b/BIN/WCC386.EXE` | 628178 | `24b0cef9c23914b0b84a54c5b2d4c5f9b1b477b4` |
| `watcom/w95b/BIN/WLINK.EXE` | 341042 | `3dc965b089db7c3bc5341483b285a3195c2b4714` |
| `watcom/w95b/LIB386/DOS/CLIB3S.LIB` | | `d68694d5c982ecbc8d8a93aaa2fdd57e17ae1543` |
| `watcom/w95b-patch/3CSDL.A` | 17408 | `286c1ccc9c9fb86787ad02fc35b865912e5e6226` |
| `watcom/w95b-patch/3CSDL.B` | 25088 | `030220d5794d57c392fd1de97c2369f8be7b9ef4` |
| `dos4gw/4gwpro.bin` | 162780 | `859e06e4d799b8f92e5ce2b412d12d621466a85b` |

A different location for any of these can be set in `build.cfg` or with an environment variable of the same name
(`WATCOM10A`, `WATCOM95`, `3CSDL.A`, `3CSDL.B`, `LOADER`).
