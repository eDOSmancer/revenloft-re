; b1ea90.asm - uninitialised data (_BSS) of module m1ea90.c, 80 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00062bb0_hD
B00062bb0_hD label byte
    db 80 dup(?)
_BSS ends
end
