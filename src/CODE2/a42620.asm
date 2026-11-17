; a42620.asm - assembler module of CODE.2 (4945 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn FUN_0002e930:near
extrn FUN_0002e9a0:near
extrn FUN_0003f29c:near
extrn FUN_00045680:near
extrn FUN_000456d8:near
extrn FUN_00045730:near
extrn DAT_0005bf34:byte
extrn DAT_0005c658:byte
extrn DAT_0005c65c:byte
extrn DAT_0005c660:byte
extrn DAT_0005c6d8:byte
extrn DAT_0005c6e0:byte
extrn DAT_0005c6f4:byte
extrn DAT_0005c730:byte
extrn DAT_0005c738:byte
extrn DAT_0005c73c:byte
extrn DAT_0005cf50:byte
extrn DAT_0005ef4d:byte
extrn B00065618_e1:byte
extrn B00065a18_cn:byte
extrn B00065a1c_ai:byte
extrn B00065a20_bf:byte
extrn B00065a24_aj:byte
extrn B00065a28_bn:byte
extrn B00065a2c_ay:byte
extrn B00065a30_af:byte
extrn B00068fe0_eN:byte
extrn B000698e0_b7:byte
extrn B00072220_gw:byte
extrn B000748e4_h8:byte
extrn B000748e8_jD:byte
extrn B000755d0_ao:byte
extrn B000755d2_ai:byte
extrn B000755d4_ak:byte
extrn B000755d6_ae:byte
extrn B000755e4_bk:byte
extrn B000755e8_ag:byte
extrn B000755ea_aN:byte
extrn B000755ec_aH:byte
extrn B000755ee_aJ:byte
extrn B000755f0_co:byte
extrn B000755f2_by:byte
extrn B000755f4_ck:byte
extrn B000755f6_bu:byte
extrn B000755f8_bg:byte
extrn B000755fc_ax:byte
extrn B00075600_b9:byte
extrn B00075604_mM:byte
extrn B00075606_b3:byte
extrn B00075608_c1:byte
extrn B0007560c_hn:byte
extrn B00075610_a9:byte
extrn B00075612_lo:byte
extrn B00075619_b0:byte
extrn B0007561b_io:byte
extrn B00075621_lx:byte
extrn B00075622_mo:byte
extrn B000756a2_ah:byte
extrn B00075722_nn:byte
extrn B000757a2_bK:byte
extrn B000758c4_j7:byte
extrn DAT_0005c664:byte
_DATA segment dword public use32 'DATA'
DAT_0005fcd0 label byte
    db 000h, 000h, 000h, 000h    ; 0005fcd0  ....
DAT_0005fcd4 label byte
    db 000h, 000h, 000h, 000h    ; 0005fcd4  ....
DAT_0005fcd8 label byte
    db 000h, 000h, 000h, 000h    ; 0005fcd8  ....
DAT_0005fcdc label byte
    db 000h, 000h, 000h, 000h    ; 0005fcdc  ....
DAT_0005fce0 label byte
    db 0ffh, 0ffh, 0ffh, 0ffh    ; 0005fce0  ....
DAT_0005fce4 label byte
    db 0ffh, 0ffh, 0ffh, 0ffh    ; 0005fce4  ....
DAT_0005fce8 label byte
    db 0ffh, 0ffh, 0ffh, 0ffh    ; 0005fce8  ....
DAT_0005fcec label byte
    db 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh    ; 0005fcec  ......
DAT_0005fcf2 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 0005fcf2  ........
public DAT_0005fcfa
DAT_0005fcfa label byte
    db 000h, 000h    ; 0005fcfa  ..
DAT_0005fcfc label byte
    db 000h, 000h, 000h, 000h    ; 0005fcfc  ....
DAT_0005fd00 label byte
    db 000h, 000h, 000h, 000h    ; 0005fd00  ....
DAT_0005fd04 label byte
    db 0ffh, 0ffh, 0ffh, 0ffh    ; 0005fd04  ....
public DAT_0005fd08
DAT_0005fd08 label byte
    db 000h, 000h, 000h, 000h    ; 0005fd08  ....
DAT_0005fd0c label byte
    db 000h, 000h, 000h, 000h    ; 0005fd0c  ....
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_000434c4
public FUN_000435dc
public FUN_00043808
public FUN_0004395c
; ---- FUN_00042620
L_00042620:
    enter 0, 0
    push esi
    push edi
    push ecx
    mov edi, dword ptr [ebp + 0xc]
    mov ecx, dword ptr [ebp + 0x10]
    mov esi, dword ptr [B000755e4_bk]
    call dword ptr [ebp + 8]
    pop ecx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_0004263c
L_0004263c:
    enter 0x2c, 0
    push ebx
    push esi
    push edi
    cmp dword ptr [DAT_0005c6f4 + 0ch], 0x93
    je near ptr L_0004294d
    mov eax, 0x800
    movzx edx, byte ptr [DAT_0005ef4d]
    mul edx
    add eax, 0xa000
    shl eax, 4
    mov dword ptr [ebp - 8], eax
    mov eax, dword ptr [DAT_0005c6f4 + 04h]
    mov edx, 0x1c
    mul edx
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov ebx, dword ptr [ebx + B00065a18_cn]
    and ebx, 0xfff8
    shr ebx, 1
    mov dword ptr [ebp - 0x14], ebx
    mov edi, dword ptr [B000758c4_j7]
    movzx eax, word ptr [edi]
    cmp dword ptr [DAT_0005c6f4 + 0ch], 0x242
    jl short L_000426ac
    cmp dword ptr [DAT_0005c6f4 + 0ch], 0x24d
    jle short L_000426e7
L_000426ac:
    movzx eax, word ptr [DAT_0005fcfa]
    cmp ebx, dword ptr [DAT_0005c730]
    jg short L_000426d9
    push ebx
    movzx eax, word ptr [edi + ebx*2]
    mov ebx, dword ptr [DAT_0005fcf2]
    db 08ah, 0fbh    ; mov bh, bl (WASM encodes it differently)
    db 066h, 02bh, 0c3h    ; sub ax, bx (WASM encodes it differently)
    cmp ah, 0
    jge short L_000426d2
    mov ah, 0
L_000426d2:
    cmp al, 0
    jge short L_000426d8
    mov al, 0
L_000426d8:
    pop ebx
L_000426d9:
    test dword ptr [DAT_0005c6f4 + 04h], 1
    je short L_000426e7
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
L_000426e7:
    mov dword ptr [ebp - 0x10], eax
    cmp eax, 0x808
    jbe short L_000426f9
    mov eax, 0x808
    mov dword ptr [ebp - 0x10], eax
L_000426f9:
    and ebx, 0xfffc
    mov eax, dword ptr [ebx + B00068fe0_eN]
    mov dword ptr [ebp - 4], eax
    mov dword ptr [ebp - 0x1c], eax
    mov eax, dword ptr [DAT_0005c6f4 + 04h]
    shr eax, 2
    add eax, dword ptr [DAT_0005c6e0]
    add dword ptr [ebp - 8], eax
    mov eax, dword ptr [DAT_0005c6f4 + 04h]
    and eax, 3
    shl eax, 3
    add eax, dword ptr [DAT_0005c6f4]
    mov dword ptr [ebp - 0x18], eax
    cmp dword ptr [DAT_0005fcd0], 0
    je near ptr L_0004285b
    mov eax, dword ptr [ebp - 0x14]
    shr eax, 3
    add eax, 0x80
    mov dword ptr [ebp - 0x28], eax
    mov edx, dword ptr [ebp - 0x14]
    shr edx, 1
    db 02bh, 0c2h    ; sub eax, edx (WASM encodes it differently)
    jle near ptr L_0004294d
    mov eax, dword ptr [ebp - 0x14]
    movsx edx, byte ptr [B00075621_lx]
    mul edx
    add eax, 0x40
    adc edx, 0
    mov ebx, 0x80
    idiv ebx
    mov dword ptr [ebp - 0x2c], eax
    mov eax, dword ptr [ebp - 8]
    mov dword ptr [ebp - 0x24], eax
    mov eax, dword ptr [ebp - 0x2c]
    mov edx, 0x50
    mul edx
    sub dword ptr [ebp - 0x24], eax
    mov eax, dword ptr [ebp - 0x28]
    mov ebx, dword ptr [ebp - 0x14]
    shr ebx, 1
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    sub eax, dword ptr [ebp - 0x2c]
    cmp eax, 0
    jge short L_000427a1
    add dword ptr [ebp - 0x2c], eax
    mov eax, 0
L_000427a1:
    sub dword ptr [ebp - 0x1c], 0x204
    mov edi, dword ptr [ebp - 0x1c]
    movsx ebx, byte ptr [B00075621_lx]
    inc ebx
    movzx ebx, word ptr [edi + ebx*2]
    mov al, byte ptr [edi + ebx]
    push eax
    mov byte ptr [edi + ebx], 0xc3
    push dword ptr [ebp - 0x2c]
    push dword ptr [ebp - 0x1c]
    call L_000437c8
    add esp, 8
    add eax, dword ptr [ebp - 0x1c]
    mov dword ptr [ebp - 0x20], eax
    mov esi, dword ptr [ebp - 0x18]
    mov ah, byte ptr [esi + DAT_0005c664 + 04h]
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 0x10]
    push dword ptr [ebp - 0x24]
    push dword ptr [ebp - 0x20]
    call L_00042620
    add esp, 0xc
    inc dword ptr [ebp - 0x24]
    mov ah, byte ptr [esi + DAT_0005c664 + 024h]
    cmp ah, 0
    je short L_0004281c
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 0x10]
    push dword ptr [ebp - 0x24]
    push dword ptr [ebp - 0x20]
    call L_00042620
    add esp, 0xc
