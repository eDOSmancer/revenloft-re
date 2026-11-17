; a373e7.asm - assembler module of CODE.2 (2174 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn FUN_00029d18:near
extrn FUN_000396c0:near
extrn FUN_00039804:near
extrn FUN_0003f29c:near
extrn __GETDS:near
extrn DAT_0005759c:byte
extrn DAT_00057f84:byte
extrn DAT_00057f88:byte
extrn DAT_0005c658:byte
extrn DAT_0005ef4d:byte
extrn DAT_0005efe0:byte
extrn DAT_0005fdbc:byte
extrn B000758dc_cl:byte
_DATA segment dword public use32 'DATA'
public DAT_0005d8e0
DAT_0005d8e0 label byte
    db 0ffh, 0ffh, 0ffh, 0ffh
public DAT_0005d8e4
DAT_0005d8e4 label byte
    db 0ffh, 0ffh, 0ffh, 0ffh
DAT_0005d8e8 label byte
    db 008h, 006h, 005h, 004h, 003h, 002h, 002h, 001h, 001h, 001h    ; 0005d8e8  ..........
    db 20 dup(0)    ; 0005d8f2
    db 001h, 001h, 001h, 002h, 002h, 003h, 004h, 005h, 006h, 008h    ; 0005d906  ..........
DAT_0005d910 label byte
    db 000h    ; 0005d910  .
DAT_0005d911 label byte
    db 000h    ; 0005d911  .
DAT_0005d912 label byte
    db 000h    ; 0005d912  .
DAT_0005d913 label byte
    db 000h    ; 0005d913  .
DAT_0005d914 label byte
    db 000h    ; 0005d914  .
DAT_0005d915 label byte
    db 000h    ; 0005d915  .
DAT_0005d916 label byte
    db 4177 dup(0)    ; 0005d916
DAT_0005e967 label byte
    db 000h, 000h, 000h, 000h    ; 0005e967  ....
DAT_0005e96b label byte
    db 000h, 000h    ; 0005e96b  ..
DAT_0005e96d label byte
    db 55 dup(0)    ; 0005e96d
DAT_0005e9a4 label byte
    db 053h, 043h, 052h, 045h, 045h, 04eh    ; 0005e9a4  SCREEN
DAT_0005e9aa label byte
    db 030h, 030h, 02eh, 04ch, 042h, 04dh, 000h    ; 0005e9aa  00.LBM.
DAT_0005e9b1 label byte
    db 000h, 000h, 000h, 000h    ; 0005e9b1  ....
DAT_0005e9b5 label byte
    db 000h, 000h, 000h, 000h    ; 0005e9b5  ....
DAT_0005e9b9 label byte
    db 320 dup(0)    ; 0005e9b9
DAT_0005eaf9 label byte
    db 046h, 04fh, 052h, 04dh, 000h, 001h, 0f7h, 030h, 050h, 042h, 04dh, 020h, 042h, 04dh, 048h, 044h    ; 0005eaf9  FORM...0PBM BMHD
    db 000h, 000h, 000h, 014h, 001h, 040h, 001h, 090h, 000h, 000h, 000h, 000h, 008h, 000h, 000h, 000h    ; 0005eb09  .....@..........
    db 000h, 0ffh, 005h, 006h, 001h, 040h, 000h, 0c8h, 043h, 04dh, 041h, 050h, 000h, 000h, 003h, 000h    ; 0005eb19  .....@..CMAP....
DAT_0005eb29 label byte
    db 768 dup(0)    ; 0005eb29
    db 042h, 04fh, 044h, 059h, 000h, 001h, 0f4h, 000h    ; 0005ee29  BODY....
DAT_0005ee31 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 0005ee31  ...............
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_000374a4
public FUN_00037894
public FUN_00037a90
public FUN_00037aec
public FUN_00037b84
public FUN_00037bd8
L_000373f0:
    db 0c8h
    add byte ptr [eax], al
    add byte ptr [edi + 0x56], dl
    push ebx
    push ecx
    mov edi, dword ptr [DAT_0005fdbc]
    add edi, 0x5663
    mov ecx, 0x28
    mov bh, 0x11
    mov bl, 0
    mov esi, offset DAT_0005d8e8
    org $
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
L_0003741c:
    mov dx, 0x3c4
    db 08ah, 0e7h    ; mov ah, bh (WASM encodes it differently)
    mov al, 2
    out dx, ax
    mov dx, 0x3ce
    db 08ah, 0e3h    ; mov ah, bl (WASM encodes it differently)
    mov al, 4
    out dx, ax
    mov ah, byte ptr [esi]
    cmp ah, 0
    je short L_0003748e
    push ecx
    push edi
    cmp ah, 8
    je short L_00037452
    cmp ah, 6
    je short L_00037476
    mov ecx, 0xe
L_00037448:
    sub byte ptr [edi], ah
    add edi, 0x50
    dec ecx
    jne short L_00037448
    jmp short L_0003748c
L_00037452:
    mov byte ptr [edi], 0xd
    add edi, 0x50
    mov byte ptr [edi], 0x50
    add edi, 0x50
    mov ecx, 0xa
L_00037463:
    sub byte ptr [edi], ah
    add edi, 0x50
    dec ecx
    jne short L_00037463
    mov byte ptr [edi], 0x50
    add edi, 0x50
    mov byte ptr [edi], 0xd
    jmp short L_0003748c
L_00037476:
    mov byte ptr [edi], 0x50
    add edi, 0x50
    mov ecx, 0xc
L_00037481:
    sub byte ptr [edi], ah
    add edi, 0x50
    dec ecx
    jne short L_00037481
    mov byte ptr [edi], 0x50
L_0003748c:
    pop edi
    pop ecx
L_0003748e:
    inc bl
    and bl, 3
    rol bh, 1
    adc edi, 0
    inc esi
    dec ecx
    jne short L_0003741c
    pop ecx
    pop edx
    pop esi
    pop edi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_000374a4
FUN_000374a4:
    enter 4, 0
    pushad
    mov eax, dword ptr [DAT_0005c658]
    mov ebx, 0xc0
    mul ebx
    add eax, 0xb4
    adc edx, 0
    mov ebx, 0x168
    div ebx
    mov edx, 0x8c
    db 02bh, 0d0h    ; sub edx, eax (WASM encodes it differently)
    movsx eax, dx
    cmp eax, 0x13
    jg short L_000374d8
    add eax, 0xc0
L_000374d8:
    cmp eax, 0xd3
    jle short L_000374e4
    sub eax, 0xc0
L_000374e4:
    movzx ebx, byte ptr [DAT_0005ef4d]
    cmp eax, dword ptr [ebx*4 + DAT_0005d8e0]
    je near ptr L_0003757b
    mov dword ptr [ebx*4 + DAT_0005d8e0], eax
    mov dword ptr [ebp - 4], eax
    push 0xb1
    push 0x121
    push 0x8e
    push 0x114
    call FUN_000396c0
    add esp, 0x10
    push 0
    mov eax, dword ptr [B000758dc_cl]
    org $
    add eax, 0x2c
    push eax
    call FUN_0003f29c
    add esp, 8
    push eax
    mov eax, 0xa0
    sub eax, dword ptr [ebp - 4]
    push eax
    push 0x114
    push 0
    call FUN_00039804
    add esp, 8
    pop eax
    add eax, 0xc0
    push eax
    push 0x114
    push 0
    call FUN_00039804
    add esp, 0x10
    call L_000373f0
    push 0x13f
    push 0x18f
    push 0
    push 0
    call FUN_000396c0
    add esp, 0x10
L_0003757b:
    popad
    leave
    ret
    add byte ptr [eax], al
    enter 0, 0
    push esi
    push edi
    push ebx
    mov esi, dword ptr [ebp + 8]
    mov eax, dword ptr [ebp + 0xc]
    shl eax, 0xb
    or eax, 0xa000
    shl eax, 4
    mov edi, dword ptr [ebp + 0x10]
    shl edi, 1
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    mov ecx, 0x190
L_000375ae:
    push ecx
    mov bx, 4
    mov ecx, 4
L_000375b8:
    db 066h, 08bh, 0c3h    ; mov ax, bx (WASM encodes it differently)
    out dx, ax
    mov al, byte ptr [edi]
    mov byte ptr [esi], al
    mov al, byte ptr [edi + 1]
    mov byte ptr [esi + 4], al
    inc esi
    inc bh
    dec ecx
    jne short L_000375b8
    add esi, 4
    add edi, 0x50
    pop ecx
    dec ecx
    jne short L_000375ae
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    enter 0, 0
    push esi
    push edi
    push ebx
    mov esi, dword ptr [ebp + 8]
    mov eax, dword ptr [ebp + 0xc]
    shl eax, 0xb
    or eax, 0xa000
    shl eax, 4
    mov edi, dword ptr [ebp + 0x10]
    shr edi, 2
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    mov eax, dword ptr [ebp + 0x10]
    and eax, 3
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    mov al, 4
    out dx, ax
    mov ecx, 0x190
L_0003761f:
    mov al, byte ptr [edi]
    mov byte ptr [esi], al
    inc esi
    add edi, 0x50
    dec ecx
    jne short L_0003761f
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
    enter 0, 0
    push esi
    push edi
    push ebx
    mov esi, dword ptr [ebp + 8]
    mov eax, dword ptr [ebp + 0xc]
    shl eax, 0xb
    or eax, 0xa000
    shl eax, 4
    mov edi, dword ptr [ebp + 0x10]
    shl edi, 1
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov ecx, 0x190
    mov dx, 0x3c4
L_00037660:
    push ecx
    mov bx, 0x102
    mov ecx, 4
L_0003766a:
    db 066h, 08bh, 0c3h    ; mov ax, bx (WASM encodes it differently)
    out dx, ax
    mov al, byte ptr [esi]
    mov byte ptr [edi], al
    mov al, byte ptr [esi + 4]
    mov byte ptr [edi + 1], al
    inc esi
    shl bh, 1
    dec ecx
    jne short L_0003766a
    add esi, 4
    add edi, 0x50
    pop ecx
    dec ecx
    jne short L_00037660
    mov ax, 0xff02
    out dx, ax
    pop ebx
    pop edi
    pop esi
    leave
    ret
    enter 0, 0
    push esi
    push edi
    pop ebx
    mov dx, 0x3c4
    mov ecx, dword ptr [ebp + 0x14]
    and ecx, 3
    mov eax, 1
    shl eax, cl
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    mov al, 2
    out dx, ax
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    mov eax, dword ptr [ebp + 0x14]
    and eax, 3
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    mov al, 4
    out dx, ax
    mov eax, dword ptr [ebp + 0xc]
    shl eax, 0xb
    or eax, 0xa000
    shl eax, 4
    mov edi, dword ptr [ebp + 0x14]
    shl edi, 2
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp + 0xc]
    xor eax, 1
    shl eax, 0xb
    or eax, 0xa000
    shl eax, 4
    mov esi, dword ptr [ebp + 0x14]
    shr esi, 2
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    mov ecx, dword ptr [ebp + 0x10]
    cmp ecx, 0
    je short L_0003770c
