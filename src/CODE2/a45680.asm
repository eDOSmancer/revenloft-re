; a45680.asm - assembler module of CODE.2 (7286 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group CONST, _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn strcmp:near
extrn FUN_0003f29c:near
extrn memset:near
extrn FUN_0004104c:near
extrn FUN_0004395c:near
extrn open:near
extrn close:near
extrn read:near
extrn lseek:near
extrn tell:near
extrn DAT_0005c029:byte
extrn DAT_0005c6cc:byte
extrn DAT_0005c6d0:byte
extrn DAT_0005c6d8:byte
extrn DAT_0005c6e0:byte
extrn DAT_0005c730:byte
extrn DAT_0005c738:byte
extrn DAT_0005ef4d:byte
extrn B00065a18_cn:byte
extrn B00068fe0_eN:byte
extrn B000755e0_bo:byte
extrn B000755e8_ag:byte
extrn B000755ec_aH:byte
extrn B000755f0_co:byte
extrn B000755f4_ck:byte
extrn B000755f8_bg:byte
extrn B000755fc_ax:byte
extrn B000758c4_j7:byte
extrn DAT_0005c664:byte
CONST segment dword public use32 'DATA'
DAT_00051604 label byte
    db 04ch, 058h, 000h, 000h    ; 00051604  LX..
CONST ends
_DATA segment dword public use32 'DATA'
DAT_00060270 label byte
    db 000h, 000h    ; 00060270  ..
DAT_00060272 label byte
    db 000h, 000h    ; 00060272  ..
DAT_00060274 label byte
    db 64 dup(0)    ; 00060274
DAT_000602b4 label byte
    db 000h, 000h, 000h, 000h    ; 000602b4  ....
DAT_000602b8 label byte
    db 32 dup(0)    ; 000602b8
DAT_000602d8 label byte
    db 000h, 000h    ; 000602d8  ..
DAT_000602da label byte
    db 68 dup(0)    ; 000602da
DAT_0006031e label byte
    db 68 dup(0)    ; 0006031e
DAT_00060362 label byte
    db 000h, 000h, 000h, 000h    ; 00060362  ....
DAT_00060366 label byte
    db 000h, 000h, 000h, 000h    ; 00060366  ....
DAT_0006036a label byte
    db 000h, 000h, 000h, 000h    ; 0006036a  ....
DAT_0006036e label byte
    db 000h, 000h, 000h, 000h    ; 0006036e  ....
DAT_00060372 label byte
    db 000h, 000h, 000h, 000h    ; 00060372  ....
DAT_00060376 label byte
    db 000h, 000h, 000h, 000h    ; 00060376  ....
DAT_0006037a label byte
    db 64 dup(0)    ; 0006037a
DAT_000603ba label byte
    db 64 dup(0)    ; 000603ba
DAT_000603fa label byte
    db 68 dup(0)    ; 000603fa
DAT_0006043e label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 0006043e  ........
DAT_00060446 label byte
    db 000h, 000h, 000h, 000h    ; 00060446  ....
DAT_0006044a label byte
    db 000h, 000h    ; 0006044a  ..
DAT_0006044c label byte
    db 0d7h, 000h, 000h, 000h    ; 0006044c  ....
DAT_00060450 label byte
    db 000h, 000h, 000h, 000h    ; 00060450  ....
DAT_00060454 label byte
    db 128 dup(0)    ; 00060454
DAT_000604d4 label byte
    db 256 dup(0)    ; 000604d4
DAT_000605d4 label byte
    db 000h    ; 000605d4  .
DAT_000605d5 label byte
    db 000h    ; 000605d5  .
DAT_000605d6 label byte
    db 000h    ; 000605d6  .
DAT_000605d7 label byte
    db 000h, 000h, 000h, 000h    ; 000605d7  ....
DAT_000605db label byte
    db 000h, 000h, 000h, 000h    ; 000605db  ....
DAT_000605df label byte
    db 000h, 000h, 000h, 000h    ; 000605df  ....
DAT_000605e3 label byte
    db 000h, 000h, 000h, 000h    ; 000605e3  ....
DAT_000605e7 label byte
    db 000h, 000h, 000h, 000h, 000h    ; 000605e7  .....
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_00045680
public FUN_000456d8
public FUN_00045730
public FUN_00045798
public FUN_00045a0c
public FUN_00046254
public FUN_000462be
public FUN_000465df
public FUN_0004666e
public FUN_0004669c
public FUN_000466bb
public FUN_000466c5
public FUN_000467ef
public FUN_000467f9
public FUN_00046803
public FUN_0004680d
public FUN_00046817
public FUN_00046867
public FUN_00046871
public FUN_0004688f
public FUN_00046899
public FUN_000468c1
public FUN_000468cb
public FUN_000468d5
public FUN_000468df
public FUN_000468e9
public FUN_000468fd
public FUN_00046907
public FUN_000469a7
public FUN_00046cec
public _FUN_00045a0c
public _FUN_00046254
public _FUN_000462be
public _FUN_000465df
public _FUN_0004669c
public _FUN_000466bb
public _FUN_000466c5
public _FUN_0004685d
public _FUN_0004687b
public _FUN_00046885
; ---- FUN_00045680
L_00045680:
FUN_00045680:
    enter 0, 0
    push bx
    push si
    push di
    mov bx, word ptr [ebp + 0xc]
    mov si, word ptr [ebp + 0xe]
    cmp word ptr [ebp + 0xa], 0
    jge short L_000456a1
    neg dword ptr [ebp + 8]
    xor si, 0x8000
L_000456a1:
    mov ax, word ptr [ebp + 8]
    mul bx
    db 066h, 08bh, 0fah    ; mov di, dx (WASM encodes it differently)
    mov ax, word ptr [ebp + 0xa]
    mul bx
    db 066h, 003h, 0c7h    ; add ax, di (WASM encodes it differently)
    adc dx, 0
    cmp si, 0
    jge short L_000456c9
    neg dx
    neg ax
    sbb dx, 0
L_000456c9:
    shl eax, 0x10
    shrd eax, edx, 0x10
    pop di
    pop si
    pop bx
    leave
    ret
; ---- FUN_000456d8
FUN_000456d8:
    enter 0, 0
    push bx
    push si
    push di
    mov bx, word ptr [ebp + 0xc]
    mov si, 0
    cmp word ptr [ebp + 0xa], 0
    jge short L_000456f9
    neg dword ptr [ebp + 8]
    xor si, 0x8000
L_000456f9:
    mov ax, word ptr [ebp + 8]
    mul bx
    db 066h, 08bh, 0fah    ; mov di, dx (WASM encodes it differently)
    mov ax, word ptr [ebp + 0xa]
    mul bx
    db 066h, 003h, 0c7h    ; add ax, di (WASM encodes it differently)
    adc dx, 0
    cmp si, 0
    jge short L_00045721
    neg dx
    neg ax
    sbb dx, 0
L_00045721:
    shl eax, 0x10
    shrd eax, edx, 0x10
    pop di
    pop si
    pop bx
    leave
    ret
; ---- FUN_00045730
FUN_00045730:
    enter 0, 0
    push ecx
    push ebx
    mov eax, dword ptr [B000755f0_co]
    sub eax, dword ptr [B000755ec_aH]
    mov ebx, dword ptr [B000755e8_ag]
    sub ebx, dword ptr [B000755f4_ck]
    push dword ptr [B000755f8_bg]
    push eax
    call L_00045680
    add esp, 8
    push eax
    push dword ptr [B000755fc_ax]
    push ebx
    call L_00045680
    add esp, 8
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    pop eax
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    cmp eax, 0x1680
    jge short L_0004577d
    mov eax, 0x1680
L_0004577d:
    shr eax, 8
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov eax, dword ptr [B000755e0_bo]
    mov edx, 0
    div ebx
    and eax, 0xffff
    pop ebx
    pop ecx
    leave
    ret
    nop
; ---- FUN_00045798
FUN_00045798:
    enter 0x10, 0
    pushad
    mov esi, dword ptr [ebp + 0x10]
    mov edi, dword ptr [ebp + 0x14]
    mov eax, dword ptr [ebp + 8]
    sub eax, dword ptr [B000755ec_aH]
    mov dword ptr [ebp - 0xc], eax
    mov ebx, dword ptr [ebp + 0xc]
    sub ebx, dword ptr [B000755f4_ck]
    mov dword ptr [ebp - 0x10], ebx
    push dword ptr [B000755f8_bg]
    push eax
    call L_00045680
    add esp, 8
    push eax
    push dword ptr [B000755fc_ax]
    push ebx
    call L_00045680
    add esp, 8
    push eax
    pop ebx
    pop eax
    db 02bh, 0c3h    ; sub eax, ebx (WASM encodes it differently)
    sub eax, 0x2000
    mov dword ptr [ebp - 4], eax
    push dword ptr [B000755fc_ax]
    push dword ptr [ebp - 0xc]
    call L_00045680
    add esp, 8
    push eax
    push dword ptr [B000755f8_bg]
    push dword ptr [ebp - 0x10]
    call L_00045680
    add esp, 8
    push eax
    pop eax
    pop ebx
    db 003h, 0c3h    ; add eax, ebx (WASM encodes it differently)
    mov dword ptr [ebp - 8], eax
    mov ax, word ptr [ebp - 4]
    mov dx, word ptr [ebp - 2]
    cmp dx, 0
    jl short L_00045828
    jne short L_00045834
    cmp ax, 0x5800
    jae short L_00045834
L_00045828:
    mov word ptr [edi], 0
    mov eax, 0
    jmp short L_00045866
L_00045834:
    mov eax, dword ptr [DAT_0005c6cc]
    mov ebx, dword ptr [ebp - 8]
    imul ebx
    mov ebx, dword ptr [ebp - 4]
    idiv ebx
    mov dx, word ptr [DAT_0005c6d0]
    db 066h, 003h, 0d0h    ; add dx, ax (WASM encodes it differently)
    mov word ptr [esi], dx
    mov ebx, dword ptr [ebp - 4]
    sar ebx, 8
    mov eax, dword ptr [B000755e0_bo]
    org $
    cdq
    idiv ebx
    mov word ptr [edi], ax
    mov eax, 1
L_00045866:
    popad
    leave
    ret
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    db 000h
L_00045870:
    db 020h
    and byte ptr [eax], al
    db 000h
L_00045874:
    db 020h
    and byte ptr [eax], al
    db 000h
L_00045878:
    db 056h, 057h
    mov esi, dword ptr [esp + 0xc]
    mov edx, dword ptr [esp + 0x10]
    mov ebx, dword ptr [esp + 0x1c]
    test byte ptr [esp + 0x14], 1
    je short L_000458ab
    mov edi, dword ptr [esp + 0x18]
    mov ecx, ebx
    add esi, edx
    push edi
    mov eax, ecx
    shr ecx, 2
    db 0f2h, 0a5h    ; movsd dword ptr es:[edi], dword ptr [esi] (WASM encodes it differently)
    db 08ah, 0c8h    ; mov cl, al (WASM encodes it differently)
    and cl, 3
    repne movsb
    pop edi
    lea eax, [edx + ebx]
    pop edi
    pop esi
    ret
L_000458ab:
    push 0
    push edx
    push esi
    call lseek
    add esp, 0xc
    push ebx
    push dword ptr [esp + 0x1c]
    push esi
    call read
    add esp, 0xc
    push esi
    call tell
    add esp, 4
    pop edi
    pop esi
    ret
    db 08dh, 040h, 000h    ; lea eax, [eax] (WASM encodes it differently)
; ---- FUN_000458d4
L_000458d4:
    push esi
    push edi
    push ebp
    sub esp, 0xcc
    mov eax, dword ptr [L_00045870]
    org $
    xor edi, edi
    mov dword ptr [esp + 0xc8], eax
    test byte ptr [esp + 0xe0], 1
    je short L_000458fe
    mov ebp, dword ptr [esp + 0xdc]
    jmp short L_00045920
L_000458fe:
    push 0x200
    push dword ptr [esp + 0xe0]
    call open
    add esp, 8
    mov ebp, eax
    cmp eax, -1
    jne short L_00045920
    xor eax, eax
    jmp near ptr L_000459ff
L_00045920:
    push 4
    lea eax, [esp + 0xc8]
    push eax
    push dword ptr [esp + 0xe8]
    push 0x3c
    push ebp
    call L_00045878
    add esp, 0x14
    push 2
    lea eax, [esp + 0xcc]
    push eax
    push dword ptr [esp + 0xe8]
    push dword ptr [esp + 0xd0]
    push ebp
    call L_00045878
    add esp, 0x14
    push offset DAT_00051604
    org $
    lea eax, [esp + 0xcc]
    push eax
    call strcmp
    add esp, 8
    test eax, eax
    je short L_0004598b
    push ebp
    call close
    add esp, 4
    xor eax, eax
    add esp, 0xcc
    pop ebp
    pop edi
    pop esi
    ret
L_0004598b:
    push 0xac
    lea eax, [esp + 4]
    push eax
    push dword ptr [esp + 0xe8]
    push dword ptr [esp + 0xd0]
    push ebp
    call L_00045878
    add esp, 0x14
    mov eax, dword ptr [esp + 0xc4]
    xor esi, esi
    add eax, dword ptr [esp + 0x40]
    cmp dword ptr [esp + 0x44], 0
    jbe short L_000459e9
L_000459c0:
    push 0x18
    lea edx, [esp + 0xb0]
    push edx
    push dword ptr [esp + 0xe8]
    push eax
    push ebp
    call L_00045878
    add esp, 0x14
    inc esi
    add edi, dword ptr [esp + 0xac]
    cmp esi, dword ptr [esp + 0x44]
    jb short L_000459c0
L_000459e9:
    test byte ptr [esp + 0xe0], 1
    jne short L_000459fc
    push ebp
    call close
    add esp, 4
L_000459fc:
    lea eax, [edi + 0xf]
L_000459ff:
    add esp, 0xcc
    pop ebp
    pop edi
    pop esi
    ret
    db 08dh, 040h, 000h    ; lea eax, [eax] (WASM encodes it differently)
; ---- FUN_00045a0c
FUN_00045a0c:
_FUN_00045a0c:
    push esi
    push edi
    push ebp
    sub esp, 0x2d0
    mov ebx, dword ptr [esp + 0x2e0]
    mov eax, dword ptr [L_00045874]
    org $
    mov dword ptr [esp + 0x2b4], 0
    mov dword ptr [esp + 0x29c], eax
    test byte ptr [esp + 0x2e4], 1
    je short L_00045a41
    mov edi, ebx
    jmp short L_00045a5d
L_00045a41:
    push 0x200
    push ebx
    call open
    add esp, 8
    mov edi, eax
    cmp eax, -1
    jne short L_00045a5d
    xor eax, eax
    jmp near ptr L_00045f7d
L_00045a5d:
    push dword ptr [esp + 0x2e4]
    push ebx
    call L_000458d4
    add esp, 8
    mov ebx, eax
    test byte ptr [esp + 0x2e4], 4
    je short L_00045aac
    push eax
    call FUN_0004104c
    add esp, 4
    mov dword ptr [esp + 0x2e8], eax
    test eax, eax
    jne short L_00045aac
    test byte ptr [esp + 0x2e4], 1
    jne short L_00045aa0
    push edi
    call close
    add esp, 4
L_00045aa0:
    xor eax, eax
    add esp, 0x2d0
    pop ebp
    pop edi
    pop esi
    ret
L_00045aac:
    push ebx
    push 0
    push dword ptr [esp + 0x2f0]
    call memset
    add esp, 0xc
    push 4
    lea eax, [esp + 0x290]
    push eax
    push dword ptr [esp + 0x2ec]
    push 0x3c
    push edi
    mov esi, dword ptr [esp + 0x2fc]
    call L_00045878
    add esp, 0x14
    push 2
    lea eax, [esp + 0x2a0]
    push eax
    push dword ptr [esp + 0x2ec]
    push dword ptr [esp + 0x298]
    push edi
    call L_00045878
    add esp, 0x14
    push offset DAT_00051604
    org $
    lea eax, [esp + 0x2a0]
    push eax
    call strcmp
    add esp, 8
    test eax, eax
    je short L_00045b3a
    test byte ptr [esp + 0x2e4], 1
    jne short L_00045b2e
    push edi
    call close
    add esp, 4
L_00045b2e:
    xor eax, eax
    add esp, 0x2d0
    pop ebp
    pop edi
    pop esi
    ret
L_00045b3a:
    push 0xac
    lea eax, [esp + 0x194]
    push eax
    push dword ptr [esp + 0x2ec]
    push dword ptr [esp + 0x298]
    push edi
    call L_00045878
    add esp, 0x14
    mov eax, dword ptr [esp + 0x28c]
    mov dword ptr [esp + 0x298], 0
    add eax, dword ptr [esp + 0x1d0]
    cmp dword ptr [esp + 0x1d4], 0
    jbe near ptr L_00045d11
L_00045b85:
    push 0x18
    lea edx, [esp + 0x268]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    mov dword ptr [esp + 0x2a8], eax
    mov eax, dword ptr [esp + 0x28c]
    mov dword ptr [esp + 0x2b8], 0
    add eax, dword ptr [esp + 0x1d8]
    cmp dword ptr [esp + 0x274], 0
    jbe near ptr L_00045cef
    mov edx, dword ptr [esp + 0x2b4]
    mov ebp, dword ptr [esp + 0x298]
    lea edx, [edx*4]
    lea ebp, [ebp*4]
    mov dword ptr [esp + 0x2b0], edx
L_00045bf1:
    push 8
    lea edx, [esp + 0x280]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    cmp dword ptr [esp + 0x2b8], 0
    jne short L_00045c46
    test byte ptr [esp + 0x26c], 2
    je short L_00045c3f
    test byte ptr [esp + 0x26c], 1
    je short L_00045c3f
    test si, 0xf
    je short L_00045c3f
    mov edx, esi
    mov ebx, 0x10
    and edx, 0xf
    sub ebx, edx
    add esi, ebx
L_00045c3f:
    mov dword ptr [esp + ebp + 0x240], esi
L_00045c46:
    mov edx, dword ptr [esp + 0x2b0]
    mov dword ptr [esp + 0x2a0], eax
    mov dword ptr [esp + edx], esi
    mov edx, esi
    mov eax, dword ptr [esp + 0x264]
    sub edx, dword ptr [esp + ebp + 0x240]
    sub eax, edx
    inc dword ptr [esp + 0x2b4]
    mov edx, eax
    movzx eax, word ptr [esp + 0x280]
    add dword ptr [esp + 0x2b0], 4
    cmp edx, eax
    jae short L_00045c8f
    mov dword ptr [esp + 0x2a4], edx
    jmp short L_00045c96
L_00045c8f:
    mov dword ptr [esp + 0x2a4], eax
L_00045c96:
    mov cl, byte ptr [esp + 0x1bc]
    push dword ptr [esp + 0x2a4]
    mov eax, dword ptr [esp + 0x280]
    push esi
    shl eax, cl
    push dword ptr [esp + 0x2ec]
    add eax, dword ptr [esp + 0x21c]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    inc dword ptr [esp + 0x2b8]
    mov eax, dword ptr [esp + 0x2a0]
    mov edx, dword ptr [esp + 0x2b8]
    add esi, dword ptr [esp + 0x2a4]
    cmp edx, dword ptr [esp + 0x274]
    jb near ptr L_00045bf1
L_00045cef:
    inc dword ptr [esp + 0x298]
    mov edx, dword ptr [esp + 0x298]
    mov eax, dword ptr [esp + 0x2a8]
    cmp edx, dword ptr [esp + 0x1d4]
    jb near ptr L_00045b85
L_00045d11:
    push 4
    lea eax, [esp + 0x28c]
    push eax
    mov edx, dword ptr [esp + 0x294]
    push dword ptr [esp + 0x2ec]
    add edx, dword ptr [esp + 0x204]
    push edx
    push edi
    call L_00045878
    add esp, 0x14
    mov edx, eax
    mov dword ptr [esp + 0x294], 0
    cmp dword ptr [esp + 0x1a4], 0
    jbe near ptr L_00045f63
    mov dword ptr [esp + 0x290], 0
L_00045d60:
    push 4
    lea eax, [esp + 0x288]
    push eax
    push dword ptr [esp + 0x2ec]
    push edx
    push edi
    call L_00045878
    add esp, 0x14
    mov edx, eax
    mov eax, dword ptr [esp + 0x288]
    cmp eax, dword ptr [esp + 0x284]
    je near ptr L_00045f32
    mov ebp, dword ptr [esp + 0x290]
    add eax, dword ptr [esp + 0x28c]
    mov dword ptr [esp + 0x2ac], edx
    add eax, dword ptr [esp + 0x1fc]
L_00045dad:
    push 1
    lea edx, [esp + 0x2d0]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    push 1
    lea edx, [esp + 0x2c8]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    mov dl, byte ptr [esp + 0x2cc]
    and dl, 7
    movzx edx, dl
    test edx, edx
    jne short L_00045e13
    test byte ptr [esp + 0x2e4], 1
    jne short L_00045e07
    push edi
    call close
    add esp, 4
L_00045e07:
    xor eax, eax
    add esp, 0x2d0
    pop ebp
    pop edi
    pop esi
    ret
L_00045e13:
    mov dl, byte ptr [esp + 0x2c4]
    and dl, 4
    movzx edx, dl
    test edx, edx
    je short L_00045e54
    mov dl, byte ptr [esp + 0x2c4]
    and dl, 0x20
    movzx edx, dl
    test edx, edx
    jne short L_00045e54
    test byte ptr [esp + 0x2e4], 1
    jne short L_00045e48
    push edi
    call close
    add esp, 4
L_00045e48:
    xor eax, eax
    add esp, 0x2d0
    pop ebp
    pop edi
    pop esi
    ret
L_00045e54:
    mov dl, byte ptr [esp + 0x2cc]
    and dl, 0x20
    movzx edx, dl
    test edx, edx
    je short L_00045e84
    test byte ptr [esp + 0x2e4], 1
    jne short L_00045e78
    push edi
    call close
    add esp, 4
L_00045e78:
    xor eax, eax
    add esp, 0x2d0
    pop ebp
    pop edi
    pop esi
    ret
L_00045e84:
    push 2
    lea edx, [esp + 0x2c4]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    push 1
    lea edx, [esp + 0x2cc]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    push 2
    lea edx, [esp + 0x2c0]
    push edx
    push dword ptr [esp + 0x2ec]
    push eax
    push edi
    call L_00045878
    add esp, 0x14
    movzx edx, word ptr [esp + 0x2c0]
    cmp edx, dword ptr [esp + 0x1b8]
    ja short L_00045f0e
    movzx ebx, word ptr [esp + 0x2c0]
    movzx esi, byte ptr [esp + 0x2c8]
    mov edx, dword ptr [esp + ebp]
    mov esi, dword ptr [esp + esi*4 + 0x23c]
    add edx, ebx
    movzx ebx, word ptr [esp + 0x2bc]
    add ebx, esi
    mov dword ptr [edx], ebx
L_00045f0e:
    mov edx, dword ptr [esp + 0x284]
    add edx, dword ptr [esp + 0x28c]
    add edx, dword ptr [esp + 0x1fc]
    cmp eax, edx
    jb near ptr L_00045dad
    mov edx, dword ptr [esp + 0x2ac]
L_00045f32:
    mov eax, dword ptr [esp + 0x284]
    inc dword ptr [esp + 0x294]
    mov dword ptr [esp + 0x288], eax
    mov eax, dword ptr [esp + 0x294]
    add dword ptr [esp + 0x290], 4
    cmp eax, dword ptr [esp + 0x1a4]
    jb near ptr L_00045d60
L_00045f63:
    test byte ptr [esp + 0x2e4], 1
    jne short L_00045f76
    push edi
    call close
    add esp, 4
L_00045f76:
    mov eax, dword ptr [esp + 0x2e8]
L_00045f7d:
    add esp, 0x2d0
    pop ebp
    pop edi
    pop esi
    ret
    db 000h
L_00045f88:
    db 083h, 0fbh, 010h, 073h, 01dh
    shl ebx, 1
    shl ebx, 1
    mov ebx, dword ptr [ebx + DAT_0006037a]
    cmp ebx, 0
    je short L_00045faa
L_00045f9c:
    mov ecx, dword ptr [ebx]
    db 03bh, 0c8h    ; cmp ecx, eax (WASM encodes it differently)
    je short L_00045fb0
    add ebx, 8
    cmp ecx, -1
    jne short L_00045f9c
L_00045faa:
    mov eax, 0
    ret
L_00045fb0:
    mov eax, dword ptr [ebx + 4]
    ret
; ---- FUN_00045fb4
L_00045fb4:
    db 08bh, 0dch    ; mov ebx, esp (WASM encodes it differently)
    mov ebx, dword ptr [ebx + 4]
    call L_00045f88
    cmp eax, 0
    je short L_00045fc5
    jmp eax
L_00045fc5:
    ret
L_00045fc6:
    pushad
    push ds
    push es
    push fs
    push gs
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    cld
    mov ds, word ptr cs:[DAT_0006044a]
    mov es, word ptr cs:[DAT_0006044a]
    cmp word ptr [DAT_00060272], 0
    je short L_00045fec
    jmp short L_0004606b
L_00045fec:
    mov word ptr [DAT_00060272], 1
    mov dword ptr [DAT_0006036e], 0
    org $
L_00045fff:
    mov esi, dword ptr [DAT_0006036e]
    shl esi, 1
    cmp word ptr [esi + DAT_000602b8], 2
    jne short L_00046053
    shl esi, 1
    mov eax, dword ptr [esi + DAT_000602da]
    add eax, dword ptr [DAT_00060362]
    cmp eax, dword ptr [esi + DAT_0006031e]
    jae short L_0004602f
    mov dword ptr [esi + DAT_000602da], eax
    jmp short L_00046053
L_0004602f:
    sub eax, dword ptr [esi + DAT_0006031e]
    mov dword ptr [esi + DAT_000602da], eax
    cmp dword ptr [DAT_0006036e], 0x10
    jb short L_0004604d
    mov word ptr [DAT_00060272], 0
L_0004604d:
    call dword ptr [esi + DAT_00060274]
L_00046053:
    inc dword ptr [DAT_0006036e]
    cmp dword ptr [DAT_0006036e], 0x10
    jbe short L_00045fff
    mov word ptr [DAT_00060272], 0
L_0004606b:
    db 08bh, 0e5h    ; mov esp, ebp (WASM encodes it differently)
    pop gs
    pop fs
    pop es
    pop ds
    popad
    push eax
    mov al, 0x20
    out 0x20, al
    pop eax
    iretd
L_0004607b:
    mov ecx, dword ptr [DAT_00060366]
    mov eax, dword ptr [DAT_0006036a]
    db 08bh, 0e5h    ; mov esp, ebp (WASM encodes it differently)
    xchg dword ptr [ebp + 0x28], ecx
    xchg dword ptr [ebp + 0x2c], eax
    pop gs
    pop fs
    pop es
    pop ds
    pop edi
    pop esi
    pop ebp
    pop ebx
    pop ebx
    pop edx
    retf
; ---- FUN_0004609b
L_0004609b:
    push esi
    push edi
    push es
    pushfd
    cli
    push ds
    pop es
    cld
    mov dword ptr [DAT_00060362], 0xffffffff
    mov edi, offset DAT_000602b8
    mov ecx, 0x11
    mov eax, 0
    rep stosw
    mov edi, offset DAT_000602da
    mov ecx, 0x11
    rep stosd
    mov edi, offset DAT_0006031e
    mov ecx, 0x11
    rep stosd
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000460e2
    sti
L_000460e2:
    pop ebp
    popfd
    pop es
    pop edi
    pop esi
    ret
; ---- FUN_000460e8
L_000460e8:
    push esi
    push edi
    pushfd
    cli
    mov eax, 8
    mov ah, 0x35
    push es
    int 0x21
    mov dx, es
    pop es
    mov dword ptr [DAT_00060366], ebx
    mov dword ptr [DAT_0006036a], edx
    mov ebx, offset L_0004607b
    mov dword ptr [DAT_000602b4], ebx
    mov eax, 8
    mov edx, offset L_00045fc6
    mov bx, cs
    mov ah, 0x25
    push ds
    db 066h, 08eh, 0dbh    ; mov ds, bx (WASM encodes it differently)
    int 0x21
    pop ds
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046132
    sti
L_00046132:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_00046137
L_00046137:
    push esi
    push edi
    pushfd
    cli
    mov dword ptr [DAT_0006036e], 0xffffffff
    mov eax, 8
    mov edx, dword ptr [DAT_00060366]
    mov ebx, dword ptr [DAT_0006036a]
    mov ah, 0x25
    push ds
    db 066h, 08eh, 0dbh    ; mov ds, bx (WASM encodes it differently)
    int 0x21
    pop ds
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0004616a
    sti
L_0004616a:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0004616f
L_0004616f:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov al, 0x36
    out 0x43, al
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_00060376], eax
    jmp short L_00046184
