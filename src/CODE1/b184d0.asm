; b184d0.asm - uninitialised data (_BSS) of module m184d0.c, 48 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_000389e8
DAT_000389e8 label byte
    db 4 dup(?)
public DAT_000389ec
DAT_000389ec label byte
    db 10 dup(?)
public DAT_000389f6
DAT_000389f6 label byte
    db 34 dup(?)
_BSS ends
end
