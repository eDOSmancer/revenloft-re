; a43de0.asm - assembler module of CODE.2 (3533 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn DAT_0005c040:byte
extrn DAT_0005c044:byte
extrn DAT_0005c048:byte
extrn DAT_0005c658:byte
extrn DAT_0005c65c:byte
extrn DAT_000693e0:byte
extrn DAT_00069660:byte
_DATA segment dword public use32 'DATA'
DAT_0005fd20 label byte
    db 000h, 000h, 000h, 000h    ; 0005fd20  ....
DAT_0005fd24 label byte
    db 000h, 000h, 000h, 000h    ; 0005fd24  ....
DAT_0005fd28 label byte
    db 000h, 000h, 000h, 000h    ; 0005fd28  ....
DAT_0005fd2c label byte
    db 000h, 000h, 000h, 000h    ; 0005fd2c  ....
DAT_0005fd30 label byte
    db 124 dup(0)    ; 0005fd30
DAT_0005fdac label byte
    db 020h, 001h, 000h, 000h    ; 0005fdac   ...
DAT_0005fdb0 label byte
    db 020h, 000h, 000h, 000h    ; 0005fdb0   ...
public DAT_0005fdb4
DAT_0005fdb4 label byte
    db 004h, 001h, 000h, 000h    ; 0005fdb4  ....
public DAT_0005fdb8
DAT_0005fdb8 label byte
    db 004h, 000h, 000h, 000h    ; 0005fdb8  ....
public DAT_0005fdbc
DAT_0005fdbc label byte
    db 000h, 000h, 000h, 000h    ; 0005fdbc  ....
public DAT_0005fdc0
DAT_0005fdc0 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdc0  ....
DAT_0005fdc4 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdc4  ....
DAT_0005fdc8 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdc8  ....
DAT_0005fdcc label byte
    db 000h, 000h, 000h, 000h    ; 0005fdcc  ....
DAT_0005fdd0 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdd0  ....
DAT_0005fdd4 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdd4  ....
DAT_0005fdd8 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdd8  ....
DAT_0005fddc label byte
    db 000h, 000h, 000h, 000h    ; 0005fddc  ....
DAT_0005fde0 label byte
    db 000h, 000h    ; 0005fde0  ..
DAT_0005fde2 label byte
    db 000h, 000h    ; 0005fde2  ..
DAT_0005fde4 label byte
    db 000h, 000h, 000h, 000h    ; 0005fde4  ....
DAT_0005fde8 label byte
    db 000h, 000h, 000h, 000h    ; 0005fde8  ....
DAT_0005fdec label byte
    db 000h, 000h, 000h, 000h    ; 0005fdec  ....
DAT_0005fdf0 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdf0  ....
DAT_0005fdf4 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdf4  ....
DAT_0005fdf8 label byte
    db 000h, 000h, 000h, 000h    ; 0005fdf8  ....
DAT_0005fdfc label byte
    db 000h, 000h, 000h, 000h    ; 0005fdfc  ....
DAT_0005fe00 label byte
    db 000h, 000h, 000h, 000h    ; 0005fe00  ....
DAT_0005fe04 label byte
    db 000h, 000h    ; 0005fe04  ..
DAT_0005fe06 label byte
    db 000h, 000h    ; 0005fe06  ..
DAT_0005fe08 label byte
    db 000h, 000h, 000h, 000h    ; 0005fe08  ....
DAT_0005fe0c label byte
    db 000h, 000h, 000h, 000h    ; 0005fe0c  ....
DAT_0005fe10 label byte
    db 0, 0, 0, 0
public DAT_0005fe14
DAT_0005fe14 label byte
    db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h    ; 0005fe20  ................
    db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h    ; 0005fe30  ................
    db 002h, 002h, 002h, 002h, 002h, 003h, 003h, 003h, 003h, 003h, 003h, 003h, 003h, 004h
public DAT_0005fe4e
DAT_0005fe4e label byte
    db 004h, 004h
    db 004h, 004h, 004h, 004h, 004h, 004h, 004h, 005h, 005h, 005h, 005h, 005h, 005h, 005h, 006h, 006h    ; 0005fe50  ................
    db 006h, 006h, 006h, 006h, 006h, 007h, 007h, 007h, 007h, 007h, 007h, 007h, 008h, 008h, 008h, 008h    ; 0005fe60  ................
    db 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h    ; 0005fe70  ................
    db 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h    ; 0005fe80  ................
    db 008h, 008h, 008h, 008h    ; 0005fe90  ....
public DAT_0005fe94
DAT_0005fe94 label byte
    db 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h    ; 0005fe94  ................
    db 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h    ; 0005fea4  ................
    db 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 007h, 007h, 007h, 007h, 007h, 007h, 007h, 006h    ; 0005feb4  ................
    db 006h, 006h, 006h, 006h, 006h, 006h, 005h, 005h, 005h, 005h, 005h, 005h, 005h, 004h, 004h, 004h    ; 0005fec4  ................
    db 004h, 004h, 004h, 004h, 004h, 004h, 004h, 003h, 003h, 003h, 003h, 003h, 003h, 003h, 003h, 002h    ; 0005fed4  ................
    db 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 001h, 001h, 001h    ; 0005fee4  ................
    db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h    ; 0005fef4  ................
    db 001h, 001h, 001h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 0005ff04  ................
DAT_0005ff14 label byte
    db 000h, 000h, 000h, 000h    ; 0005ff14  ....
DAT_0005ff18 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 03fh, 000h, 000h, 000h, 03fh, 000h, 000h, 000h    ; 0005ff18  ........?...?...
    db 03fh, 000h, 000h, 000h, 03fh    ; 0005ff28  ?...?
    db 19 dup(0)    ; 0005ff2d
DAT_0005ff40 label byte
    db 000h, 000h, 000h, 000h    ; 0005ff40  ....
public DAT_0005ff44
DAT_0005ff44 label byte
    db 000h, 000h, 000h, 000h    ; 0005ff44  ....
public DAT_0005ff48
DAT_0005ff48 label byte
    db 000h, 000h, 000h, 000h    ; 0005ff48  ....
public DAT_0005ff4c
DAT_0005ff4c label byte
    db 000h, 000h, 000h, 000h    ; 0005ff4c  ....
public DAT_0005ff50
DAT_0005ff50 label byte
    db 000h, 000h, 000h, 000h    ; 0005ff50  ....
DAT_0005ff54 label byte
    db 000h, 000h, 000h, 000h    ; 0005ff54  ....
DAT_0005ff58 label byte
    db 768 dup(0)    ; 0005ff58
DAT_00060258 label byte
    db 000h, 000h, 000h, 000h    ; 00060258  ....
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_00043de0
public FUN_00043e28
public FUN_00043e6c
public FUN_00044998
public FUN_00044a74
; ---- FUN_00043de0
FUN_00043de0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov edi, dword ptr [DAT_0005fdbc]
    add edi, 0x50f8
    mov ebx, 0x80
    mov ah, byte ptr [ebp + 8]
L_00043e07:
    db 08ah, 0c4h    ; mov al, ah (WASM encodes it differently)
    sub al, byte ptr [ebx + DAT_0005fe94]
    org $
    mov ecx, 0x40
    rep stosb
    sub edi, 0x90
    dec ebx
    jne short L_00043e07
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00043e28
FUN_00043e28:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov edi, dword ptr [DAT_0005fdbc]
    add edi, 0x148
    mov ebx, 0x80
    mov ah, byte ptr [ebp + 8]
L_00043e4f:
    db 08ah, 0c4h    ; mov al, ah (WASM encodes it differently)
    sub al, byte ptr [ebx + DAT_0005fe94]
    mov ecx, 0x40
    rep stosb
    add edi, 0x10
    dec ebx
    jne short L_00043e4f
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_00043e6c
FUN_00043e6c:
    enter 0x10, 0
    pushad
    mov dword ptr [ebp - 4], 0x7fffffff
    mov dword ptr [ebp - 8], 0x80000001
    mov dword ptr [ebp - 0xc], 0x7fffffff
    mov dword ptr [ebp - 0x10], 0x80000001
    mov esi, dword ptr [ebp + 8]
    mov edi, offset DAT_0005fd2c
    mov ecx, 8
    rep movsd
    mov ecx, 4
    mov esi, 0
    mov ebx, 0
L_00043eab:
    mov eax, dword ptr [ebx + DAT_0005fd30]
    cmp eax, dword ptr [ebp - 4]
    jge short L_00043ebf
    mov dword ptr [ebp - 4], eax
    mov dword ptr [DAT_0005fd28], esi
L_00043ebf:
    cmp eax, dword ptr [ebp - 8]
    jle short L_00043ecd
    mov dword ptr [ebp - 8], eax
    mov dword ptr [DAT_0005fd24], esi
L_00043ecd:
    mov eax, dword ptr [ebx + DAT_0005fd2c]
    cmp eax, dword ptr [ebp - 0xc]
    jge short L_00043edb
    mov dword ptr [ebp - 0xc], eax
L_00043edb:
    cmp eax, dword ptr [ebp - 0x10]
    jle short L_00043ee3
    mov dword ptr [ebp - 0x10], eax
L_00043ee3:
    inc esi
    add ebx, 8
    dec ecx
    jne short L_00043eab
    mov eax, dword ptr [ebp - 0x10]
    cmp eax, dword ptr [DAT_0005fdb8]
    jle near ptr L_00043faf
    mov eax, dword ptr [ebp - 0xc]
    cmp eax, dword ptr [DAT_0005fdb4]
    jge near ptr L_00043faf
    mov eax, dword ptr [ebp - 8]
    cmp eax, dword ptr [DAT_0005fdb0]
    jle near ptr L_00043faf
    mov eax, dword ptr [ebp - 4]
    cmp eax, dword ptr [DAT_0005fdac]
    jge near ptr L_00043faf
    cmp eax, dword ptr [ebp - 8]
    jge near ptr L_00043faf
    mov dword ptr [DAT_0005fd20], eax
    mov edi, offset DAT_0005fdc4
    mov dword ptr [DAT_0005fdc4], 1
    mov esi, dword ptr [DAT_0005fd28]
    call L_0004402c
    mov edi, offset DAT_0005fde8
    mov dword ptr [DAT_0005fde8], 3
    mov esi, dword ptr [DAT_0005fd28]
    call L_0004402c
    mov ecx, dword ptr [DAT_0005fdb0]
    cmp ecx, dword ptr [DAT_0005fd20]
    jle short L_00043f8c
    sub ecx, dword ptr [DAT_0005fd20]
L_00043f7c:
    push ecx
    call L_00043fb4
    inc dword ptr [DAT_0005fd20]
    pop ecx
    dec ecx
    jne short L_00043f7c
L_00043f8c:
    mov ecx, dword ptr [DAT_0005fdac]
    sub ecx, dword ptr [DAT_0005fd20]
L_00043f98:
    push ecx
    call L_00044110
    call L_00043fb4
    pop ecx
    jae short L_00043faf
    inc dword ptr [DAT_0005fd20]
    org $
    dec ecx
    jne short L_00043f98
L_00043faf:
    popad
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00043fb4
L_00043fb4:
    dec dword ptr [DAT_0005fdc8]
    jne short L_00043fcf
    mov esi, dword ptr [DAT_0005fdcc]
    mov edi, offset DAT_0005fdc4
    call L_0004402c
    jb short L_00043ff0
    ret
L_00043fcf:
    mov eax, dword ptr [DAT_0005fdd8]
    add dword ptr [DAT_0005fdd0], eax
    mov eax, dword ptr [DAT_0005fddc]
    add dword ptr [DAT_0005fdd4], eax
    mov eax, dword ptr [DAT_0005fde4]
    add dword ptr [DAT_0005fde0], eax
L_00043ff0:
    dec dword ptr [DAT_0005fdec]
    jne short L_00044009
    mov esi, dword ptr [DAT_0005fdf0]
    mov edi, offset DAT_0005fde8
    call L_0004402c
    ret
L_00044009:
    mov eax, dword ptr [DAT_0005fdfc]
    add dword ptr [DAT_0005fdf4], eax
    mov eax, dword ptr [DAT_0005fe00]
    add dword ptr [DAT_0005fdf8], eax
    mov eax, dword ptr [DAT_0005fe08]
    add dword ptr [DAT_0005fe04], eax
    stc
    ret
; ---- FUN_0004402c
L_0004402c:
    enter 0xc, 0
    mov dword ptr [ebp - 4], esi
L_00044033:
    mov esi, dword ptr [ebp - 4]
    cmp esi, dword ptr [DAT_0005fd24]
    jne short L_00044041
    clc
    leave
    ret
L_00044041:
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    add ebx, dword ptr [edi]
    and ebx, 3
    mov dword ptr [ebp - 8], ebx
    shl ebx, 3
    shl esi, 3
    mov eax, dword ptr [ebx + DAT_0005fd30]
    sub eax, dword ptr [esi + DAT_0005fd30]
    mov dword ptr [edi + 4], eax
    cmp eax, 0
    jne short L_0004406d
    mov eax, dword ptr [ebp - 8]
    mov dword ptr [ebp - 4], eax
    jmp short L_00044033
L_0004406d:
    shl eax, 0x10
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp - 8]
    mov dword ptr [edi + 8], eax
    mov eax, dword ptr [esi + DAT_0005ff18]
    shl eax, 0x10
    mov dword ptr [edi + 0xc], eax
    mov eax, dword ptr [esi + DAT_0005ff14]
    shl eax, 0x10
    mov dword ptr [edi + 0x10], eax
    mov eax, dword ptr [ebx + DAT_0005ff18]
    shl eax, 0x10
    sub eax, dword ptr [edi + 0xc]
    mov edx, 0
    rol eax, 0x10
    cwd
    rol edx, 0x10
    xchg dx, ax
    idiv ecx
    mov dword ptr [edi + 0x14], eax
    mov eax, dword ptr [ebx + DAT_0005ff14]
    shl eax, 0x10
    sub eax, dword ptr [edi + 0x10]
    mov edx, 0
    rol eax, 0x10
    cwd
    rol edx, 0x10
    xchg dx, ax
    idiv ecx
    mov dword ptr [edi + 0x18], eax
    mov eax, dword ptr [esi + DAT_0005fd2c]
    shl eax, 0x10
    mov dword ptr [edi + 0x1c], eax
    mov eax, dword ptr [ebx + DAT_0005fd2c]
    sub eax, dword ptr [esi + DAT_0005fd2c]
    org $
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mov ebx, dword ptr [edi + 4]
    shl ebx, 0x10
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    shl eax, 0x10
    mov edx, 0
    rol eax, 0x10
    cwd
    rol edx, 0x10
    xchg dx, ax
    idiv ebx
    mov dword ptr [edi + 0x20], eax
    stc
    leave
    ret
