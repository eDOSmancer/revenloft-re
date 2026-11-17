; b32e40.asm - uninitialised data (_BSS) of module m32e40.c, 6128 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00075900
DAT_00075900 label byte
    db 33 dup(?)
public DAT_00075921
DAT_00075921 label byte
    db 6095 dup(?)
_BSS ends
end
