; a19ca0.asm - assembler module of CODE.1 (4920 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
_DATA segment dword public use32 'DATA'
public DAT_00032b28
DAT_00032b28 label byte
    db 000h    ; 00032b28  .
DAT_00032b29 label byte
    db 000h, 000h, 000h, 000h    ; 00032b29  ....
DAT_00032b2d label byte
    db 000h, 000h, 000h, 000h    ; 00032b2d  ....
DAT_00032b31 label byte
    db 000h, 000h, 000h, 000h    ; 00032b31  ....
DAT_00032b35 label byte
    db 000h, 000h, 000h, 000h    ; 00032b35  ....
DAT_00032b39 label byte
    db 000h, 000h, 000h, 000h    ; 00032b39  ....
DAT_00032b3d label byte
    db 000h, 000h, 000h, 000h    ; 00032b3d  ....
DAT_00032b41 label byte
    db 000h, 000h, 000h, 000h    ; 00032b41  ....
DAT_00032b45 label byte
    db 000h, 000h, 000h, 000h    ; 00032b45  ....
DAT_00032b49 label byte
    db 000h, 000h, 000h, 000h    ; 00032b49  ....
DAT_00032b4d label byte
    db 000h, 000h, 000h, 000h    ; 00032b4d  ....
DAT_00032b51 label byte
    db 000h, 000h, 000h, 000h    ; 00032b51  ....
DAT_00032b55 label byte
    db 000h, 000h, 000h, 000h    ; 00032b55  ....
DAT_00032b59 label byte
    db 000h, 000h, 000h, 000h    ; 00032b59  ....
DAT_00032b5d label byte
    db 000h, 000h, 000h, 000h    ; 00032b5d  ....
DAT_00032b61 label byte
    db 000h, 000h, 000h, 000h    ; 00032b61  ....
DAT_00032b65 label byte
    db 000h, 000h, 000h, 000h    ; 00032b65  ....
DAT_00032b69 label byte
    db 000h, 000h, 000h, 000h    ; 00032b69  ....
DAT_00032b6d label byte
    db 000h, 000h, 000h, 000h    ; 00032b6d  ....
DAT_00032b71 label byte
    db 000h, 000h, 000h, 000h    ; 00032b71  ....
DAT_00032b75 label byte
    db 000h, 000h, 000h, 000h    ; 00032b75  ....
DAT_00032b79 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 00032b79  .......
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_00019ca0
public FUN_00019df4
public FUN_00019eb0
public FUN_0001a010
public FUN_0001a05c
public FUN_0001a21c
public FUN_0001a2b0
public FUN_0001a35c
public FUN_0001a36c
public FUN_0001a390
public FUN_0001a3e8
public FUN_0001a474
public FUN_0001a484
public FUN_0001a4e8
public FUN_0001a558
public FUN_0001a57c
public FUN_0001a5c8
public FUN_0001a678
public FUN_0001a6f0
public FUN_0001a7e8
public FUN_0001a8f4
public FUN_0001aa20
public FUN_0001ac10
public FUN_0001ae0c
public FUN_0001aea8
; ---- FUN_00019ca0
FUN_00019ca0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_00032b29], eax
    and dword ptr [DAT_00032b29], 0x80
    and eax, 0x7f
    mov dword ptr [DAT_00032b2d], eax
    mov dword ptr [DAT_00032b3d], 0xc8
    mov dword ptr [DAT_00032b41], 0x50
    mov dword ptr [DAT_00032b49], 0xa0000
    mov dword ptr [DAT_00032b31], 0
    mov byte ptr [DAT_00032b28], 0
    mov dword ptr [DAT_00032b4d], 0x400
    mov dword ptr [DAT_00032b35], 4
    mov dword ptr [DAT_00032b39], 2
    call L_0001af08
    cmp dword ptr [DAT_00032b2d], 3
    jne short L_00019d28
    mov dword ptr [DAT_00032b4d], 0x800
L_00019d28:
    mov ah, 0xf
    int 0x10
    cmp al, 0x13
    je short L_00019d36
    mov ax, 0x13
    int 0x10
L_00019d36:
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_00032b28]
    mov al, 3
    out dx, ax
    mov dx, 0x3c4
    mov al, 4
    out dx, al
    inc dx
    in al, dx
    and al, 0xf7
    or al, 4
    out dx, al
    mov dx, 0x3ce
    mov al, 5
    out dx, al
    inc dx
    in al, dx
    and al, 0xef
    out dx, al
    dec dx
    mov al, 6
    out dx, al
    inc dx
    in al, dx
    and al, 0xfd
    out dx, al
    call L_0001af08
    mov dx, 0x3d4
    mov al, 9
    out dx, al
    inc dx
    in al, dx
    cmp dword ptr [DAT_00032b2d], 3
    jne short L_00019d87
    and al, 0xe0
    jmp short L_00019d89
L_00019d87:
    mov al, 0x41
L_00019d89:
    out dx, al
    dec dx
    mov al, 0x14
    out dx, al
    inc dx
    in al, dx
    and al, 0xbf
    out dx, al
    dec dx
    mov al, 0x17
    out dx, al
    inc dx
    in al, dx
    or al, 0x40
    out dx, al
    db 033h, 0dbh    ; xor ebx, ebx (WASM encodes it differently)
    call L_0001af64
    mov ecx, 0xff
    call L_0001af80
    mov ebx, 0xc8
    mov ecx, 0x140
    cmp dword ptr [DAT_00032b2d], 3
    jne short L_00019dc6
    shl ebx, 1
L_00019dc6:
    mov dword ptr [DAT_00032b45], ebx
    mov ax, 0x20d
    mov dword ptr [DAT_00032b29], 0
    org $
    mov edi, dword ptr [ebp + 0xc]
    mov byte ptr [edi + 1], ah
    mov word ptr [edi + 3], bx
    mov word ptr [edi + 5], cx
    and eax, 0xff
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_00019df4
FUN_00019df4:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    call L_0001af08
    mov ax, 3
    int 0x10
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
    jmp short L_00019e8c
    xchg ebx, ebx
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0001aea8
    mov dx, 0x3ce
    db 08ah, 0e1h    ; mov ah, cl (WASM encodes it differently)
    mov al, 4
    out dx, ax
    mov ah, 1
    shl ah, cl
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_00032b28]
    org $
    mov al, 3
    out dx, ax
    mov al, byte ptr [ebx]
    mov eax, dword ptr [ebp + 0x10]
    mov byte ptr [ebx], al
    mov ax, 3
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0001aea8
    db 08ah, 0e1h    ; mov ah, cl (WASM encodes it differently)
    mov al, 4
    mov dx, 0x3ce
    out dx, ax
    mov al, byte ptr [ebx]
    db 032h, 0e4h    ; xor ah, ah (WASM encodes it differently)
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
L_00019e8c:
    enter 0, 0
    push ebx
    mov ebx, dword ptr [ebp + 8]
    mov al, byte ptr cs:[ebx + L_00019ea3]
    org $
    mov byte ptr [DAT_00032b28], al
    org $
    pop ebx
    leave
    ret