L_0004410c:
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00044110
L_00044110:
    enter 8, 0
    movsx ebx, word ptr [DAT_0005fde2]
    cmp ebx, dword ptr [DAT_0005fdb4]
    jge short L_0004410c
    mov dword ptr [ebp - 4], ebx
    movsx eax, word ptr [DAT_0005fe06]
    cmp eax, dword ptr [DAT_0005fdb8]
    jle short L_0004410c
    mov dword ptr [ebp - 8], eax
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    inc eax
    cmp eax, 0
    je short L_0004410c
    shl eax, 0x10
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov eax, dword ptr [DAT_0005fdf4]
    sub eax, dword ptr [DAT_0005fdd0]
    rol eax, 0x10
    cwd
    shl edx, 0x10
    xchg dx, ax
    idiv ebx
    mov dword ptr [DAT_0005fe0c], eax
    sar eax, 1
    add eax, dword ptr [DAT_0005fdd0]
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    mov eax, dword ptr [DAT_0005fdf8]
    sub eax, dword ptr [DAT_0005fdd4]
    rol eax, 0x10
    cwd
    shl edx, 0x10
    xchg dx, ax
    idiv ebx
    mov dword ptr [DAT_0005fe10], eax
    sar eax, 1
    add eax, dword ptr [DAT_0005fdd4]
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [DAT_0005fdb4]
    cmp dword ptr [ebp - 8], eax
    jle short L_0004419e
    mov dword ptr [ebp - 8], eax
