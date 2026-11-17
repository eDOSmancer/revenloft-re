; b106c0.asm - uninitialised data (_BSS) of module m106c0.c, 32 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00062740
DAT_00062740 label byte
    db 4 dup(?)
public DAT_00062744
DAT_00062744 label byte
    db 4 dup(?)
public DAT_00062748
DAT_00062748 label byte
    db 4 dup(?)
public DAT_0006274c
DAT_0006274c label byte
    db 4 dup(?)
public DAT_00062750
DAT_00062750 label byte
    db 4 dup(?)
public DAT_00062754
DAT_00062754 label byte
    db 2 dup(?)
public DAT_00062756
DAT_00062756 label byte
    db 10 dup(?)
_BSS ends
end
