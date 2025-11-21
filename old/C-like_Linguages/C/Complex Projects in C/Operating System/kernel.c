#include <stdio.h>
#include "memory.c"
#include "process.c"
#include "filesystem.c"

void kernel_main(){
    init_memory();
    init_process_management();
    init_filesystem();
    printf("Kernel initialized!/n");
}