L_0004419e:
    mov eax, dword ptr [ebp - 4]
    cmp eax, dword ptr [DAT_0005fdb8]
    jge short L_000441dc
    mov eax, 0
    mov eax, dword ptr [DAT_0005fdb8]
    sub eax, dword ptr [ebp - 4]
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov eax, dword ptr [DAT_0005fe0c]
    mov edx, 0
    imul ebx
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    mov eax, dword ptr [DAT_0005fe10]
    mov edx, 0
    imul ebx
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov eax, dword ptr [DAT_0005fdb8]
    mov dword ptr [ebp - 4], eax
L_000441dc:
    db 08bh, 0d6h    ; mov edx, esi (WASM encodes it differently)
    shl edi, 6
    shl dword ptr [DAT_0005fe10], 6
    db 08bh, 0f7h    ; mov esi, edi (WASM encodes it differently)
    and esi, 0xffc00000
    db 003h, 0f2h    ; add esi, edx (WASM encodes it differently)
    sar esi, 0x10
    add esi, dword ptr [DAT_0005fdc0]
    push edx
    db 06bh, 045h, 0fch, 050h    ; imul eax, dword ptr [ebp - 4], 0x50 (WASM encodes it differently)
    mov ebx, dword ptr [DAT_0005fd20]
    shr ebx, 2
    db 003h, 0d8h    ; add ebx, eax (WASM encodes it differently)
    add ebx, dword ptr [DAT_0005fdbc]
    mov edx, 0x3c4
    mov eax, 0x102
    mov ecx, dword ptr [DAT_0005fd20]
    and ecx, 3
    shl ah, cl
    out dx, ax
    pop edx
    mov ecx, dword ptr [ebp - 8]
    sub ecx, dword ptr [ebp - 4]
    inc ecx
    push ebp
    mov ebp, dword ptr [ebp - 4]
