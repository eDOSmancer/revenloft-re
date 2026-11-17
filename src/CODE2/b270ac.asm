; b270ac.asm - uninitialised data (_BSS) of module m270ac.c, 8 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_00072238
DAT_00072238 label byte
    db 2 dup(?)
public DAT_0007223a
DAT_0007223a label byte
    db 2 dup(?)
public DAT_0007223c
DAT_0007223c label byte
    db 2 dup(?)
public DAT_0007223e
DAT_0007223e label byte
    db 2 dup(?)
_BSS ends
end
