; a1e3b4.asm - assembler module of CODE.1 (2591 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment dword public use32 'CODE'
_TEXT ends
_DATA segment dword public use32 'DATA'
DAT_0003510c label byte
    db 000h, 000h    ; 0003510c  ..
DAT_0003510e label byte
    db 000h, 000h    ; 0003510e  ..
DAT_00035110 label byte
    db 64 dup(0)    ; 00035110
DAT_00035150 label byte
    db 000h, 000h, 000h, 000h    ; 00035150  ....
DAT_00035154 label byte
    db 32 dup(0)    ; 00035154
DAT_00035174 label byte
    db 000h, 000h    ; 00035174  ..
DAT_00035176 label byte
    db 68 dup(0)    ; 00035176
DAT_000351ba label byte
    db 68 dup(0)    ; 000351ba
DAT_000351fe label byte
    db 000h, 000h, 000h, 000h    ; 000351fe  ....
DAT_00035202 label byte
    db 000h, 000h, 000h, 000h    ; 00035202  ....
DAT_00035206 label byte
    db 000h, 000h, 000h, 000h    ; 00035206  ....
DAT_0003520a label byte
    db 000h, 000h, 000h, 000h    ; 0003520a  ....
DAT_0003520e label byte
    db 000h, 000h, 000h, 000h    ; 0003520e  ....
DAT_00035212 label byte
    db 000h, 000h, 000h, 000h    ; 00035212  ....
DAT_00035216 label byte
    db 64 dup(0)    ; 00035216
DAT_00035256 label byte
    db 64 dup(0)    ; 00035256
DAT_00035296 label byte
    db 68 dup(0)    ; 00035296
DAT_000352da label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 000352da  ........
DAT_000352e2 label byte
    db 000h, 000h, 000h, 000h    ; 000352e2  ....
DAT_000352e6 label byte
    db 000h, 000h    ; 000352e6  ..
DAT_000352e8 label byte
    db 0d7h, 000h, 000h, 000h    ; 000352e8  ....
_DATA ends
_TEXT segment dword public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_0001e680
public FUN_0001e6ea
public FUN_0001ea0b
public FUN_0001ea9a
public FUN_0001eac8
public FUN_0001eae7
public FUN_0001eaf1
public FUN_0001ec1b
public FUN_0001ec25
public FUN_0001ec2f
public FUN_0001ec39
public FUN_0001ec43
public FUN_0001ec89
public FUN_0001ec93
public FUN_0001ec9d
public FUN_0001eca7
public FUN_0001ecb1
public FUN_0001ecbb
public FUN_0001ecc5
public FUN_0001eced
public FUN_0001ecf7
public FUN_0001ed01
public FUN_0001ed0b
public FUN_0001ed15
public FUN_0001ed29
public FUN_0001ed33
; ---- FUN_0001e3b4
L_0001e3b4:
    cmp ebx, 0x10
    jae short L_0001e3d6
    shl ebx, 1
    shl ebx, 1
    mov ebx, dword ptr [ebx + DAT_00035216]
    cmp ebx, 0
    je short L_0001e3d6
L_0001e3c8:
    mov ecx, dword ptr [ebx]
    db 03bh, 0c8h    ; cmp ecx, eax (WASM encodes it differently)
    je short L_0001e3dc
    add ebx, 8
    cmp ecx, -1
    jne short L_0001e3c8
L_0001e3d6:
    mov eax, 0
    ret
L_0001e3dc:
    mov eax, dword ptr [ebx + 4]
    ret
; ---- FUN_0001e3e0
L_0001e3e0:
    db 08bh, 0dch    ; mov ebx, esp (WASM encodes it differently)
    mov ebx, dword ptr [ebx + 4]
    call L_0001e3b4
    cmp eax, 0
    je short L_0001e3f1
    jmp eax
L_0001e3f1:
    ret
L_0001e3f2:
    pushad
    push ds
    push es
    push fs
    push gs
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    cld
    mov ds, word ptr cs:[DAT_000352e6]
    mov es, word ptr cs:[DAT_000352e6]
    cmp word ptr [DAT_0003510e], 0
    je short L_0001e418
    jmp short L_0001e497
L_0001e418:
    mov word ptr [DAT_0003510e], 1
    mov dword ptr [DAT_0003520a], 0
L_0001e42b:
    mov esi, dword ptr [DAT_0003520a]
    shl esi, 1
    cmp word ptr [esi + DAT_00035154], 2
    jne short L_0001e47f
    shl esi, 1
    mov eax, dword ptr [esi + DAT_00035176]
    add eax, dword ptr [DAT_000351fe]
    cmp eax, dword ptr [esi + DAT_000351ba]
    jae short L_0001e45b
    mov dword ptr [esi + DAT_00035176], eax
    jmp short L_0001e47f
L_0001e45b:
    sub eax, dword ptr [esi + DAT_000351ba]
    mov dword ptr [esi + DAT_00035176], eax
    cmp dword ptr [DAT_0003520a], 0x10
    jb short L_0001e479
    mov word ptr [DAT_0003510e], 0
L_0001e479:
    call dword ptr [esi + DAT_00035110]
L_0001e47f:
    inc dword ptr [DAT_0003520a]
    cmp dword ptr [DAT_0003520a], 0x10
    jbe short L_0001e42b
    mov word ptr [DAT_0003510e], 0
L_0001e497:
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
L_0001e4a7:
    mov ecx, dword ptr [DAT_00035202]
    mov eax, dword ptr [DAT_00035206]
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
; ---- FUN_0001e4c7
L_0001e4c7:
    push esi
    push edi
    push es
    pushfd
    cli
    push ds
    pop es
    cld
    mov dword ptr [DAT_000351fe], 0xffffffff
    mov edi, offset DAT_00035154
    mov ecx, 0x11
    mov eax, 0
    rep stosw
    mov edi, offset DAT_00035176
    mov ecx, 0x11
    rep stosd
    mov edi, offset DAT_000351ba
    mov ecx, 0x11
    rep stosd
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e50e
    sti
L_0001e50e:
    pop ebp
    popfd
    pop es
    pop edi
    pop esi
    ret
; ---- FUN_0001e514
L_0001e514:
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
    mov dword ptr [DAT_00035202], ebx
    mov dword ptr [DAT_00035206], edx
    mov ebx, offset L_0001e4a7
    mov dword ptr [DAT_00035150], ebx
    mov eax, 8
    mov edx, offset L_0001e3f2
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
    je short L_0001e55e
    sti
L_0001e55e:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0001e563
L_0001e563:
    push esi
    push edi
    pushfd
    cli
    mov dword ptr [DAT_0003520a], 0xffffffff
    mov eax, 8
    mov edx, dword ptr [DAT_00035202]
    mov ebx, dword ptr [DAT_00035206]
    mov ah, 0x25
    push ds
    db 066h, 08eh, 0dbh    ; mov ds, bx (WASM encodes it differently)
    int 0x21
    pop ds
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e596
    sti
L_0001e596:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0001e59b
L_0001e59b:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov al, 0x36
    out 0x43, al
    mov eax, dword ptr [ebp + 8]
    mov dword ptr [DAT_00035212], eax
    jmp short L_0001e5b0
L_0001e5b0:
    out 0x40, al
    db 08ah, 0c4h    ; mov al, ah (WASM encodes it differently)
    jmp short L_0001e5b6
L_0001e5b6:
    out 0x40, al
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e5c3
    sti
L_0001e5c3:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001e5c9
L_0001e5c9:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    mov eax, 0
    cmp dword ptr [ebp + 8], 0xd68d
    jae short L_0001e5ed
    mov eax, dword ptr [ebp + 8]
    mov ebx, 0x20bc
    mov ecx, 0x2710
    mul ecx
    div ebx
L_0001e5ed:
    push eax
    call L_0001e59b
    add esp, 4
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001e5fa
L_0001e5fa:
    push esi
    push edi
    push es
    pushfd
    cli
    cld
    mov dword ptr [DAT_0003520e], 0xffffffff
    mov esi, 0
L_0001e60f:
    db 08bh, 0deh    ; mov ebx, esi (WASM encodes it differently)
    shl ebx, 1
    cmp word ptr [ebx + DAT_00035154], 0
    je short L_0001e631
    mov eax, dword ptr [ebx*2 + DAT_000351ba]
    cmp eax, dword ptr [DAT_0003520e]
    jae short L_0001e631
    mov dword ptr [DAT_0003520e], eax
L_0001e631:
    inc esi
    cmp esi, 0x10
    jbe short L_0001e60f
    mov eax, dword ptr [DAT_0003520e]
    cmp eax, dword ptr [DAT_000351fe]
    je short L_0001e66f
    mov dword ptr [DAT_0003520a], 0xffffffff
    mov dword ptr [DAT_000351fe], eax
    push eax
    call L_0001e5c9
    add esp, 4
    mov edi, offset DAT_00035176
    mov ecx, 0x11
    mov eax, 0
    push ds
    pop es
    rep stosd
L_0001e66f:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e67a
    sti
L_0001e67a:
    pop ebp
    popfd
    pop es
    pop edi
    pop esi
    ret
; ---- FUN_0001e680
FUN_0001e680:
    push esi
    push edi
    push es
    pushfd
    cli
    mov word ptr [DAT_000352e6], ds
    mov es, word ptr [DAT_000352e6]
    mov word ptr [DAT_0003510c], 0
    mov word ptr [DAT_0003510e], 0
    cld
    mov edi, offset DAT_00035216
    mov ecx, 0x10
    mov eax, 0
    rep stosd
    mov edi, offset DAT_00035256
    mov ecx, 0x10
    mov eax, 0xffffffff
    rep stosd
    mov edi, offset DAT_00035296
    mov ecx, 0x10
    mov eax, 0
    rep stosd
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e6e4
    sti
L_0001e6e4:
    pop ebp
    popfd
    pop es
    pop edi
    pop esi
    ret
; ---- FUN_0001e6ea
FUN_0001e6ea:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov dword ptr [DAT_000352da], 0
L_0001e6fb:
    mov esi, dword ptr [DAT_000352da]
    shl esi, 2
    mov edx, dword ptr [esi + DAT_00035256]
    mov eax, dword ptr [esi + DAT_00035216]
    cmp eax, 0
    je short L_0001e734
    cmp edx, -1
    je short L_0001e723
    push edx
    call L_0001e809
    add esp, 4
L_0001e723:
    push dword ptr [ebp + 8]
    push dword ptr [DAT_000352da]
    call L_0001ebb6
    add esp, 8
L_0001e734:
    inc dword ptr [DAT_000352da]
    cmp dword ptr [DAT_000352da], 0x10
    jne short L_0001e6fb
    call L_0001e856
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e753
    sti
L_0001e753:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001e759
L_0001e759:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, 0
L_0001e765:
    cmp word ptr [ebx + DAT_00035154], 0
    je short L_0001e77e
    add ebx, 2
    cmp ebx, 0x20
    jb short L_0001e765
    mov eax, 0xffffffff
    jmp short L_0001e7f8
L_0001e77e:
    db 08bh, 0c3h    ; mov eax, ebx (WASM encodes it differently)
    shr eax, 1
    mov word ptr [ebx + DAT_00035154], 1
    mov esi, dword ptr [ebp + 8]
    shl ebx, 1
    mov dword ptr [ebx + DAT_00035110], esi
    mov dword ptr [ebx + DAT_000351ba], 0xffffffff
    inc word ptr [DAT_0003510c]
    org $
    cmp word ptr [DAT_0003510c], 1
    jne short L_0001e7f8
    push eax
    call L_0001e4c7
    mov word ptr [DAT_00035174], 1
    call L_0001e514
    push 0xd68d
    push 0x10
    call L_0001e925
    add esp, 8
    push 0x10
    call L_0001e87b
    add esp, 4
    pop eax
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    shl ebx, 1
    mov word ptr [ebx + DAT_00035154], 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_000351ba], 0xffffffff