L_00044234:
    mov al, byte ptr [esi]
    sub al, byte ptr ds:[ebp + DAT_0005fe10]
    inc ebp
    mov byte ptr [ebx], al
    add edx, dword ptr [DAT_0005fe0c]
    add edi, dword ptr [DAT_0005fe10]
    db 08bh, 0f7h    ; mov esi, edi (WASM encodes it differently)
    and esi, 0xffc00000
    db 003h, 0f2h    ; add esi, edx (WASM encodes it differently)
    sar esi, 0x10
    add esi, dword ptr [DAT_0005fdc0]
    org $
    add ebx, 0x50
    dec ecx
    jne short L_00044234
    pop ebp
    leave
    ret
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
; ---- FUN_00044270
L_00044270:
    sub eax, 0x10e
; ---- FUN_00044275
L_00044275:
    test eax, 0x80000000
    jns short L_00044283
    add eax, 0x168
    jmp short L_00044275
L_00044283:
    cmp eax, 0x168
    jl short L_0004428f
    sub eax, 0x168
L_0004428f:
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    db 02bh, 0d2h    ; sub edx, edx (WASM encodes it differently)
    cmp eax, 0x10e
    jl short L_000442a9
    mov edx, 3
    sub edi, 0x168
    neg edi
    jmp short L_000442cf
