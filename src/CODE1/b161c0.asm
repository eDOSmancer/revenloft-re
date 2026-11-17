; b161c0.asm - uninitialised data (_BSS) of module m161c0.c, 132 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00038904_eu
B00038904_eu label byte
    db 43 dup(?)
public B0003892f_eu
B0003892f_eu label byte
    db 89 dup(?)
_BSS ends
end
