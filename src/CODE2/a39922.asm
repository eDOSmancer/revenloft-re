; a39922.asm - assembler module of CODE.2 (4920 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
_DATA segment dword public use32 'DATA'
public DAT_0005efe0
DAT_0005efe0 label byte
    db 000h    ; 0005efe0  .
DAT_0005efe1 label byte
    db 000h, 000h, 000h, 000h    ; 0005efe1  ....
DAT_0005efe5 label byte
    db 000h, 000h, 000h, 000h    ; 0005efe5  ....
DAT_0005efe9 label byte
    db 000h, 000h, 000h, 000h    ; 0005efe9  ....
DAT_0005efed label byte
    db 000h, 000h, 000h, 000h    ; 0005efed  ....
DAT_0005eff1 label byte
    db 000h, 000h, 000h, 000h    ; 0005eff1  ....
DAT_0005eff5 label byte
    db 000h, 000h, 000h, 000h    ; 0005eff5  ....
DAT_0005eff9 label byte
    db 000h, 000h, 000h, 000h    ; 0005eff9  ....
DAT_0005effd label byte
    db 000h, 000h, 000h, 000h    ; 0005effd  ....
DAT_0005f001 label byte
    db 000h, 000h, 000h, 000h    ; 0005f001  ....
DAT_0005f005 label byte
    db 000h, 000h, 000h, 000h    ; 0005f005  ....
DAT_0005f009 label byte
    db 000h, 000h, 000h, 000h    ; 0005f009  ....
DAT_0005f00d label byte
    db 000h, 000h, 000h, 000h    ; 0005f00d  ....
DAT_0005f011 label byte
    db 000h, 000h, 000h, 000h    ; 0005f011  ....
DAT_0005f015 label byte
    db 000h, 000h, 000h, 000h    ; 0005f015  ....
DAT_0005f019 label byte
    db 000h, 000h, 000h, 000h    ; 0005f019  ....
DAT_0005f01d label byte
    db 000h, 000h, 000h, 000h    ; 0005f01d  ....
DAT_0005f021 label byte
    db 000h, 000h, 000h, 000h    ; 0005f021  ....
DAT_0005f025 label byte
    db 000h, 000h, 000h, 000h    ; 0005f025  ....
DAT_0005f029 label byte
    db 000h, 000h, 000h, 000h    ; 0005f029  ....
DAT_0005f02d label byte
    db 000h, 000h, 000h, 000h    ; 0005f02d  ....
DAT_0005f031 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 0005f031  .......
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_00039930
public FUN_00039a84
public FUN_00039aa4
public FUN_00039b40
public FUN_00039ca0
public FUN_00039cec
public FUN_00039eac
public FUN_00039f40
public FUN_00039fec
public FUN_00039ffc
public FUN_0003a020
public FUN_0003a078
public FUN_0003a104
public FUN_0003a114
public FUN_0003a178
public FUN_0003a1e8
public FUN_0003a20c
public FUN_0003a258
public FUN_0003a308
public FUN_0003a380
public FUN_0003a478
public FUN_0003a584
public FUN_0003a6b0
public FUN_0003a8a0
public FUN_0003aa9c
; ---- FUN_00039930
FUN_00039930:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_0005efe1], eax
    and dword ptr [DAT_0005efe1], 0x80
    and eax, 0x7f
    mov dword ptr [DAT_0005efe5], eax
    mov dword ptr [DAT_0005eff5], 0xc8
    mov dword ptr [DAT_0005eff9], 0x50
    mov dword ptr [DAT_0005f001], 0xa0000
    mov dword ptr [DAT_0005efe9], 0
    mov byte ptr [DAT_0005efe0], 0
    mov dword ptr [DAT_0005f005], 0x400
    mov dword ptr [DAT_0005efed], 4
    mov dword ptr [DAT_0005eff1], 2
    call L_0003ab98
    cmp dword ptr [DAT_0005efe5], 3
    jne short L_000399b8
    mov dword ptr [DAT_0005f005], 0x800
L_000399b8:
    mov ah, 0xf
    int 0x10
    cmp al, 0x13
    je short L_000399c6
    mov ax, 0x13
    int 0x10
L_000399c6:
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_0005efe0]
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
    call L_0003ab98
    mov dx, 0x3d4
    mov al, 9
    out dx, al
    inc dx
    in al, dx
    cmp dword ptr [DAT_0005efe5], 3
    jne short L_00039a17
    and al, 0xe0
    jmp short L_00039a19
L_00039a17:
    mov al, 0x41
L_00039a19:
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
    call L_0003abf4
    mov ecx, 0xff
    call L_0003ac10
    mov ebx, 0xc8
    mov ecx, 0x140
    cmp dword ptr [DAT_0005efe5], 3
    jne short L_00039a56
    shl ebx, 1
L_00039a56:
    mov dword ptr [DAT_0005effd], ebx
    mov ax, 0x20d
    mov dword ptr [DAT_0005efe1], 0
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
; ---- FUN_00039a84
FUN_00039a84:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    call L_0003ab98
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
    jmp short L_00039b1c
    xchg ebx, ebx
; ---- FUN_00039aa4
FUN_00039aa4:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0003ab38
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
    mov ah, byte ptr [DAT_0005efe0]
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
    call L_0003ab38
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
L_00039b1c:
    enter 0, 0
    push ebx
    mov ebx, dword ptr [ebp + 8]
    mov al, byte ptr cs:[ebx + L_00039b33]
    org $
    mov byte ptr [DAT_0005efe0], al
    org $
    pop ebx
    leave
    ret