L_000442a9:
    cmp eax, 0xb4
    jl short L_000442bd
    mov edx, 2
    sub edi, 0xb4
    jmp short L_000442cf
L_000442bd:
    cmp eax, 0x5a
    jl short L_000442cf
    mov edx, 1
    sub edi, 0xb4
    neg edi
L_000442cf:
    movzx eax, word ptr [ebx + edi*4]
    inc eax
    shr eax, 2
    test edx, 2
    je short L_000442e1
    neg eax
L_000442e1:
    ret
    xchg ebx, ebx
; ---- FUN_000442e4
L_000442e4:
    pop dword ptr [DAT_00060258]
    mov edi, dword ptr [DAT_0005ff40]
    mov dx, 0x3c4
    mov ax, 0x802
    out dx, ax
    pop edx
    pop eax
    shl ebp, 2
    shl ebx, 2
    call L_00044350
    mov edi, dword ptr [DAT_0005ff40]
    mov dx, 0x3c4
    mov ax, 0x402
    out dx, ax
    pop edx
    pop eax
    call L_00044350
    mov edi, dword ptr [DAT_0005ff40]
    mov dx, 0x3c4
    mov ax, 0x202
    out dx, ax
    pop edx
    pop eax
    call L_00044350
    mov edi, dword ptr [DAT_0005ff40]
    mov dx, 0x3c4
    mov ax, 0x102
    out dx, ax
    pop edx
    pop eax
    push dword ptr [DAT_00060258]
    org $
    xchg ebx, ebx
    nop
