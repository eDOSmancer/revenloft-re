; b186c4.asm - uninitialised data (_BSS) of module m186c4.c, 10384 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
    db 3 dup(?)
public DAT_00064d8b
DAT_00064d8b label byte
    db 1 dup(?)
public DAT_00064d8c
DAT_00064d8c label byte
    db 2 dup(?)
public DAT_00064d8e
DAT_00064d8e label byte
    db 4 dup(?)
public DAT_00064d92
DAT_00064d92 label byte
    db 2 dup(?)
public DAT_00064d94
DAT_00064d94 label byte
    db 2180 dup(?)
public DAT_00065618
DAT_00065618 label byte
    db 1024 dup(?)
public DAT_00065a18
DAT_00065a18 label byte
    db 4 dup(?)
public DAT_00065a1c
DAT_00065a1c label byte
    db 4 dup(?)
public DAT_00065a20
DAT_00065a20 label byte
    db 4 dup(?)
public DAT_00065a24
DAT_00065a24 label byte
    db 4 dup(?)
public DAT_00065a28
DAT_00065a28 label byte
    db 4 dup(?)
public DAT_00065a2c
DAT_00065a2c label byte
    db 4 dup(?)
public DAT_00065a30
DAT_00065a30 label byte
    db 7144 dup(?)
_BSS ends
end
