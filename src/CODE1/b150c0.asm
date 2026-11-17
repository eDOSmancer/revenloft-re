; b150c0.asm - uninitialised data (_BSS) of module m150c0.c, 2680 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00037178
DAT_00037178 label byte
    db 24 dup(?)
public DAT_00037190
DAT_00037190 label byte
    db 28 dup(?)
public DAT_000371ac
DAT_000371ac label byte
    db 28 dup(?)
public DAT_000371c8
DAT_000371c8 label byte
    db 12 dup(?)
public DAT_000371d4
DAT_000371d4 label byte
    db 6 dup(?)
public DAT_000371da
DAT_000371da label byte
    db 2 dup(?)
public DAT_000371dc
DAT_000371dc label byte
    db 522 dup(?)
public DAT_000373e6
DAT_000373e6 label byte
    db 2 dup(?)
public DAT_000373e8
DAT_000373e8 label byte
    db 2 dup(?)
public DAT_000373ea
DAT_000373ea label byte
    db 2 dup(?)
public DAT_000373ec
DAT_000373ec label byte
    db 2 dup(?)
public DAT_000373ee
DAT_000373ee label byte
    db 1 dup(?)
public DAT_000373ef
DAT_000373ef label byte
    db 2049 dup(?)
_BSS ends
end
