; b17f50.asm - uninitialised data (_BSS) of module m17f50.c, 24 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B000389d0_eu
B000389d0_eu label byte
    db 24 dup(?)
_BSS ends
end
