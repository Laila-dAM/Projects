#include <stdio.h>

void init_memory() {
    printf("Memory management initialized!\n");
}
void allocate_memory(int size){
    printf("Allocated %d bytes of memory\n", size);
}
void deallocate_memory(int size){
    printf("Deallocated %d bytes of memory\n", size);
}
