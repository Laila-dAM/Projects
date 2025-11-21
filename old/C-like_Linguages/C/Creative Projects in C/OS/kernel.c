#include "kernel.h"

void kernel_main(void) {
    initialize_interrupts();
    print("Minimal OS Kernel Loaded!");
    initialize_memory();

    while(1){
    }
}
void print(char* str){
    char* video_memory = (char*) 0xB8000;
    for (int i = 0; str[i] != '\0'; i++){
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = 0x0F;
    }
}
extern void initialize_interrupts(void);
extern void initialize_memory(void);