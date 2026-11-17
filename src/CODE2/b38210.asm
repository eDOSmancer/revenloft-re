; b38210.asm - uninitialised data (_BSS) of module m38210.c, 16 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B000770f0_a0
B000770f0_a0 label byte
    db 16 dup(?)
_BSS ends
end
