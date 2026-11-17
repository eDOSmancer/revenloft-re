; b184d0.asm - uninitialised data (_BSS) of module m184d0.c, 48 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B000389e8_eu
B000389e8_eu label byte
    db 4 dup(?)
public B000389ec_eu
B000389ec_eu label byte
    db 10 dup(?)
public B000389f6_eu
B000389f6_eu label byte
    db 34 dup(?)
_BSS ends
end