L_00046184:
    out 0x40, al
    db 08ah, 0c4h    ; mov al, ah (WASM encodes it differently)
    jmp short L_0004618a
L_0004618a:
    out 0x40, al
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046197
    sti
L_00046197:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004619d
L_0004619d:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    mov eax, 0
    cmp dword ptr [ebp + 8], 0xd68d
    jae short L_000461c1
    mov eax, dword ptr [ebp + 8]
    mov ebx, 0x20bc
    mov ecx, 0x2710
    mul ecx
    div ebx
L_000461c1:
    push eax
    call L_0004616f
    add esp, 4
    pop edi
    pop esi
    leave
    ret
; ---- FUN_000461ce
L_000461ce:
    push esi
    push edi
    push es
    pushfd
    cli
    cld
    mov dword ptr [DAT_00060372], 0xffffffff
    mov esi, 0
L_000461e3:
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    shl ebx, 1
    cmp word ptr [ebx + DAT_000602b8], 0
    je short L_00046205
    mov eax, dword ptr [ebx*2 + DAT_0006031e]
    cmp eax, dword ptr [DAT_00060372]
    jae short L_00046205
    mov dword ptr [DAT_00060372], eax
L_00046205:
    inc esi
    cmp esi, 0x10
    jbe short L_000461e3
    mov eax, dword ptr [DAT_00060372]
    cmp eax, dword ptr [DAT_00060362]
    je short L_00046243
    mov dword ptr [DAT_0006036e], 0xffffffff
    mov dword ptr [DAT_00060362], eax
    push eax
    call L_0004619d
    add esp, 4
    mov edi, offset DAT_000602da
    mov ecx, 0x11
    mov eax, 0
    push ds
    pop es
    rep stosd
