; b29c80.asm - uninitialised data (_BSS) of module m29c80.c, 16 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B000640a0_hC
B000640a0_hC label byte
    db 16 dup(?)
_BSS ends
end
