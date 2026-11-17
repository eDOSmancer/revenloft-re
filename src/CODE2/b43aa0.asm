; b43aa0.asm - uninitialised data (_BSS) of module m43aa0.c, 64 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b770_gl
B0007b770_gl label byte
    db 50 dup(?)
public B0007b7a2_c0
B0007b7a2_c0 label byte
    db 2 dup(?)
public B0007b7a4_c2
B0007b7a4_c2 label byte
    db 2 dup(?)
public B0007b7a6_c4
B0007b7a6_c4 label byte
    db 2 dup(?)
public B0007b7a8_b6
B0007b7a8_b6 label byte
    db 4 dup(?)
public B0007b7ac_kp
B0007b7ac_kp label byte
    db 2 dup(?)
public B0007b7ae_hb
B0007b7ae_hb label byte
    db 2 dup(?)
_BSS ends
end
