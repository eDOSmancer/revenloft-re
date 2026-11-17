; b40700.asm - uninitialised data (_BSS) of module m40700.c, 12 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b6c4_dQ
B0007b6c4_dQ label byte
    db 12 dup(?)
_BSS ends
end
