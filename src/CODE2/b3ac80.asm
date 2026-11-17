; b3ac80.asm - uninitialised data (_BSS) of module m3ac80.c, 17712 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00077100_ds
B00077100_ds label byte
    db 6 dup(?)
public B00077106_dq
B00077106_dq label byte
    db 2 dup(?)
public B00077108_dk
B00077108_dk label byte
    db 32 dup(?)
public B00077128_fk
B00077128_fk label byte
    db 32 dup(?)
public B00077148_eJ
B00077148_eJ label byte
    db 8 dup(?)
public B00077150_dR
B00077150_dR label byte
    db 2 dup(?)
public B00077152_el
B00077152_el label byte
    db 17590 dup(?)
public B0007b608_e2
B0007b608_e2 label byte
    db 20 dup(?)
public B0007b61c_dd
B0007b61c_dd label byte
    db 20 dup(?)
_BSS ends
end