L_00046243:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0004624e
    sti
L_0004624e:
    pop ebp
    popfd
    pop es
    pop edi
    pop esi
    ret
; ---- FUN_00046254
FUN_00046254:
_FUN_00046254:
    push esi
    push edi
    push es
    pushfd
    cli
    mov word ptr [DAT_0006044a], ds
    mov es, word ptr [DAT_0006044a]
    mov word ptr [DAT_00060270], 0
    mov word ptr [DAT_00060272], 0
    cld
    mov edi, offset DAT_0006037a
    mov ecx, 0x10
    mov eax, 0
    rep stosd
    mov edi, offset DAT_000603ba
    mov ecx, 0x10
    mov eax, 0xffffffff
    rep stosd
    mov edi, offset DAT_000603fa
    mov ecx, 0x10
    mov eax, 0
    rep stosd
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000462b8
    sti
L_000462b8:
    pop ebp
    popfd
    pop es
    pop edi
    pop esi
    ret
; ---- FUN_000462be
FUN_000462be:
_FUN_000462be:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov dword ptr [DAT_0006043e], 0
L_000462cf:
    mov esi, dword ptr [DAT_0006043e]
    shl esi, 2
    mov edx, dword ptr [esi + DAT_000603ba]
    mov eax, dword ptr [esi + DAT_0006037a]
    cmp eax, 0
    je short L_00046308
    cmp edx, -1
    je short L_000462f7
    push edx
    call L_000463dd
    add esp, 4