L_000376ff:
    mov al, byte ptr [esi]
    mov byte ptr [edi], al
    add esi, 0x50
    add edi, 0x50
    dec ecx
    jne short L_000376ff
L_0003770c:
    mov esi, dword ptr [ebp + 8]
    mov ecx, 0x190
    sub ecx, dword ptr [ebp + 0x10]
L_00037717:
    lodsb
    mov byte ptr [edi], al
    add edi, 0x50
    dec ecx
    jne short L_00037717
    mov dx, 0x3c4
    mov ax, 0xff02
    out dx, ax
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
    enter 0, 0
    push esi
    push edi
    push ebx
    mov esi, dword ptr [ebp + 0x10]
    mov edi, dword ptr [ebp + 0xc]
    mov ecx, 0x320
    rep movsd
    mov esi, dword ptr [ebp + 8]
    mov edi, dword ptr [ebp + 0xc]
    mov ecx, 0x190
    cmp dword ptr [ebp + 0x14], 0
    jne short L_00037767
    shl ecx, 1
    rep movsd
    jmp short L_000377dd
L_00037767:
    cmp dword ptr [ebp + 0x14], 1
    jne short L_0003779b
L_0003776d:
    mov al, byte ptr [esi]
    mov byte ptr [edi + 1], al
    mov al, byte ptr [esi + 1]
    mov byte ptr [edi + 2], al
    mov al, byte ptr [esi + 3]
    mov byte ptr [edi + 3], al
    mov al, byte ptr [esi + 4]
    mov byte ptr [edi + 4], al
    mov al, byte ptr [esi + 6]
    mov byte ptr [edi + 5], al
    mov al, byte ptr [esi + 7]
    mov byte ptr [edi + 6], al
    add esi, 8
    add edi, 8
    dec ecx
    jne short L_0003776d
    jmp short L_000377dd