L_00019ea3:
    add byte ptr [eax], cl
    adc byte ptr [eax], bl
L_00019ea7:
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00019eb0
FUN_00019eb0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    mov ebx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 0x14]
    mov eax, dword ptr [ebp + 0x18]
    cmp ebx, 0
    jle short L_00019ea7
    cmp esi, 0
    jle short L_00019ea7
    push eax
    push ebx
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08bh, 0d9h    ; mov ebx, ecx (WASM encodes it differently)
    call L_0001aea8
    mov dh, 0xf
    shl dh, cl
    db 032h, 0edh    ; xor ch, ch (WASM encodes it differently)
    dec esi
    xor cl, 3
    db 02bh, 0f1h    ; sub esi, ecx (WASM encodes it differently)
    jbe short L_00019f01
    dec esi
    db 08bh, 0ceh    ; mov ecx, esi (WASM encodes it differently)
    and ecx, 3
    db 02bh, 0f1h    ; sub esi, ecx (WASM encodes it differently)
    xor cl, 3
    mov dl, 0xf0
    sar dl, cl
    not dl
    shr esi, 2
    jmp short L_00019f15
L_00019f01:
    add esi, 3
    db 08bh, 0ceh    ; mov ecx, esi (WASM encodes it differently)
    xor cl, 3
    mov dl, 0xf0
    sar dl, cl
    not dl
    db 022h, 0f2h    ; and dh, dl (WASM encodes it differently)
    db 032h, 0d2h    ; xor dl, dl (WASM encodes it differently)
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
L_00019f15:
    mov edi, dword ptr [DAT_00032b41]
    db 02bh, 0feh    ; sub edi, esi (WASM encodes it differently)
    dec edi
    cmp dl, 0
    je short L_00019f25
    dec di
L_00019f25:
    pop ecx
    push edx
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_00032b28]
    mov al, 3
    out dx, ax
    cmp ah, 0
    je short L_00019fb0
    pop edx
    pop eax
    push ebp
    db 08bh, 0e9h    ; mov ebp, ecx (WASM encodes it differently)
    db 08ah, 0e8h    ; mov ch, al (WASM encodes it differently)
L_00019f41:
    push edx
    db 066h, 08bh, 0c2h    ; mov ax, dx (WASM encodes it differently)
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], ch
    inc ebx
    cmp esi, 0
    je short L_00019f68
    mov ax, 0xff02
    out dx, ax
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
L_00019f5f:
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], ch
    inc ebx
    dec al
    jne short L_00019f5f
L_00019f68:
    pop edx
    cmp dl, 0
    je short L_00019f81
    push edx
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08ah, 0e0h    ; mov ah, al (WASM encodes it differently)
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], ch
    inc ebx
    pop edx
L_00019f81:
    db 003h, 0dfh    ; add ebx, edi (WASM encodes it differently)
    dec ebp
    jne short L_00019f41
    pop ebp
    mov dx, 0x3ce
    mov ax, 3
    out dx, ax
    jmp short L_0001a007
    nop
L_00019f94:
    db 08bh, 0e8h    ; mov ebp, eax (WASM encodes it differently)
    mov ax, 0xff02
    out dx, ax
    mov eax, dword ptr [DAT_00032b41]
    org 03d9h
    mov ecx, dword ptr [ebp + 0x14]
    sub ecx, dword ptr [ebp + 0xc]
    je short L_0001a0f4
    jns short L_0001a097
    neg ecx
    mov ebx, dword ptr [ebp + 0x14]
    xchg dword ptr [ebp + 0xc], ebx
    mov dword ptr [ebp + 0x14], ebx
    mov ebx, dword ptr [ebp + 0x10]
    xchg dword ptr [ebp + 8], ebx
    mov dword ptr [ebp + 0x10], ebx
L_0001a097:
    mov ebx, dword ptr [ebp + 0x10]
    sub ebx, dword ptr [ebp + 8]
    je near ptr L_0001a130
    jns short L_0001a0a9
    neg ebx
    neg esi
L_0001a0a9:
    push esi
    mov dword ptr [ebp - 0xc], offset L_0001a19c
    db 03bh, 0d9h    ; cmp ebx, ecx (WASM encodes it differently)
    jle short L_0001a0be
    mov dword ptr [ebp - 0xc], offset L_0001a1d4
    org $
    xchg ecx, ebx
L_0001a0be:
    shl ebx, 1
    mov dword ptr [ebp - 4], ebx
    db 02bh, 0d9h    ; sub ebx, ecx (WASM encodes it differently)
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    db 02bh, 0d9h    ; sub ebx, ecx (WASM encodes it differently)
    mov dword ptr [ebp - 8], ebx
    push ecx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov al, 2
    mov ah, 1
    shl ah, cl
    mov dx, 0x3c4
    out dx, ax
    pop ecx
    inc ecx
    pop ebx
    xchg dword ptr [DAT_00032b51], eax
    org 0301h
    mul esi
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    shr ecx, 1
    db 08bh, 0c5h    ; mov eax, ebp (WASM encodes it differently)
    rep stosw
    pop ebp
    jmp short L_0001a007
    nop
L_00019fb0:
    pop edx
    pop eax
    db 08ah, 0e0h    ; mov ah, al (WASM encodes it differently)
    push ebp
    xchg ecx, esi
    db 08bh, 0efh    ; mov ebp, edi (WASM encodes it differently)
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    db 08bh, 0dah    ; mov ebx, edx (WASM encodes it differently)
    mov dx, 0x3c4
    db 00bh, 0edh    ; or ebp, ebp (WASM encodes it differently)
    jne short L_00019fcd
    cmp ebx, 0xf0f
    je short L_00019f94
L_00019fcd:
    push esi
    push ecx
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    db 08ah, 0e7h    ; mov ah, bh (WASM encodes it differently)
    mov al, 2
    out dx, ax
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
    stosb
    mov ax, 0xff02
    out dx, ax
    db 066h, 08bh, 0c6h    ; mov ax, si (WASM encodes it differently)
    cmp ecx, 0
    je short L_00019ff1
    shr ecx, 1
    rep stosw
    db 013h, 0c9h    ; adc ecx, ecx (WASM encodes it differently)
    rep stosb
