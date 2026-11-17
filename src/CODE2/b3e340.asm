; b3e340.asm - uninitialised data (_BSS) of module m3e340.c, 60 bytes
; STANDIN: these variables were defined in the C file.  They are defined here, in address order, because wcc386
; writes the _BSS of a module in symbol-hash order and the hash depends on the (unknown) original names.
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public DAT_0007b640
DAT_0007b640 label byte
    db 4 dup(?)
public DAT_0007b644
DAT_0007b644 label byte
    db 10 dup(?)
public DAT_0007b64e
DAT_0007b64e label byte
    db 34 dup(?)
public DAT_0007b670
DAT_0007b670 label byte
    db 12 dup(?)
_BSS ends
end