L_0004281c:
    inc dword ptr [ebp - 0x24]
    mov ah, byte ptr [esi + DAT_0005c664 + 044h]
    cmp ah, 0
    je short L_00042843
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 0x10]
    push dword ptr [ebp - 0x24]
    push dword ptr [ebp - 0x20]
    call L_00042620
    add esp, 0xc
L_00042843:
    mov edi, dword ptr [ebp - 0x1c]
    movsx ebx, byte ptr [B00075621_lx]
    inc ebx
    movzx ebx, word ptr [edi + ebx*2]
    pop eax
    mov byte ptr [edi + ebx], al
    jmp near ptr L_0004294d
L_0004285b:
    mov esi, dword ptr [ebp - 0x18]
    mov ah, byte ptr [esi + DAT_0005c664 + 04h]
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    mov eax, dword ptr [ebp - 0x14]
    cmp eax, dword ptr [DAT_0005c730]
    jle short L_000428ee
    push dword ptr [ebp - 8]
    push dword ptr [B000755e4_bk]
    push dword ptr [ebp - 0x14]
    push dword ptr [ebp - 0x10]
    call L_000438c8
    add esp, 0x10
    inc dword ptr [ebp - 8]
    mov ah, byte ptr [esi + DAT_0005c664 + 024h]
    cmp ah, 0
    je short L_000428bb
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 8]
    push dword ptr [B000755e4_bk]
    push dword ptr [ebp - 0x14]
    push dword ptr [ebp - 0x10]
    call L_000438c8
    add esp, 0x10
L_000428bb:
    inc dword ptr [ebp - 8]
    mov ah, byte ptr [esi + DAT_0005c664 + 044h]
    cmp ah, 0
    je near ptr L_0004294d
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 8]
    push dword ptr [B000755e4_bk]
    push dword ptr [ebp - 0x14]
    push dword ptr [ebp - 0x10]
    call L_000438c8
    add esp, 0x10
    jmp short L_0004294d
L_000428ee:
    push dword ptr [ebp - 0x10]
    push dword ptr [ebp - 8]
    push dword ptr [ebp - 4]
    call L_00042620
    add esp, 0xc
    inc dword ptr [ebp - 8]
    mov ah, byte ptr [esi + DAT_0005c664 + 024h]
    cmp ah, 0
    je short L_00042926
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 0x10]
    push dword ptr [ebp - 8]
    push dword ptr [ebp - 4]
    call L_00042620
    add esp, 0xc
L_00042926:
    inc dword ptr [ebp - 8]
    mov ah, byte ptr [esi + DAT_0005c664 + 044h]
    org 051ah
    mov byte ptr [L_00042c1a], 0x8d
    mov byte ptr [L_00042d04], 0x8d
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    sub ebx, 0xa8c
    mov eax, dword ptr [edi + ebx*4]
    mov dword ptr [B00075608_c1], eax
    mov ebx, 0xe0f
    db 02bh, 0deh    ; sub ebx, esi (WASM encodes it differently)
    mov eax, dword ptr [edi + ebx*4]
    mov dword ptr [B00075600_b9], eax
    push dword ptr [DAT_0005c6f4 + 01ch]
    push dword ptr [DAT_0005c6f4 + 014h]
    jmp short L_00042b80
L_00042b75:
    sub esi, 0xe10
    jmp near ptr L_00042a19
