; b1cef0.asm - uninitialised data (_BSS) of module m1cef0.c, 64 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00038a28
DAT_00038a28 label byte
    db 50 dup(?)
public DAT_00038a5a
DAT_00038a5a label byte
    db 2 dup(?)
public DAT_00038a5c
DAT_00038a5c label byte
    db 2 dup(?)
public DAT_00038a5e
DAT_00038a5e label byte
    db 2 dup(?)
public DAT_00038a60
DAT_00038a60 label byte
    db 4 dup(?)
public DAT_00038a64
DAT_00038a64 label byte
    db 2 dup(?)
public DAT_00038a66
DAT_00038a66 label byte
    db 2 dup(?)
_BSS ends
end