L_00019ff1:
    cmp bl, 0
    je short L_00019fff
    db 08ah, 0e3h    ; mov ah, bl (WASM encodes it differently)
    mov al, 2
    out dx, ax
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
    stosb
L_00019fff:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    pop ecx
    pop esi
    dec esi
    jne short L_00019fcd
    pop ebp
L_0001a007:
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0001a010
FUN_0001a010:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 8]
    mov dx, 0x3c8
    out dx, al
    mov dx, 0x3c9
    db 08bh, 0d9h    ; mov ebx, ecx (WASM encodes it differently)
L_0001a02d:
    call L_0001af34
    cmp ebx, 0xc0
    jle short L_0001a049
    mov ecx, 0xc0
    rep outsb
    sub ebx, 0xc0
    jmp short L_0001a02d
L_0001a049:
    cmp ebx, 0
    je short L_0001a052
    db 08bh, 0cbh    ; mov ecx, ebx (WASM encodes it differently)
    rep outsb
L_0001a052:
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001a05c
FUN_0001a05c:
    enter 0xc, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_00032b28]
    mov al, 3
    out dx, ax
    mov esi, dword ptr [DAT_00032b41]
    org 044fh
    jmp dword ptr [ebp - 0xc]
    xchg ebx, ebx
L_0001a0f4:
    mov eax, dword ptr [ebp + 8]
    mov ebx, dword ptr [ebp + 0x10]
    db 08bh, 0cbh    ; mov ecx, ebx (WASM encodes it differently)
    db 02bh, 0c8h    ; sub ecx, eax (WASM encodes it differently)
    jge short L_0001a104
    neg ecx
    db 08bh, 0c3h    ; mov eax, ebx (WASM encodes it differently)
L_0001a104:
    inc ecx
    push ecx
    db 08bh, 0d0h    ; mov edx, eax (WASM encodes it differently)
    mov ecx, dword ptr [ebp + 0xc]
    call L_0001aea8
    mov ah, 1
    shl ah, cl
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    pop ecx
    mov eax, dword ptr [ebp + 0x18]
L_0001a120:
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], al
    db 003h, 0deh    ; add ebx, esi (WASM encodes it differently)
    dec ecx
    jne short L_0001a120
    jmp near ptr L_0001a209
    xchg ebx, ebx
L_0001a130:
    cld
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov dh, 0xf
    shl dh, cl
    mov ecx, dword ptr [ebp + 0x14]
    and cl, 3
    xor cl, 3
    mov dl, 0xf0
    sar dl, cl
    not dl
    mov eax, dword ptr [ebp + 0x14]
    mov ebx, dword ptr [ebp + 0xc]
    mov cl, 2
    shr eax, cl
    shr ebx, cl
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    db 02bh, 0cbh    ; sub ecx, ebx (WASM encodes it differently)
    db 08bh, 0dah    ; mov ebx, edx (WASM encodes it differently)
    mov eax, dword ptr [ebp + 0x18]
    xchg esi, eax
    mov al, 2
    mov dx, 0x3c4
    db 00ah, 0ffh    ; or bh, bh (WASM encodes it differently)
    js short L_0001a184
    db 00bh, 0c9h    ; or ecx, ecx (WASM encodes it differently)
    jne short L_0001a179
    db 022h, 0dfh    ; and bl, bh (WASM encodes it differently)
    jmp short L_0001a191
L_0001a179:
    db 08ah, 0e7h    ; mov ah, bh (WASM encodes it differently)
    out dx, ax
    xchg esi, eax
    mov ah, byte ptr [edi]
    stosb
    dec ecx
    je short L_0001a190
L_0001a184:
    xchg esi, eax
    mov ah, 0xff
    out dx, ax
    xchg esi, eax
L_0001a18a:
    mov ah, byte ptr [edi]
    stosb
    dec ecx
    jne short L_0001a18a
L_0001a190:
    xchg esi, eax
L_0001a191:
    db 08ah, 0e3h    ; mov ah, bl (WASM encodes it differently)
    out dx, ax
    xchg esi, eax
    mov ah, byte ptr [edi]
    stosb
    jmp short L_0001a209
    nop
L_0001a19c:
    mov eax, dword ptr [ebp + 0x18]
L_0001a19f:
    mov ah, byte ptr [edi]
    mov byte ptr [edi], al
    xchg dword ptr [DAT_00032b51], eax
    shl ah, 1
    and ah, 0xf
    db 00ah, 0e4h    ; or ah, ah (WASM encodes it differently)
    jne short L_0001a1b5
    mov ah, 1
    inc edi
L_0001a1b5:
    out dx, ax
    xchg dword ptr [DAT_00032b51], eax
    db 00bh, 0f6h    ; or esi, esi (WASM encodes it differently)
    jns short L_0001a1c9
    add esi, dword ptr [ebp - 4]
    dec ecx
    jne short L_0001a19f
    jmp short L_0001a209
L_0001a1c9:
    add esi, dword ptr [ebp - 8]
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    dec ecx
    jne short L_0001a19f
    jmp short L_0001a209
    nop
L_0001a1d4:
    mov eax, dword ptr [ebp + 0x18]
L_0001a1d7:
    mov ah, byte ptr [edi]
    mov byte ptr [edi], al
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    db 00bh, 0f6h    ; or esi, esi (WASM encodes it differently)
    jns short L_0001a1e9
    add esi, dword ptr [ebp - 4]
    dec ecx
    jne short L_0001a1d7
    jmp short L_0001a209
L_0001a1e9:
    xchg dword ptr [DAT_00032b51], eax
    shl ah, 1
    and ah, 0xf
    db 00ah, 0e4h    ; or ah, ah (WASM encodes it differently)
    jne short L_0001a1fb
    mov ah, 1
    inc edi
L_0001a1fb:
    out dx, ax
    xchg dword ptr [DAT_00032b51], eax
    org $
    add esi, dword ptr [ebp - 8]
    dec ecx
    jne short L_0001a1d7