; ---- FUN_00044350
L_00044350:
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    org $
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    shld esi, edx, 6
    shld esi, eax, 6
    add esi, dword ptr [DAT_0005ff54]
    org $
    lodsb
    db 02ah, 0c4h    ; sub al, ah (WASM encodes it differently)
    stosb
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00044954
L_00044954:
    pop dword ptr [DAT_00060258]
    mov edi, dword ptr [DAT_0005ff40]
    mov dx, 0x3c4
    mov ax, 0xc02
    out dx, ax
    pop edx
    pop eax
    shl ebp, 2
    shl ebx, 2
    call L_00044350
    mov edi, dword ptr [DAT_0005ff40]
    mov dx, 0x3c4
    mov ax, 0x302
    out dx, ax
    pop edx
    pop eax
    call L_00044350
    push dword ptr [DAT_00060258]
    org 0d5fh
    dec ecx
    jne short L_00044ae5
    mov byte ptr [L_00044b77], al
    mov ecx, dword ptr [DAT_0005ff50]
    sub ecx, 0x50
    cmp ecx, 0
    jle short L_00044baa
L_00044b55:
    push ecx
    push edi
    push esi
    mov bp, word ptr [esi]
    mov bx, word ptr [esi + 2]
    mov al, byte ptr [esi + 4]
    mov dl, byte ptr [esi + 5]
    db 004h
L_00044b66:
    db 0dfh
    db 080h, 0c2h
L_00044b69:
    db 0dfh
    shl eax, 0x18
    shl edx, 0x18
    shl ebp, 0x10
    shl ebx, 0x10
    db 0b4h
L_00044b77:
    db 0dfh
    push eax
    push edx
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    push eax
    push edx
    call L_00044954
    pop esi
    pop edi
    pop ecx
    sub edi, dword ptr [DAT_0005ff4c]
    add esi, 6
    mov eax, dword ptr [DAT_0005ff44]
    add dword ptr [DAT_0005ff40], eax
    mov al, byte ptr [edi]
    mov byte ptr [L_00044b77], al
    dec ecx
    jne short L_00044b55
L_00044baa:
    popad
    leave
    ret
    org 0cfah
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov al, byte ptr [edi]
    mov byte ptr [L_00044b07], al
    org 0cadh
    mov byte ptr [L_00044af6], al
    mov byte ptr [L_00044b66], al
    org 0c9eh
    mov byte ptr [L_00044af9], al
    mov byte ptr [L_00044b69], al
    org 0bd3h
    push eax
    sub eax, 0x20
    jge short L_000449be
    add eax, 0x168