L_00039b33:
    add byte ptr [eax], cl
    adc byte ptr [eax], bl
L_00039b37:
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00039b40
FUN_00039b40:
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
    jle short L_00039b37
    cmp esi, 0
    jle short L_00039b37
    push eax
    push ebx
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08bh, 0d9h    ; mov ebx, ecx (WASM encodes it differently)
    call L_0003ab38
    mov dh, 0xf
    shl dh, cl
    db 032h, 0edh    ; xor ch, ch (WASM encodes it differently)
    dec esi
    xor cl, 3
    db 02bh, 0f1h    ; sub esi, ecx (WASM encodes it differently)
    jbe short L_00039b91
    dec esi
    db 08bh, 0ceh    ; mov ecx, esi (WASM encodes it differently)
    and ecx, 3
    db 02bh, 0f1h    ; sub esi, ecx (WASM encodes it differently)
    xor cl, 3
    mov dl, 0xf0
    sar dl, cl
    not dl
    shr esi, 2
    jmp short L_00039ba5
L_00039b91:
    add esi, 3
    db 08bh, 0ceh    ; mov ecx, esi (WASM encodes it differently)
    xor cl, 3
    mov dl, 0xf0
    sar dl, cl
    not dl
    db 022h, 0f2h    ; and dh, dl (WASM encodes it differently)
    db 032h, 0d2h    ; xor dl, dl (WASM encodes it differently)
    db 033h, 0f6h    ; xor esi, esi (WASM encodes it differently)
L_00039ba5:
    mov edi, dword ptr [DAT_0005eff9]
    db 02bh, 0feh    ; sub edi, esi (WASM encodes it differently)
    dec edi
    cmp dl, 0
    je short L_00039bb5
    dec di
L_00039bb5:
    pop ecx
    push edx
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_0005efe0]
    mov al, 3
    out dx, ax
    cmp ah, 0
    je short L_00039c40
    pop edx
    pop eax
    push ebp
    db 08bh, 0e9h    ; mov ebp, ecx (WASM encodes it differently)
    db 08ah, 0e8h    ; mov ch, al (WASM encodes it differently)
L_00039bd1:
    push edx
    db 066h, 08bh, 0c2h    ; mov ax, dx (WASM encodes it differently)
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], ch
    inc ebx
    cmp esi, 0
    je short L_00039bf8
    mov ax, 0xff02
    out dx, ax
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
L_00039bef:
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], ch
    inc ebx
    dec al
    jne short L_00039bef
L_00039bf8:
    pop edx
    cmp dl, 0
    je short L_00039c11
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
L_00039c11:
    db 003h, 0dfh    ; add ebx, edi (WASM encodes it differently)
    dec ebp
    jne short L_00039bd1
    pop ebp
    mov dx, 0x3ce
    mov ax, 3
    out dx, ax
    jmp short L_00039c97
    nop
L_00039c24:
    db 08bh, 0e8h    ; mov ebp, eax (WASM encodes it differently)
    mov ax, 0xff02
    out dx, ax
    mov eax, dword ptr [DAT_0005eff9]
    org 03d9h
    mov ecx, dword ptr [ebp + 0x14]
    sub ecx, dword ptr [ebp + 0xc]
    je short L_00039d84
    jns short L_00039d27
    neg ecx
    mov ebx, dword ptr [ebp + 0x14]
    xchg dword ptr [ebp + 0xc], ebx
    mov dword ptr [ebp + 0x14], ebx
    mov ebx, dword ptr [ebp + 0x10]
    xchg dword ptr [ebp + 8], ebx
    mov dword ptr [ebp + 0x10], ebx
L_00039d27:
    mov ebx, dword ptr [ebp + 0x10]
    sub ebx, dword ptr [ebp + 8]
    je near ptr L_00039dc0
    jns short L_00039d39
    neg ebx
    neg esi
L_00039d39:
    push esi
    mov dword ptr [ebp - 0xc], offset L_00039e2c
    db 03bh, 0d9h    ; cmp ebx, ecx (WASM encodes it differently)
    jle short L_00039d4e
    mov dword ptr [ebp - 0xc], offset L_00039e64
    org $
    xchg ecx, ebx
L_00039d4e:
    shl ebx, 1
    mov dword ptr [ebp - 4], ebx
    db 02bh, 0d9h    ; sub ebx, ecx (WASM encodes it differently)
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    db 02bh, 0d9h    ; sub ebx, ecx (WASM encodes it differently)
    mov dword ptr [ebp - 8], ebx
    push ecx
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0003ab38
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov al, 2
    mov ah, 1
    shl ah, cl
    mov dx, 0x3c4
    out dx, ax
    pop ecx
    inc ecx
    pop ebx
    xchg dword ptr [DAT_0005f009], eax
    org 0301h
    mul esi
    db 08bh, 0c8h    ; mov ecx, eax (WASM encodes it differently)
    shr ecx, 1
    db 08bh, 0c5h    ; mov eax, ebp (WASM encodes it differently)
    rep stosw
    pop ebp
    jmp short L_00039c97
    nop
L_00039c40:
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
    jne short L_00039c5d
    cmp ebx, 0xf0f
    je short L_00039c24
L_00039c5d:
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
    je short L_00039c81
    shr ecx, 1
    rep stosw
    db 013h, 0c9h    ; adc ecx, ecx (WASM encodes it differently)
    rep stosb