L_000462f7:
    push dword ptr [ebp + 8]
    push dword ptr [DAT_0006043e]
    call L_0004678a
    add esp, 8
L_00046308:
    inc dword ptr [DAT_0006043e]
    cmp dword ptr [DAT_0006043e], 0x10
    jne short L_000462cf
    call L_0004642a
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046327
    sti
L_00046327:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004632d
L_0004632d:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, 0
L_00046339:
    cmp word ptr [ebx + DAT_000602b8], 0
    je short L_00046352
    add ebx, 2
    cmp ebx, 0x20
    jb short L_00046339
    mov eax, 0xffffffff
    jmp short L_000463cc
L_00046352:
    db 08bh, 0c3h    ; mov eax, ebx (WASM encodes it differently)
    shr eax, 1
    mov word ptr [ebx + DAT_000602b8], 1
    mov esi, dword ptr [ebp + 8]
    shl ebx, 1
    mov dword ptr [ebx + DAT_00060274], esi
    mov dword ptr [ebx + DAT_0006031e], 0xffffffff
    inc word ptr [DAT_00060270]
    org $
    cmp word ptr [DAT_00060270], 1
    jne short L_000463cc
    push eax
    call L_0004609b
    mov word ptr [DAT_000602d8], 1
    call L_000460e8
    push 0xd68d
    push 0x10
    call L_000464f9
    add esp, 8
    push 0x10
    call L_0004644f
    add esp, 4
    pop eax
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    shl ebx, 1
    mov word ptr [ebx + DAT_000602b8], 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_0006031e], 0xffffffff
L_000463cc:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000463d7
    sti
L_000463d7:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_000463dd
L_000463dd:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    cmp ebx, -1
    je short L_00046419
    shl ebx, 1
    cmp word ptr [ebx + DAT_000602b8], 0
    je short L_00046419
    mov word ptr [ebx + DAT_000602b8], 0
    dec word ptr [DAT_00060270]
    jne short L_00046419
    push 0
    call L_0004616f
    add esp, 4
    call L_00046137
L_00046419:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046424
    sti
L_00046424:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004642a
L_0004642a:
    push esi
    push edi
    pushfd
    cli
    mov esi, 0xf
