; b13a78.asm - uninitialised data (_BSS) of module m13a78.c, 1016 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00062760_fl
B00062760_fl label byte
    db 80 dup(?)
public B000627b0_dn
B000627b0_dn label byte
    db 160 dup(?)
public B00062850_hl
B00062850_hl label byte
    db 160 dup(?)
public B000628f0_jm
B000628f0_jm label byte
    db 160 dup(?)
public B00062990_ll
B00062990_ll label byte
    db 160 dup(?)
public B00062a30_mJ
B00062a30_mJ label byte
    db 256 dup(?)
public B00062b30_k9
B00062b30_k9 label byte
    db 20 dup(?)
public B00062b44_bl
B00062b44_bl label byte
    db 20 dup(?)
_BSS ends
end
