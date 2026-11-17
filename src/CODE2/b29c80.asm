; b29c80.asm - uninitialised data (_BSS) of module m29c80.c, 9892 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
    db 4 dup(?)
public DAT_00072244
DAT_00072244 label byte
    db 2 dup(?)
public DAT_00072246
DAT_00072246 label byte
    db 6 dup(?)
public DAT_0007224c
DAT_0007224c label byte
    db 9880 dup(?)
_BSS ends
end