L_00046433:
    push esi
    call L_000463dd
    add esp, 4
    dec esi
    jge short L_00046433
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0004644a
    sti
L_0004644a:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0004644f
L_0004644f:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    cmp word ptr [ebx + DAT_000602b8], 1
    jne short L_0004646e
    mov word ptr [ebx + DAT_000602b8], 2
L_0004646e:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046479
    sti
L_00046479:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
    push esi
    push edi
    pushfd
    cli
    mov esi, 0xf
L_00046488:
    push esi
    call L_0004644f
    add esp, 4
    dec esi
    jge short L_00046488
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0004649f
    sti
L_0004649f:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
L_000464a4:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    cmp word ptr [ebx + DAT_000602b8], 2
    jne short L_000464c3
    mov word ptr [ebx + DAT_000602b8], 1
L_000464c3:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000464ce
    sti
L_000464ce:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
    push esi
    push edi
    pushfd
    cli
    mov esi, 0xf
L_000464dd:
    push esi
    call L_000464a4
    add esp, 4
    dec esi
    jge short L_000464dd
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000464f4
    sti
L_000464f4:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_000464f9
L_000464f9:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    movzx eax, word ptr [ebx + DAT_000602b8]
    push eax
    mov word ptr [ebx + DAT_000602b8], 1
    shl ebx, 1
    mov eax, dword ptr [ebp + 0xc]
    mov dword ptr [ebx + DAT_0006031e], eax
    mov dword ptr [ebx + DAT_000602da], 0
    call L_000461ce
    pop eax
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    mov word ptr [ebx + DAT_000602b8], ax
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046548
    sti
L_00046548:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004654e
L_0004654e:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov edx, 0
    mov eax, 0xf4240
    mov ebx, dword ptr [ebp + 0xc]
    div ebx
    push eax
    push dword ptr [ebp + 8]
    call L_000464f9
    add esp, 8
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0004657b
    sti
L_0004657b:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    cmp dword ptr [ebp + 0xc], 0
    jne short L_00046595
    mov eax, 0xd68d
    jmp short L_000465a9
L_00046595:
    mov eax, 0x2710
    mov edx, 0
    mov ebx, 0x2e9c
    mul dword ptr [ebp + 0xc]
    div ebx
L_000465a9:
    push eax
    push dword ptr [ebp + 8]
    call L_000464f9
    add esp, 8
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000465c0
    sti
L_000465c0:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
L_000465c6:
    push esi
    push edi
    pushfd
    cli
    mov eax, dword ptr [DAT_00060376]
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_000465da
    sti
L_000465da:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_000465df
FUN_000465df:
_FUN_000465df:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov dword ptr [DAT_0006043e], 0
L_000465f0:
    mov esi, dword ptr [DAT_0006043e]
    shl esi, 1
    shl esi, 1
    mov eax, dword ptr [esi + DAT_0006037a]
    cmp eax, 0
    je short L_0004661b
    inc dword ptr [DAT_0006043e]
    cmp dword ptr [DAT_0006043e], 0x10
    jne short L_000465f0
    mov eax, 0xffffffff
    jmp short L_0004665d
L_0004661b:
    mov edi, dword ptr [ebp + 8]
    mov eax, 0xffffffff
    cmp dword ptr [edi + 4], 0x79706f43
    jne short L_0004665d
    mov edi, dword ptr [edi]
    mov dword ptr [esi + DAT_0006037a], edi
    push dword ptr [DAT_0006043e]
    call L_0004669c
    add esp, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    cmp eax, 0
    mov eax, 0xffffffff
    je short L_0004665d
    mov edx, dword ptr [edi]
    cmp edx, dword ptr [DAT_0006044c]
    ja short L_0004665d
    mov eax, dword ptr [DAT_0006043e]
L_0004665d:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046668
    sti
L_00046668:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004666e
FUN_0004666e:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    cmp ebx, 0x10
    jae short L_0004668b
    shl ebx, 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_0006037a], 0
L_0004668b:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046696
    sti
L_00046696:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004669c
L_0004669c:
FUN_0004669c:
_FUN_0004669c:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    mov eax, offset L_000465c6
    push eax
    push dword ptr [ebp + 8]
    mov eax, 0x64
    call L_00045fb4
    add esp, 8
    pop edi
    pop esi
    leave
    ret
; ---- FUN_000466bb
FUN_000466bb:
_FUN_000466bb:
    mov eax, 0x65
    jmp near ptr L_00045fb4
; ---- FUN_000466c5
FUN_000466c5:
_FUN_000466c5:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    cmp dword ptr [ebp + 8], 0x10
    jae near ptr L_00046779
    mov dword ptr [DAT_00060446], 0xffffffff
    push dword ptr [ebp + 8]
    call L_0004669c
    add esp, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov esi, dword ptr [edi + 0x20]
    cmp esi, -1
    je short L_00046735
    mov eax, 0x67
    mov ebx, dword ptr [ebp + 8]
    call L_00045f88
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    cmp ebx, 0
    je short L_00046735
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    push edi
    call L_0004632d
    add esp, 4
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_000603ba], eax
    mov dword ptr [DAT_00060446], eax
    push esi
    push dword ptr [DAT_00060446]
    call L_0004654e
    add esp, 8
L_00046735:
    push dword ptr [ebp + 0x18]
    push dword ptr [ebp + 0x14]
    push dword ptr [ebp + 0x10]
    push dword ptr [ebp + 0xc]
    push dword ptr [ebp + 8]
    mov eax, 0x66
    call L_00045fb4
    add esp, 0x14
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_000603fa], 1
    cmp dword ptr [DAT_00060446], -1
    je short L_00046779
    push dword ptr [DAT_00060446]
    org $
    call L_0004644f
    add esp, 4
L_00046779:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_00046784
    sti
L_00046784:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0004678a
L_0004678a:
    db 08bh, 0dch    ; mov ebx, esp (WASM encodes it differently)
    mov ebx, dword ptr [ebx + 4]
    cmp ebx, 0x10
    jae short L_000467c6
    shl ebx, 1
    shl ebx, 1
    mov edx, 0
    xchg dword ptr [ebx + DAT_000603fa], edx
    cmp edx, 0
    je short L_000467c6
    mov edx, dword ptr [ebx + DAT_000603ba]
    org $
    cmp edx, -1
    je short L_000467bc
    push edx
    call L_000463dd
    add esp, 4
L_000467bc:
    mov eax, 0x68
    jmp near ptr L_00045fb4
L_000467c6:
    ret
    mov eax, 0x78
    jmp near ptr L_00045fb4
    mov eax, 0x79
    jmp near ptr L_00045fb4
    mov eax, 0x86
    jmp near ptr L_00045fb4
    mov eax, 0x7a
    jmp near ptr L_00045fb4
; ---- FUN_000467ef
FUN_000467ef:
    mov eax, 0x7b
    jmp near ptr L_00045fb4
; ---- FUN_000467f9
FUN_000467f9:
    mov eax, 0x85
    jmp near ptr L_00045fb4
; ---- FUN_00046803
FUN_00046803:
    mov eax, 0x7c
    jmp near ptr L_00045fb4
; ---- FUN_0004680d
FUN_0004680d:
    mov eax, 0x7d
    jmp near ptr L_00045fb4
; ---- FUN_00046817
FUN_00046817:
    mov eax, 0x7e
    jmp near ptr L_00045fb4
    mov eax, 0x7f
    jmp near ptr L_00045fb4
    mov eax, 0x80
    jmp near ptr L_00045fb4
    mov eax, 0x81
    jmp near ptr L_00045fb4
    mov eax, 0x82
    jmp near ptr L_00045fb4
    mov eax, 0x83
    jmp near ptr L_00045fb4
    mov eax, 0x84
    jmp near ptr L_00045fb4
; ---- FUN_0004685d
_FUN_0004685d:
    mov eax, 0x96
    jmp near ptr L_00045fb4
; ---- FUN_00046867
FUN_00046867:
    mov eax, 0x97
    jmp near ptr L_00045fb4
; ---- FUN_00046871
FUN_00046871:
    mov eax, 0x98
    jmp near ptr L_00045fb4
; ---- FUN_0004687b
_FUN_0004687b:
    mov eax, 0x99
    jmp near ptr L_00045fb4
; ---- FUN_00046885
_FUN_00046885:
    mov eax, 0x9a
    jmp near ptr L_00045fb4
; ---- FUN_0004688f
FUN_0004688f:
    mov eax, 0x9b
    jmp near ptr L_00045fb4
; ---- FUN_00046899
FUN_00046899:
    mov eax, 0x9c
    jmp near ptr L_00045fb4
    mov eax, 0x9d
    jmp near ptr L_00045fb4
    mov eax, 0x9e
    jmp near ptr L_00045fb4
    mov eax, 0x9f
    jmp near ptr L_00045fb4
