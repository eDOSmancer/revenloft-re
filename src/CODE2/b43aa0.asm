; b43aa0.asm - uninitialised data (_BSS) of module m43aa0.c, 64 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_0007b770
DAT_0007b770 label byte
    db 50 dup(?)
public DAT_0007b7a2
DAT_0007b7a2 label byte
    db 2 dup(?)
public DAT_0007b7a4
DAT_0007b7a4 label byte
    db 2 dup(?)
public DAT_0007b7a6
DAT_0007b7a6 label byte
    db 2 dup(?)
public DAT_0007b7a8
DAT_0007b7a8 label byte
    db 4 dup(?)
public DAT_0007b7ac
DAT_0007b7ac label byte
    db 2 dup(?)
public DAT_0007b7ae
DAT_0007b7ae label byte
    db 2 dup(?)
_BSS ends
end