L_0001e7f8:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e803
    sti
L_0001e803:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001e809
L_0001e809:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    cmp ebx, -1
    je short L_0001e845
    shl ebx, 1
    cmp word ptr [ebx + DAT_00035154], 0
    je short L_0001e845
    mov word ptr [ebx + DAT_00035154], 0
    dec word ptr [DAT_0003510c]
    jne short L_0001e845
    push 0
    call L_0001e59b
    add esp, 4
    call L_0001e563
L_0001e845:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e850
    sti
L_0001e850:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001e856
L_0001e856:
    push esi
    push edi
    pushfd
    cli
    mov esi, 0xf
L_0001e85f:
    push esi
    call L_0001e809
    add esp, 4
    dec esi
    jge short L_0001e85f
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e876
    sti
L_0001e876:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0001e87b
L_0001e87b:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    cmp word ptr [ebx + DAT_00035154], 1
    jne short L_0001e89a
    mov word ptr [ebx + DAT_00035154], 2
L_0001e89a:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e8a5
    sti
L_0001e8a5:
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
L_0001e8b4:
    push esi
    call L_0001e87b
    add esp, 4
    dec esi
    jge short L_0001e8b4
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e8cb
    sti
L_0001e8cb:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
L_0001e8d0:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    cmp word ptr [ebx + DAT_00035154], 2
    jne short L_0001e8ef
    mov word ptr [ebx + DAT_00035154], 1