L_0003779b:
    cmp dword ptr [ebp + 0x14], 2
    jne short L_000377c3
L_000377a1:
    mov al, byte ptr [esi]
    mov byte ptr [edi + 2], al
    mov al, byte ptr [esi + 3]
    mov byte ptr [edi + 3], al
    mov al, byte ptr [esi + 4]
    mov byte ptr [edi + 4], al
    mov al, byte ptr [esi + 7]
    mov byte ptr [edi + 5], al
    add esi, 8
    add edi, 8
    dec ecx
    jne short L_000377a1
    jmp short L_000377dd
L_000377c3:
    cmp dword ptr [ebp + 0x14], 3
    jne short L_000377dd
L_000377c9:
    mov al, byte ptr [esi]
    mov byte ptr [edi + 3], al
    mov al, byte ptr [esi + 7]
    mov byte ptr [edi + 4], al
    add esi, 8
    add edi, 8
    dec ecx
    jne short L_000377c9
L_000377dd:
    pop ebx
    pop edi
    pop esi
    leave
    ret
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
; ---- FUN_000377f0
L_000377f0:
    push ebx
    push edx
    push eax
    mov ebx, 0x54
L_000377f8:
    mov al, byte ptr [ebx + DAT_0005efe0]
    mov byte ptr [ebx + DAT_0005d916], al
    dec ebx
    jge short L_000377f8
    mov dx, 0x3c4
    in al, dx
    mov byte ptr [DAT_0005d912], al
    mov al, 2
    out dx, al
    inc dx
    in al, dx
    mov byte ptr [DAT_0005d911], al
    mov dx, 0x3ce
    in al, dx
    mov byte ptr [DAT_0005d914], al
    mov al, 5
    out dx, al
    inc dx
    in al, dx
    mov byte ptr [DAT_0005d913], al
    dec dx
    mov al, 4
    out dx, al
    inc dx
    in al, dx
    mov byte ptr [DAT_0005d915], al
    org $
    pop eax
    pop edx
    pop ebx
    ret
    xchg ebx, ebx
