NASM = nasm
GCC = gcc
LD = ld
QEMU = qemu-system-x86_64

ASM_FILES = boot.asm interrupt.asm kernel_entry.asm
C_FILES = kernel.c memory.c fs.c
OBJECTS = kernel.o memory.o fs.o
OUTPUT = os.img

LINKER_SCRIPT = linker.ld

all: $(OUTPUT)

$(OUTPUT): $(ASM_FILES) $(C_FILES)
	$(NASM) -f elf32 boot.asm -o boot.o
	$(NASM) -f elf32 interrupt.asm -o interrupt.o
	$(NASM) -f elf32 kernel_entry.asm -o kernel_entry.o
	
	$(GCC) -m32 -ffreestanding -c kernel.c -o kernel.o
	$(GCC) -m32 -ffreestanding -c memory.c -o memory.o
	$(GCC) -m32 -ffreestanding -c fs.c -o fs.o
	
	$(LD) -m elf_i386 -T $(LINKER_SCRIPT) -o $(OUTPUT) boot.o kernel.o memory.o fs.o interrupt.o kernel_entry.o

run: $(OUTPUT)
	$(QEMU) -drive file=$(OUTPUT),format=raw
