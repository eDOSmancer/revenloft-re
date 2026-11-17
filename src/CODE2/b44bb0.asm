; b44bb0.asm - uninitialised data (_BSS) of module m44bb0.c, 320 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b7b0_bn
B0007b7b0_bn label byte
    db 32 dup(?)
public B0007b7d0_ko
B0007b7d0_ko label byte
    db 32 dup(?)
public B0007b7f0_dN
B0007b7f0_dN label byte
    db 128 dup(?)
public B0007b870_hl
B0007b870_hl label byte
    db 128 dup(?)
_BSS ends
end
