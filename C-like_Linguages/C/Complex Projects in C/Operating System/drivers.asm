section .text
global _start

_start:
mov ax, 0x13
int 0x10
ret