L_0001a209:
    mov dx, 0x3ce
    mov ax, 3
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
FUN_0001a21c:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov ecx, dword ptr [ebp + 8]
    cmp cx, 0
    jl short L_0001a269
    mov edi, dword ptr [DAT_00032b49]
    db 08bh, 0f1h    ; mov esi, ecx (WASM encodes it differently)
    shr esi, 2
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov ecx, dword ptr [DAT_00032b4d]
    shl ecx, 4
    rep movsb
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001a269:
    neg ecx
    mov edi, dword ptr [DAT_00032b49]
    mov eax, dword ptr [DAT_00032b4d]
    org $
    shl eax, 4
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    dec edi
    shr ecx, 2
    db 08bh, 0f7h    ; mov esi, edi (WASM encodes it differently)
    db 02bh, 0f1h    ; sub esi, ecx (WASM encodes it differently)
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    std
    rep movsb
    cld
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
FUN_0001a2b0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 8]
    cmp dx, 0
    jl short L_0001a308
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
    call L_0001aea8
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    mov edi, dword ptr [DAT_00032b49]
    mov ebx, dword ptr [DAT_00032b41]
    mul ebx
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    cld
    rep movsb
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001a308:
    neg edx
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
    call L_0001aea8
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    mov edx, dword ptr [DAT_00032b45]
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    dec esi
    dec edi
    mov ebx, dword ptr [DAT_00032b41]
    org $
    mul ebx
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    std
    rep movsb
    cld
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001a35c
FUN_0001a35c:
    enter 0, 0
    mov eax, dword ptr [ebp + 8]
    call L_0001aedc
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0001a36c
FUN_0001a36c:
    enter 0, 0
    push edx
    push ebx
    mov eax, dword ptr [ebp + 8]
    mov edx, dword ptr [DAT_00032b4d]
    org $
    shr edx, 4
    mul edx
    db 08ah, 0f8h    ; mov bh, al (WASM encodes it differently)
    db 032h, 0dbh    ; xor bl, bl (WASM encodes it differently)
    call L_0001af64
    pop ebx
    pop edx
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001a390
FUN_0001a390:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 8]
    mov edx, dword ptr [DAT_00032b4d]
    mul edx
    add eax, 0xa000
    shl eax, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov esi, dword ptr [DAT_00032b49]
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov ecx, dword ptr [DAT_00032b4d]
    org $
    shl cx, 4
    rep movsb
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001a3e8
FUN_0001a3e8:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0001aea8
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    add dword ptr [ebp + 0x20], ecx
    mov eax, dword ptr [ebp + 8]
    mov ah, byte ptr [DAT_00032b31]
    call L_0001aedc
    push dword ptr [DAT_00032b41]
    mov edx, dword ptr [ebp + 0x14]
    mov ecx, dword ptr [ebp + 0x18]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    db 08ah, 0c4h    ; mov al, ah (WASM encodes it differently)
    call L_0001aedc
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov edx, dword ptr [ebp + 0x20]
    add edx, 3
    shr edx, 2
    mov eax, dword ptr [ebp + 0x1c]
    pop ebx
    db 02bh, 0dah    ; sub ebx, edx (WASM encodes it differently)
    push ebp
    mov ebp, dword ptr [DAT_00032b41]
    db 02bh, 0eah    ; sub ebp, edx (WASM encodes it differently)
    cld
L_0001a456:
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
    rep movsb
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    db 003h, 0f5h    ; add esi, ebp (WASM encodes it differently)
    dec eax
    jne short L_0001a456
    pop ebp
    mov dx, 0x3ce
    mov ax, 0x4005
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_0001a474
FUN_0001a474:
    enter 0, 0
    push ecx
    mov ecx, dword ptr [ebp + 8]
    call L_0001af80
    pop ecx
    leave
    ret
; ---- FUN_0001a484
FUN_0001a484:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov ebx, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x18]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    mov edi, dword ptr [ebp + 8]
    push ebx
    push esi
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08bh, 0d9h    ; mov ebx, ecx (WASM encodes it differently)
    call L_0001aea8
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    pop ebx
    db 003h, 0d9h    ; add ebx, ecx (WASM encodes it differently)
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    add edx, 3
    shr edx, 2
    pop ecx
    mov ebx, dword ptr [DAT_00032b41]
    db 02bh, 0dah    ; sub ebx, edx (WASM encodes it differently)
    cld
    mov ax, 4
L_0001a4c2:
    push ecx
    push esi
    push edx
    mov dx, 0x3ce
    out dx, ax
    pop edx
L_0001a4cc:
    push ecx
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
    rep movsb
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    pop ecx
    dec ecx
    jne short L_0001a4cc
    pop esi
    pop ecx
    inc ah
    cmp ah, 4
    jl short L_0001a4c2
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_0001a4e8
FUN_0001a4e8:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov ebx, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x18]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    mov edi, dword ptr [ebp + 8]
    push ebx
    push esi
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08bh, 0d9h    ; mov ebx, ecx (WASM encodes it differently)
    call L_0001aea8
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    xchg edi, esi
    pop ebx
    db 003h, 0d9h    ; add ebx, ecx (WASM encodes it differently)
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    add edx, 3
    shr edx, 2
    pop ecx
    mov ebx, dword ptr [DAT_00032b41]
    org 0c35h
    pop edi
    pop ecx
    pop edx
    dec edx
    je short L_0001a8ec
    rol ah, 1
    adc edi, 0
    push edx
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    pop edx
    jmp short L_0001a8b1
L_0001a8ec:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001a8f4
FUN_0001a8f4:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0x18]
    mov dword ptr [L_0001a97b], eax
    mov dword ptr [L_0001a9e2], eax
    org $
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    mov ebx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 0x14]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    shl ah, cl
    push eax
    movzx eax, word ptr [esi + 4]
    push eax
    movzx eax, byte ptr [esi + 6]
    push eax
    movzx eax, byte ptr [esi + 7]
    push eax
    movzx eax, word ptr [esi]
    mul edx
    add eax, 8
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    pop ebx
    test bl, 0x80
    jne short L_0001a9a8
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_00032b41]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    shr ebx, 1
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov dx, 0x3c4
    out dx, ax
    mov bh, 4
L_0001a967:
    push edi
    push ecx
    push ebx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0001a96e:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
    shl cx, 1
    push bx
L_0001a975:
    lodsb
    movzx ebx, al
    db 08ah, 083h
L_0001a97b:
    db 078h, 056h, 034h, 012h
    stosb
    dec ecx
    jne short L_0001a975
    pop bx
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0001a96e
    pop ebx
    pop ecx
    pop edi
    dec bh
    je short L_0001a9a0
    rol ah, 1
    adc edi, 0
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    jmp short L_0001a967
L_0001a9a0:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001a9a8:
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_00032b41]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov bh, byte ptr [esi]
    inc esi
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_00032b51], ecx
    mov dx, 4
L_0001a9cb:
    push dx
    push cx
    push edi
    db 066h, 08bh, 0d1h    ; mov dx, cx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0001a9d5:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