L_0001e8ef:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e8fa
    sti
L_0001e8fa:
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
L_0001e909:
    push esi
    call L_0001e8d0
    add esp, 4
    dec esi
    jge short L_0001e909
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e920
    sti
L_0001e920:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0001e925
L_0001e925:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    movzx eax, word ptr [ebx + DAT_00035154]
    push eax
    mov word ptr [ebx + DAT_00035154], 1
    shl ebx, 1
    mov eax, dword ptr [ebp + 0xc]
    mov dword ptr [ebx + DAT_000351ba], eax
    mov dword ptr [ebx + DAT_00035176], 0
    call L_0001e5fa
    pop eax
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    mov word ptr [ebx + DAT_00035154], ax
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e974
    sti
L_0001e974:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001e97a
L_0001e97a:
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
    call L_0001e925
    add esp, 8
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e9a7
    sti
L_0001e9a7:
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
    jne short L_0001e9c1
    mov eax, 0xd68d
    jmp short L_0001e9d5
L_0001e9c1:
    mov eax, 0x2710
    mov edx, 0
    mov ebx, 0x2e9c
    mul dword ptr [ebp + 0xc]
    div ebx
L_0001e9d5:
    push eax
    push dword ptr [ebp + 8]
    call L_0001e925
    add esp, 8
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001e9ec
    sti