L_00039c81:
    cmp bl, 0
    je short L_00039c8f
    db 08ah, 0e3h    ; mov ah, bl (WASM encodes it differently)
    mov al, 2
    out dx, ax
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
    stosb
L_00039c8f:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    pop ecx
    pop esi
    dec esi
    jne short L_00039c5d
    pop ebp
L_00039c97:
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00039ca0
FUN_00039ca0:
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
L_00039cbd:
    call L_0003abc4
    cmp ebx, 0xc0
    jle short L_00039cd9
    mov ecx, 0xc0
    rep outsb
    sub ebx, 0xc0
    jmp short L_00039cbd
L_00039cd9:
    cmp ebx, 0
    je short L_00039ce2
    db 08bh, 0cbh    ; mov ecx, ebx (WASM encodes it differently)
    rep outsb
L_00039ce2:
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00039cec
FUN_00039cec:
    enter 0xc, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov dx, 0x3ce
    mov ah, byte ptr [DAT_0005efe0]
    mov al, 3
    out dx, ax
    mov esi, dword ptr [DAT_0005eff9]
    org 044fh
    jmp dword ptr [ebp - 0xc]
    xchg ebx, ebx
L_00039d84:
    mov eax, dword ptr [ebp + 8]
    mov ebx, dword ptr [ebp + 0x10]
    db 08bh, 0cbh    ; mov ecx, ebx (WASM encodes it differently)
    db 02bh, 0c8h    ; sub ecx, eax (WASM encodes it differently)
    jge short L_00039d94
    neg ecx
    db 08bh, 0c3h    ; mov eax, ebx (WASM encodes it differently)
L_00039d94:
    inc ecx
    push ecx
    db 08bh, 0d0h    ; mov edx, eax (WASM encodes it differently)
    mov ecx, dword ptr [ebp + 0xc]
    call L_0003ab38
    mov ah, 1
    shl ah, cl
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    pop ecx
    mov eax, dword ptr [ebp + 0x18]
L_00039db0:
    mov ah, byte ptr [ebx]
    mov byte ptr [ebx], al
    db 003h, 0deh    ; add ebx, esi (WASM encodes it differently)
    dec ecx
    jne short L_00039db0
    jmp near ptr L_00039e99
    xchg ebx, ebx
L_00039dc0:
    cld
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    call L_0003ab38
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
    js short L_00039e14
    db 00bh, 0c9h    ; or ecx, ecx (WASM encodes it differently)
    jne short L_00039e09
    db 022h, 0dfh    ; and bl, bh (WASM encodes it differently)
    jmp short L_00039e21
L_00039e09:
    db 08ah, 0e7h    ; mov ah, bh (WASM encodes it differently)
    out dx, ax
    xchg esi, eax
    mov ah, byte ptr [edi]
    stosb
    dec ecx
    je short L_00039e20
L_00039e14:
    xchg esi, eax
    mov ah, 0xff
    out dx, ax
    xchg esi, eax
L_00039e1a:
    mov ah, byte ptr [edi]
    stosb
    dec ecx
    jne short L_00039e1a
L_00039e20:
    xchg esi, eax
L_00039e21:
    db 08ah, 0e3h    ; mov ah, bl (WASM encodes it differently)
    out dx, ax
    xchg esi, eax
    mov ah, byte ptr [edi]
    stosb
    jmp short L_00039e99
    nop
L_00039e2c:
    mov eax, dword ptr [ebp + 0x18]
L_00039e2f:
    mov ah, byte ptr [edi]
    mov byte ptr [edi], al
    xchg dword ptr [DAT_0005f009], eax
    shl ah, 1
    and ah, 0xf
    db 00ah, 0e4h    ; or ah, ah (WASM encodes it differently)
    jne short L_00039e45
    mov ah, 1
    inc edi
L_00039e45:
    out dx, ax
    xchg dword ptr [DAT_0005f009], eax
    db 00bh, 0f6h    ; or esi, esi (WASM encodes it differently)
    jns short L_00039e59
    add esi, dword ptr [ebp - 4]
    dec ecx
    jne short L_00039e2f
    jmp short L_00039e99
L_00039e59:
    add esi, dword ptr [ebp - 8]
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    dec ecx
    jne short L_00039e2f
    jmp short L_00039e99
    nop
L_00039e64:
    mov eax, dword ptr [ebp + 0x18]
L_00039e67:
    mov ah, byte ptr [edi]
    mov byte ptr [edi], al
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    db 00bh, 0f6h    ; or esi, esi (WASM encodes it differently)
    jns short L_00039e79
    add esi, dword ptr [ebp - 4]
    dec ecx
    jne short L_00039e67
    jmp short L_00039e99
L_00039e79:
    xchg dword ptr [DAT_0005f009], eax
    shl ah, 1
    and ah, 0xf
    db 00ah, 0e4h    ; or ah, ah (WASM encodes it differently)
    jne short L_00039e8b
    mov ah, 1
    inc edi
L_00039e8b:
    out dx, ax
    xchg dword ptr [DAT_0005f009], eax
    org $
    add esi, dword ptr [ebp - 8]
    dec ecx
    jne short L_00039e67
