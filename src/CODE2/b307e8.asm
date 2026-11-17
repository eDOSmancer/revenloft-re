; b307e8.asm - uninitialised data (_BSS) of module m307e8.c, 676 bytes
; STANDIN: the level header at 0x75618 (struct LEV of include/world.h, 0x2a4 bytes) with the labels of the members that code
;   names as variables of their own.  Not defined in C because FUN_0002bbd8 (m2af90.c) compiles to the original code only
;   with the map width 0x75619 as a global of its own; as a member or view of the record the allocator swaps eax / edx at
;   one place (docs/BSS.md).  The words ahead of and behind the record are defined in m307e8.c and d758bc.c.
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
