; b3ac80.asm - uninitialised data (_BSS) of module m3ac80.c, 17712 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00077100
DAT_00077100 label byte
    db 6 dup(?)
public DAT_00077106
DAT_00077106 label byte
    db 2 dup(?)
public DAT_00077108
DAT_00077108 label byte
    db 32 dup(?)
public DAT_00077128
DAT_00077128 label byte
    db 32 dup(?)
public DAT_00077148
DAT_00077148 label byte
    db 8 dup(?)
public DAT_00077150
DAT_00077150 label byte
    db 2 dup(?)
public DAT_00077152
DAT_00077152 label byte
    db 17590 dup(?)
public DAT_0007b608
DAT_0007b608 label byte
    db 20 dup(?)
public DAT_0007b61c
DAT_0007b61c label byte
    db 20 dup(?)
_BSS ends
end
