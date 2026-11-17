; b40d80.asm - uninitialised data (_BSS) of module m40d80.c, 124 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b6d0_hn
B0007b6d0_hn label byte
    db 43 dup(?)
public B0007b6fb_iP
B0007b6fb_iP label byte
    db 81 dup(?)
_BSS ends
end
