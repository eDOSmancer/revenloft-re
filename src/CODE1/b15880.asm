; b15880.asm - uninitialised data (_BSS) of module m15880.c, 3348 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00037bf0_eu
B00037bf0_eu label byte
    db 1024 dup(?)
public B00037ff0_eu
B00037ff0_eu label byte
    db 3 dup(?)
public B00037ff3_eu
B00037ff3_eu label byte
    db 2 dup(?)
public B00037ff5_eu
B00037ff5_eu label byte
    db 2 dup(?)
public B00037ff7_eu
B00037ff7_eu label byte
    db 2309 dup(?)
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
