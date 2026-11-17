; b10010.asm - uninitialised data (_BSS) of module m10010.c, 4636 bytes
; STANDIN: part of the module's uninitialised data that is not defined in the C file (see docs/BSS.md).
.386p
DGROUP group _BSS
_BSS segment dword public use32 'BSS'
public B000355f8_eu
B000355f8_eu label byte
    db 1024 dup(?)
public B000359f8_eu
B000359f8_eu label byte
    db 8 dup(?)
public B00035a00_eu
B00035a00_eu label byte
    db 248 dup(?)
public B00035af8_eu
B00035af8_eu label byte
    db 1280 dup(?)
public B00035ff8_eu
B00035ff8_eu label byte
    db 1024 dup(?)
public B000363f8_eu
B000363f8_eu label byte
    db 256 dup(?)
public B000364f8_eu
B000364f8_eu label byte
    db 768 dup(?)
public B000367f8_eu
B000367f8_eu label byte
    db 16 dup(?)
public B00036808_eu
B00036808_eu label byte
    db 1 dup(?)
public B00036809_eu
B00036809_eu label byte
    db 1 dup(?)
public B0003680a_eu
B0003680a_eu label byte
    db 1 dup(?)
public B0003680b_eu
B0003680b_eu label byte
    db 1 dup(?)
public B0003680c_eu
B0003680c_eu label byte
    db 1 dup(?)
public B0003680d_eu
B0003680d_eu label byte
    db 1 dup(?)
public B0003680e_eu
B0003680e_eu label byte
    db 1 dup(?)
public B0003680f_eu
B0003680f_eu label byte
    db 1 dup(?)
public B00036810_eu
B00036810_eu label byte
    db 2 dup(?)
public B00036812_eu
B00036812_eu label byte
    db 1 dup(?)
public B00036813_eu
B00036813_eu label byte
    db 1 dup(?)
_BSS ends
end
