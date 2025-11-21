[bits 32]
global_start

_start:
    call initialize_interrupts
    call initialize_memory
    jmp $

initialize_interrupts:
    ret

initialize_memory:
    ret
    