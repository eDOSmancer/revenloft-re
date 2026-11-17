; b307e8.asm - uninitialised data (_BSS) of module m307e8.c, 676 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00075618_b1
B00075618_b1 label byte
    db 1 dup(?)
public B00075619_b0
B00075619_b0 label byte
    db 2 dup(?)
public B0007561b_io
B0007561b_io label byte
    db 6 dup(?)
public B00075621_lx
B00075621_lx label byte
    db 1 dup(?)
public B00075622_mo
B00075622_mo label byte
    db 128 dup(?)
public B000756a2_ah
B000756a2_ah label byte
    db 128 dup(?)
public B00075722_nn
B00075722_nn label byte
    db 128 dup(?)
public B000757a2_bK
B000757a2_bK label byte
    db 282 dup(?)
_BSS ends
end