L_00042b80:
    push dword ptr [B00075608_c1]
    call FUN_000456d8
    add esp, 8
    add eax, dword ptr [B000755ec_aH]
    mov dword ptr [B000755f0_co], eax
    movsx ecx, word ptr [B000755f2_by]
    push dword ptr [B00075600_b9]
    call FUN_000456d8
    add esp, 8
    add eax, dword ptr [B000755f4_ck]
    mov dword ptr [B000755e8_ag], eax
    movsx ebx, word ptr [B000755ea_aN]
    mov eax, dword ptr [DAT_0005c6f4 + 030h]
    shl eax, 0x10
    add eax, dword ptr [B00075610_a9]
    mov dword ptr [B000748e4_h8], eax
    mov eax, dword ptr [DAT_0005c6f4 + 02ch]
    shl eax, 0x10
    add eax, dword ptr [B00075604_mM]
    mov dword ptr [B000748e8_jD], eax
    movsx eax, word ptr [B000748e4_h8+2]
    movsx edx, word ptr [B00075619_b0]
    mul edx
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    shl esi, 1
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    movsx edx, word ptr [B00075619_b0]
    mul edx
    add ax, word ptr [B000748e8_jD+2]
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    shl edi, 1
L_00042c12:
    cmp bx, word ptr [B000748e8_jD+2]
    db 00fh
L_00042c1a:
    db 08eh, 0eah, 000h, 000h, 000h
L_00042c1f:
    shr esi, 1
    mov dword ptr [DAT_0005fcdc], esi
    cmp esi, dword ptr [DAT_0005fd0c]
    jb short L_00042c39
    call L_00042f4c
    jmp near ptr L_000429b2
L_00042c39:
    shl esi, 1
    test word ptr [esi + B000698e0_b7], 0x3f
    jne short L_00042c89
L_00042c46:
    or word ptr [esi + B000698e0_b7], 0x440
L_00042c4f:
    mov eax, dword ptr [B00075610_a9]
    add dword ptr [B000748e4_h8], eax
    mov eax, dword ptr [B00075600_b9]
    add dword ptr [B000755e8_ag], eax
    movsx ebx, word ptr [B000755ea_aN]
    movsx eax, word ptr [B000748e4_h8+2]
    movsx edx, word ptr [B00075619_b0]
    mul edx
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    shl esi, 1
    mov dword ptr [DAT_0005fcdc], eax
    jmp short L_00042c12
L_00042c89:
    test dword ptr [DAT_0005fd08], 0xffffffff
    je short L_00042ca0
    test word ptr [esi + B000698e0_b7], 0x800
    jne short L_00042c46
L_00042ca0:
    or word ptr [esi + B000698e0_b7], 0x440
    movzx eax, word ptr [esi + B000698e0_b7]
    push eax
    and eax, 0x200
    shr eax, 9
    mov dword ptr [DAT_0005fcd4], eax
    pop eax
    and eax, 0x3f
    mov dword ptr [DAT_0005c6f4 + 0ch], eax
    test word ptr [esi + B000698e0_b7], 0x80
    jne near ptr L_00042de6
    mov eax, dword ptr [B000748e4_h8]
    mov ax, 0
    mov dword ptr [B000755f0_co], eax
    mov word ptr [B000748e8_jD+2], bx
    call L_00042f8c
    movsx ecx, word ptr [B000755f2_by]
    jmp near ptr L_000429b2
L_00042cfc:
    cmp cx, word ptr [B000748e4_h8+2]
    db 00fh
L_00042d04:
    db 08eh, 016h, 0ffh, 0ffh, 0ffh
L_00042d09:
    shr edi, 1
    mov dword ptr [DAT_0005fcdc], edi
    cmp edi, dword ptr [DAT_0005fd0c]
    org 04c1h
    mov byte ptr [L_00042c1a], 0x8d
    mov byte ptr [L_00042d04], 0x8e
    org 0463h
    mov byte ptr [L_00042c1a], 0x8e
    mov byte ptr [L_00042d04], 0x8e
    org 040dh
    mov byte ptr [L_00042c1a], 0x8e
    mov byte ptr [L_00042d04], 0x8d
    org 04cfh
    mov ebx, 0xa8b
    db 02bh, 0deh    ; sub ebx, esi (WASM encodes it differently)
    mov eax, dword ptr [edi + ebx*4]
    neg eax
    mov dword ptr [B00075608_c1], eax
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    sub ebx, 0x708
    mov eax, dword ptr [edi + ebx*4]
    mov dword ptr [B00075600_b9], eax
    push dword ptr [DAT_0005c6f4 + 018h]
    push dword ptr [DAT_0005c6f4 + 014h]
    jmp short L_00042b80
L_00042b1e:
    cmp esi, 0xe10
    jge short L_00042b75
L_00042b26:
    mov dword ptr [B00075610_a9], 0x10000
    mov dword ptr [B00075604_mM], 0x10000
    org 0471h
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    sub ebx, 0x384
    mov eax, dword ptr [edi + ebx*4]
    neg eax
    mov dword ptr [B00075608_c1], eax
    mov ebx, 0x707
    db 02bh, 0deh    ; sub ebx, esi (WASM encodes it differently)
    mov eax, dword ptr [edi + ebx*4]
    neg eax
    mov dword ptr [B00075600_b9], eax
    push dword ptr [DAT_0005c6f4 + 018h]
    push dword ptr [DAT_0005c6f4 + 010h]
    jmp near ptr L_00042b80
L_00042ac5:
    cmp esi, 0xa8c
    jge short L_00042b1e
    mov dword ptr [B00075610_a9], 0xffff0000
    mov dword ptr [B00075604_mM], 0x10000
    org 041bh
    mov ebx, 0x383
    db 02bh, 0deh    ; sub ebx, esi (WASM encodes it differently)
    mov eax, dword ptr [edi + ebx*4]
    mov dword ptr [B00075608_c1], eax
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    mov eax, dword ptr [edi + ebx*4]
    neg eax
    mov dword ptr [B00075600_b9], eax
    push dword ptr [DAT_0005c6f4 + 01ch]
    push dword ptr [DAT_0005c6f4 + 010h]
    jmp near ptr L_00042b80
L_00042a67:
    cmp esi, 0x708
    jge short L_00042ac5
    mov dword ptr [B00075610_a9], 0xffff0000
    mov dword ptr [B00075604_mM], 0xffff0000
    org 030fh
    cmp ah, 0
    je short L_0004294d
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    push dword ptr [ebp - 0x10]
    push dword ptr [ebp - 8]
    push dword ptr [ebp - 4]
    call L_00042620
    add esp, 0xc
L_0004294d:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00042954
L_00042954:
    enter 0, 0
    mov dword ptr [DAT_0005fce8], 0xffffffff
    mov dword ptr [DAT_0005fcec], 0xffffffff
    cmp dword ptr [DAT_0005cf50], 0
    jne short L_0004299c
    mov eax, dword ptr [DAT_0005c658]
    cmp dword ptr [DAT_0005fd04], eax
    jne short L_0004299c
    mov eax, dword ptr [DAT_0005fcfc]
    cmp dword ptr [B000755d0_ao], eax
    jne short L_0004299c
    mov eax, dword ptr [DAT_0005fd00]
    cmp dword ptr [B000755d4_ak], eax
    je short L_000429a6
