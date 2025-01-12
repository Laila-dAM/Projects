section .text
global _start

_start:
mov ax, 0x4F00
int 0x10
ret
