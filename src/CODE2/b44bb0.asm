; b44bb0.asm - uninitialised data (_BSS) of module m44bb0.c, 320 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_0007b7b0
DAT_0007b7b0 label byte
    db 32 dup(?)
public DAT_0007b7d0
DAT_0007b7d0 label byte
    db 32 dup(?)
public DAT_0007b7f0
DAT_0007b7f0 label byte
    db 128 dup(?)
public DAT_0007b870
DAT_0007b870 label byte
    db 128 dup(?)
_BSS ends
end
