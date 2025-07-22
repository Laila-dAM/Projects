ᴄᴏᴅᴇ 👾

---

# OS

## What is it?

A minimalist operating system kernel written in C and x86 Assembly. It boots via a custom bootloader, initializes basic interrupts, and outputs text directly to video memory. This project serves as a learning foundation for low-level OS development, offering a clear structure with interrupt setup, memory management, and framebuffer output.

## How to use?

1. Make sure you have the required tools installed:
- `nasm` for assembling `.asm` files
- `gcc` for compiling C code
- `ld` or a cross-compiler (`i686-elf-gcc`)
- `qemu` for running the OS

2. In the project directory, build the OS using the provided Makefile:

```bash
make
```

3. Run the OS in QEMU:

```bash
make run
```

> This will launch QEMU and boot into the kernel, displaying:
Minimal OS Kernel Loaded!

## Features
- Custom bootloader (boot.asm)
- Kernel entry point in assembly (kernel_entry.asm)
- Text-mode framebuffer printing directly to 0xB8000
- Basic memory initialization stub
- Interrupt system setup
- Fully linkable with linker.ld
- Organized modular structure

## Folder Structure
```bash
📁 Minimal OS/
├── boot.asm              # Bootloader (real mode)
├── kernel_entry.asm      # Transition to protected mode and kernel start
├── kernel.c              # Main kernel logic (C)
├── kernel.h              # Kernel declarations
├── fs.c / memory.c       # File system and memory modules
├── interrupt.asm         # Interrupt setup
├── types.h               # Type definitions
├── linker.ld             # Linker script
├── Makefile              # Build and run commands
└── qemu                  # (Optional) QEMU config or boot image
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