; ---- FUN_00037844
L_00037844:
    push ebx
    push edx
    push eax
    mov ebx, 0x54
L_0003784c:
    mov al, byte ptr [ebx + DAT_0005d916]
    mov byte ptr [ebx + DAT_0005efe0], al
    dec ebx
    jge short L_0003784c
    mov dx, 0x3c4
    mov al, 2
    mov ah, byte ptr [DAT_0005d911]
    out dx, ax
    mov al, byte ptr [DAT_0005d912]
    out dx, al
    mov dx, 0x3ce
    mov al, 5
    mov ah, byte ptr [DAT_0005d913]
    out dx, ax
    mov al, 4
    mov ah, byte ptr [DAT_0005d915]
    out dx, ax
    mov al, byte ptr [DAT_0005d914]
    org $
    out dx, al
    pop eax
    pop edx
    pop ebx
    ret
    xchg ebx, ebx
    nop
FUN_00037894:
    pushf
    pushad
    push ds
    push es
    push fs
    push gs
    cld
    call __GETDS
    push ds
    pop es
    cmp byte ptr [DAT_0005d910], 0
    jne short L_00037909
    mov byte ptr [DAT_0005d910], 1
    mov word ptr [DAT_0005e96b], ss
    mov dword ptr [DAT_0005e96d], esp
    mov dword ptr [DAT_0005d916], eax
    mov ax, ds
    db 08eh, 0d0h    ; mov ss, eax (WASM rejects it)
    mov esp, offset DAT_0005e967
    mov eax, dword ptr [DAT_0005d916]
    and esi, 0xffff
    shl esi, 4
    push esi
    push edx
    push ecx
    push ebx
    push eax
    call L_000377f0
    call FUN_00029d18
    add esp, 8
    call L_00037844
    mov esp, dword ptr [DAT_0005e96d]
    db 08eh, 015h
    dd offset DAT_0005e96b    ; mov ss, word ptr [0xe96b] (WASM encodes it differently)
    mov byte ptr [DAT_0005d910], 0
    org $
L_00037909:
    pop gs
    pop fs
    pop es
    pop ds
    popad
    popf
    retf
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    db 000h
L_00037920:
    db 056h, 051h
    push eax
    mov esi, offset DAT_0005eb29
    mov ecx, 0x300
L_0003792d:
    shl byte ptr [esi], 2
    inc esi
    dec ecx
    jne short L_0003792d
    pop eax
    pop ecx
    pop esi
    ret