L_0004299c:
    push ebx
    push ecx
    push esi
    push edi
    jmp short L_000429a8
L_000429a2:
    pop edi
    pop esi
    pop ecx
    pop ebx
L_000429a6:
    leave
    ret
L_000429a8:
    mov dword ptr [DAT_0005c6f4 + 08h], 0xffffffff
L_000429b2:
    inc dword ptr [DAT_0005c6f4 + 08h]
    mov eax, dword ptr [DAT_0005c6f4 + 08h]
    cmp dword ptr [DAT_0005c6d8], eax
    jbe short L_000429a2
    mov ebx, dword ptr [DAT_0005c6f4 + 08h]
    mov esi, 0
    mov esi, dword ptr [ebx*4 + DAT_0005c73c]
    add esi, dword ptr [DAT_0005c6f4 + 020h]
    mov edi, 0
    mov ebx, 0
    mov edi, dword ptr [DAT_0005c660]
    mov dword ptr [DAT_0005fcd4], 0
    mov dword ptr [DAT_0005fcd8], 0
    cmp esi, 0
    jge short L_00042a11
    add esi, 0xe10
    jmp near ptr L_00042b26
L_00042a11:
    cmp esi, 0x384
    jge short L_00042a67
L_00042a19:
    mov dword ptr [B00075610_a9], 0x10000
    mov dword ptr [B00075604_mM], 0xffff0000
    org 06f7h
    jb short L_00042d23
    call L_00042f4c
    jmp near ptr L_000429b2
L_00042d23:
    shl edi, 1
    test word ptr [edi + B000698e0_b7], 0x3f
    jne short L_00042d73
L_00042d30:
    or word ptr [edi + B000698e0_b7], 0x440
L_00042d39:
    mov eax, dword ptr [B00075604_mM]
    add dword ptr [B000748e8_jD], eax
    mov eax, dword ptr [B00075608_c1]
    add dword ptr [B000755f0_co], eax
    movsx ecx, word ptr [B000755f2_by]
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    movsx edx, word ptr [B00075619_b0]
    mul edx
    add ax, word ptr [B000748e8_jD+2]
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    shl edi, 1
    mov dword ptr [DAT_0005fcdc], eax
    jmp short L_00042cfc
L_00042d73:
    test dword ptr [DAT_0005fd08], 0xffffffff
    je short L_00042d8a
    test word ptr [edi + B000698e0_b7], 0x800
    jne short L_00042d30
L_00042d8a:
    or word ptr [edi + B000698e0_b7], 0x440
    movzx eax, word ptr [edi + B000698e0_b7]
    push eax
    and eax, 0x200
    shr eax, 9
    mov dword ptr [DAT_0005fcd4], eax
    pop eax
    and eax, 0x3f
    mov dword ptr [DAT_0005c6f4 + 0ch], eax
    test word ptr [edi + B000698e0_b7], 0x80
    jne near ptr L_00042e9d
    mov eax, dword ptr [B000748e8_jD]
    mov ax, 0
    mov dword ptr [B000755e8_ag], eax
    mov word ptr [B000748e4_h8+2], cx
    call L_00043124
    movsx ebx, word ptr [B000755ea_aN]
    jmp near ptr L_000429b2
L_00042de6:
    mov eax, dword ptr [B00075600_b9]
    sar eax, 1
    add eax, dword ptr [B000755e8_ag]
    ror eax, 0x10
    db 066h, 03bh, 0d8h    ; cmp bx, ax (WASM encodes it differently)
    jne near ptr L_00042c4f
    ror eax, 0x10
    push eax
    mov edx, dword ptr [DAT_0005fcdc]
    cmp edx, dword ptr [DAT_0005fce8]
    je short L_00042e49
    push ebx
    push ecx
    push dword ptr [DAT_0005fcdc]
    call FUN_0002e930
    add esp, 4
    db 066h, 08bh, 0d8h    ; mov bx, ax (WASM encodes it differently)
    movsx eax, bx
    pop ecx
    pop ebx
    mov dword ptr [DAT_0005fce0], eax
    mov eax, 0xffffffff
    sub eax, dword ptr [DAT_0005fce0]
    inc eax
    mov dword ptr [DAT_0005fce4], eax
    mov eax, dword ptr [DAT_0005fcdc]
    mov dword ptr [DAT_0005fce8], eax
L_00042e49:
    pop eax
    db 08bh, 0d0h    ; mov edx, eax (WASM encodes it differently)
    movsx eax, dx
    cmp dword ptr [DAT_0005fce0], 0
    je near ptr L_00042c4f
    cmp eax, dword ptr [DAT_0005fce0]
    jbe short L_00042e71
    cmp eax, dword ptr [DAT_0005fce4]
    jae short L_00042e71
    jmp near ptr L_00042c4f
L_00042e71:
    mov dword ptr [B000755e8_ag], edx
    mov eax, dword ptr [B000748e4_h8]
    mov ax, 0x8000
    mov dword ptr [B000755f0_co], eax
    call L_000432b4
    movsx ecx, word ptr [B000755f2_by]
    movsx ebx, word ptr [B000755ea_aN]
    jmp near ptr L_000429b2
L_00042e9d:
    mov eax, dword ptr [B00075608_c1]
    sar eax, 1
    add eax, dword ptr [B000755f0_co]
    ror eax, 0x10
    db 066h, 03bh, 0c8h    ; cmp cx, ax (WASM encodes it differently)
    jne near ptr L_00042d39
    ror eax, 0x10
    push eax
    mov edx, dword ptr [DAT_0005fcdc]
    cmp edx, dword ptr [DAT_0005fce8]
    je short L_00042ef6
    push ebx
    push ecx
    push dword ptr [DAT_0005fcdc]
    call FUN_0002e930
    add esp, 4
    db 066h, 08bh, 0d8h    ; mov bx, ax (WASM encodes it differently)
    movsx eax, bx
    pop ecx
    pop ebx
    mov dword ptr [DAT_0005fce0], eax
    neg eax
    mov dword ptr [DAT_0005fce4], eax
    mov eax, dword ptr [DAT_0005fcdc]
    mov dword ptr [DAT_0005fce8], eax
L_00042ef6:
    pop eax
    db 08bh, 0d0h    ; mov edx, eax (WASM encodes it differently)
    movsx eax, dx
    cmp dword ptr [DAT_0005fce0], 0
    je near ptr L_00042d39
    cmp eax, dword ptr [DAT_0005fce0]
    jbe short L_00042f1e
    cmp eax, dword ptr [DAT_0005fce4]
    jae short L_00042f1e
    jmp near ptr L_00042d39
