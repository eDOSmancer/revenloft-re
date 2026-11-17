; b1eee0.asm - uninitialised data (_BSS) of module m1eee0.c, 16 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00062c00_hH
B00062c00_hH label byte
    db 16 dup(?)
_BSS ends
end