; ---- FUN_000468c1
FUN_000468c1:
    mov eax, 0xaa
    jmp near ptr L_00045fb4
; ---- FUN_000468cb
FUN_000468cb:
    mov eax, 0xab
    jmp near ptr L_00045fb4
; ---- FUN_000468d5
FUN_000468d5:
    mov eax, 0xad
    jmp near ptr L_00045fb4
; ---- FUN_000468df
FUN_000468df:
    mov eax, 0xae
    jmp near ptr L_00045fb4
; ---- FUN_000468e9
FUN_000468e9:
    mov eax, 0xaf
    jmp near ptr L_00045fb4
    mov eax, 0xb0
    jmp near ptr L_00045fb4
; ---- FUN_000468fd
FUN_000468fd:
    mov eax, 0xb1
    jmp near ptr L_00045fb4
; ---- FUN_00046907
FUN_00046907:
    mov eax, 0xb2
    jmp near ptr L_00045fb4
    mov eax, 0xb3
    jmp near ptr L_00045fb4
    mov eax, 0xb4
    jmp near ptr L_00045fb4
    mov eax, 0xb5
    jmp near ptr L_00045fb4
    mov eax, 0xb6
    jmp near ptr L_00045fb4
    mov eax, 0xb7
    jmp near ptr L_00045fb4
    mov eax, 0xb9
    jmp near ptr L_00045fb4
    mov eax, 0xba
    jmp near ptr L_00045fb4
    mov eax, 0xbb
    jmp near ptr L_00045fb4
    mov eax, 0xbc
    jmp near ptr L_00045fb4
    mov eax, 0xbd
    jmp near ptr L_00045fb4
    mov eax, 0xbe
    jmp near ptr L_00045fb4
    mov eax, 0xbf
    jmp near ptr L_00045fb4
    mov eax, 0xc0
    jmp near ptr L_00045fb4
    mov eax, 0xc1
    jmp near ptr L_00045fb4
    mov eax, 0xc2
    jmp near ptr L_00045fb4
; ---- FUN_000469a7
FUN_000469a7:
    mov eax, dword ptr [esp + 4]
    test eax, eax
    jge short L_000469b1
    neg eax
L_000469b1:
    ret
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
    add byte ptr [eax], al
; ---- FUN_000469c0
L_000469c0:
    enter 0, 0
    push edi
    push esi
    push ecx
    mov edi, dword ptr [ebp + 0x14]
    mov esi, dword ptr [ebp + 0x10]
    mov ecx, dword ptr [ebp + 0xc]
    call dword ptr [ebp + 8]
    pop ecx
    pop esi
    pop edi
    leave
    ret
; ---- FUN_000469d8
L_000469d8:
    enter 0xc, 0
    push ebx
    push edi
    push esi
    mov eax, 0x800
    movzx edx, byte ptr [DAT_0005ef4d]
    mul edx
    add eax, 0xa000
    shl eax, 4
    mov dword ptr [ebp - 4], eax
    mov eax, dword ptr [DAT_00060450]
    mov edx, 0x50
    imul edx
    add eax, dword ptr [DAT_0005c6e0]
    mov edx, dword ptr [DAT_000605e3]
    sar edx, 2
    db 003h, 0c2h    ; add eax, edx (WASM encodes it differently)
    add dword ptr [ebp - 4], eax
    mov eax, dword ptr [DAT_000605e3]
    and eax, 3
    shl eax, 3
    add eax, dword ptr [DAT_000605df]
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    mov al, byte ptr [ebx + DAT_0005c664 + 04h]
    mov byte ptr [DAT_000605d4], al
    mov al, byte ptr [ebx + DAT_0005c664 + 024h]
    mov byte ptr [DAT_000605d5], al
    mov al, byte ptr [ebx + DAT_0005c664 + 044h]
    mov byte ptr [DAT_000605d6], al
    mov edi, dword ptr [DAT_000605db]
    mov esi, dword ptr [DAT_000605d7]
    mov dword ptr [ebp - 0xc], edi
L_00046a5b:
    movsx ebx, word ptr [edi]
    cmp ebx, 0
    je near ptr L_00046b0e
    movzx ebx, word ptr [esi + ebx]
    mov dword ptr [ebp - 8], ebx
    add dword ptr [ebp - 8], esi
    movzx eax, byte ptr [esi + ebx]
    mov byte ptr [esi + ebx], 0xc3
    push eax
    movsx ebx, word ptr [edi + 4]
    movzx ebx, word ptr [esi + ebx]
    db 003h, 0deh    ; add ebx, esi (WASM encodes it differently)
    movsx eax, word ptr [edi + 2]
    add eax, dword ptr [ebp + 8]
    mov dword ptr [ebp - 0xc], eax
    add edi, 6
    mov al, byte ptr [DAT_000605d4]
    push eax
    call FUN_0004395c
    add esp, 4
    push dword ptr [ebp - 4]
    push dword ptr [ebp - 0xc]
    push dword ptr [ebp + 0xc]
    push ebx
    call L_000469c0
    add esp, 0x10
    mov al, byte ptr [DAT_000605d5]
    cmp al, 0
    je short L_00046ad7
    push eax
    call FUN_0004395c
    add esp, 4
    mov eax, dword ptr [ebp - 4]
    inc eax
    push eax
    push dword ptr [ebp - 0xc]
    push dword ptr [ebp + 0xc]
    push ebx
    call L_000469c0
    add esp, 0x10
L_00046ad7:
    mov al, byte ptr [DAT_000605d6]
    cmp al, 0
    je short L_00046aff
    push eax
    call FUN_0004395c
    add esp, 4
    mov eax, dword ptr [ebp - 4]
    add eax, 2
    push eax
    push dword ptr [ebp - 0xc]
    push dword ptr [ebp + 0xc]
    push ebx
    call L_000469c0
    add esp, 0x10
L_00046aff:
    xchg esi, ebx
    mov esi, dword ptr [ebp - 8]
    pop eax
    mov byte ptr [esi], al
    xchg esi, ebx
    jmp near ptr L_00046a5b
L_00046b0e:
    pop esi
    pop edi
    pop ebx
    leave
    ret
    nop
; ---- FUN_00046b14
L_00046b14:
    enter 0, 0
    push esi
    push edi
    cmp byte ptr [DAT_0005c029], 0
    jne short L_00046b42
    push dword ptr [DAT_000605e7]
    push dword ptr [ebp + 8]
    call L_000469d8
    add esp, 8
    mov eax, dword ptr [DAT_000605e7]
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    mov dword ptr [DAT_000605e7], eax
    jmp short L_00046b95
L_00046b42:
    push dword ptr [DAT_000605df]
    push dword ptr [DAT_000605e3]
    mov edi, dword ptr [DAT_000605e7]
    mov esi, dword ptr [DAT_000605df]
    mov dword ptr [DAT_000605df], 1
L_00046b64:
    db 08bh, 0c7h    ; mov eax, edi (WASM encodes it differently)
    test dword ptr [DAT_000605e3], 1
    je short L_00046b74
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
L_00046b74:
    push eax
    push dword ptr [ebp + 8]
    call L_000469d8
    add esp, 8
    inc dword ptr [DAT_000605e3]
    dec esi
    jne short L_00046b64
    pop dword ptr [DAT_000605e3]
    pop dword ptr [DAT_000605df]
    org $
L_00046b95:
    pop edi
    pop esi
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00046b9c
L_00046b9c:
    enter 0, 0
    push edi
    push ebx
    mov edi, dword ptr [ebp + 8]
    sub edi, 0x204
    add edi, 0x102
    mov eax, 0
    mov ebx, 0x7f
L_00046bbb:
    add ax, word ptr [edi + ebx*2]
    cmp eax, dword ptr [ebp + 0xc]
    jg short L_00046bc7
    dec ebx
    jge short L_00046bbb
L_00046bc7:
    inc ebx
    cmp ebx, 0x7f
    jl short L_00046bd2
    mov ebx, 0x7f
L_00046bd2:
    db 08bh, 0c3h    ; mov eax, ebx (WASM encodes it differently)
    pop ebx
    pop edi
    leave
    ret
; ---- FUN_00046bd8
L_00046bd8:
    enter 0, 0
    push edi
    push ebx
    mov edi, dword ptr [ebp + 8]
    sub edi, 0x204
    add edi, 0x102
    mov eax, 0
    mov ebx, 0
L_00046bf7:
    add ax, word ptr [edi + ebx*2]
    cmp eax, dword ptr [ebp + 0xc]
    jg short L_00046c09
    inc ebx
    cmp ebx, 0x80
    jl short L_00046bf7