L_00042f1e:
    mov dword ptr [B000755f0_co], edx
    mov eax, dword ptr [B000748e8_jD]
    mov ax, 0x8000
    mov dword ptr [B000755e8_ag], eax
    call L_000433bc
    movsx ecx, word ptr [B000755f2_by]
    movsx ebx, word ptr [B000755ea_aN]
    org $
    jmp near ptr L_000429b2
    xchg ebx, ebx
; ---- FUN_00042f4c
L_00042f4c:
    push eax
    db 06bh, 005h    ; imul eax, dword ptr [DAT_0005c6f4 + 08h], 0x1c (WASM adds the displacement constant to the immediate)
    dd offset DAT_0005c6f4 + 08h
    db 01ch
    add eax, offset B00065a18_cn
    mov dword ptr [eax], 0
    mov dword ptr [eax + 4], 0x93
    mov dword ptr [eax + 8], 0x93
    mov dword ptr [eax + 0xc], 0
    mov dword ptr [eax + 0x10], 0
    mov dword ptr [eax + 0x14], 0
    mov dword ptr [eax + 0x18], 0
    pop eax
    ret
    nop
; ---- FUN_00042f8c
L_00042f8c:
    enter 0x10, 0
    push ebx
    push esi
    push edi
    mov eax, dword ptr [B000755e8_ag]
    shr eax, 4
    and eax, 0xfc0
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    mov dword ptr [ebp - 4], esi
    cmp dword ptr [B00075610_a9], 0xffff0000
    jne short L_00042fc2
    mov eax, 0xfc0
    db 02bh, 0c6h    ; sub eax, esi (WASM encodes it differently)
    mov dword ptr [ebp - 4], eax
    inc word ptr [B000755f2_by]
L_00042fc2:
    call FUN_00045730
    mov dword ptr [ebp - 8], eax
    mov eax, dword ptr [DAT_0005c6f4 + 0ch]
    mov dword ptr [ebp - 0xc], eax
    mov dword ptr [ebp - 0x10], 0
    mov edi, dword ptr [DAT_0005fcdc]
    shl edi, 1
    or word ptr [edi + B000698e0_b7], 0x440
    movzx eax, word ptr [edi + B000698e0_b7]
    and eax, 0xc000
    shr eax, 0xe
    push eax
    test word ptr [edi + B000698e0_b7], 0x100
    je short L_00043049
    movsx eax, word ptr [B00075612_lo]
    movsx edx, word ptr [B00075619_b0]
    mul edx
    shl eax, 1
    db 08bh, 0d7h    ; mov edx, edi (WASM encodes it differently)
    db 02bh, 0f8h    ; sub edi, eax (WASM encodes it differently)
    mov ax, word ptr [B000755ea_aN]
    mov word ptr [B000748e8_jD+2], ax
    test word ptr [edi + B000698e0_b7], 0x80
    je short L_00043049
    movzx eax, word ptr [edi + B000698e0_b7]
    and eax, 0x3f
    mov dword ptr [ebp - 0xc], eax
    mov dword ptr [ebp - 4], esi
    mov dword ptr [ebp - 0x10], 1
L_00043049:
    mov edi, dword ptr [DAT_0005fcdc]
    shl edi, 1
    or word ptr [edi + B000698e0_b7], 0x440
    test word ptr [edi + B000698e0_b7], 0x1000
    je short L_00043085
    cmp dword ptr [ebp - 0x10], 0
    jne short L_00043085
    push ebx
    push ecx
    push dword ptr [DAT_0005fcdc]
    call FUN_0002e9a0
    add esp, 4
    pop ecx
    pop ebx
    and eax, 0xffff
    mov dword ptr [ebp - 0x10], eax
L_00043085:
    mov eax, dword ptr [DAT_0005c6f4 + 08h]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    pop eax
    mov dword ptr [esi + B00065a30_af], eax
    mov eax, dword ptr [ebp - 8]
    mov dword ptr [esi + B00065a18_cn], eax
    mov eax, dword ptr [ebp - 4]
    mov dword ptr [esi + B00065a28_bn], eax
    mov ebx, dword ptr [ebp - 0xc]
    shl ebx, 1
    movzx eax, word ptr [ebx + B000757a2_bK]
    add eax, dword ptr [ebp - 0x10]
    mov dword ptr [esi + B00065a1c_ai], eax
    movzx eax, word ptr [ebx + B00075722_nn]
    add eax, dword ptr [ebp - 0x10]
    mov dword ptr [esi + B00065a20_bf], eax
    mov eax, dword ptr [DAT_0005fcd4]
    mov dword ptr [esi + B00065a24_aj], eax
    mov eax, dword ptr [DAT_0005fcdc]
    mov dword ptr [esi + B00065a2c_ay], eax
    cmp dword ptr [esi + B00065a20_bf], 0x93
    jne short L_000430fd
    mov dword ptr [B00072220_gw], 0
L_000430fd:
    mov eax, dword ptr [esi + B00065a18_cn]
    cmp eax, dword ptr [B00072220_gw]
    jge short L_00043110
    mov dword ptr [B00072220_gw], eax
L_00043110:
    cmp eax, dword ptr [DAT_0005bf34]
    jle short L_0004311d
    mov dword ptr [DAT_0005bf34], eax
    org $
L_0004311d:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    xchg ebx, ebx
; ---- FUN_00043124
L_00043124:
    enter 0x10, 0
    push ebx
    push esi
    push edi
    mov eax, dword ptr [B000755f0_co]
    shr eax, 4
    and eax, 0xfc0
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    mov dword ptr [ebp - 4], esi
    cmp dword ptr [B00075604_mM], 0xffff0000
    jne short L_00043152
    inc word ptr [B000755ea_aN]
    jmp short L_0004315c
L_00043152:
    mov eax, 0xfc0
    db 02bh, 0c6h    ; sub eax, esi (WASM encodes it differently)
    mov dword ptr [ebp - 4], eax
L_0004315c:
    call FUN_00045730
    mov dword ptr [ebp - 8], eax
    mov eax, dword ptr [DAT_0005c6f4 + 0ch]
    mov dword ptr [ebp - 0xc], eax
    mov dword ptr [ebp - 0x10], 0
    mov edi, dword ptr [DAT_0005fcdc]
    shl edi, 1
    or word ptr [edi + B000698e0_b7], 0x440
    movzx eax, word ptr [edi + B000698e0_b7]
    and eax, 0xc000
    shr eax, 0xe
    push eax
    test word ptr [edi + B000698e0_b7], 0x100
    je short L_000431da
    movsx eax, word ptr [B00075606_b3]
    shl eax, 1
    db 08bh, 0d7h    ; mov edx, edi (WASM encodes it differently)
    db 02bh, 0f8h    ; sub edi, eax (WASM encodes it differently)
    mov ax, word ptr [B000755f2_by]
    mov word ptr [B000748e4_h8+2], ax
    test word ptr [edi + B000698e0_b7], 0x80
    je short L_000431da
    movzx eax, word ptr [edi + B000698e0_b7]
    and eax, 0x3f
    mov dword ptr [ebp - 0xc], eax
    mov dword ptr [ebp - 4], esi
    mov dword ptr [ebp - 0x10], 1
