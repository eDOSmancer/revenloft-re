; b186c4.asm - uninitialised data (_BSS) of module m186c4.c, 16 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00062ba0_hT
B00062ba0_hT label byte
    db 4 dup(?)
public B00062ba4_hh
B00062ba4_hh label byte
    db 12 dup(?)
_BSS ends
end
