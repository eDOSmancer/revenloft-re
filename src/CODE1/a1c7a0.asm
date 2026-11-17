; a1c7a0.asm - assembler module of CODE.1 (1103 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn FUN_0001aea8:near
_DATA segment dword public use32 'DATA'
DAT_00032f88 label byte
    db 000h, 001h, 002h, 003h, 004h, 005h, 006h, 007h, 008h, 009h, 00ah, 00bh, 00ch, 00dh, 00eh, 00fh    ; 00032f88  ................
    db 010h, 011h, 012h, 013h, 014h, 015h, 016h, 017h, 018h, 019h, 01ah, 01bh, 01ch, 01dh, 01eh, 01fh    ; 00032f98  ................
    db 020h, 021h, 022h, 023h, 024h, 025h, 026h, 027h, 028h, 029h, 02ah, 02bh, 02ch, 02dh, 02eh, 02fh    ; 00032fa8   !"#$%&'()*+,-./
    db 030h, 031h, 032h, 033h, 034h, 035h, 036h, 037h, 038h, 039h, 03ah, 03bh, 03ch, 03dh, 03eh, 03fh    ; 00032fb8  0123456789:;<=>?
    db 040h, 041h, 042h, 043h, 044h, 045h, 046h, 047h, 048h, 049h, 04ah, 04bh, 04ch, 04dh, 04eh, 04fh    ; 00032fc8  @ABCDEFGHIJKLMNO
    db 050h, 051h, 052h, 053h, 054h, 055h, 056h, 057h, 058h, 059h, 05ah, 05bh, 05ch, 05dh, 05eh, 05fh    ; 00032fd8  PQRSTUVWXYZ[\]^_
    db 060h, 061h, 062h, 063h, 064h, 065h, 066h, 067h, 068h, 069h, 06ah, 06bh, 06ch, 06dh, 06eh, 06fh    ; 00032fe8  `abcdefghijklmno
    db 070h, 071h, 072h, 073h, 074h, 075h, 076h, 077h, 078h, 079h, 07ah, 07bh, 07ch, 07dh, 07eh, 07fh    ; 00032ff8  pqrstuvwxyz{|}~.
    db 080h, 081h, 082h, 083h, 084h, 085h, 086h, 087h, 088h, 089h, 08ah, 08bh, 08ch, 08dh, 08eh, 08fh    ; 00033008  ................
    db 090h, 091h, 092h, 093h, 094h, 095h, 096h, 097h, 098h, 099h, 09ah, 09bh, 09ch, 09dh, 09eh, 09fh    ; 00033018  ................
    db 0a0h, 0a1h, 0a2h, 0a3h, 0a4h, 0a5h, 0a6h, 0a7h, 0a8h, 0a9h, 0aah, 0abh, 0ach, 0adh, 0aeh, 0afh    ; 00033028  ................
    db 0b0h, 0b1h, 0b2h, 0b3h, 0b4h, 0b5h, 0b6h, 0b7h, 0b8h, 0b9h, 0bah, 0bbh, 0bch, 0bdh, 0beh, 0bfh    ; 00033038  ................
    db 0c0h, 0c1h, 0c2h, 0c3h, 0c4h, 0c5h, 0c6h, 0c7h, 0c8h, 0c9h, 0cah, 0cbh, 0cch, 0cdh, 0ceh, 0cfh    ; 00033048  ................
    db 0d0h, 0d1h, 0d2h, 0d3h, 0d4h, 0d5h, 0d6h, 0d7h, 0d8h, 0d9h, 0dah, 0dbh, 0dch, 0ddh, 0deh, 0dfh    ; 00033058  ................
    db 0e0h, 0e1h, 0e2h, 0e3h, 0e4h, 0e5h, 0e6h, 0e7h, 0e8h, 0e9h, 0eah, 0ebh, 0ech, 0edh, 0eeh, 0efh    ; 00033068  ................
    db 0f0h, 0f1h, 0f2h, 0f3h, 0f4h, 0f5h, 0f6h, 0f7h, 0f8h, 0f9h, 0fah, 0fbh, 0fch, 0fdh, 0feh, 0ffh    ; 00033078  ................
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_0001c7a0
public FUN_0001c8c4
public FUN_0001c9d4
public FUN_0001cacc
public FUN_0001cbd4
    org 042h
    xchg ebx, ebp
    db 032h, 0e4h    ; xor ah, ah (WASM encodes it differently)
    mov al, byte ptr [esi + 6]
    shl ax, 1
    mov word ptr [L_0001c897], ax
    shl ax, 2
    db 066h, 08bh, 0c8h    ; mov cx, ax (WASM encodes it differently)
    inc ax
    mov word ptr [L_0001c871], ax
    dec ax
    dec ax
    mov word ptr [L_0001c8a2], ax
    mov ax, word ptr [esi + 2]
    mov word ptr [L_0001c849], ax
    mov al, byte ptr [esi + 8]
    mov byte ptr [L_0001c858], al
    org 00h
FUN_0001c7a0:
    enter 0, 0
    pushad
    mov al, 0x11
    mov byte ptr [L_0001c89b], al
    mov edx, dword ptr [ebp + 0x14]
    mov ecx, dword ptr [ebp + 0x18]
    call FUN_0001aea8
    mov ah, 0x11
    rol ah, cl
    mov al, 2
    mov word ptr [L_0001c843], ax
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov esi, dword ptr [ebp + 0x10]
    mov ax, word ptr [ebp + 8]
    mov word ptr [L_0001c82b], ax
    mov word ptr [L_0001c850], ax
    org 07dh
    jmp short L_0001c81f
L_0001c81f:
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    shr edx, 1
    add esi, 8
    inc esi
L_0001c827:
    push esi
    db 081h, 0c2h, 078h
L_0001c82b:
    db 056h, 000h, 000h
L_0001c82e:
    db 03bh, 0d3h    ; cmp edx, ebx (WASM encodes it differently)
    jb short L_0001c893
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    push edx
    push esi
    push edi
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    shr edx, 1
    push ecx
    push edx
    mov dx, 0x3c4
    db 066h, 0b8h
L_0001c843:
    db 0dfh
L_0001c844:
    db 03ch
    out dx, ax
    pop edx
    db 0b9h
L_0001c849:
    db 078h, 056h, 000h, 000h
L_0001c84d:
    db 081h, 0c2h, 078h
L_0001c850:
    db 056h, 000h, 000h
    db 03bh, 0d3h    ; cmp edx, ebx (WASM encodes it differently)
    jb short L_0001c86f
    db 0b4h
L_0001c858:
    db 0dfh
    mov al, byte ptr [esi]
    xchg ebx, ebp
    db 0d7h    ; xlatb  (not transcribed)
    xchg ebx, ebp
L_0001c860:
    db 03ah, 0c4h    ; cmp al, ah (WASM encodes it differently)
    je short L_0001c866
    mov byte ptr [edi], al
L_0001c866:
    add edi, 0x50
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    db 03bh, 0d3h    ; cmp edx, ebx (WASM encodes it differently)
    jae short L_0001c860
L_0001c86f:
    db 081h, 0c6h
L_0001c871:
    db 078h, 056h, 000h, 000h
    dec ecx
    jne short L_0001c84d
    pop ecx
    pop edi
    pop esi
    pop edx
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    mov ah, byte ptr [L_0001c844]
    rol ah, 1
    adc edi, 0
    mov byte ptr [L_0001c844], ah
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    jmp short L_0001c82e
L_0001c893:
    pop esi
    db 081h, 0c6h, 078h
L_0001c897:
    db 056h, 000h, 000h
    db 0b0h
L_0001c89b:
    db 0dfh
    rol al, 1
    jae short L_0001c8a6
    db 081h, 0eeh
L_0001c8a2:
    db 078h, 056h, 000h, 000h
L_0001c8a6:
    mov byte ptr [L_0001c89b], al
    org 038h
    mov ebx, dword ptr [ebp + 0xc]
    xchg ebx, ebp
    mov ebx, offset DAT_00032f88
    org 010bh
    jmp short L_0001c8ad
L_0001c8ad:
    dec ecx
    jne near ptr L_0001c827
    mov ax, 0xff02
    mov dx, 0x3c4
    out dx, ax
    popad
    leave
    ret
    xchg ebx, ebx
    nop
FUN_0001c8c4:
    enter 0, 0
    pushad
    mov al, 0x11
    mov byte ptr [L_0001c9ae], al
    mov edx, dword ptr [ebp + 0x14]
    mov ecx, dword ptr [ebp + 0x18]
    call FUN_0001aea8
    mov ah, 0x11
    rol ah, cl
    mov al, 2
    mov word ptr [L_0001c95b], ax
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov esi, dword ptr [ebp + 0x10]
    mov ebx, dword ptr [ebp + 0xc]
    mov eax, dword ptr [ebp + 8]
    mov word ptr [L_0001c942], ax
    mov word ptr [L_0001c967], ax
    db 032h, 0e4h    ; xor ah, ah (WASM encodes it differently)
    mov al, byte ptr [esi + 6]
    shl ax, 1
    mov word ptr [L_0001c9a9], ax
    shl ax, 2
    db 066h, 08bh, 0c8h    ; mov cx, ax (WASM encodes it differently)
    inc ax
    mov word ptr [L_0001c984], ax
    dec ax
    dec ax
    mov word ptr [L_0001c9b5], ax
    mov ax, word ptr [esi + 2]
    mov word ptr [L_0001c961], ax
    mov al, byte ptr [esi + 8]
    mov byte ptr [L_0001c970], al
    org $
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    shr edx, 1
    add esi, 8
    inc esi
L_0001c93f:
    push esi
    db 081h, 0c2h
L_0001c942:
    db 078h, 056h, 000h, 000h
L_0001c946:
    db 03bh, 0d3h    ; cmp edx, ebx (WASM encodes it differently)
    jb short L_0001c9a6
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    push edx
    push esi
    push edi
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    shr edx, 1
    push ecx
    push edx
    mov dx, 0x3c4
    db 066h, 0b8h
L_0001c95b:
    db 0dfh
L_0001c95c:
    db 03ch
    out dx, ax
    pop edx
    db 0b9h
L_0001c961:
    db 078h, 056h, 000h, 000h
L_0001c965:
    db 081h, 0c2h
L_0001c967:
    db 078h, 056h, 000h, 000h
    db 03bh, 0d3h    ; cmp edx, ebx (WASM encodes it differently)
    jb short L_0001c982
    db 0b4h
L_0001c970:
    db 0dfh
    mov al, byte ptr [esi]
L_0001c973:
    db 03ah, 0e0h    ; cmp ah, al (WASM encodes it differently)
    je short L_0001c979
    mov byte ptr [edi], al
L_0001c979:
    add edi, 0x50
    db 02bh, 0d3h    ; sub edx, ebx (WASM encodes it differently)
    db 03bh, 0d3h    ; cmp edx, ebx (WASM encodes it differently)
    jae short L_0001c973
L_0001c982:
    db 081h, 0c6h
L_0001c984:
    db 078h, 056h, 000h, 000h
    dec ecx
    jne short L_0001c965
    pop ecx
    pop edi
    pop esi
    pop edx
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    mov ah, byte ptr [L_0001c95c]
    rol ah, 1
    adc edi, 0
    mov byte ptr [L_0001c95c], ah
    db 086h, 0e0h    ; xchg al, ah (WASM encodes it differently)
    jmp short L_0001c946
L_0001c9a6:
    pop esi
    db 081h, 0c6h
L_0001c9a9:
    db 078h, 056h, 000h, 000h
    db 0b0h
L_0001c9ae:
    db 0dfh
    rol al, 1
    jae short L_0001c9b9
    db 081h, 0eeh
L_0001c9b5:
    db 078h, 056h, 000h, 000h
L_0001c9b9:
    mov byte ptr [L_0001c9ae], al
    org $
    dec ecx
    jne near ptr L_0001c93f
    mov ax, 0xff02
    mov dx, 0x3c4
    out dx, ax
    popad
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0001c9d4
FUN_0001c9d4:
    enter 0, 0
    pushad
    mov al, 0x11
    mov byte ptr [L_0001caaa], al
    mov edx, dword ptr [ebp + 0x1c]
    mov ecx, dword ptr [ebp + 0x20]
    call FUN_0001aea8
    mov ah, 0x11
    rol ah, cl
    mov al, 2
    mov word ptr [L_0001ca5e], ax
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov esi, dword ptr [ebp + 0x18]
    db 032h, 0e4h    ; xor ah, ah (WASM encodes it differently)
    mov al, byte ptr [esi + 6]
    shl ax, 1
    mov word ptr [L_0001ca86], ax
    shl ax, 2
    movzx ecx, ax
    mov ax, word ptr [esi]
    dec ax
    mov word ptr [L_0001cab1], ax
    inc ax
    shr ax, 2
    mov word ptr [L_0001caa5], ax
    mov ax, word ptr [esi + 4]
    mov word ptr [L_0001ca63], ax
    mov al, byte ptr [esi + 8]
    mov byte ptr [L_0001ca70], al
    org $
    mov edx, dword ptr [ebp + 0xc]
    shr edx, 1
    add esi, 8
    inc esi
L_0001ca43:
    push esi
    add edx, dword ptr [ebp + 8]
L_0001ca47:
    cmp edx, dword ptr [ebp + 0xc]
    jb short L_0001caa2
    sub edx, dword ptr [ebp + 0xc]
    push edx
    push esi
    push edi
    mov ebx, dword ptr [ebp + 0x14]
    shr ebx, 1
    push ecx
    mov dx, 0x3c4
    db 066h, 0b8h
L_0001ca5e:
    db 0dfh
L_0001ca5f:
    db 03ch
    out dx, ax
    db 0b9h
L_0001ca63:
    db 078h, 056h, 000h, 000h
L_0001ca67:
    add ebx, dword ptr [ebp + 0x10]
    cmp ebx, dword ptr [ebp + 0x14]
    jb short L_0001ca84
    db 0b4h
L_0001ca70:
    db 0dfh
    mov al, byte ptr [esi]
L_0001ca73:
    db 03ah, 0e0h    ; cmp ah, al (WASM encodes it differently)
    je short L_0001ca79
    mov byte ptr [edi], al
L_0001ca79:
    add edi, 0x50
    sub ebx, dword ptr [ebp + 0x14]
    cmp ebx, dword ptr [ebp + 0x14]
    jae short L_0001ca73
L_0001ca84:
    db 081h, 0c6h
L_0001ca86:
    db 078h, 056h, 000h, 000h
    dec ecx
    jne short L_0001ca67
    pop ecx
    pop edi
    pop esi
    pop edx
    mov al, byte ptr [L_0001ca5f]
    rol al, 1
    adc edi, 0
    mov byte ptr [L_0001ca5f], al
    jmp short L_0001ca47
L_0001caa2:
    pop esi
    db 081h, 0c6h
L_0001caa5:
    db 078h, 056h, 000h, 000h
    db 0b0h
L_0001caaa:
    db 0dfh
    rol al, 1
    jae short L_0001cab5
    db 081h, 0eeh
L_0001cab1:
    db 078h, 056h, 000h, 000h
L_0001cab5:
    mov byte ptr [L_0001caaa], al
    org $
    dec ecx
    jne short L_0001ca43
    mov ax, 0xff02
    mov dx, 0x3c4
    out dx, ax
    popad
    leave
    ret
    xchg ebx, ebx
; ---- FUN_0001cacc
FUN_0001cacc:
    enter 0, 0
    pushad
    mov al, 0x11
    mov byte ptr [L_0001cbac], al
    mov edx, dword ptr [ebp + 0x1c]
    mov ecx, dword ptr [ebp + 0x20]
    call FUN_0001aea8
    mov ah, 0x11
    rol ah, cl
    mov al, 2
    mov word ptr [L_0001cb56], ax
    db 08bh, 0fbh    ; mov edi, ebx (WASM encodes it differently)
    mov esi, dword ptr [ebp + 0x18]
    db 032h, 0e4h    ; xor ah, ah (WASM encodes it differently)
    mov al, byte ptr [esi + 6]
    shl ax, 1
    mov word ptr [L_0001cb88], ax
    shl ax, 2
    movzx ecx, ax
    mov ax, word ptr [esi]
    dec ax
    mov word ptr [L_0001cbb3], ax
    inc ax
    shr ax, 2
    mov word ptr [L_0001cba7], ax
    mov ax, word ptr [esi + 4]
    mov word ptr [L_0001cb62], ax
    mov al, byte ptr [esi + 8]
    mov byte ptr [L_0001cb6f], al
    mov ebx, dword ptr [ebp + 0xc]
    shr ebx, 1
    add esi, 8
    inc esi
L_0001cb3b:
    push esi
    add ebx, dword ptr [ebp + 8]
L_0001cb3f:
    cmp ebx, dword ptr [ebp + 0xc]
    jb short L_0001cba4
    sub ebx, dword ptr [ebp + 0xc]
    push ebx
    push esi
    push edi
    mov ebx, dword ptr [ebp + 0x14]
    shr ebx, 1
    push ecx
    mov dx, 0x3c4
    db 066h, 0b8h
L_0001cb56:
    db 0dfh
L_0001cb57:
    db 03ch
    out dx, ax
    db 08bh, 0d3h    ; mov edx, ebx (WASM encodes it differently)
    mov ebx, 0
    db 0b9h
L_0001cb62:
    db 078h, 056h, 000h, 000h
L_0001cb66:
    add edx, dword ptr [ebp + 0x10]
    cmp edx, dword ptr [ebp + 0x14]
    jb short L_0001cb86
    db 0b4h
L_0001cb6f:
    db 0dfh
    movzx ebx, byte ptr [esi]
    mov al, byte ptr [ebx + DAT_00032f88]
L_0001cb79:
    mov byte ptr [edi], al
    add edi, 0x50
    sub edx, dword ptr [ebp + 0x14]
    cmp edx, dword ptr [ebp + 0x14]
    jae short L_0001cb79
L_0001cb86:
    db 081h, 0c6h
L_0001cb88:
    db 078h, 056h, 000h, 000h
    dec ecx
    jne short L_0001cb66
    pop ecx
    pop edi
    pop esi
    pop ebx
    mov al, byte ptr [L_0001cb57]
    rol al, 1
    adc edi, 0
    mov byte ptr [L_0001cb57], al
    jmp short L_0001cb3f
L_0001cba4:
    pop esi
    db 081h, 0c6h
L_0001cba7:
    db 078h, 056h, 000h, 000h
    db 0b4h
L_0001cbac:
    db 0dfh
    rol ah, 1
    jae short L_0001cbb7
    db 081h, 0eeh
L_0001cbb3:
    db 078h, 056h, 000h, 000h
L_0001cbb7:
    mov byte ptr [L_0001cbac], ah
    org $
    dec ecx
    jne near ptr L_0001cb3b
    mov ax, 0xff02
    mov dx, 0x3c4
    out dx, ax
    popad
    leave
    ret
    xchg ebx, ebx
    nop
; ---- FUN_0001cbd4
FUN_0001cbd4:
    enter 0, 0
    push edi
    push esi
    push ecx
    mov edi, offset DAT_00032f88
    mov esi, dword ptr [ebp + 8]
    mov ecx, 0x40
    rep movsd
    pop ecx
    pop esi
    pop edi
    leave
    ret
_TEXT ends
end