L_00039e99:
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
FUN_00039eac:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov ecx, dword ptr [ebp + 8]
    cmp cx, 0
    jl short L_00039ef9
    mov edi, dword ptr [DAT_0005f001]
    db 08bh, 0f1h    ; mov esi, ecx (WASM encodes it differently)
    shr esi, 2
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov ecx, dword ptr [DAT_0005f005]
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
L_00039ef9:
    neg ecx
    mov edi, dword ptr [DAT_0005f001]
    mov eax, dword ptr [DAT_0005f005]
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
FUN_00039f40:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 8]
    cmp dx, 0
    jl short L_00039f98
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
    call L_0003ab38
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    mov edi, dword ptr [DAT_0005f001]
    mov ebx, dword ptr [DAT_0005eff9]
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
L_00039f98:
    neg edx
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
    call L_0003ab38
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    mov edx, dword ptr [DAT_0005effd]
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
    call L_0003ab38
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    dec esi
    dec edi
    mov ebx, dword ptr [DAT_0005eff9]
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
; ---- FUN_00039fec
FUN_00039fec:
    enter 0, 0
    mov eax, dword ptr [ebp + 8]
    call L_0003ab6c
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00039ffc
FUN_00039ffc:
    enter 0, 0
    push edx
    push ebx
    mov eax, dword ptr [ebp + 8]
    mov edx, dword ptr [DAT_0005f005]
    org $
    shr edx, 4
    mul edx
    db 08ah, 0f8h    ; mov bh, al (WASM encodes it differently)
    db 032h, 0dbh    ; xor bl, bl (WASM encodes it differently)
    call L_0003abf4
    pop ebx
    pop edx
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0003a020
FUN_0003a020:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 8]
    mov edx, dword ptr [DAT_0005f005]
    mul edx
    add eax, 0xa000
    shl eax, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov esi, dword ptr [DAT_0005f001]
    mov dx, 0x3ce
    mov ax, 0x4105
    out dx, ax
    mov dx, 0x3c4
    mov ax, 0xf02
    out dx, ax
    mov ecx, dword ptr [DAT_0005f005]
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
; ---- FUN_0003a078
FUN_0003a078:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0003ab38
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    add dword ptr [ebp + 0x20], ecx
    mov eax, dword ptr [ebp + 8]
    mov ah, byte ptr [DAT_0005efe9]
    call L_0003ab6c
    push dword ptr [DAT_0005eff9]
    mov edx, dword ptr [ebp + 0x14]
    mov ecx, dword ptr [ebp + 0x18]
    call L_0003ab38
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    db 08ah, 0c4h    ; mov al, ah (WASM encodes it differently)
    call L_0003ab6c
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
    mov ebp, dword ptr [DAT_0005eff9]
    db 02bh, 0eah    ; sub ebp, edx (WASM encodes it differently)
    cld
L_0003a0e6:
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
    rep movsb
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    db 003h, 0f5h    ; add esi, ebp (WASM encodes it differently)
    dec eax
    jne short L_0003a0e6
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
; ---- FUN_0003a104
FUN_0003a104:
    enter 0, 0
    push ecx
    mov ecx, dword ptr [ebp + 8]
    call L_0003ac10
    pop ecx
    leave
    ret
; ---- FUN_0003a114
FUN_0003a114:
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
    call L_0003ab38
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    pop ebx
    db 003h, 0d9h    ; add ebx, ecx (WASM encodes it differently)
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    add edx, 3
    shr edx, 2
    pop ecx
    mov ebx, dword ptr [DAT_0005eff9]
    db 02bh, 0dah    ; sub ebx, edx (WASM encodes it differently)
    cld
    mov ax, 4
L_0003a152:
    push ecx
    push esi
    push edx
    mov dx, 0x3ce
    out dx, ax
    pop edx
L_0003a15c:
    push ecx
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
    rep movsb
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    pop ecx
    dec ecx
    jne short L_0003a15c
    pop esi
    pop ecx
    inc ah
    cmp ah, 4
    jl short L_0003a152
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_0003a178
FUN_0003a178:
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
    call L_0003ab38
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    xchg edi, esi
    pop ebx
    db 003h, 0d9h    ; add ebx, ecx (WASM encodes it differently)
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    add edx, 3
    shr edx, 2
    pop ecx
    mov ebx, dword ptr [DAT_0005eff9]
    org 0c35h
    pop edi
    pop ecx
    pop edx
    dec edx
    je short L_0003a57c
    rol ah, 1
    adc edi, 0
    push edx
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    pop edx
    jmp short L_0003a541
L_0003a57c:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0003a584
FUN_0003a584:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0x18]
    mov dword ptr [L_0003a60b], eax
    mov dword ptr [L_0003a672], eax
    org $
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    mov ebx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 0x14]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0003ab38
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
    jne short L_0003a638
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_0005eff9]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    shr ebx, 1
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov dx, 0x3c4
    out dx, ax
    mov bh, 4
L_0003a5f7:
    push edi
    push ecx
    push ebx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0003a5fe:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
    shl cx, 1
    push bx
L_0003a605:
    lodsb
    movzx ebx, al
    db 08ah, 083h
L_0003a60b:
    db 078h, 056h, 034h, 012h
    stosb
    dec ecx
    jne short L_0003a605
    pop bx
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0003a5fe
    pop ebx
    pop ecx
    pop edi
    dec bh
    je short L_0003a630
    rol ah, 1
    adc edi, 0
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    jmp short L_0003a5f7
L_0003a630:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0003a638:
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_0005eff9]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov bh, byte ptr [esi]
    inc esi
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_0005f009], ecx
    mov dx, 4
L_0003a65b:
    push dx
    push cx
    push edi
    db 066h, 08bh, 0d1h    ; mov dx, cx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0003a665:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
