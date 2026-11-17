; b270ac.asm - uninitialised data (_BSS) of module m270ac.c, 8 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B00072238_dL
B00072238_dL label byte
    db 2 dup(?)
public B0007223a_et
B0007223a_et label byte
    db 2 dup(?)
public B0007223c_dz
B0007223c_dz label byte
    db 2 dup(?)
public B0007223e_dx
B0007223e_dx label byte
    db 2 dup(?)
_BSS ends
end
