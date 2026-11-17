; b15880.asm - uninitialised data (_BSS) of module m15880.c, 3348 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00037bf0_eu
B00037bf0_eu label byte
    db 1024 dup(?)
public B00037ff0_eu
B00037ff0_eu label byte
    db 2316 dup(?)
public B000388fc_eu
B000388fc_eu label byte
    db 2 dup(?)
public B000388fe_eu
B000388fe_eu label byte
    db 2 dup(?)
public B00038900_eu
B00038900_eu label byte
    db 4 dup(?)
_BSS ends
end