L_0003a667:
    cmp byte ptr [esi], bh
    je short L_0003a67d
    push ebx
    lodsb
    movzx ebx, al
    db 08ah, 083h
L_0003a672:
    db 078h, 056h, 034h, 012h
    stosb
    pop ebx
    dec ecx
    jne short L_0003a667
    jmp short L_0003a682
L_0003a67d:
    inc edi
    inc esi
    dec ecx
    jne short L_0003a667
L_0003a682:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec dx
    jne short L_0003a665
    mov ecx, dword ptr [DAT_0005f009]
    pop edi
    pop cx
    pop dx
    dec dx
    je short L_0003a6a8
    rol ah, 1
    adc edi, 0
    push edx
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    pop edx
    jmp short L_0003a65b
L_0003a6a8:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0003a6b0
FUN_0003a6b0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov edi, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x18]
    mov dword ptr [DAT_0005f029], 0
    mov dword ptr [DAT_0005f02d], 0
    mov eax, dword ptr [edi]
    shr eax, 2
    mov dword ptr [DAT_0005f00d], eax
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
L_0003a4eb:
    push edi
    push ecx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
L_0003a4ef:
    movzx ecx, bl
    shl ecx, 1
L_0003a4f4:
    lodsb
    db 02ch
L_0003a4f6:
    db 000h
    stosb
    dec ecx
    jne short L_0003a4f4
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0003a4ef
    pop ecx
    pop edi
    dec bh
    je short L_0003a515
    rol ah, 1
    adc edi, 0
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    jmp short L_0003a4eb
L_0003a515:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0003a51d:
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_0005eff9]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov bh, byte ptr [esi]
    inc esi
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_0005f009], ecx
    mov edx, 4
L_0003a541:
    push edx
    push ecx
    push edi
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
L_0003a546:
    movzx ecx, bl
L_0003a549:
    lodsb
    db 03ah, 0c7h    ; cmp al, bh (WASM encodes it differently)
    je short L_0003a556
    db 02ch
L_0003a54f:
    db 000h
    stosb
    dec ecx
    jne short L_0003a549
    jmp short L_0003a55a
L_0003a556:
    inc edi
    dec ecx
    jne short L_0003a549
L_0003a55a:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0003a546
    mov ecx, dword ptr [DAT_0005f009]
    org 0b2ah
    pop edi
    pop dx
    dec dx
    je short L_0003a470
    rol ah, 1
    adc edi, 0
    push edx
    mov dx, 0x3c4
    out dx, ax
    pop edx
    jmp short L_0003a435
L_0003a470:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0003a478
FUN_0003a478:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0x18]
    mov byte ptr [L_0003a4f6], al
    mov byte ptr [L_0003a54f], al
    org $
    mov edx, dword ptr [ebp + 8]
    mov ecx, dword ptr [ebp + 0xc]
    mov ebx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [ebp + 0x14]
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0003ab38
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
    jne short L_0003a51d
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_0005eff9]
    org 0881h
    db 02bh, 0dah    ; sub ebx, edx (WASM encodes it differently)
    cld
    mov ax, 0x102
L_0003a1b8:
    push ecx
    push edi
    push edx
    mov dx, 0x3c4
    out dx, ax
    pop edx
L_0003a1c2:
    push ecx
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
    rep movsb
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    pop ecx
    dec ecx
    jne short L_0003a1c2
    pop edi
    pop ecx
    shl ah, 1
    cmp ah, 0x10
    jl short L_0003a1b8
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
; ---- FUN_0003a1e8
FUN_0003a1e8:
    enter 0, 0
    push edx
    mov eax, dword ptr [ebp + 0xc]
    mov edx, dword ptr [ebp + 0x10]
    mul edx
    mov edx, dword ptr [ebp + 8]
    mul edx
    shl eax, 3
    cmp dword ptr [ebp + 0x18], 0xff
    je short L_0003a209
    add eax, dword ptr [ebp + 8]
L_0003a209:
    pop edx
    leave
    ret
; ---- FUN_0003a20c
FUN_0003a20c:
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
    je short L_0003a235
    mov byte ptr [edi], al
    inc edi
L_0003a235:
    shr ecx, 2
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    dec eax
L_0003a23b:
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
    jne short L_0003a23b
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0003a258
FUN_0003a258:
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
    je short L_0003a289
    inc esi
L_0003a289:
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
L_0003a2b3:
    push cx
    db 066h, 08bh, 0cah    ; mov cx, dx (WASM encodes it differently)
L_0003a2b8:
    mov al, byte ptr [esi]
    xchg byte ptr [edi], al
    mov byte ptr [esi], al
    dec edi
    inc esi
    dec cx
    jne short L_0003a2b8
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    pop cx
    dec cx
    jne short L_0003a2b3
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
L_0003a2e3:
    push cx
    db 066h, 08bh, 0cah    ; mov cx, dx (WASM encodes it differently)
L_0003a2e8:
    mov al, byte ptr [esi]
    xchg byte ptr [edi], al
    mov byte ptr [esi], al
    dec edi
    inc esi
    dec cx
    jne short L_0003a2e8
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
    pop cx
    dec cx
    jne short L_0003a2e3
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
FUN_0003a308:
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
    je short L_0003a343
    inc esi
L_0003a343:
    dec eax
    mul edx
    shl eax, 1
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov edx, dword ptr [ebp - 8]
    shl edx, 1
