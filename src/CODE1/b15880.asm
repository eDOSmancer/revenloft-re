; b15880.asm - uninitialised data (_BSS) of module m15880.c, 3348 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00037bf0
DAT_00037bf0 label byte
    db 1024 dup(?)
public DAT_00037ff0
DAT_00037ff0 label byte
    db 3 dup(?)
public DAT_00037ff3
DAT_00037ff3 label byte
    db 2 dup(?)
public DAT_00037ff5
DAT_00037ff5 label byte
    db 2 dup(?)
public DAT_00037ff7
DAT_00037ff7 label byte
    db 2309 dup(?)
public DAT_000388fc
DAT_000388fc label byte
    db 2 dup(?)
public DAT_000388fe
DAT_000388fe label byte
    db 2 dup(?)
public DAT_00038900
DAT_00038900 label byte
    db 4 dup(?)
_BSS ends
end
