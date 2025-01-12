#include <stdio.h>

void init_filesystem(){
    printf("File system initialized!\n");
}
void read_file(const char* filename){
    printf("Reading file: %s\n", filename);
}
void write_file(const char* filename, const char* content){
    printf("Writing to file: %s\n", filename);
}