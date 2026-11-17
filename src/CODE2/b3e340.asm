; b3e340.asm - uninitialised data (_BSS) of module m3e340.c, 60 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B0007b640_gk
B0007b640_gk label byte
    db 4 dup(?)
public B0007b644_dg
B0007b644_dg label byte
    db 10 dup(?)
public B0007b64e_bV
B0007b64e_bV label byte
    db 34 dup(?)
public B0007b670_fk
B0007b670_fk label byte
    db 12 dup(?)
_BSS ends
end
