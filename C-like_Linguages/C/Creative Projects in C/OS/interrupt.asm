[bits 32]
global isr_handler
isr_handler:
    mov al, 0x20
    out 0x20, al
    iret
    