L_00046c09:
    db 08bh, 0c3h    ; mov eax, ebx (WASM encodes it differently)
    pop ebx
    pop edi
    leave
    ret
    nop
; ---- FUN_00046c10
L_00046c10:
    enter 0, 0
    push esi
    push edi
    push ebx
    mov edi, dword ptr [ebp + 8]
    sub edi, 0x204
    mov esi, dword ptr [ebp + 0xc]
L_00046c23:
    cmp esi, 0x80
    jge short L_00046c3f
    movzx ebx, word ptr [edi + esi*2]
    mov al, byte ptr [edi + ebx]
    mov byte ptr [esi + DAT_00060454], al
    mov byte ptr [edi + ebx], 0xc3
    inc esi
    jmp short L_00046c23
L_00046c3f:
    pop ebx
    pop edi
    pop esi
    leave
    ret
; ---- FUN_00046c44
L_00046c44:
    enter 0, 0
    push esi
    push edi
    push ebx
    push ecx
    mov edi, dword ptr [ebp + 8]
    sub edi, 0x204
    mov ebx, 0
L_00046c5a:
    cmp ebx, dword ptr [ebp + 0xc]
    jge short L_00046c89
    movzx ecx, word ptr [edi + ebx*2]
    mov ax, word ptr [edi + ecx]
    mov word ptr [ebx*2 + DAT_000604d4], ax
    db 08bh, 0f3h    ; mov esi, ebx (WASM encodes it differently)
    inc esi
    mov ax, word ptr [edi + esi*2]
    sub ax, word ptr [edi + ebx*2]
    db 066h, 02dh, 002h, 000h    ; sub ax, 2 (WASM encodes it differently)
    mov byte ptr [edi + ecx], 0xeb
    mov byte ptr [edi + ecx + 1], al
    inc ebx
    jmp short L_00046c5a
L_00046c89:
    pop ecx
    pop ebx
    pop edi
    pop esi
    leave
    ret
    nop
; ---- FUN_00046c90
L_00046c90:
    enter 0, 0
    push ebx
    push esi
    push edi
    mov edi, dword ptr [ebp + 8]
    mov esi, 0x7f
L_00046c9f:
    cmp esi, dword ptr [ebp + 0xc]
    jl short L_00046cb4
    movzx ebx, word ptr [edi + esi*2]
    mov al, byte ptr [esi + DAT_00060454]
    org $
    mov byte ptr [edi + ebx], al
    dec esi
    jmp short L_00046c9f
L_00046cb4:
    pop edi
    pop esi
    pop ebx
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00046cbc
L_00046cbc:
    enter 0, 0
    push ecx
    push ebx
    push esi
    push edi
    mov edi, dword ptr [ebp + 8]
    mov ebx, dword ptr [ebp + 0xc]
    dec ebx
L_00046ccb:
    cmp ebx, 0
    jl short L_00046ce3
    movzx ecx, word ptr [edi + ebx*2]
    mov ax, word ptr [ebx*2 + DAT_000604d4]
    org $
    mov word ptr [edi + ecx], ax
    dec ebx
    jmp short L_00046ccb
L_00046ce3:
    pop edi
    pop esi
    pop ebx
    pop ecx
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_00046cec
FUN_00046cec:
    enter 0x20, 0
    pushad
    mov eax, dword ptr [ebp + 0x10]
    shr eax, 3
    mov dword ptr [ebp - 8], eax
    mov eax, dword ptr [ebp + 0x10]
    and eax, 0xfff8
    shr eax, 1
    mov dword ptr [ebp - 0x20], eax
    mov eax, dword ptr [ebp - 8]
    cmp eax, 0
    jle near ptr L_000472f3
    cmp eax, dword ptr [DAT_0005c738]
    jle short L_00046d23
    mov eax, dword ptr [DAT_0005c738]
    mov dword ptr [ebp - 8], eax
L_00046d23:
    mov eax, dword ptr [ebp + 0xc]
    cmp eax, 0x117
    jl short L_00046d49
    cmp eax, 0x13b
    jge short L_00046d49
    mov eax, dword ptr [ebp - 8]
    shl eax, 1
    mov dword ptr [DAT_00060450], eax
    shr eax, 3
    add dword ptr [DAT_00060450], eax
    jmp short L_00046d54
L_00046d49:
    mov eax, dword ptr [ebp - 8]
    shr eax, 2
    mov dword ptr [DAT_00060450], eax
L_00046d54:
    shr eax, 1
    sub dword ptr [ebp - 8], eax
    mov ebx, 0
    mov edi, 0
    mov ebx, dword ptr [ebp - 0x20]
    add ebx, dword ptr [ebp + 0x14]
    cmp ebx, dword ptr [DAT_0005c730]
    jle short L_00046d7d
    mov eax, 0
    mov dword ptr [DAT_000605e7], eax
    jmp short L_00046d8c
L_00046d7d:
    mov edi, dword ptr [B000758c4_j7]
    movzx eax, word ptr [edi + ebx*2]
    mov dword ptr [DAT_000605e7], eax
L_00046d8c:
    mov ebx, dword ptr [ebp - 8]
    cmp eax, 0x808
    jbe short L_00046da2
    mov dword ptr [DAT_000605e7], 0x808
    jmp short L_00046da2
L_00046da2:
    mov edi, 0
    shl ebx, 2
    mov dword ptr [ebp - 8], ebx
    mov eax, dword ptr [ebx + B00068fe0_eN]
    mov dword ptr [DAT_000605d7], eax
    cmp dword ptr [ebp + 0x18], 0
    jne short L_00046e15
    mov eax, dword ptr [DAT_00060450]
    mov edx, 0x100
    sub edx, dword ptr [ebp - 8]
    sar edx, 1
    db 003h, 0c2h    ; add eax, edx (WASM encodes it differently)
    mov edx, dword ptr [ebp - 8]
    shr edx, 3
    db 003h, 0c2h    ; add eax, edx (WASM encodes it differently)
    mov dword ptr [ebp - 0xc], 0x80
    add eax, dword ptr [ebp - 8]
    cmp eax, 0x100
    jle short L_00046dff
    sub eax, 0x100
    push eax
    push dword ptr [DAT_000605d7]
    call L_00046b9c
    add esp, 8
    mov dword ptr [ebp - 0xc], eax
L_00046dff:
    push dword ptr [ebp - 0xc]
    push dword ptr [DAT_000605d7]
    call L_00046c10
    add esp, 8
    jmp near ptr L_00046e94
L_00046e15:
    mov eax, dword ptr [DAT_00060450]
    mov edx, dword ptr [ebp - 8]
    shr edx, 3
    db 003h, 0c2h    ; add eax, edx (WASM encodes it differently)
    mov edx, 0x100
    sub edx, dword ptr [ebp - 8]
    sar edx, 1
    db 003h, 0c2h    ; add eax, edx (WASM encodes it differently)
    cmp eax, 0
    jle near ptr L_000472f3
    mov dword ptr [ebp - 0xc], eax
    mov eax, dword ptr [ebp - 8]
    shl eax, 1
    mov edx, dword ptr [ebp + 0x18]
    mul edx
    add eax, 0x40
    adc edx, 0
    shrd eax, edx, 8
    mov dword ptr [ebp - 8], eax
    sub dword ptr [DAT_00060450], eax
    mov eax, dword ptr [ebp - 0xc]
    sub eax, dword ptr [ebp - 8]
    mov dword ptr [ebp - 0xc], 0xffffffff
    cmp eax, 0
    jge short L_00046e7d
    neg eax
    push eax
    push dword ptr [DAT_000605d7]
    call L_00046bd8
    add esp, 8
    mov dword ptr [ebp - 0xc], eax
L_00046e7d:
    cmp dword ptr [ebp - 0xc], 0
    jl short L_00046e94
    push dword ptr [ebp - 0xc]
    push dword ptr [DAT_000605d7]
    call L_00046c44
    add esp, 8
L_00046e94:
    push 3
    mov eax, dword ptr [ebp + 0xc]
    push eax
    call FUN_0003f29c
    add esp, 8
    add eax, 2
    mov dword ptr [ebp - 4], eax
    sub dword ptr [DAT_000605d7], 0x204
    mov eax, dword ptr [ebp - 4]
    mov dword ptr [DAT_000605db], eax
    mov edi, dword ptr [ebp - 4]
    movzx eax, word ptr [edi]
    mov dword ptr [ebp - 0x10], eax
    shr eax, 1
    mov dword ptr [ebp - 0x18], eax
    movzx eax, word ptr [edi + 2]
    mov dword ptr [ebp - 0x14], eax
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_000605e3], eax
    mov eax, dword ptr [ebp - 0x10]
    shr eax, 1
    dec eax
    sub eax, dword ptr [ebp - 0x14]
    shl eax, 1
    add eax, 0xa
    mov dword ptr [ebp - 0x1c], eax
    jmp near ptr L_00047094
