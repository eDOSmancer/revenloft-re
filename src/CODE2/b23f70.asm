; b23f70.asm - uninitialised data (_BSS) of module m23f70.c, 5232 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00062c20_jH
B00062c20_jH label byte
    db 1024 dup(?)
public B00063020_bP
B00063020_bP label byte
    db 4088 dup(?)
public B00064018_co
B00064018_co label byte
    db 8 dup(?)
public B00064020_bW
B00064020_bW label byte
    db 4 dup(?)
public B00064024_ck
B00064024_ck label byte
    db 60 dup(?)
public B00064060_aa
B00064060_aa label byte
    db 4 dup(?)
public B00064064_am
B00064064_am label byte
    db 44 dup(?)
_BSS ends
end