L_00037938:
    pushad
    mov dword ptr [DAT_0005e9b1], ebx
    mov dword ptr [DAT_0005e9b5], 0x190
    mov edx, offset DAT_0005eaf9
    mov ecx, 0x338
    mov ah, 0x40
    int 0x21
    jb short L_000379cc
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov esi, dword ptr [DAT_0005ee31]
L_00037969:
    mov edi, 4
    mov ecx, 4
    mov ebx, 0
L_00037978:
    push esi
    push ecx
    push ebx
    mov ecx, 0x50
    mov edx, 0x3ce
    db 08bh, 0c7h    ; mov eax, edi (WASM encodes it differently)
    out dx, ax
    inc ah
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
L_0003798d:
    mov al, byte ptr [esi]
    mov byte ptr [ebx + DAT_0005e9b9], al
    add ebx, 4
    inc esi
    dec ecx
    jne short L_0003798d
    pop ebx
    pop ecx
    pop esi
    inc ebx
    dec ecx
    jne short L_00037978
    mov edx, offset DAT_0005e9b9
    mov ecx, 0x140
    mov ebx, dword ptr [DAT_0005e9b1]
    mov ah, 0x40
    int 0x21
    add esi, 0x50
    dec dword ptr [DAT_0005e9b5]
    org $
    jne short L_00037969
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
L_000379cc:
    popad
    ret
    xchg ebx, ebx
    enter 0, 0
    pushad
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_0005ee31], eax
L_000379dd:
    mov edx, offset DAT_0005e9a4
    mov eax, 0x5b00
    mov ecx, 0
    int 0x21
    jae short L_00037a0c
    db 066h, 03dh, 050h, 000h    ; cmp ax, 0x50 (WASM encodes it differently)
    jne short L_00037a51
    mov esi, offset DAT_0005e9aa
    inc byte ptr [esi + 1]
    cmp byte ptr [esi + 1], 0x3a
    jne short L_00037a0a
    inc byte ptr [esi]
    mov byte ptr [esi + 1], 0x30
L_00037a0a:
    jmp short L_000379dd
L_00037a0c:
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    push ebx
    mov edx, offset DAT_0005eb29
    mov ebx, 0
    mov ecx, 0x100
    mov eax, 0x1017
    int 0x10
    pop ebx
    call L_00037920
    call L_00037938
    mov eax, 0x3e00
    mov ebx, dword ptr [DAT_0005e9b1]
    int 0x21
    mov esi, offset DAT_0005e9aa
    org $
    inc byte ptr [esi + 1]
    cmp byte ptr [esi + 1], 0x3a
    jne short L_00037a51
    inc byte ptr [esi]
    mov byte ptr [esi + 1], 0x30
L_00037a51:
    popad
    leave
    ret
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
; ---- FUN_00037a60
L_00037a60:
    mov eax, dword ptr [DAT_00057f88]
    add eax, dword ptr [DAT_00057f84]
    movzx eax, byte ptr [eax]
    inc dword ptr [DAT_00057f88]
    org $
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00037a78
L_00037a78:
    mov eax, dword ptr [DAT_00057f88]
    add eax, dword ptr [DAT_00057f84]
    movzx eax, word ptr [eax]
    add dword ptr [DAT_00057f88], 2
    org $
    ret
    xchg ebx, ebx
; ---- FUN_00037a90
L_00037a90:
FUN_00037a90:
    enter 0, 0
    push ebx
    push edi
    push esi
    mov eax, dword ptr [ebp + 0x18]
    shl eax, 0xb
    add eax, 0xa000
    shl eax, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp + 0xc]
    mov edx, 0x50
    imul edx
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp + 0x10]
    shl eax, 2
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov esi, dword ptr [ebp + 8]
    mov ah, 0x11
    mov al, 2
    mov dx, 0x3c4
    mov ebx, 4
L_00037acb:
    out dx, ax
    rol ah, 1
    mov ecx, dword ptr [ebp + 0x14]
    push edi
    push esi
L_00037ad4:
    movsb
    add esi, 3
    dec ecx
    jne short L_00037ad4
    pop esi
    pop edi
    inc esi
    dec ebx
    jne short L_00037acb
    mov ax, 0xff02
    out dx, ax
    pop esi
    pop edi
    pop ebx
    leave
    ret
