; b28d90.asm - uninitialised data (_BSS) of module m28d90.c, 16 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00064090_dP
B00064090_dP label byte
    db 4 dup(?)
public B00064094_eL
B00064094_eL label byte
    db 12 dup(?)
_BSS ends
end
