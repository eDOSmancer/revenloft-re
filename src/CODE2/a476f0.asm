; a476f0.asm - assembler module of CODE.2 (616 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn FUN_0003f9e4:near
extrn FUN_0003fa30:near
extrn DAT_0007b6c2:byte
_DATA segment dword public use32 'DATA'
DAT_00060604 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 00060604  ............
DAT_00060610 label byte
    db 8212 dup(0)    ; 00060610
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_000476f0
public FUN_00047700
public FUN_00047810
; ---- FUN_000476f0
FUN_000476f0:
    ret
    db 15 dup(0)
FUN_00047700:
    enter 6, 0
    pushad
    cld
    mov ebx, 0
    mov edi, offset DAT_00060610
    mov al, 0xfe
    mov ecx, 0xfee
    rep stosb
    mov ax, 0xfee
    mov word ptr [ebp - 6], ax
    db 066h, 033h, 0f6h    ; xor si, si (WASM encodes it differently)
L_00047724:
    shr si, 1
    test si, 0x100
    jne short L_00047746
    cmp byte ptr [DAT_0007b6c2], 1
    jne short L_0004773c
    jmp near ptr L_0004780a
L_0004773c:
    call FUN_0003f9e4
    mov ah, 0xff
    db 066h, 08bh, 0f0h    ; mov si, ax (WASM encodes it differently)
L_00047746:
    test si, 1
    je short L_00047785
    cmp byte ptr [DAT_0007b6c2], 1
    jne short L_0004775b
    jmp near ptr L_0004780a
L_0004775b:
    call FUN_0003f9e4
    db 032h, 0e4h    ; xor ah, ah (WASM encodes it differently)
    push ax
    call FUN_0003fa30
    pop ax
    mov bx, word ptr [ebp - 6]
    mov byte ptr [ebx + DAT_00060610], al
    inc bx
    and bx, 0xfff
    mov word ptr [ebp - 6], bx
    jmp near ptr L_00047805
L_00047785:
    cmp byte ptr [DAT_0007b6c2], 1
    je short L_0004780a
    call FUN_0003f9e4
    mov word ptr [ebp - 2], ax
    cmp byte ptr [DAT_0007b6c2], 1
    je short L_0004780a
    call FUN_0003f9e4
    db 066h, 08bh, 0f8h    ; mov di, ax (WASM encodes it differently)
    and ax, 0xf0
    shl ax, 4
    or ax, word ptr [ebp - 2]
    mov word ptr [ebp - 2], ax
    and di, 0xf
    add di, 2
    db 066h, 033h, 0c9h    ; xor cx, cx (WASM encodes it differently)
    mov word ptr [ebp - 4], cx
L_000477c7:
    mov bx, word ptr [ebp - 2]
    add bx, word ptr [ebp - 4]
    and bx, 0xfff
    db 066h, 033h, 0c0h    ; xor ax, ax (WASM encodes it differently)
    mov al, byte ptr [ebx + DAT_00060610]
    push ax
    call FUN_0003fa30
    pop ax
    mov bx, word ptr [ebp - 6]
    mov byte ptr [ebx + DAT_00060610], al
    org $
    inc bx
    and bx, 0xfff
    mov word ptr [ebp - 6], bx
    inc word ptr [ebp - 4]
    cmp word ptr [ebp - 4], di
    jle short L_000477c7
L_00047805:
    jmp near ptr L_00047724
L_0004780a:
    popad
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00047810
FUN_00047810:
    enter 0x24, 0
    pushad
    mov edi, dword ptr [ebp + 8]
    cmp word ptr [edi + 4], 1
    je short L_00047824
    jmp near ptr L_00047955
L_00047824:
    mov dword ptr [ebp - 0x24], offset DAT_00060610
    mov dword ptr [ebp - 0x10], edi
    mov dword ptr [ebp - 0x18], edi
    add dword ptr [ebp - 0x10], 8
    add dword ptr [ebp - 0x18], 8
    test byte ptr [edi + 7], 0x80
    je short L_00047845
    inc dword ptr [ebp - 0x10]
    inc dword ptr [ebp - 0x18]
L_00047845:
    movzx eax, word ptr [edi]
    mov dword ptr [ebp - 8], eax
    movzx eax, byte ptr [edi + 6]
    shl eax, 1
    mov dword ptr [ebp - 4], eax
    mov eax, 4
    movzx ebx, word ptr [edi + 2]
    mul ebx
    mov dword ptr [ebp - 0xc], eax
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    shl eax, 1
    db 08bh, 0d0h    ; mov edx, eax (WASM encodes it differently)
    db 033h, 0dbh    ; xor ebx, ebx (WASM encodes it differently)
    db 033h, 0c0h    ; xor eax, eax (WASM encodes it differently)
L_0004786c:
    mov word ptr [ebx + DAT_00060610], ax
    add ebx, 8
    inc eax
    db 03bh, 0dah    ; cmp ebx, edx (WASM encodes it differently)
    jb short L_00047880
    db 02bh, 0dah    ; sub ebx, edx (WASM encodes it differently)
    add ebx, 2
L_00047880:
    dec ecx
    jne short L_0004786c
    dec dword ptr [ebp - 0xc]
    mov eax, dword ptr [ebp - 4]
    add dword ptr [ebp - 0x10], eax
    mov dword ptr [ebp - 0x1c], 1
L_00047893:
    mov edi, dword ptr [ebp - 0x24]
    mov eax, dword ptr [ebp - 0x1c]
    shl eax, 1
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    shr eax, 1
    mov bx, word ptr [edi]
    mov ecx, dword ptr [ebp - 0xc]
    push edi
    cmp ecx, 0
    je short L_000478b1
    repne scasw
    sub edi, 2
L_000478b1:
    mov ax, word ptr [edi]
    mov word ptr [edi], bx
    sub edi, offset DAT_00060610
    shr edi, 1
    mov dword ptr [ebp - 0x20], edi
    pop edi
    mov word ptr [edi], ax
    mov ecx, dword ptr [ebp - 4]
    mov edi, dword ptr [ebp - 0x18]
    mov eax, dword ptr [ebp - 0x1c]
    shr eax, 2
    mov ebx, dword ptr [ebp - 8]
    mul ebx
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp - 0x1c]
    and eax, 3
    mov ebx, dword ptr [ebp - 4]
    mul ebx
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    push edi
    mov esi, dword ptr [ebp - 0x18]
    mov eax, dword ptr [ebp - 0x20]
    shr eax, 2
    mov ebx, dword ptr [ebp - 8]
    mul ebx
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
    mov eax, dword ptr [ebp - 0x20]
    and eax, 3
    mov ebx, dword ptr [ebp - 4]
    mul ebx
    db 003h, 0f0h    ; add esi, eax (WASM encodes it differently)
L_00047904:
    mov al, byte ptr [edi]
    mov ah, byte ptr [esi]
    mov byte ptr [edi], ah
    mov byte ptr [esi], al
    inc edi
    inc esi
    dec ecx
    jne short L_00047904
    pop esi
    mov edi, dword ptr [ebp - 0x10]
    mov ecx, dword ptr [ebp - 4]
    rep movsb
    inc dword ptr [ebp - 0x1c]
    mov eax, dword ptr [ebp - 4]
    add dword ptr [ebp - 0x10], eax
    dec dword ptr [ebp - 0xc]
    je short L_0004792d
    jmp near ptr L_00047893
L_0004792d:
    mov edi, dword ptr [ebp + 8]
    mov ax, word ptr [edi + 2]
    mov word ptr [edi + 4], ax
    mov word ptr [edi + 2], 1
    db 066h, 033h, 0c0h    ; xor ax, ax (WASM encodes it differently)
    db 066h, 033h, 0dbh    ; xor bx, bx (WASM encodes it differently)
    mov ax, word ptr [edi + 4]
    mov bl, byte ptr [edi + 6]
    shl bx, 3
    mul bx
    mov word ptr [edi], ax
L_00047955:
    popad
    leave
    ret
_TEXT ends
end