L_000449be:
    push eax
    call L_00044270
    mov word ptr [L_00044a11], ax
    pop eax
    call L_00044275
    mov word ptr [L_00044a27], ax
    pop eax
    add eax, 0x5a
    cmp eax, 0x168
    jl short L_000449e6
    sub eax, 0x168
L_000449e6:
    push eax
    call L_00044270
    mov word ptr [L_00044a3d], ax
    pop eax
    call L_00044275
    mov word ptr [L_00044a54], ax
    org 0d03h
    jmp short L_00044ae5
L_00044ae5:
    push ecx
    push edi
    push esi
    mov bp, word ptr [esi]
    mov bx, word ptr [esi + 2]
    mov al, byte ptr [esi + 4]
    mov dl, byte ptr [esi + 5]
    db 004h
L_00044af6:
    db 0dfh
    db 080h, 0c2h
L_00044af9:
    db 0dfh
    shl eax, 0x18
    shl edx, 0x18
    shl ebp, 0x10
    shl ebx, 0x10
    db 0b4h
L_00044b07:
    db 0dfh
    push eax
    push edx
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    push eax
    push edx
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    push eax
    push edx
    db 003h, 0c5h    ; add eax, ebp (WASM encodes it differently)
    db 003h, 0d3h    ; add edx, ebx (WASM encodes it differently)
    push eax
    push edx
    call L_000442e4
    pop esi
    pop edi
    pop ecx
    sub edi, dword ptr [DAT_0005ff4c]
    add esi, 6
    mov eax, dword ptr [DAT_0005ff44]
    add dword ptr [DAT_0005ff40], eax
    mov al, byte ptr [edi]
    mov byte ptr [L_00044b07], al
    org 0cb7h
    mov eax, dword ptr [DAT_0005ff48]
    add eax, dword ptr [DAT_0005fdbc]
    mov dword ptr [DAT_0005ff40], eax
    mov eax, dword ptr [DAT_0005c040]
    add eax, 2
    mov dword ptr [DAT_0005ff54], eax
    mov esi, offset DAT_0005ff58
    mov ecx, dword ptr [DAT_0005ff50]
    cmp ecx, 0x50
    jl short L_00044ac9
    mov ecx, 0x50
L_00044ac9:
    mov eax, 0x7f
    imul eax, dword ptr [DAT_0005ff4c]
    mov edi, offset DAT_0005fe94
    org 0ca8h
    mov al, byte ptr [DAT_0005c048]
    org 0c1eh
    mov esi, 0
    mov edi, offset DAT_0005ff58
    mov ecx, 0x80
    jmp short L_00044a0f
L_00044a0f:
    db 066h, 0b8h
L_00044a11:
    db 0dfh, 03ch
    mov dx, word ptr [esi + DAT_000693e0]
    imul dx
    shld dx, ax, 3
    mov byte ptr [edi + 5], dl
    db 066h, 0b8h
L_00044a27:
    db 0dfh, 03ch
    mov dx, word ptr [esi + DAT_000693e0]
    imul dx
    shld dx, ax, 3
    mov byte ptr [edi + 4], dl
    db 066h, 0b8h
L_00044a3d:
    db 0dfh, 03ch
    mov dx, word ptr [esi + DAT_00069660]
    imul dx
    shld dx, ax, 3
    mov word ptr [edi + 2], dx
    db 066h, 0b8h
L_00044a54:
    db 0dfh, 03ch
    mov dx, word ptr [esi + DAT_00069660]
    imul dx
    shld dx, ax, 3
    mov word ptr [edi], dx
    add esi, 2
    add edi, 6
    dec ecx
    jne short L_00044a0f
    popad
    leave
    ret
; ---- FUN_00044a74
FUN_00044a74:
    enter 0, 0
    pushad
    mov al, byte ptr [DAT_0005c044]
    org 0bb4h
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00044998
FUN_00044998:
    enter 0, 0
    pushad
    mov ebx, 0
    mov ebx, dword ptr [DAT_0005c65c]
    mov eax, 0x168
    sub eax, dword ptr [DAT_0005c658]
_TEXT ends
end
