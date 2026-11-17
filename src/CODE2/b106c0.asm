; b106c0.asm - uninitialised data (_BSS) of module m106c0.c, 32 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00062740_gK
B00062740_gK label byte
    db 4 dup(?)
public B00062744_fp
B00062744_fp label byte
    db 4 dup(?)
public B00062748_f3
B00062748_f3 label byte
    db 4 dup(?)
public B0006274c_dc
B0006274c_dc label byte
    db 4 dup(?)
public B00062750_gl
B00062750_gl label byte
    db 4 dup(?)
public B00062754_gp
B00062754_gp label byte
    db 2 dup(?)
public B00062756_ff
B00062756_ff label byte
    db 10 dup(?)
_BSS ends
end