L_0003a34f:
    push esi
    mov ecx, dword ptr [ebp - 4]
    shr ecx, 1
    db 08bh, 0feh    ; mov edi, esi (WASM encodes it differently)
    db 003h, 0fbh    ; add edi, ebx (WASM encodes it differently)
L_0003a359:
    push ecx
    db 08bh, 0cah    ; mov ecx, edx (WASM encodes it differently)
L_0003a35c:
    mov al, byte ptr [esi]
    xchg byte ptr [edi], al
    mov byte ptr [esi], al
    inc edi
    inc esi
    dec ecx
    jne short L_0003a35c
    pop ecx
    db 02bh, 0fah    ; sub edi, edx (WASM encodes it differently)
    db 02bh, 0fah    ; sub edi, edx (WASM encodes it differently)
    dec ecx
    jne short L_0003a359
    pop esi
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    db 003h, 0f2h    ; add esi, edx (WASM encodes it differently)
    dec dword ptr [ebp - 0x10]
    jne short L_0003a34f
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0003a380
FUN_0003a380:
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
    call L_0003ab38
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
    jne short L_0003a411
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_0005eff9]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    shr ebx, 1
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov dx, 0x3c4
    out dx, ax
    mov bh, 4
L_0003a3e6:
    push edi
    push ecx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0003a3ec:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
    rep movsw
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0003a3ec
    pop ecx
    pop edi
    dec bh
    je short L_0003a409
    rol ah, 1
    adc edi, 0
    mov dx, 0x3c4
    out dx, ax
    jmp short L_0003a3e6
L_0003a409:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0003a411:
    pop ebx
    pop ecx
    shl ebx, 1
    mov edx, dword ptr [DAT_0005eff9]
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    pop eax
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    cld
    mov bh, byte ptr [esi]
    inc esi
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_0005f009], ecx
    mov dx, 4
L_0003a435:
    push dx
    push edi
    db 066h, 08bh, 0d1h    ; mov dx, cx (WASM encodes it differently)
    db 033h, 0c9h    ; xor ecx, ecx (WASM encodes it differently)
L_0003a43d:
    db 08ah, 0cbh    ; mov cl, bl (WASM encodes it differently)
L_0003a43f:
    cmp byte ptr [esi], bh
    je short L_0003a449
    movsb
    dec ecx
    jne short L_0003a43f
    jmp short L_0003a44e
L_0003a449:
    inc edi
    inc esi
    dec ecx
    jne short L_0003a43f
L_0003a44e:
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec dx
    jne short L_0003a43d
    mov ecx, dword ptr [DAT_0005f009]
    org 01072h
    mov dword ptr [DAT_0005f031], 4
    pop ebx
    shr ebx, 2
    pop eax
    mov edx, dword ptr [DAT_0005f02d]
    cmp edx, 0
    je short L_0003a9c7
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    dec edx
    dec dword ptr [DAT_0005f031]
    rol ah, 1
L_0003a9c7:
    mov ecx, dword ptr [DAT_0005f015]
    mov edx, dword ptr [DAT_0005eff9]
    sub edx, dword ptr [DAT_0005f021]
    sub edx, dword ptr [DAT_0005f01d]
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_0005f009], ecx
    mov edx, dword ptr [DAT_0005f031]
L_0003a9f4:
    push edi
    push edx
    db 066h, 08bh, 0d1h    ; mov dx, cx (WASM encodes it differently)
    add esi, dword ptr [DAT_0005f00d]
L_0003a9ff:
    mov ecx, dword ptr [DAT_0005f021]
    add esi, dword ptr [DAT_0005f019]
L_0003aa0b:
    db 080h, 03eh
L_0003aa0d:
    db 004h
    je short L_0003aa19
    lodsb
    db 02ch
L_0003aa12:
    db 003h
    stosb
    dec ecx
    jne short L_0003aa0b
    jmp short L_0003aa1e
L_0003aa19:
    inc edi
    inc esi
    dec ecx
    jne short L_0003aa0b
L_0003aa1e:
    mov ecx, dword ptr [DAT_0005f01d]
    db 003h, 0f9h    ; add edi, ecx (WASM encodes it differently)
    db 003h, 0f1h    ; add esi, ecx (WASM encodes it differently)
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0003a9ff
    mov ecx, dword ptr [DAT_0005f009]
    pop edx
    pop edi
    add esi, dword ptr [DAT_0005f011]
    dec edx
    je short L_0003aa93
    rol ah, 1
    jae short L_0003aa84
    inc edi
    cmp dword ptr [DAT_0005f019], 0
    je short L_0003aa6d
    dec dword ptr [DAT_0005f019]
    dec ebp
    dec edi
    cmp dword ptr [DAT_0005f029], 0
    je short L_0003aa65
    inc dword ptr [DAT_0005f01d]
    jmp short L_0003aa84
L_0003aa65:
    inc dword ptr [DAT_0005f021]
    jmp short L_0003aa84
L_0003aa6d:
    cmp dword ptr [DAT_0005f029], 0
    je short L_0003aa84
    inc dword ptr [DAT_0005f01d]
    dec dword ptr [DAT_0005f021]
    org 0f95h
    mov edi, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x18]
    mov eax, dword ptr [edi]
    shr eax, 2
    mov dword ptr [DAT_0005f00d], eax
    mov eax, dword ptr [edi + 4]
    shr eax, 2
    mov dword ptr [DAT_0005f011], eax
    mov eax, dword ptr [edi + 8]
    mov dword ptr [DAT_0005f015], eax
    mov eax, dword ptr [edi + 0xc]
    add eax, 3
    shr eax, 2
    mov dword ptr [DAT_0005f019], eax
    mov eax, dword ptr [edi + 0x10]
    and eax, 3
    mov dword ptr [DAT_0005f025], eax
    mov eax, dword ptr [edi + 0x10]
    cmp eax, 0
    je short L_0003a916
    mov dword ptr [DAT_0005f029], 1
    shr eax, 2
