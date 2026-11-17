; b3c800.asm - uninitialised data (_BSS) of module m3c800.c, 16 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_0007b630
DAT_0007b630 label byte
    db 4 dup(?)
public DAT_0007b634
DAT_0007b634 label byte
    db 4 dup(?)
public DAT_0007b638
DAT_0007b638 label byte
    db 8 dup(?)
_BSS ends
end