L_0001a9d7:
    cmp byte ptr [esi], bh
    je short L_0001a9ed
    push ebx
    lodsb
    movzx ebx, al
    db 08ah, 083h
L_0001a9e2:
    db 078h, 056h, 034h, 012h
    stosb
    pop ebx
    dec ecx
    jne short L_0001a9d7
    jmp short L_0001a9f2
L_0001a9ed:
    inc edi
    inc esi
    dec ecx
    jne short L_0001a9d7
L_0001a9f2:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec dx
    jne short L_0001a9d5
    mov ecx, dword ptr [DAT_00032b51]
    pop edi
    pop cx
    pop dx
    dec dx
    je short L_0001aa18
    rol ah, 1
    adc edi, 0
    push edx
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    pop edx
    jmp short L_0001a9cb
L_0001aa18:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001aa20
FUN_0001aa20:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edi, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x18]
    mov dword ptr [DAT_00032b71], 0
    mov dword ptr [DAT_00032b75], 0
    mov eax, dword ptr [edi]
    shr eax, 2
    mov dword ptr [DAT_00032b55], eax
    org 0baah
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    shr ebx, 1
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov dx, 0x3c4
    out dx, ax
    mov bh, 4
L_0001a85b:
    push edi
    push ecx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
L_0001a85f:
    movzx ecx, bl
    shl ecx, 1
L_0001a864:
    lodsb
    db 02ch
L_0001a866:
    db 000h
    stosb
    dec ecx
    jne short L_0001a864
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0001a85f
    pop ecx
    pop edi
    dec bh
    je short L_0001a885
    rol ah, 1
    adc edi, 0
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    jmp short L_0001a85b
L_0001a885:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001a88d:
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_00032b41]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov bh, byte ptr [esi]
    inc esi
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_00032b51], ecx
    mov edx, 4
L_0001a8b1:
    push edx
    push ecx
    push edi
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
L_0001a8b6:
    movzx ecx, bl
L_0001a8b9:
    lodsb
    db 03ah, 0c7h    ; cmp al, bh (WASM encodes it differently)
    je short L_0001a8c6
    db 02ch
L_0001a8bf:
    db 000h
    stosb
    dec ecx
    jne short L_0001a8b9
    jmp short L_0001a8ca
L_0001a8c6:
    inc edi
    dec ecx
    jne short L_0001a8b9
L_0001a8ca:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0001a8b6
    mov ecx, dword ptr [DAT_00032b51]
    org 0b2ah
    pop edi
    pop dx
    dec dx
    je short L_0001a7e0
    rol ah, 1
    adc edi, 0
    push edx
    mov dx, 0x3c4
    out dx, ax
    pop edx
    jmp short L_0001a7a5
L_0001a7e0:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
FUN_0001a7e8:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0x18]
    mov byte ptr [L_0001a866], al
    mov byte ptr [L_0001a8bf], al
    org $
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    mov ebx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 0x14]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    shl ah, cl
    push eax
    movzx eax, word ptr [esi + 4]
    push eax
    movzx eax, byte ptr [esi + 6]
    push eax
    movzx eax, byte ptr [esi + 7]
    push eax
    movzx eax, word ptr [esi]
    mul edx
    add eax, 8
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    pop ebx
    test bl, 0x80
    jne short L_0001a88d
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_00032b41]
    org 0881h
    db 02bh, 0dah    ; sub ebx, edx (WASM encodes it differently)
    cld
    mov ax, 0x102
L_0001a528:
    push ecx
    push edi
    push edx
    mov dx, 0x3c4
    out dx, ax
    pop edx
L_0001a532:
    push ecx
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
    rep movsb
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    pop ecx
    dec ecx
    jne short L_0001a532
    pop edi
    pop ecx
    shl ah, 1
    cmp ah, 0x10
    jl short L_0001a528
    mov dx, 0x3c4
    mov ah, 0xff
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001a558
FUN_0001a558:
    enter 0, 0
    push edx
    mov eax, dword ptr [ebp + 0xc]
    mov edx, dword ptr [ebp + 0x10]
    mul edx
    mov edx, dword ptr [ebp + 8]
    mul edx
    shl eax, 3
    cmp dword ptr [ebp + 0x18], 0xff
    je short L_0001a579
    add eax, dword ptr [ebp + 8]
L_0001a579:
    pop edx
    leave
    ret
; ---- FUN_0001a57c
FUN_0001a57c:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov esi, dword ptr [ebp + 0x10]
    mov edi, dword ptr [ebp + 0x14]
    mov ecx, dword ptr [ebp + 0xc]
    mov edx, dword ptr [ebp + 8]
    movzx eax, word ptr [edi]
    mul edx
    add eax, 8
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp + 0x18]
    cmp al, 0xff
    je short L_0001a5a5
    mov byte ptr [edi], al
    inc edi
L_0001a5a5:
    shr ecx, 2
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    dec eax
L_0001a5ab:
    db 08bh, 0dfh    ; mov ebx, edi (WASM encodes it differently)
    movsb
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    movsb
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    movsb
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    movsb
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    inc edi
    dec ecx
    jne short L_0001a5ab
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0001a5c8
FUN_0001a5c8:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov esi, dword ptr [ebp + 0xc]
    mov edx, dword ptr [ebp + 8]
    movzx eax, word ptr [esi]
    mul edx
    add eax, 8
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov ax, word ptr [esi + 4]
    movzx dx, byte ptr [esi + 6]
    shl dl, 1
    mov bl, byte ptr [esi + 7]
    db 08bh, 0f7h    ; mov esi, edi (WASM encodes it differently)
    test bl, 0x80
    je short L_0001a5f9
    inc esi
L_0001a5f9:
    push ax
    push dx
    mul dx
    movzx ebx, ax
    pop dx
    pop ax
    push ebx
    push esi
    db 066h, 08bh, 0cbh    ; mov cx, bx (WASM encodes it differently)
    shl bx, 1
    db 066h, 003h, 0d9h    ; add bx, cx (WASM encodes it differently)
    db 066h, 08bh, 0cah    ; mov cx, dx (WASM encodes it differently)
    dec cx
    db 066h, 003h, 0d9h    ; add bx, cx (WASM encodes it differently)
    db 066h, 08bh, 0c8h    ; mov cx, ax (WASM encodes it differently)
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    push ax
L_0001a623:
    push cx
    db 066h, 08bh, 0cah    ; mov cx, dx (WASM encodes it differently)
