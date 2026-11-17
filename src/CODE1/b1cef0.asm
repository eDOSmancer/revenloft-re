; b1cef0.asm - uninitialised data (_BSS) of module m1cef0.c, 64 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00038a28_eu
B00038a28_eu label byte
    db 50 dup(?)
public B00038a5a_eu
B00038a5a_eu label byte
    db 2 dup(?)
public B00038a5c_eu
B00038a5c_eu label byte
    db 2 dup(?)
public B00038a5e_eu
B00038a5e_eu label byte
    db 2 dup(?)
public B00038a60_eu
B00038a60_eu label byte
    db 4 dup(?)
public B00038a64_eu
B00038a64_eu label byte
    db 2 dup(?)
public B00038a66_eu
B00038a66_eu label byte
    db 2 dup(?)
_BSS ends
end