L_000431da:
    mov edi, dword ptr [DAT_0005fcdc]
    shl edi, 1
    or word ptr [edi + B000698e0_b7], 0x440
    test word ptr [edi + B000698e0_b7], 0x1000
    je short L_00043216
    cmp dword ptr [ebp - 0x10], 0
    jne short L_00043216
    push ebx
    push ecx
    push dword ptr [DAT_0005fcdc]
    call FUN_0002e9a0
    add esp, 4
    pop ecx
    pop ebx
    and eax, 0xffff
    mov dword ptr [ebp - 0x10], eax
L_00043216:
    mov eax, dword ptr [DAT_0005c6f4 + 08h]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    pop eax
    mov dword ptr [esi + B00065a30_af], eax
    mov eax, dword ptr [ebp - 8]
    mov dword ptr [esi + B00065a18_cn], eax
    mov eax, dword ptr [ebp - 4]
    mov dword ptr [esi + B00065a28_bn], eax
    mov ebx, dword ptr [ebp - 0xc]
    shl ebx, 1
    movzx eax, word ptr [ebx + B000756a2_ah]
    add eax, dword ptr [ebp - 0x10]
    mov dword ptr [esi + B00065a1c_ai], eax
    movzx eax, word ptr [ebx + B00075622_mo]
    add eax, dword ptr [ebp - 0x10]
    mov dword ptr [esi + B00065a20_bf], eax
    mov eax, dword ptr [DAT_0005fcd4]
    mov dword ptr [esi + B00065a24_aj], eax
    mov eax, dword ptr [DAT_0005fcdc]
    mov dword ptr [esi + B00065a2c_ay], eax
    cmp dword ptr [esi + B00065a20_bf], 0x93
    jne short L_0004328e
    mov dword ptr [B00072220_gw], 0
L_0004328e:
    mov eax, dword ptr [esi + B00065a18_cn]
    cmp eax, dword ptr [B00072220_gw]
    jge short L_000432a1
    mov dword ptr [B00072220_gw], eax
L_000432a1:
    cmp eax, dword ptr [DAT_0005bf34]
    jle short L_000432ae
    mov dword ptr [DAT_0005bf34], eax
L_000432ae:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    nop
; ---- FUN_000432b4
L_000432b4:
    enter 0, 0
    push ebx
    push esi
    push edi
    cmp word ptr [B000755e8_ag], 0x8000
    jb short L_000432df
    mov eax, dword ptr [B000755e8_ag]
    movzx ebx, word ptr [DAT_0005fce4]
    sub ebx, 0x8000
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    shr eax, 4
    jmp short L_000432f6
L_000432df:
    mov eax, dword ptr [B000755e8_ag]
    movzx ebx, word ptr [DAT_0005fce4]
    sub ebx, 0x8000
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    shr eax, 4
L_000432f6:
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    and esi, 0xfc0
    mov edi, dword ptr [DAT_0005fcdc]
    shl edi, 1
    or word ptr [edi + B000698e0_b7], 0x440
    movzx eax, word ptr [edi + B000698e0_b7]
    and eax, 0xc000
    shr eax, 0xe
    push eax
    call FUN_00045730
    push eax
    mov eax, dword ptr [DAT_0005c6f4 + 08h]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    pop eax
    mov dword ptr [edi + B00065a18_cn], eax
    pop eax
    mov dword ptr [edi + B00065a30_af], eax
    mov dword ptr [edi + B00065a28_bn], esi
    mov eax, dword ptr [DAT_0005fcd4]
    mov dword ptr [edi + B00065a24_aj], eax
    mov eax, dword ptr [DAT_0005fcdc]
    mov dword ptr [edi + B00065a2c_ay], eax
    mov ebx, dword ptr [DAT_0005c6f4 + 0ch]
    shl ebx, 1
    movzx eax, word ptr [ebx + B000756a2_ah]
    mov dword ptr [edi + B00065a1c_ai], eax
    movzx eax, word ptr [ebx + B00075622_mo]
    mov dword ptr [edi + B00065a20_bf], eax
    cmp dword ptr [edi + B00065a20_bf], 0x93
    jne short L_00043395
    mov dword ptr [B00072220_gw], 0
L_00043395:
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [B00072220_gw]
    jge short L_000433a8
    mov dword ptr [B00072220_gw], eax
L_000433a8:
    cmp eax, dword ptr [DAT_0005bf34]
    jle short L_000433b5
    mov dword ptr [DAT_0005bf34], eax
    org $
L_000433b5:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    xchg ebx, ebx
; ---- FUN_000433bc
L_000433bc:
    enter 0, 0
    push ebx
    push esi
    push edi
    cmp word ptr [B000755f0_co], 0x8000
    jb short L_000433e7
    mov eax, dword ptr [B000755f0_co]
    movzx ebx, word ptr [DAT_0005fce4]
    sub ebx, 0x8000
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    shr eax, 4
    jmp short L_000433fe
L_000433e7:
    mov eax, dword ptr [B000755f0_co]
    movzx ebx, word ptr [DAT_0005fce4]
    sub ebx, 0x8000
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    shr eax, 4
L_000433fe:
    db 08bh, 0f0h    ; mov esi, eax (WASM encodes it differently)
    and esi, 0xfc0
    mov edi, dword ptr [DAT_0005fcdc]
    shl edi, 1
    or word ptr [edi + B000698e0_b7], 0x440
    movzx eax, word ptr [edi + B000698e0_b7]
    and eax, 0xc000
    shr eax, 0xe
    push eax
    call FUN_00045730
    push eax
    mov eax, dword ptr [DAT_0005c6f4 + 08h]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    pop eax
    mov dword ptr [edi + B00065a18_cn], eax
    pop eax
    mov dword ptr [edi + B00065a30_af], eax
    mov dword ptr [edi + B00065a28_bn], esi
    mov eax, dword ptr [DAT_0005fcd4]
    mov dword ptr [edi + B00065a24_aj], eax
    mov eax, dword ptr [DAT_0005fcdc]
    mov dword ptr [edi + B00065a2c_ay], eax
    mov ebx, dword ptr [DAT_0005c6f4 + 0ch]
    shl ebx, 1
    movzx eax, word ptr [ebx + B000756a2_ah]
    mov dword ptr [edi + B00065a1c_ai], eax
    movzx eax, word ptr [ebx + B00075622_mo]
    mov dword ptr [edi + B00065a20_bf], eax
    cmp dword ptr [edi + B00065a20_bf], 0x93
    jne short L_0004349d
    mov dword ptr [B00072220_gw], 0
