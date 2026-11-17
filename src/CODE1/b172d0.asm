; b172d0.asm - uninitialised data (_BSS) of module m172d0.c, 72 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00038988
DAT_00038988 label byte
    db 4 dup(?)
public DAT_0003898c
DAT_0003898c label byte
    db 4 dup(?)
public DAT_00038990
DAT_00038990 label byte
    db 4 dup(?)
public DAT_00038994
DAT_00038994 label byte
    db 8 dup(?)
public DAT_0003899c
DAT_0003899c label byte
    db 8 dup(?)
public DAT_000389a4
DAT_000389a4 label byte
    db 16 dup(?)
public DAT_000389b4
DAT_000389b4 label byte
    db 4 dup(?)
public DAT_000389b8
DAT_000389b8 label byte
    db 12 dup(?)
public DAT_000389c4
DAT_000389c4 label byte
    db 4 dup(?)
public DAT_000389c8
DAT_000389c8 label byte
    db 6 dup(?)
public DAT_000389ce
DAT_000389ce label byte
    db 1 dup(?)
public DAT_000389cf
DAT_000389cf label byte
    db 1 dup(?)
_BSS ends
end