L_0001a628:
    mov al, byte ptr [esi]
    xchg byte ptr [edi], al
    mov byte ptr [esi], al
    dec edi
    inc esi
    dec cx
    jne short L_0001a628
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    pop cx
    dec cx
    jne short L_0001a623
    pop ax
    pop esi
    pop ebx
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    db 066h, 08bh, 0cah    ; mov cx, dx (WASM encodes it differently)
    dec cx
    db 066h, 003h, 0d9h    ; add bx, cx (WASM encodes it differently)
    db 066h, 08bh, 0c8h    ; mov cx, ax (WASM encodes it differently)
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
L_0001a653:
    push cx
    db 066h, 08bh, 0cah    ; mov cx, dx (WASM encodes it differently)
L_0001a658:
    mov al, byte ptr [esi]
    xchg byte ptr [edi], al
    mov byte ptr [esi], al
    dec edi
    inc esi
    dec cx
    jne short L_0001a658
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    pop cx
    dec cx
    jne short L_0001a653
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
FUN_0001a678:
    enter 0x10, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov esi, dword ptr [ebp + 0xc]
    mov edx, dword ptr [ebp + 8]
    movzx eax, word ptr [esi]
    mul edx
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    add edi, 8
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    movzx eax, word ptr [esi + 4]
    mov dword ptr [ebp - 4], eax
    movzx edx, byte ptr [esi + 6]
    mov dword ptr [ebp - 8], edx
    mov bl, byte ptr [esi + 7]
    db 08bh, 0f7h    ; mov esi, edi (WASM encodes it differently)
    mov dword ptr [ebp - 0x10], 4
    test bl, 0x80
    je short L_0001a6b3
    inc esi
L_0001a6b3:
    dec eax
    mul edx
    shl eax, 1
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov edx, dword ptr [ebp - 8]
    shl edx, 1
L_0001a6bf:
    push esi
    mov ecx, dword ptr [ebp - 4]
    shr ecx, 1
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
L_0001a6c9:
    push ecx
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
L_0001a6cc:
    mov al, byte ptr [esi]
    xchg byte ptr [edi], al
    mov byte ptr [esi], al
    inc edi
    inc esi
    dec ecx
    jne short L_0001a6cc
    pop ecx
    db 02bh, 0fah    ; sub edi, edx (WASM encodes it differently)
    db 02bh, 0fah    ; sub edi, edx (WASM encodes it differently)
    dec ecx
    jne short L_0001a6c9
    pop esi
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    db 003h, 0f2h    ; add esi, edx (WASM encodes it differently)
    dec dword ptr [ebp - 0x10]
    jne short L_0001a6bf
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001a6f0
FUN_0001a6f0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    mov ebx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 0x14]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    shl ah, cl
    push eax
    movzx eax, word ptr [esi + 4]
    push eax
    movzx eax, byte ptr [esi + 6]
    push eax
    movzx eax, byte ptr [esi + 7]
    push eax
    movzx eax, word ptr [esi]
    mul edx
    add eax, 8
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    pop ebx
    test bl, 0x80
    jne short L_0001a781
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_00032b41]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    shr ebx, 1
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov dx, 0x3c4
    out dx, ax
    mov bh, 4
L_0001a756:
    push edi
    push ecx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0001a75c:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
    rep movsw
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0001a75c
    pop ecx
    pop edi
    dec bh
    je short L_0001a779
    rol ah, 1
    adc edi, 0
    mov dx, 0x3c4
    out dx, ax
    jmp short L_0001a756
L_0001a779:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001a781:
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_00032b41]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov bh, byte ptr [esi]
    inc esi
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_00032b51], ecx
    mov dx, 4
L_0001a7a5:
    push dx
    push edi
    db 066h, 08bh, 0d1h    ; mov dx, cx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0001a7ad:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
L_0001a7af:
    cmp byte ptr [esi], bh
    je short L_0001a7b9
    movsb
    dec ecx
    jne short L_0001a7af
    jmp short L_0001a7be
L_0001a7b9:
    inc edi
    inc esi
    dec ecx
    jne short L_0001a7af
L_0001a7be:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec dx
    jne short L_0001a7ad
    mov ecx, dword ptr [DAT_00032b51]
    org 01072h
    mov dword ptr [DAT_00032b79], 4
    pop ebx
    shr ebx, 2
    pop eax
    mov edx, dword ptr [DAT_00032b75]
    cmp edx, 0
    je short L_0001ad37
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    dec edx
    dec dword ptr [DAT_00032b79]
    rol ah, 1
L_0001ad37:
    mov ecx, dword ptr [DAT_00032b5d]
    mov edx, dword ptr [DAT_00032b41]
    sub edx, dword ptr [DAT_00032b69]
    sub edx, dword ptr [DAT_00032b65]
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_00032b51], ecx
    mov edx, dword ptr [DAT_00032b79]
L_0001ad64:
    push edi
    push edx
    db 066h, 08bh, 0d1h    ; mov dx, cx (WASM encodes it differently)
    add esi, dword ptr [DAT_00032b55]
L_0001ad6f:
    mov ecx, dword ptr [DAT_00032b69]
    add esi, dword ptr [DAT_00032b61]
L_0001ad7b:
    db 080h, 03eh
L_0001ad7d:
    db 004h
    je short L_0001ad89
    lodsb
    db 02ch
L_0001ad82:
    db 003h
    stosb
    dec ecx
    jne short L_0001ad7b
    jmp short L_0001ad8e
L_0001ad89:
    inc edi
    inc esi
    dec ecx
    jne short L_0001ad7b
L_0001ad8e:
    mov ecx, dword ptr [DAT_00032b65]
    db 003h, 0f9h    ; add edi, ecx (WASM encodes it differently)
    db 003h, 0f1h    ; add esi, ecx (WASM encodes it differently)
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0001ad6f
    mov ecx, dword ptr [DAT_00032b51]
    pop edx
    pop edi
    add esi, dword ptr [DAT_00032b59]
    dec edx
    je short L_0001ae03
    rol ah, 1
    jae short L_0001adf4
    inc edi
    cmp dword ptr [DAT_00032b61], 0
    je short L_0001addd
    dec dword ptr [DAT_00032b61]
    dec ebp
    dec edi
    cmp dword ptr [DAT_00032b71], 0
    je short L_0001add5
    inc dword ptr [DAT_00032b65]
    jmp short L_0001adf4
L_0001add5:
    inc dword ptr [DAT_00032b69]
    jmp short L_0001adf4
