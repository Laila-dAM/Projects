ᴄᴏᴅᴇ 👾

---

# Simple Operating System

## What is it?

A C-based educational operating system that simulates basic OS components such as memory management, process handling, and file systems. It initializes core kernel modules and includes additional low-level drivers written in Assembly. This project offers a minimal but extendable foundation for understanding operating system internals.

## How to use?

1. Make sure you have a C compiler (e.g., `gcc`) and `nasm` installed.

2. Assemble the hardware drivers:

```bash
nasm -f elf32 drivers.asm -o simple_os/bin/drivers.o
nasm -f elf32 hardware.asm -o simple_os/bin/hardware.o
```

3. Compile all C source files:

```bash
gcc -m32 kernel.c memory.c process.c filesystem.c init.c multitask.c -o simple_os/bin/simple_os
```

4. Run (simulation example using QEMU or equivalent):

```bash
qemu-system-i386 -kernel simple_os/bin/simple_os
```

## Features

- Initializes kernel with memory, process, and filesystem modules
- Includes low-level hardware and driver stubs (ASM)
- Modular design for easier experimentation and learning
- Optional shell.py to simulate a user interface
- Configuration via config.py for boot-time behavior

## Folder Structure

```bash
📁 Operating System/
├── kernel.c                  # Main kernel logic (entry point)
├── memory.c / memory.o       # Memory management system
├── process.c / process.o     # Process scheduling and control
├── filesystem.c / filesystem.o # Simulated file system
├── init.c / multitask.c      # Initialization and multitasking logic
├── drivers.asm / hardware.asm # Low-level system code
├── config.py                 # Configuration script
├── shell.py                  # Simulated command-line shell
├── simple_os/
│   └── bin/                  # Compiled binaries
└── README.md                 # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