L_0001e9ec:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
L_0001e9f2:
    push esi
    push edi
    pushfd
    cli
    mov eax, dword ptr [DAT_00035212]
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001ea06
    sti
L_0001ea06:
    pop ebp
    popfd
    pop edi
    pop esi
    ret
; ---- FUN_0001ea0b
FUN_0001ea0b:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov dword ptr [DAT_000352da], 0
L_0001ea1c:
    mov esi, dword ptr [DAT_000352da]
    shl esi, 1
    shl esi, 1
    mov eax, dword ptr [esi + DAT_00035216]
    cmp eax, 0
    je short L_0001ea47
    inc dword ptr [DAT_000352da]
    cmp dword ptr [DAT_000352da], 0x10
    jne short L_0001ea1c
    mov eax, 0xffffffff
    jmp short L_0001ea89
L_0001ea47:
    mov edi, dword ptr [ebp + 8]
    mov eax, 0xffffffff
    cmp dword ptr [edi + 4], 0x79706f43
    jne short L_0001ea89
    mov edi, dword ptr [edi]
    mov dword ptr [esi + DAT_00035216], edi
    push dword ptr [DAT_000352da]
    call L_0001eac8
    add esp, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    cmp eax, 0
    mov eax, 0xffffffff
    je short L_0001ea89
    mov edx, dword ptr [edi]
    cmp edx, dword ptr [DAT_000352e8]
    ja short L_0001ea89
    mov eax, dword ptr [DAT_000352da]