L_0004349d:
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [B00072220_gw]
    jge short L_000434b0
    mov dword ptr [B00072220_gw], eax
L_000434b0:
    cmp eax, dword ptr [DAT_0005bf34]
    jle short L_000434bd
    mov dword ptr [DAT_0005bf34], eax
    org $
L_000434bd:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    xchg ebx, ebx
; ---- FUN_000434c4
FUN_000434c4:
    enter 0, 0
    push ebx
    push edi
    push esi
    movzx eax, word ptr [B00075619_b0]
    movzx ebx, word ptr [B0007561b_io]
    imul eax, ebx
    mov dword ptr [DAT_0005fd0c], eax
    mov ebx, 0
    mov ecx, dword ptr [DAT_0005fd0c]
L_000434ec:
    and byte ptr [ebx*2 + B000698e0_b7], 0xbf
    inc ebx
    dec ecx
    jne short L_000434ec
    mov eax, dword ptr [DAT_0005c658]
    mov ebx, 0xa
    mul ebx
    mov dword ptr [DAT_0005c6f4 + 020h], eax
    mov edi, dword ptr [DAT_0005c65c]
    mov ebx, dword ptr [DAT_0005c658]
    mov eax, dword ptr [edi + ebx*4]
    mov dword ptr [B000755fc_ax], eax
    add ebx, 0x5a
    mov eax, dword ptr [edi + ebx*4]
    mov dword ptr [B000755f8_bg], eax
    push dword ptr [B000755f8_bg]
    push dword ptr [B0007560c_hn]
    call FUN_00045680
    add esp, 8
    push eax
    pop ebx
    mov eax, dword ptr [B000755d4_ak]
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    mov dword ptr [B000755ec_aH], eax
    and eax, 0xffff
    mov dword ptr [DAT_0005c6f4 + 018h], eax
    neg eax
    mov dword ptr [DAT_0005c6f4 + 01ch], eax
    push dword ptr [B000755fc_ax]
    push dword ptr [B0007560c_hn]
    call FUN_00045680
    add esp, 8
    push eax
    pop ebx
    mov eax, dword ptr [B000755d0_ao]
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    mov dword ptr [B000755f4_ck], eax
    and eax, 0xffff
    mov dword ptr [DAT_0005c6f4 + 010h], eax
    neg eax
    mov dword ptr [DAT_0005c6f4 + 014h], eax
    movsx eax, word ptr [B000755ee_aJ]
    mov dword ptr [DAT_0005c6f4 + 030h], eax
    movsx eax, word ptr [B000755f6_bu]
    mov dword ptr [DAT_0005c6f4 + 02ch], eax
    movsx eax, word ptr [B000755d6_ae]
    mov dword ptr [DAT_0005c6f4 + 028h], eax
    movsx eax, word ptr [B000755d2_ai]
    mov dword ptr [DAT_0005c6f4 + 024h], eax
    mov dword ptr [DAT_0005c6f4 + 038h], 0xffffffff
    mov dword ptr [B00072220_gw], 0x800
    call L_00042954
    pop esi
    pop edi
    pop ebx
    leave
    ret
; ---- FUN_000435dc
FUN_000435dc:
    enter 0, 0
    pushad
    mov esi, offset B00065a18_cn
    mov edi, 0
    mov dword ptr [DAT_0005fcd0], 1
    mov dword ptr [DAT_0005c6f4], 1
    mov dword ptr [DAT_0005c6f4 + 04h], 0
    mov dword ptr [DAT_0005fcf2], 0
L_00043613:
    cmp dword ptr [esi + 0xc], 1
    je short L_00043625
    add esi, 0x1c
    inc edi
    cmp edi, dword ptr [DAT_0005c6d8]
    jne short L_00043613
L_00043625:
    cmp edi, dword ptr [DAT_0005c6d8]
    jge near ptr L_000436f7
    mov dword ptr [DAT_0005c6f4 + 04h], edi
    mov eax, dword ptr [esi + 0x18]
    mov dword ptr [DAT_0005fcf2], eax
    mov eax, dword ptr [esi + 4]
    mov dword ptr [DAT_0005c6f4 + 0ch], eax
    mov eax, dword ptr [esi + 0x10]
    shl eax, 1
    mov dword ptr [B000755e4_bk], eax
    push 4
    push dword ptr [DAT_0005c6f4 + 0ch]
    call FUN_0003f29c
    add esp, 8
    add eax, 2
    add dword ptr [B000755e4_bk], eax
    jmp short L_000436e2
L_0004366c:
    cmp dword ptr [esi + 0xc], 1
    je short L_00043683
    call L_0004263c
    mov dword ptr [DAT_0005c6f4], 1
    jmp short L_00043613
L_00043683:
    mov eax, dword ptr [esi]
    cmp eax, dword ptr [esi - 0x1c]
    jne short L_00043692
    mov eax, dword ptr [esi + 0x10]
    cmp eax, dword ptr [esi - 0xc]
    je short L_000436dc
L_00043692:
    call L_0004263c
    mov dword ptr [DAT_0005c6f4], 1
    mov dword ptr [DAT_0005c6f4 + 04h], edi
    mov eax, dword ptr [esi + 0x18]
    mov dword ptr [DAT_0005fcf2], eax
    mov eax, dword ptr [esi + 4]
    mov dword ptr [DAT_0005c6f4 + 0ch], eax
    push 4
    push dword ptr [DAT_0005c6f4 + 0ch]
    call FUN_0003f29c
    add esp, 8
    add eax, 2
    mov dword ptr [B000755e4_bk], eax
    mov eax, dword ptr [esi + 0x10]
    shl eax, 1
    add dword ptr [B000755e4_bk], eax
    jmp short L_000436e2
L_000436dc:
    inc dword ptr [DAT_0005c6f4]
L_000436e2:
    inc edi
    add esi, 0x1c
    cmp edi, dword ptr [DAT_0005c6d8]
    jne near ptr L_0004366c
    call L_0004263c
L_000436f7:
    mov esi, offset B00065a18_cn
    mov edi, 0
    mov dword ptr [DAT_0005fcd0], 0
    mov dword ptr [DAT_0005c6f4], 1
    mov dword ptr [DAT_0005c6f4 + 04h], 0
    mov eax, dword ptr [esi + 8]
    mov dword ptr [DAT_0005c6f4 + 0ch], eax
    mov eax, dword ptr [esi + 0x18]
    mov dword ptr [DAT_0005fcf2], eax
    mov eax, dword ptr [esi + 0x10]
    shl eax, 1
    mov dword ptr [B000755e4_bk], eax
    push 4
    push dword ptr [DAT_0005c6f4 + 0ch]
    call FUN_0003f29c
    add esp, 8
    add eax, 2
    add dword ptr [B000755e4_bk], eax
    jmp short L_000437b3