L_00046eed:
    mov eax, dword ptr [ebp - 4]
    mov dword ptr [DAT_000605db], eax
    mov edi, dword ptr [ebp - 4]
    add edi, dword ptr [ebp - 0x1c]
    movzx eax, word ptr [edi]
    add dword ptr [DAT_000605db], eax
    add dword ptr [ebp - 0x1c], -2
    mov edi, dword ptr [DAT_000605d7]
    add edi, dword ptr [ebp - 0x18]
    add edi, dword ptr [ebp - 0x18]
    movzx eax, word ptr [edi + 0x102]
    mov dword ptr [DAT_000605df], eax
    cmp eax, 0
    je near ptr L_00047094
    cmp eax, 1
    jne short L_00046f6f
    dec dword ptr [DAT_000605e3]
    mov eax, dword ptr [DAT_000605e3]
    cmp eax, dword ptr [DAT_0005c6d8]
    jge near ptr L_00047094
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jge near ptr L_00047094
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp near ptr L_00047094
L_00046f6f:
    mov eax, dword ptr [DAT_000605e3]
    cmp eax, dword ptr [DAT_0005c6d8]
    jg short L_00046f96
    cmp dword ptr [DAT_000605df], eax
    jle short L_00046f89
    mov dword ptr [DAT_000605df], eax
L_00046f89:
    mov eax, dword ptr [DAT_000605df]
    sub dword ptr [DAT_000605e3], eax
    jmp short L_00046fbe
L_00046f96:
    mov eax, dword ptr [DAT_000605df]
    sub dword ptr [DAT_000605e3], eax
    mov eax, dword ptr [DAT_0005c6d8]
    sub eax, dword ptr [DAT_000605e3]
    mov dword ptr [DAT_000605df], eax
    cmp dword ptr [DAT_000605df], 1
    jl near ptr L_00047094
L_00046fbe:
    mov bh, 0
    mov eax, dword ptr [DAT_000605e3]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jge short L_00046fdb
    mov bh, 1
L_00046fdb:
    mov bl, 0
    mov eax, dword ptr [DAT_000605e3]
    add eax, dword ptr [DAT_000605df]
    sub eax, 1
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [edi + B00065a18_cn]
    org $
    cmp eax, dword ptr [ebp + 0x1c]
    jge short L_00047001
    mov bl, 1
L_00047001:
    cmp bh, 0
    je short L_00047056
    cmp bl, 0
    je short L_0004701a
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp short L_00047094
L_0004701a:
    mov eax, dword ptr [DAT_000605e3]
    add eax, dword ptr [DAT_000605df]
    sub eax, 1
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
L_00047031:
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jl short L_00047047
    dec dword ptr [DAT_000605df]
    sub edi, 0x1c
    jmp short L_00047031
L_00047047:
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp short L_00047094
L_00047056:
    cmp bl, 0
    je short L_00047094
    mov eax, dword ptr [DAT_000605e3]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
L_00047069:
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jl short L_00047085
    inc dword ptr [DAT_000605e3]
    dec dword ptr [DAT_000605df]
    add edi, 0x1c
    jmp short L_00047069
L_00047085:
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp short L_000470ae
L_00047094:
    mov eax, dword ptr [ebp - 0x18]
    dec eax
    mov dword ptr [ebp - 0x18], eax
    cmp eax, dword ptr [ebp - 0x14]
    jl short L_000470ae
    cmp dword ptr [DAT_000605e3], 0
    jle short L_000470ae
    jmp near ptr L_00046eed
L_000470ae:
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_000605e3], eax
    org $
    mov edi, dword ptr [ebp - 4]
    movzx eax, word ptr [edi + 4]
    inc eax
    mov dword ptr [ebp - 0x14], eax
    movzx ebx, word ptr [edi + 2]
    mov eax, dword ptr [ebp - 0x10]
    shr eax, 1
    dec eax
    db 03bh, 0d8h    ; cmp ebx, eax (WASM encodes it differently)
    jge short L_000470e1
    mov dword ptr [ebp - 0x18], eax
    inc eax
    sub ax, word ptr [edi + 2]
    shl eax, 1
    add eax, 0xa
    mov dword ptr [ebp - 0x1c], eax
    jmp short L_000470f0
L_000470e1:
    movzx eax, word ptr [edi + 2]
    dec eax
    mov dword ptr [ebp - 0x18], eax
    mov dword ptr [ebp - 0x1c], 0xa
L_000470f0:
    mov dword ptr [DAT_000605df], 0
    jmp near ptr L_0004729b
L_000470ff:
    mov eax, dword ptr [ebp - 4]
    mov dword ptr [DAT_000605db], eax
    mov edi, dword ptr [ebp - 4]
    add edi, dword ptr [ebp - 0x1c]
    movzx eax, word ptr [edi]
    add dword ptr [DAT_000605db], eax
    add dword ptr [ebp - 0x1c], 2
    mov edi, dword ptr [DAT_000605d7]
    add edi, dword ptr [ebp - 0x18]
    add edi, dword ptr [ebp - 0x18]
    movzx eax, word ptr [edi + 0x102]
    mov dword ptr [DAT_000605df], eax
    cmp eax, 0
    je near ptr L_0004729b
    cmp eax, 1
    jne short L_00047178
    mov eax, dword ptr [DAT_000605e3]
    cmp eax, 0
    jl near ptr L_0004729b
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jge near ptr L_0004729b
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp near ptr L_0004729b
L_00047178:
    mov eax, dword ptr [DAT_000605e3]
    cmp eax, 0
    jge short L_000471a4
    neg eax
    cmp eax, dword ptr [DAT_000605df]
    jge near ptr L_0004729b
    neg eax
    add dword ptr [DAT_000605df], eax
    mov dword ptr [DAT_000605e3], 0
    jmp short L_000471c7
L_000471a4:
    mov eax, dword ptr [DAT_000605e3]
    add eax, dword ptr [DAT_000605df]
    cmp eax, dword ptr [DAT_0005c6d8]
    jle short L_000471c7
    mov eax, dword ptr [DAT_0005c6d8]
    sub eax, dword ptr [DAT_000605e3]
    mov dword ptr [DAT_000605df], eax
L_000471c7:
    mov bh, 0
    mov eax, dword ptr [DAT_000605e3]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jge short L_000471e4
    mov bh, 1
L_000471e4:
    mov bl, 0
    mov eax, dword ptr [DAT_000605e3]
    add eax, dword ptr [DAT_000605df]
    sub eax, 1
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jge short L_0004720a
    mov bl, 1
L_0004720a:
    cmp bh, 0
    je short L_0004725f
    cmp bl, 0
    je short L_00047223
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp short L_0004729b
L_00047223:
    mov eax, dword ptr [DAT_000605e3]
    add eax, dword ptr [DAT_000605df]
    sub eax, 1
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
L_0004723a:
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jl short L_00047250
    dec dword ptr [DAT_000605df]
    sub edi, 0x1c
    jmp short L_0004723a
L_00047250:
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
    jmp short L_0004729b
L_0004725f:
    cmp bl, 0
    je short L_0004729b
    mov eax, dword ptr [DAT_000605e3]
    mov edx, 0x1c
    mul edx
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
L_00047272:
    mov eax, dword ptr [edi + B00065a18_cn]
    cmp eax, dword ptr [ebp + 0x1c]
    jl short L_0004728e
    inc dword ptr [DAT_000605e3]
    dec dword ptr [DAT_000605df]
    add edi, 0x1c
    jmp short L_00047272
L_0004728e:
    push 1
    push dword ptr [ebp - 4]
    call L_00046b14
    add esp, 8
L_0004729b:
    mov eax, dword ptr [ebp - 0x18]
    inc eax
    mov dword ptr [ebp - 0x18], eax
    cmp eax, dword ptr [ebp - 0x14]
    jge short L_000472c3
    mov eax, dword ptr [DAT_000605e3]
    add eax, dword ptr [DAT_000605df]
    mov dword ptr [DAT_000605e3], eax
    cmp eax, dword ptr [DAT_0005c6d8]
    jl near ptr L_000470ff
L_000472c3:
    cmp dword ptr [ebp + 0x18], 0
    jne short L_000472dc
    push dword ptr [ebp - 0xc]
    push dword ptr [DAT_000605d7]
    call L_00046c90
    add esp, 8
    jmp short L_000472f3
L_000472dc:
    cmp dword ptr [ebp - 0xc], 0
    jl short L_000472f3
    push dword ptr [ebp - 0xc]
    push dword ptr [DAT_000605d7]
    call L_00046cbc
    add esp, 8
L_000472f3:
    popad
    leave
    ret
_TEXT ends
end