L_0001ea89:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001ea94
    sti
L_0001ea94:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001ea9a
FUN_0001ea9a:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    mov ebx, dword ptr [ebp + 8]
    cmp ebx, 0x10
    jae short L_0001eab7
    shl ebx, 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_00035216], 0
L_0001eab7:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001eac2
    sti
L_0001eac2:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001eac8
L_0001eac8:
FUN_0001eac8:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    mov eax, offset L_0001e9f2
    push eax
    push dword ptr [ebp + 8]
    mov eax, 0x64
    call L_0001e3e0
    add esp, 8
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001eae7
FUN_0001eae7:
    mov eax, 0x65
    jmp near ptr L_0001e3e0
; ---- FUN_0001eaf1
FUN_0001eaf1:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    push esi
    push edi
    pushfd
    cli
    cmp dword ptr [ebp + 8], 0x10
    jae near ptr L_0001eba5
    mov dword ptr [DAT_000352e2], 0xffffffff
    push dword ptr [ebp + 8]
    call L_0001eac8
    add esp, 4
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    mov esi, dword ptr [edi + 0x20]
    cmp esi, -1
    je short L_0001eb61
    mov eax, 0x67
    mov ebx, dword ptr [ebp + 8]
    call L_0001e3b4
    db 08bh, 0d8h    ; mov ebx, eax (WASM encodes it differently)
    cmp ebx, 0
    je short L_0001eb61
    db 08bh, 0f8h    ; mov edi, eax (WASM encodes it differently)
    push edi
    call L_0001e759
    add esp, 4
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_00035256], eax
    mov dword ptr [DAT_000352e2], eax
    push esi
    push dword ptr [DAT_000352e2]
    call L_0001e97a
    add esp, 8
L_0001eb61:
    push dword ptr [ebp + 0x18]
    push dword ptr [ebp + 0x14]
    push dword ptr [ebp + 0x10]
    push dword ptr [ebp + 0xc]
    push dword ptr [ebp + 8]
    mov eax, 0x66
    call L_0001e3e0
    add esp, 0x14
    mov ebx, dword ptr [ebp + 8]
    shl ebx, 1
    shl ebx, 1
    mov dword ptr [ebx + DAT_00035296], 1
    cmp dword ptr [DAT_000352e2], -1
    je short L_0001eba5
    push dword ptr [DAT_000352e2]
    org $
    call L_0001e87b
    add esp, 4
L_0001eba5:
    push ebp
    db 08bh, 0ech    ; mov ebp, esp (WASM encodes it differently)
    test byte ptr [ebp + 5], 2
    cli
    je short L_0001ebb0
    sti
L_0001ebb0:
    pop ebp
    popfd
    pop edi
    pop esi
    leave
    ret
; ---- FUN_0001ebb6
L_0001ebb6:
    db 08bh, 0dch    ; mov ebx, esp (WASM encodes it differently)
    mov ebx, dword ptr [ebx + 4]
    cmp ebx, 0x10
    jae short L_0001ebf2
    shl ebx, 1
    shl ebx, 1
    mov edx, 0
    xchg dword ptr [ebx + DAT_00035296], edx
    cmp edx, 0
    je short L_0001ebf2
    mov edx, dword ptr [ebx + DAT_00035256]
    cmp edx, -1
    je short L_0001ebe8
    push edx
    call L_0001e809
    add esp, 4
L_0001ebe8:
    mov eax, 0x68
    jmp near ptr L_0001e3e0