; ---- FUN_00037aec
FUN_00037aec:
    enter 0x10, 0
    push ebx
    push esi
    push edi
    mov dword ptr [ebp - 0xc], 0
    call L_00037a78
    mov dword ptr [ebp - 4], eax
L_00037b02:
    cmp dword ptr [ebp - 4], 0
    je short L_00037b7e
    call L_00037a78
    add dword ptr [ebp - 0xc], eax
    call L_00037a78
    mov dword ptr [ebp - 8], eax
    mov dword ptr [ebp - 0x10], 0
    mov dx, 0x3c4
    mov eax, dword ptr [ebp - 0xc]
    db 066h, 025h, 003h, 000h    ; and ax, 3 (WASM encodes it differently)
    db 08ah, 0c8h    ; mov cl, al (WASM encodes it differently)
    mov ah, 0x11
    shl ah, cl
    mov al, 2
    out dx, ax
L_00037b34:
    cmp dword ptr [ebp - 8], 0
    je short L_00037b79
    call L_00037a78
    add dword ptr [ebp - 0x10], eax
    call L_00037a78
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    db 06bh, 045h, 0f0h, 050h    ; imul eax, dword ptr [ebp - 0x10], 0x50 (WASM encodes it differently)
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp - 0xc]
    shr eax, 2
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp + 8]
    shl eax, 0xf
    or eax, 0xa0000
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
L_00037b64:
    call L_00037a60
    mov byte ptr [edi], al
    add edi, 0x50
    inc dword ptr [ebp - 0x10]
    dec ecx
    jne short L_00037b64
    dec dword ptr [ebp - 8]
    jmp short L_00037b34
L_00037b79:
    dec dword ptr [ebp - 4]
    jmp short L_00037b02
L_00037b7e:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    nop
; ---- FUN_00037b84
FUN_00037b84:
    enter 8, 0
    push ebx
    push edi
    push esi
    push ecx
    push edx
    mov esi, dword ptr [DAT_00057f84]
    mov eax, dword ptr [ebp + 8]
    shl eax, 0xf
    or eax, 0xa0000
    add eax, 0xff0
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov dword ptr [ebp - 4], eax
    mov dword ptr [ebp - 8], 0
L_00037baf:
    mov dx, 0x3c4
    mov ah, 1
    mov cl, byte ptr [ebp - 8]
    shl ah, cl
    mov al, 2
    out dx, ax
    mov ecx, 0x5000
    rep movsb
    mov edi, dword ptr [ebp - 4]
    inc dword ptr [ebp - 8]
    cmp dword ptr [ebp - 8], 4
    jne short L_00037baf
    pop edx
    pop ecx
    pop esi
    pop edi
    pop ebx
    leave
    ret
; ---- FUN_00037bd8
FUN_00037bd8:
    enter 0xc, 0
    push ecx
    push ebx
    push esi
    push edi
    mov dword ptr [ebp - 4], 0
    mov esi, dword ptr [DAT_00057f88]
    add esi, dword ptr [DAT_00057f84]
L_00037bf3:
    mov dword ptr [ebp - 8], 0
    mov edi, offset DAT_0005759c
L_00037bff:
    movzx ecx, byte ptr [esi]
    inc dword ptr [DAT_00057f88]
    inc esi
    test ecx, 0x80
    jne short L_00037c1f
    inc ecx
    add dword ptr [ebp - 8], ecx
    add dword ptr [DAT_00057f88], ecx
    rep movsb
    jmp short L_00037c37
L_00037c1f:
    mov eax, 0x101
    db 02bh, 0c1h    ; sub eax, ecx (WASM encodes it differently)
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    add dword ptr [ebp - 8], ecx
    movzx eax, byte ptr [esi]
    inc dword ptr [DAT_00057f88]
    inc esi
    rep stosb
L_00037c37:
    cmp dword ptr [ebp - 8], 0x140
    jl short L_00037bff
    push esi
    push edi
    push dword ptr [ebp + 8]
    push 0x50
    push 0
    push dword ptr [ebp - 4]
    mov eax, offset DAT_0005759c
    push eax
    call L_00037a90
    add esp, 0x14
    pop edi
    pop esi
    inc dword ptr [ebp - 4]
    cmp dword ptr [ebp - 4], 0x190
    jne short L_00037bf3
    pop edi
    pop esi
    pop ebx
    pop ecx
    leave
    ret
_TEXT ends
end
