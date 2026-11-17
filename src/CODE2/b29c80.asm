; b29c80.asm - uninitialised data (_BSS) of module m29c80.c, 9892 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
    db 4 dup(?)
public B00072244_c8
B00072244_c8 label byte
    db 2 dup(?)
public B00072246_dJ
B00072246_dJ label byte
    db 6 dup(?)
public B0007224c_ez
B0007224c_ez label byte
    db 9880 dup(?)
_BSS ends
end