L_0001ebf2:
    ret
    mov eax, 0x78
    jmp near ptr L_0001e3e0
    mov eax, 0x79
    jmp near ptr L_0001e3e0
    mov eax, 0x86
    jmp near ptr L_0001e3e0
    mov eax, 0x7a
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec1b
FUN_0001ec1b:
    mov eax, 0x7b
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec25
FUN_0001ec25:
    mov eax, 0x85
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec2f
FUN_0001ec2f:
    mov eax, 0x7c
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec39
FUN_0001ec39:
    mov eax, 0x7d
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec43
FUN_0001ec43:
    mov eax, 0x7e
    jmp near ptr L_0001e3e0
    mov eax, 0x7f
    jmp near ptr L_0001e3e0
    mov eax, 0x80
    jmp near ptr L_0001e3e0
    mov eax, 0x81
    jmp near ptr L_0001e3e0
    mov eax, 0x82
    jmp near ptr L_0001e3e0
    mov eax, 0x83
    jmp near ptr L_0001e3e0
    mov eax, 0x84
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec89
FUN_0001ec89:
    mov eax, 0x96
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec93
FUN_0001ec93:
    mov eax, 0x97
    jmp near ptr L_0001e3e0
; ---- FUN_0001ec9d
FUN_0001ec9d:
    mov eax, 0x98
    jmp near ptr L_0001e3e0
; ---- FUN_0001eca7
FUN_0001eca7:
    mov eax, 0x99
    jmp near ptr L_0001e3e0
; ---- FUN_0001ecb1
FUN_0001ecb1:
    mov eax, 0x9a
    jmp near ptr L_0001e3e0
; ---- FUN_0001ecbb
FUN_0001ecbb:
    mov eax, 0x9b
    jmp near ptr L_0001e3e0
; ---- FUN_0001ecc5
FUN_0001ecc5:
    mov eax, 0x9c
    jmp near ptr L_0001e3e0
    mov eax, 0x9d
    jmp near ptr L_0001e3e0
    mov eax, 0x9e
    jmp near ptr L_0001e3e0
    mov eax, 0x9f
    jmp near ptr L_0001e3e0
; ---- FUN_0001eced
FUN_0001eced:
    mov eax, 0xaa
    jmp near ptr L_0001e3e0
; ---- FUN_0001ecf7
FUN_0001ecf7:
    mov eax, 0xab
    jmp near ptr L_0001e3e0
FUN_0001ed01:
    mov eax, 0xad
    jmp near ptr L_0001e3e0
; ---- FUN_0001ed0b
FUN_0001ed0b:
    mov eax, 0xae
    jmp near ptr L_0001e3e0
; ---- FUN_0001ed15
FUN_0001ed15:
    mov eax, 0xaf
    jmp near ptr L_0001e3e0
    mov eax, 0xb0
    jmp near ptr L_0001e3e0
; ---- FUN_0001ed29
FUN_0001ed29:
    mov eax, 0xb1
    jmp near ptr L_0001e3e0
; ---- FUN_0001ed33
FUN_0001ed33:
    mov eax, 0xb2
    jmp near ptr L_0001e3e0
    mov eax, 0xb3
    jmp near ptr L_0001e3e0
    mov eax, 0xb4
    jmp near ptr L_0001e3e0
    mov eax, 0xb5
    jmp near ptr L_0001e3e0
    mov eax, 0xb6
    jmp near ptr L_0001e3e0
    mov eax, 0xb7
    jmp near ptr L_0001e3e0
    mov eax, 0xb9
    jmp near ptr L_0001e3e0
    mov eax, 0xba
    jmp near ptr L_0001e3e0
    mov eax, 0xbb
    jmp near ptr L_0001e3e0
    mov eax, 0xbc
    jmp near ptr L_0001e3e0
    mov eax, 0xbd
    jmp near ptr L_0001e3e0
    mov eax, 0xbe
    jmp near ptr L_0001e3e0
    mov eax, 0xbf
    jmp near ptr L_0001e3e0
    mov eax, 0xc0
    jmp near ptr L_0001e3e0
    mov eax, 0xc1
    jmp near ptr L_0001e3e0
    mov eax, 0xc2
    jmp near ptr L_0001e3e0
_TEXT ends
end
