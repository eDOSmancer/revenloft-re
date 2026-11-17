; b3c800.asm - uninitialised data (_BSS) of module m3c800.c, 16 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b630_hz
B0007b630_hz label byte
    db 4 dup(?)
public B0007b634_e6
B0007b634_e6 label byte
    db 4 dup(?)
public B0007b638_d2
B0007b638_d2 label byte
    db 8 dup(?)
_BSS ends
end
