; b172d0.asm - uninitialised data (_BSS) of module m172d0.c, 72 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00038988_eu
B00038988_eu label byte
    db 4 dup(?)
public B0003898c_eu
B0003898c_eu label byte
    db 4 dup(?)
public B00038990_eu
B00038990_eu label byte
    db 4 dup(?)
public B00038994_eu
B00038994_eu label byte
    db 8 dup(?)
public B0003899c_eu
B0003899c_eu label byte
    db 8 dup(?)
public B000389a4_eu
B000389a4_eu label byte
    db 16 dup(?)
public B000389b4_eu
B000389b4_eu label byte
    db 4 dup(?)
public B000389b8_eu
B000389b8_eu label byte
    db 12 dup(?)
public B000389c4_eu
B000389c4_eu label byte
    db 4 dup(?)
public B000389c8_eu
B000389c8_eu label byte
    db 6 dup(?)
public B000389ce_eu
B000389ce_eu label byte
    db 1 dup(?)
public B000389cf_eu
B000389cf_eu label byte
    db 1 dup(?)
_BSS ends
end