L_0003a916:
    mov dword ptr [DAT_0005f01d], eax
    mov eax, dword ptr [edi + 0x14]
    add eax, dword ptr [DAT_0005f025]
    shr eax, 2
    jne short L_0003a94f
    mov eax, 1
    cmp dword ptr [DAT_0005f029], 1
    je short L_0003a94f
    mov eax, 4
    sub eax, dword ptr [edi + 0x14]
    mov dword ptr [DAT_0005f02d], eax
    dec dword ptr [DAT_0005f019]
    mov eax, 1
L_0003a94f:
    mov dword ptr [DAT_0005f021], eax
    mov eax, dword ptr [edi + 0xc]
    and eax, 3
    mov dword ptr [DAT_0005f025], eax
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0003ab38
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    add ecx, 4
    sub ecx, dword ptr [DAT_0005f025]
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
    jne short L_0003a999
    jmp short L_0003a99c
L_0003a999:
    mov dh, byte ptr [esi]
    inc esi
L_0003a99c:
    mov byte ptr [L_0003aa0d], dh
    org 0f58h
    je short L_0003a897
L_0003a88a:
    push edx
    mov dx, 0x3c4
    out dx, ax
    pop edx
    jmp near ptr L_0003a7fe
L_0003a897:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_0003a8a0
FUN_0003a8a0:
    enter 0, 0
    push esi
    push edi
    push edx
    push ecx
    push ebx
    mov eax, dword ptr [ebp + 0x1c]
    mov byte ptr [L_0003aa12], al
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
    jne short L_0003a7a1
    jmp short L_0003a7a4
L_0003a7a1:
    mov dh, byte ptr [esi]
    inc esi
L_0003a7a4:
    mov byte ptr [L_0003a816], dh
    org 0f81h
    mov dword ptr [DAT_0005f029], 0
    mov dword ptr [DAT_0005f02d], 0
    org 0e7ah
    mov dword ptr [DAT_0005f031], 4
    pop ebx
    shr ebx, 2
    pop eax
    mov edx, dword ptr [DAT_0005f02d]
L_0003a7bf:
    cmp edx, 0
    je short L_0003a7d1
    db 003h, 0f3h    ; add esi, ebx (WASM encodes it differently)
    dec edx
    dec dword ptr [DAT_0005f031]
    rol ah, 1
    jmp short L_0003a7bf
L_0003a7d1:
    mov ecx, dword ptr [DAT_0005f015]
    mov edx, dword ptr [DAT_0005eff9]
    sub edx, dword ptr [DAT_0005f021]
    sub edx, dword ptr [DAT_0005f01d]
    push ebp
    db 08bh, 0eah    ; mov ebp, edx (WASM encodes it differently)
    mov dx, 0x3c4
    out dx, ax
    mov dword ptr [DAT_0005f009], ecx
    mov edx, dword ptr [DAT_0005f031]
L_0003a7fe:
    push edi
    push edx
    db 08bh, 0d1h    ; mov edx, ecx (WASM encodes it differently)
    add esi, dword ptr [DAT_0005f00d]
L_0003a808:
    mov ecx, dword ptr [DAT_0005f021]
    add esi, dword ptr [DAT_0005f019]
L_0003a814:
    db 080h, 03eh
L_0003a816:
    db 004h
    je short L_0003a81f
    movsb
    dec ecx
    jne short L_0003a814
    jmp short L_0003a824
L_0003a81f:
    inc edi
    inc esi
    dec ecx
    jne short L_0003a814
L_0003a824:
    mov ecx, dword ptr [DAT_0005f01d]
    db 003h, 0f9h    ; add edi, ecx (WASM encodes it differently)
    db 003h, 0f1h    ; add esi, ecx (WASM encodes it differently)
    db 003h, 0fdh    ; add edi, ebp (WASM encodes it differently)
    dec edx
    jne short L_0003a808
    mov ecx, dword ptr [DAT_0005f009]
    pop edx
    pop edi
    add esi, dword ptr [DAT_0005f011]
    dec edx
    je short L_0003a897
    rol ah, 1
    jae short L_0003a88a
    inc edi
    cmp dword ptr [DAT_0005f019], 0
    je short L_0003a873
    dec dword ptr [DAT_0005f019]
    dec ebp
    dec edi
    cmp dword ptr [DAT_0005f029], 0
    je short L_0003a86b
    inc dword ptr [DAT_0005f01d]
    jmp short L_0003a88a
L_0003a86b:
    inc dword ptr [DAT_0005f021]
    jmp short L_0003a88a
L_0003a873:
    cmp dword ptr [DAT_0005f029], 0
    je short L_0003a88a
    inc dword ptr [DAT_0005f01d]
    dec dword ptr [DAT_0005f021]
    org 0dadh
    mov eax, dword ptr [edi + 4]
    shr eax, 2
    mov dword ptr [DAT_0005f011], eax
    mov eax, dword ptr [edi + 8]
    mov dword ptr [DAT_0005f015], eax
    mov eax, dword ptr [edi + 0xc]
    add eax, 3
    shr eax, 2
    mov dword ptr [DAT_0005f019], eax
    mov eax, dword ptr [edi + 0x10]
    and eax, 3
    mov dword ptr [DAT_0005f025], eax
    mov eax, dword ptr [edi + 0x10]
    cmp eax, 0
    je short L_0003a71e
    mov dword ptr [DAT_0005f029], 1
    shr eax, 2
