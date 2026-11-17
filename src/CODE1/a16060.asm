; a16060.asm - assembler module of CODE.1 (292 bytes of code)
; Instructions written as `db` are encodings the original assembler chose and WASM does not (comment: the instruction).
; `org` lines are object record boundaries: the linker writes the relocation records of the executable in the order
; of the object records, so the code is laid out in the record order of the original object.
.386p
DGROUP group _DATA
_TEXT segment para public use32 'CODE'
_TEXT ends
extrn FUN_000150c0:near
extrn __GETDS:near
extrn DAT_00032b28:byte
_DATA segment dword public use32 'DATA'
DAT_00031360 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 00031360  ........
DAT_00031368 label byte
    db 000h    ; 00031368  .
DAT_00031369 label byte
    db 000h    ; 00031369  .
DAT_0003136a label byte
    db 000h    ; 0003136a  .
DAT_0003136b label byte
    db 000h    ; 0003136b  .
DAT_0003136c label byte
    db 000h    ; 0003136c  .
DAT_0003136d label byte
    db 000h    ; 0003136d  .
DAT_0003136e label byte
    db 4177 dup(0)    ; 0003136e
DAT_000323bf label byte
    db 000h, 000h, 000h, 000h    ; 000323bf  ....
DAT_000323c3 label byte
    db 000h, 000h    ; 000323c3  ..
DAT_000323c5 label byte
    db 000h, 000h, 000h, 000h, 000h, 000h, 000h    ; 000323c5  .......
_DATA ends
_TEXT segment para public use32 'CODE'
assume cs:_TEXT, ds:DGROUP, ss:DGROUP
public FUN_00016104
; ---- FUN_00016060
L_00016060:
    push ebx
    push edx
    push eax
    mov ebx, 0x54
L_00016068:
    mov al, byte ptr [ebx + DAT_00032b28]
    mov byte ptr [ebx + DAT_0003136e], al
    dec ebx
    jge short L_00016068
    mov dx, 0x3c4
    in al, dx
    mov byte ptr [DAT_0003136a], al
    mov al, 2
    out dx, al
    inc dx
    in al, dx
    mov byte ptr [DAT_00031369], al
    mov dx, 0x3ce
    in al, dx
    mov byte ptr [DAT_0003136c], al
    mov al, 5
    out dx, al
    inc dx
    in al, dx
    mov byte ptr [DAT_0003136b], al
    dec dx
    mov al, 4
    out dx, al
    inc dx
    in al, dx
    mov byte ptr [DAT_0003136d], al
    org $
    pop eax
    pop edx
    pop ebx
    ret
    xchg ebx, ebx
; ---- FUN_000160b4
L_000160b4:
    push ebx
    push edx
    push eax
    mov ebx, 0x54
L_000160bc:
    mov al, byte ptr [ebx + DAT_0003136e]
    mov byte ptr [ebx + DAT_00032b28], al
    dec ebx
    jge short L_000160bc
    mov dx, 0x3c4
    mov al, 2
    mov ah, byte ptr [DAT_00031369]
    out dx, ax
    mov al, byte ptr [DAT_0003136a]
    out dx, al
    mov dx, 0x3ce
    mov al, 5
    mov ah, byte ptr [DAT_0003136b]
    out dx, ax
    mov al, 4
    mov ah, byte ptr [DAT_0003136d]
    out dx, ax
    mov al, byte ptr [DAT_0003136c]
    org $
    out dx, al
    pop eax
    pop edx
    pop ebx
    ret
    xchg ebx, ebx
    nop
FUN_00016104:
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
    cmp byte ptr [DAT_00031368], 0
    jne short L_0001617a
    mov byte ptr [DAT_00031368], 1
    mov word ptr [DAT_000323c3], ss
    mov dword ptr [DAT_000323c5], esp
    cli
    mov dword ptr [DAT_0003136e], eax
    mov ax, ds
    db 08eh, 0d0h    ; mov ss, eax (WASM rejects it)
    mov esp, offset DAT_000323bf
    mov eax, dword ptr [DAT_0003136e]
    and esi, 0xffff
    shl esi, 4
    push esi
    push edx
    push ecx
    push ebx
    push eax
    call L_00016060
    call FUN_000150c0
    add esp, 8
    call L_000160b4
    mov esp, dword ptr [DAT_000323c5]
    db 08eh, 015h
    dd offset DAT_000323c3    ; mov ss, word ptr [0x23c3] (WASM encodes it differently)
    mov byte ptr [DAT_00031368], 0
L_0001617a:
    pop gs
    pop fs
    pop es
    pop ds
    popad
    popf
    retf
_TEXT ends
end
