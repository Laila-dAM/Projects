#include "types.h"

#define MEMORY_SIZE 0x1000000
char memory[MEMORY_SIZE];

void initialize_memory(void) {
    for(int i = 0; i < MEMORY_SIZE; i++){
        memory[i] = 0;
    }
}
void* malloc(size_t size){
    static int next_free = 0;
    if (next_free + size > MEMORY_SIZE){
        return 0;
    }
void* ptr = &memory[next_free];
    next_free += size;
    return ptr;
}
void free(void* ptr){
}