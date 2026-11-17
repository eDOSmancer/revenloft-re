; b3f960.asm - uninitialised data (_BSS) of module m3f960.c, 72 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_0007b67c
DAT_0007b67c label byte
    db 4 dup(?)
public DAT_0007b680
DAT_0007b680 label byte
    db 4 dup(?)
public DAT_0007b684
DAT_0007b684 label byte
    db 4 dup(?)
public DAT_0007b688
DAT_0007b688 label byte
    db 4 dup(?)
public DAT_0007b68c
DAT_0007b68c label byte
    db 8 dup(?)
public DAT_0007b694
DAT_0007b694 label byte
    db 4 dup(?)
public DAT_0007b698
DAT_0007b698 label byte
    db 12 dup(?)
public DAT_0007b6a4
DAT_0007b6a4 label byte
    db 16 dup(?)
public DAT_0007b6b4
DAT_0007b6b4 label byte
    db 8 dup(?)
public DAT_0007b6bc
DAT_0007b6bc label byte
    db 6 dup(?)
public DAT_0007b6c2
DAT_0007b6c2 label byte
    db 1 dup(?)
public DAT_0007b6c3
DAT_0007b6c3 label byte
    db 1 dup(?)
_BSS ends
end