L_0001addd:
    cmp dword ptr [DAT_00032b71], 0
    je short L_0001adf4
    inc dword ptr [DAT_00032b65]
    dec dword ptr [DAT_00032b69]
    org 0f95h
    mov edi, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x18]
    mov eax, dword ptr [edi]
    shr eax, 2
    mov dword ptr [DAT_00032b55], eax
    mov eax, dword ptr [edi + 4]
    shr eax, 2
    mov dword ptr [DAT_00032b59], eax
    mov eax, dword ptr [edi + 8]
    mov dword ptr [DAT_00032b5d], eax
    mov eax, dword ptr [edi + 0xc]
    add eax, 3
    shr eax, 2
    mov dword ptr [DAT_00032b61], eax
    mov eax, dword ptr [edi + 0x10]
    and eax, 3
    mov dword ptr [DAT_00032b6d], eax
    mov eax, dword ptr [edi + 0x10]
    cmp eax, 0
    je short L_0001ac86
    mov dword ptr [DAT_00032b71], 1
    shr eax, 2
L_0001ac86:
    mov dword ptr [DAT_00032b65], eax
    mov eax, dword ptr [edi + 0x14]
    add eax, dword ptr [DAT_00032b6d]
    shr eax, 2
    jne short L_0001acbf
    mov eax, 1
    cmp dword ptr [DAT_00032b71], 1
    je short L_0001acbf
    mov eax, 4
    sub eax, dword ptr [edi + 0x14]
    mov dword ptr [DAT_00032b75], eax
    dec dword ptr [DAT_00032b61]
    mov eax, 1
L_0001acbf:
    mov dword ptr [DAT_00032b69], eax
    mov eax, dword ptr [edi + 0xc]
    and eax, 3
    mov dword ptr [DAT_00032b6d], eax
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    add ecx, 4
    sub ecx, dword ptr [DAT_00032b6d]
    org $
    and ecx, 3
    shl ah, cl
    push eax
    movzx eax, word ptr [esi]
    push eax
    mov cl, byte ptr [esi + 7]
    mul edx
    add eax, 8
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    mov dh, 0xff
    test cl, 0x80
    jne short L_0001ad09
    jmp short L_0001ad0c
L_0001ad09:
    mov dh, byte ptr [esi]
    inc esi
L_0001ad0c:
    mov byte ptr [L_0001ad7d], dh
    org 0f58h
    je short L_0001ac07
L_0001abfa:
    push edx
    mov dx, 0x3c4
    out dx, ax
    pop edx
    jmp near ptr L_0001ab6e
L_0001ac07:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
FUN_0001ac10:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0x1c]
    mov byte ptr [L_0001ad82], al
    org 0e54h
    and ecx, 3
    rol ah, cl
    push eax
    movzx eax, word ptr [esi]
    push eax
    mov cl, byte ptr [esi + 7]
    mul edx
    add eax, 8
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    mov dh, 0xff
    test cl, 0x80
    jne short L_0001ab11
    jmp short L_0001ab14
L_0001ab11:
    mov dh, byte ptr [esi]
    inc esi
L_0001ab14:
    mov byte ptr [L_0001ab86], dh
    org 0f81h
    mov dword ptr [DAT_00032b71], 0
    mov dword ptr [DAT_00032b75], 0
    org 0e7ah
    mov dword ptr [DAT_00032b79], 4
    pop ebx
    shr ebx, 2
    pop eax
    mov edx, dword ptr [DAT_00032b75]
L_0001ab2f:
    cmp edx, 0
    je short L_0001ab41
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    dec edx
    dec dword ptr [DAT_00032b79]
    rol ah, 1
    jmp short L_0001ab2f
L_0001ab41:
    mov ecx, dword ptr [DAT_00032b5d]
    mov edx, dword ptr [DAT_00032b41]
    sub edx, dword ptr [DAT_00032b69]
    sub edx, dword ptr [DAT_00032b65]
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_00032b51], ecx
    mov edx, dword ptr [DAT_00032b79]
L_0001ab6e:
    push edi
    push edx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
    add esi, dword ptr [DAT_00032b55]
L_0001ab78:
    mov ecx, dword ptr [DAT_00032b69]
    add esi, dword ptr [DAT_00032b61]
L_0001ab84:
    db 080h, 03eh
L_0001ab86:
    db 004h
    je short L_0001ab8f
    movsb
    dec ecx
    jne short L_0001ab84
    jmp short L_0001ab94
L_0001ab8f:
    inc edi
    inc esi
    dec ecx
    jne short L_0001ab84
L_0001ab94:
    mov ecx, dword ptr [DAT_00032b65]
    db 003h, 0f9h    ; add edi, ecx (WASM encodes it differently)
    db 003h, 0f1h    ; add esi, ecx (WASM encodes it differently)
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0001ab78
    mov ecx, dword ptr [DAT_00032b51]
    pop edx
    pop edi
    add esi, dword ptr [DAT_00032b59]
    dec edx
    je short L_0001ac07
    rol ah, 1
    jae short L_0001abfa
    inc edi
    cmp dword ptr [DAT_00032b61], 0
    je short L_0001abe3
    dec dword ptr [DAT_00032b61]
    dec ebp
    dec edi
    cmp dword ptr [DAT_00032b71], 0
    je short L_0001abdb
    inc dword ptr [DAT_00032b65]
    jmp short L_0001abfa
L_0001abdb:
    inc dword ptr [DAT_00032b69]
    jmp short L_0001abfa
L_0001abe3:
    cmp dword ptr [DAT_00032b71], 0
    je short L_0001abfa
    inc dword ptr [DAT_00032b65]
    dec dword ptr [DAT_00032b69]
    org 0dadh
    mov eax, dword ptr [edi + 4]
    shr eax, 2
    mov dword ptr [DAT_00032b59], eax
    mov eax, dword ptr [edi + 8]
    mov dword ptr [DAT_00032b5d], eax
    mov eax, dword ptr [edi + 0xc]
    add eax, 3
    shr eax, 2
    mov dword ptr [DAT_00032b61], eax
    mov eax, dword ptr [edi + 0x10]
    and eax, 3
    mov dword ptr [DAT_00032b6d], eax
    mov eax, dword ptr [edi + 0x10]
    cmp eax, 0
    je short L_0001aa8e
    mov dword ptr [DAT_00032b71], 1
    shr eax, 2
L_0001aa8e:
    mov dword ptr [DAT_00032b65], eax
    mov eax, dword ptr [edi + 0x14]
    add eax, dword ptr [DAT_00032b6d]
    shr eax, 2
    jne short L_0001aac7
    mov eax, 1
    cmp dword ptr [DAT_00032b71], 1
    je short L_0001aac7
    mov eax, 4
    sub eax, dword ptr [edi + 0x14]
    mov dword ptr [DAT_00032b75], eax
    dec dword ptr [DAT_00032b61]
    mov eax, 1
