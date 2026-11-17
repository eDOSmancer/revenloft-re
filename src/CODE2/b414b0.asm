; b414b0.asm - uninitialised data (_BSS) of module m414b0.c, 32 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_0007b750
DAT_0007b750 label byte
    db 20 dup(?)
public DAT_0007b764
DAT_0007b764 label byte
    db 12 dup(?)
_BSS ends
end
