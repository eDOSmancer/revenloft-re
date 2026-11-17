; b3f960.asm - uninitialised data (_BSS) of module m3f960.c, 72 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b67c_at
B0007b67c_at label byte
    db 4 dup(?)
public B0007b680_az
B0007b680_az label byte
    db 4 dup(?)
public B0007b684_aF
B0007b684_aF label byte
    db 4 dup(?)
public B0007b688_ar
B0007b688_ar label byte
    db 4 dup(?)
public B0007b68c_a5
B0007b68c_a5 label byte
    db 8 dup(?)
public B0007b694_aV
B0007b694_aV label byte
    db 4 dup(?)
public B0007b698_aB
B0007b698_aB label byte
    db 12 dup(?)
public B0007b6a4_d1
B0007b6a4_d1 label byte
    db 16 dup(?)
public B0007b6b4_da
B0007b6b4_da label byte
    db 8 dup(?)
public B0007b6bc_d2
B0007b6bc_d2 label byte
    db 6 dup(?)
public B0007b6c2_dS
B0007b6c2_dS label byte
    db 1 dup(?)
public B0007b6c3_dR
B0007b6c3_dR label byte
    db 1 dup(?)
_BSS ends
end