L_0001aac7:
    mov dword ptr [DAT_00032b69], eax
    mov eax, dword ptr [edi + 0xc]
    and eax, 3
    mov dword ptr [DAT_00032b6d], eax
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0001aea8
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    add ecx, 4
    sub ecx, dword ptr [DAT_00032b6d]
    org 01152h
    je short L_0001ae03
L_0001adf4:
    push edx
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    pop edx
    jmp near ptr L_0001ad64
L_0001ae03:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
FUN_0001ae0c:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov esi, dword ptr [ebp + 0x10]
    mov ebx, dword ptr [ebp + 0xc]
    mov edx, dword ptr [ebp + 8]
    movzx eax, word ptr [esi]
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mul edx
    add eax, 8
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov al, byte ptr [esi + 7]
    test al, 0x80
    je short L_0001ae4a
    mov ah, byte ptr [edi]
    inc edi
L_0001ae36:
    mov al, byte ptr [edi]
    db 03ah, 0c4h    ; cmp al, ah (WASM encodes it differently)
    je short L_0001ae3f
    db 0d7h    ; xlatb  (not transcribed)
    mov byte ptr [edi], al
L_0001ae3f:
    inc edi
    dec ecx
    jne short L_0001ae36
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001ae4a:
    mov al, byte ptr [edi]
    db 0d7h    ; xlatb  (not transcribed)
    mov byte ptr [edi], al
    inc edi
    dec ecx
    jne short L_0001ae4a
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov ebx, dword ptr [ebp + 0xc]
    movzx eax, word ptr [esi]
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    mul edx
    add eax, 8
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov al, byte ptr [esi + 7]
    test al, 0x80
    je short L_0001ae95
    mov ah, byte ptr [edi]
    inc edi
L_0001ae80:
    mov al, byte ptr [edi]
    db 03ah, 0c4h    ; cmp al, ah (WASM encodes it differently)
    je short L_0001ae8a
    db 02ah, 0c3h    ; sub al, bl (WASM encodes it differently)
    mov byte ptr [edi], al
L_0001ae8a:
    inc edi
    dec ecx
    jne short L_0001ae80
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0001ae95:
    mov al, byte ptr [edi]
    db 02ah, 0c3h    ; sub al, bl (WASM encodes it differently)
    mov byte ptr [edi], al
    inc edi
    dec ecx
    jne short L_0001ae95
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0001aea8
L_0001aea8:
FUN_0001aea8:
    push esi
    push eax
    mov ebx, 0
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08bh, 0f1h    ; mov esi, ecx (WASM encodes it differently)
    mov ecx, dword ptr [DAT_00032b35]
    shl eax, cl
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov ecx, dword ptr [DAT_00032b39]
    shl eax, cl
    db 003h, 0d8h    ; add ebx, eax (WASM encodes it differently)
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
    shr eax, 2
    db 003h, 0d8h    ; add ebx, eax (WASM encodes it differently)
    db 08bh, 0ceh    ; mov ecx, esi (WASM encodes it differently)
    and ecx, 3
    add ebx, dword ptr [DAT_00032b49]
    pop eax
    pop esi
    ret
; ---- FUN_0001aedc
L_0001aedc:
    push eax
    push edx
    and eax, 0xff
    mov dword ptr [DAT_00032b31], eax
    mov eax, dword ptr [DAT_00032b31]
    mov edx, dword ptr [DAT_00032b4d]
    mul edx
    add eax, 0xa000
    shl eax, 4
    mov dword ptr [DAT_00032b49], eax
    org $
    pop edx
    pop eax
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001af08
L_0001af08:
    cmp dword ptr [DAT_00032b29], 0
    jne short L_0001af33
    push edi
    push ecx
    push edx
    mov dx, 0x3c4
    mov ah, 0xf
    mov al, 2
    out dx, ax
    mov edi, 0xa0000
    mov eax, 0
    mov ecx, 0x4000
    cld
    rep stosd
    pop edx
    pop ecx
    pop edi
L_0001af33:
    ret
; ---- FUN_0001af34
L_0001af34:
    push dx
    push ax
    mov dx, 0x3da
L_0001af3c:
    in al, dx
    test al, 8
    jne short L_0001af3c
L_0001af41:
    in al, dx
    test al, 8
    je short L_0001af41
    pop ax
    pop dx
    ret
    nop
    push dx
    push ax
    mov dx, 0x3da
L_0001af54:
    in al, dx
    test al, 8
    je short L_0001af54
L_0001af59:
    in al, dx
    test al, 8
    jne short L_0001af59
    pop ax
    pop dx
    ret
    nop
; ---- FUN_0001af64
L_0001af64:
    push edx
    push ebx
    cli
    mov dx, 0x3d4
    db 08ah, 0e7h    ; mov ah, bh (WASM encodes it differently)
    mov al, 0xc
    out dx, ax
    db 08ah, 0e3h    ; mov ah, bl (WASM encodes it differently)
    inc al
    out dx, ax
    sti
    call L_0001af34
    pop ebx
    pop edx
    ret
; ---- FUN_0001af80
L_0001af80:
    push edx
    push ecx
    push ebx
    mov dword ptr [DAT_00032b3d], ecx
    call L_0001af34
    mov dx, 0x3d4
    db 066h, 08bh, 0c1h    ; mov ax, cx (WASM encodes it differently)
    shl ax, 1
    db 08ah, 0fch    ; mov bh, ah (WASM encodes it differently)
    db 08ah, 0dfh    ; mov bl, bh (WASM encodes it differently)
    and bx, 0x201
    mov cl, 4
    shl bx, cl
    shl bh, 1
    db 08ah, 0e0h    ; mov ah, al (WASM encodes it differently)
    mov al, 0x18
    out dx, ax
    mov al, 7
    out dx, al
    inc dx
    in al, dx
    dec dx
    db 08ah, 0e0h    ; mov ah, al (WASM encodes it differently)
    and ah, 0xef
    db 00ah, 0e3h    ; or ah, bl (WASM encodes it differently)
    mov al, 7
    out dx, ax
    mov al, 9
    out dx, al
    inc dx
    in al, dx
    dec dx
    db 08ah, 0e0h    ; mov ah, al (WASM encodes it differently)
    and ah, 0xbf
    db 00ah, 0e7h    ; or ah, bh (WASM encodes it differently)
    mov al, 9
    out dx, ax
    pop ebx
    pop ecx
    pop edx
    ret
_TEXT ends
end