L_0003a71e:
    mov dword ptr [DAT_0005f01d], eax
    mov eax, dword ptr [edi + 0x14]
    add eax, dword ptr [DAT_0005f025]
    shr eax, 2
    jne short L_0003a757
    mov eax, 1
    cmp dword ptr [DAT_0005f029], 1
    je short L_0003a757
    mov eax, 4
    sub eax, dword ptr [edi + 0x14]
    mov dword ptr [DAT_0005f02d], eax
    dec dword ptr [DAT_0005f019]
    mov eax, 1
L_0003a757:
    mov dword ptr [DAT_0005f021], eax
    mov eax, dword ptr [edi + 0xc]
    and eax, 3
    mov dword ptr [DAT_0005f025], eax
    mov edx, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    call L_0003ab38
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov edx, dword ptr [ebp + 8]
    mov al, 2
    mov ah, 0x11
    add ecx, 4
    sub ecx, dword ptr [DAT_0005f025]
    org 01152h
    je short L_0003aa93
L_0003aa84:
    push edx
    mov dx, 0x3c4
    mov al, 2
    out dx, ax
    pop edx
    jmp near ptr L_0003a9f4
L_0003aa93:
    pop ebp
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_0003aa9c
FUN_0003aa9c:
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
    je short L_0003aada
    mov ah, byte ptr [edi]
    inc edi
L_0003aac6:
    mov al, byte ptr [edi]
    db 03ah, 0c4h    ; cmp al, ah (WASM encodes it differently)
    je short L_0003aacf
    db 0d7h    ; xlatb  (not transcribed)
    mov byte ptr [edi], al
L_0003aacf:
    inc edi
    dec ecx
    jne short L_0003aac6
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0003aada:
    mov al, byte ptr [edi]
    db 0d7h    ; xlatb  (not transcribed)
    mov byte ptr [edi], al
    inc edi
    dec ecx
    jne short L_0003aada
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
    je short L_0003ab25
    mov ah, byte ptr [edi]
    inc edi
L_0003ab10:
    mov al, byte ptr [edi]
    db 03ah, 0c4h    ; cmp al, ah (WASM encodes it differently)
    je short L_0003ab1a
    db 02ah, 0c3h    ; sub al, bl (WASM encodes it differently)
    mov byte ptr [edi], al
L_0003ab1a:
    inc edi
    dec ecx
    jne short L_0003ab10
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
L_0003ab25:
    mov al, byte ptr [edi]
    db 02ah, 0c3h    ; sub al, bl (WASM encodes it differently)
    mov byte ptr [edi], al
    inc edi
    dec ecx
    jne short L_0003ab25
    pop ebx
    pop ecx
    pop edx
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0003ab38
L_0003ab38:
    push esi
    push eax
    mov ebx, 0
    db 08bh, 0c2h    ; mov eax, edx (WASM encodes it differently)
    db 08bh, 0f1h    ; mov esi, ecx (WASM encodes it differently)
    mov ecx, dword ptr [DAT_0005efed]
    shl eax, cl
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov ecx, dword ptr [DAT_0005eff1]
    shl eax, cl
    db 003h, 0d8h    ; add ebx, eax (WASM encodes it differently)
    db 08bh, 0c6h    ; mov eax, esi (WASM encodes it differently)
    shr eax, 2
    db 003h, 0d8h    ; add ebx, eax (WASM encodes it differently)
    db 08bh, 0ceh    ; mov ecx, esi (WASM encodes it differently)
    and ecx, 3
    add ebx, dword ptr [DAT_0005f001]
    pop eax
    pop esi
    ret
; ---- FUN_0003ab6c
L_0003ab6c:
    push eax
    push edx
    and eax, 0xff
    mov dword ptr [DAT_0005efe9], eax
    mov eax, dword ptr [DAT_0005efe9]
    mov edx, dword ptr [DAT_0005f005]
    mul edx
    add eax, 0xa000
    shl eax, 4
    mov dword ptr [DAT_0005f001], eax
    org $
    pop edx
    pop eax
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0003ab98
L_0003ab98:
    cmp dword ptr [DAT_0005efe1], 0
    jne short L_0003abc3
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
L_0003abc3:
    ret
; ---- FUN_0003abc4
L_0003abc4:
    push dx
    push ax
    mov dx, 0x3da
L_0003abcc:
    in al, dx
    test al, 8
    jne short L_0003abcc
L_0003abd1:
    in al, dx
    test al, 8
    je short L_0003abd1
    pop ax
    pop dx
    ret
    nop
    push dx
    push ax
    mov dx, 0x3da
L_0003abe4:
    in al, dx
    test al, 8
    je short L_0003abe4
L_0003abe9:
    in al, dx
    test al, 8
    jne short L_0003abe9
    pop ax
    pop dx
    ret
    nop
; ---- FUN_0003abf4
L_0003abf4:
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
    call L_0003abc4
    pop ebx
    pop edx
    ret
; ---- FUN_0003ac10
L_0003ac10:
    push edx
    push ecx
    push ebx
    mov dword ptr [DAT_0005eff5], ecx
    call L_0003abc4
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
