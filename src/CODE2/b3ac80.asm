; b3ac80.asm - uninitialised data (_BSS) of module m3ac80.c, 17712 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00077100_ds
B00077100_ds label byte
    db 8 dup(?)
public B00077108_dk
B00077108_dk label byte
    db 32 dup(?)
public B00077128_fk
B00077128_fk label byte
    db 32 dup(?)
public B00077148_eJ
B00077148_eJ label byte
    db 17600 dup(?)
public B0007b608_e2
B0007b608_e2 label byte
    db 20 dup(?)
public B0007b61c_dd
B0007b61c_dd label byte
    db 20 dup(?)
_BSS ends
end