L_00043754:
    mov eax, dword ptr [esi]
    cmp eax, dword ptr [esi - 0x1c]
    jne short L_00043763
    mov eax, dword ptr [esi + 0x10]
    cmp eax, dword ptr [esi - 0xc]
    je short L_000437ad
L_00043763:
    call L_0004263c
    mov dword ptr [DAT_0005c6f4], 1
    mov dword ptr [DAT_0005c6f4 + 04h], edi
    mov eax, dword ptr [esi + 0x18]
    mov dword ptr [DAT_0005fcf2], eax
    mov eax, dword ptr [esi + 8]
    mov dword ptr [DAT_0005c6f4 + 0ch], eax
    push 4
    push dword ptr [DAT_0005c6f4 + 0ch]
    call FUN_0003f29c
    add esp, 8
    add eax, 2
    mov dword ptr [B000755e4_bk], eax
    mov eax, dword ptr [esi + 0x10]
    shl eax, 1
    add dword ptr [B000755e4_bk], eax
    jmp short L_000437b3
L_000437ad:
    inc dword ptr [DAT_0005c6f4]
L_000437b3:
    inc edi
    add esi, 0x1c
    cmp edi, dword ptr [DAT_0005c6d8]
    jne short L_00043754
    call L_0004263c
    popad
    leave
    ret
    nop
; ---- FUN_000437c8
L_000437c8:
    enter 0, 0
    push ebx
    push ecx
    push edi
    mov edi, dword ptr [ebp + 8]
    mov ecx, 0
    mov edx, dword ptr [ebp + 0xc]
    movsx ebx, byte ptr [B00075621_lx]
    shl ebx, 1
L_000437e3:
    add cx, word ptr [edi + ebx + 0x102]
    db 03bh, 0cah    ; cmp ecx, edx (WASM encodes it differently)
    jge short L_000437f4
    sub ebx, 2
    jge short L_000437e3
L_000437f4:
    sub ebx, 2
    jae short L_000437fe
    mov ebx, 0
L_000437fe:
    movzx eax, word ptr [edi + ebx]
    pop edi
    pop ecx
    pop ebx
    leave
    ret
    nop
; ---- FUN_00043808
FUN_00043808:
    enter 0, 0
    pushad
    mov eax, dword ptr [ebp + 0x10]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov esi, dword ptr [ebp + 0x14]
    mov eax, dword ptr [edi + B00065a20_bf]
    mov dword ptr [esi], eax
    mov esi, dword ptr [ebp + 0x18]
    mov eax, dword ptr [edi + B00065a28_bn]
    shr eax, 6
    mov dword ptr [esi], eax
    mov eax, dword ptr [edi + B00065a2c_ay]
    mov edx, 0
    movsx ebx, word ptr [B00075619_b0]
    div ebx
    mov esi, dword ptr [ebp + 0x20]
    mov dword ptr [esi], edx
    mov esi, dword ptr [ebp + 0x24]
    mov dword ptr [esi], eax
    mov esi, dword ptr [ebp + 0x1c]
    mov word ptr [esi], 0xffff
    mov ebx, 0
    mov edi, 0
    mov ebx, dword ptr [ebp + 8]
    cmp ebx, dword ptr [DAT_0005c738]
    jae short L_000438c2
    mov eax, dword ptr [ebx*4 + B00065618_e1]
    cmp eax, 0
    je short L_000438c2
    mov edi, dword ptr [ebx*4 + B00068fe0_eN]
    sub edi, 0x102
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    shr eax, 3
    add eax, 0x84
    shr ebx, 1
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    db 08bh, 0d0h    ; mov edx, eax (WASM encodes it differently)
    mov ecx, 0
    mov ebx, 0
L_000438a0:
    movzx eax, word ptr [edi + ebx*2]
    db 003h, 0c8h    ; add ecx, eax (WASM encodes it differently)
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    db 003h, 0c2h    ; add eax, edx (WASM encodes it differently)
    cmp eax, dword ptr [ebp + 0xc]
    jge short L_000438b8
    inc ebx
    cmp ebx, 0x80
    jl short L_000438a0
L_000438b8:
    cmp ebx, 0x80
    je short L_000438c2
    mov dword ptr [esi], ebx
L_000438c2:
    popad
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_000438c8
L_000438c8:
    enter 8, 0
    pushad
    mov edi, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x10]
    mov ecx, dword ptr [ebp + 0xc]
    mov eax, 0x800000
    mov edx, 0
    mov ebx, dword ptr [ebp + 0xc]
    idiv ebx
    mov dword ptr [ebp - 4], eax
    mov eax, 0x100
    sub eax, dword ptr [ebp + 0xc]
    sar eax, 1
    mov ebx, dword ptr [ebp + 0xc]
    sar ebx, 3
    db 003h, 0d8h    ; add ebx, eax (WASM encodes it differently)
    cmp ebx, 0
    jge short L_00043913
    mov eax, dword ptr [ebp - 4]
    neg ebx
    imul ebx
    mov dword ptr [ebp - 8], eax
    mov ebx, 0
    mov ecx, 0x100
L_00043913:
    mov eax, 0x50
    mul ebx
    db 003h, 0f8h    ; add edi, eax (WASM encodes it differently)
    db 08bh, 0c1h    ; mov eax, ecx (WASM encodes it differently)
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    cmp eax, 0x100
    jle short L_0004392e
    sub eax, 0x100
    db 02bh, 0c8h    ; sub ecx, eax (WASM encodes it differently)
L_0004392e:
    mov edx, dword ptr [ebp - 4]
    mov ebx, dword ptr [ebp - 8]
    db 08ah, 0e1h    ; mov ah, cl (WASM encodes it differently)
    mov cx, word ptr [ebp + 8]
L_0004393a:
    mov esi, 0
    shld esi, ebx, 0x10
    add esi, dword ptr [ebp + 0x10]
    mov al, byte ptr [esi]
    db 02ah, 0c1h    ; sub al, cl (WASM encodes it differently)
    mov byte ptr [edi], al
    add edi, 0x50
    db 003h, 0dah    ; add ebx, edx (WASM encodes it differently)
    xchg cl, ch
    dec ah
    jne short L_0004393a
    popad
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0004395c
FUN_0004395c:
    enter 0, 0
    push dx
    mov ah, byte ptr [ebp + 8]
    mov al, 2
    mov dx, 0x3c4
    out dx, ax
    pop dx
    leave
    ret
_TEXT ends
end
