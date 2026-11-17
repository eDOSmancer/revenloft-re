; b150c0.asm - uninitialised data (_BSS) of module m150c0.c, 2680 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00037178_eu
B00037178_eu label byte
    db 24 dup(?)
public B00037190_eu
B00037190_eu label byte
    db 28 dup(?)
public B000371ac_eu
B000371ac_eu label byte
    db 28 dup(?)
public B000371c8_eu
B000371c8_eu label byte
    db 12 dup(?)
public B000371d4_eu
B000371d4_eu label byte
    db 6 dup(?)
public B000371da_eu
B000371da_eu label byte
    db 2 dup(?)
public B000371dc_eu
B000371dc_eu label byte
    db 522 dup(?)
public B000373e6_eu
B000373e6_eu label byte
    db 2 dup(?)
public B000373e8_eu
B000373e8_eu label byte
    db 2 dup(?)
public B000373ea_eu
B000373ea_eu label byte
    db 2 dup(?)
public B000373ec_eu
B000373ec_eu label byte
    db 2 dup(?)
public B000373ee_eu
B000373ee_eu label byte
    db 1 dup(?)
public B000373ef_eu
B000373ef_eu label byte
    db 2049 dup(?)
_BSS ends
end
