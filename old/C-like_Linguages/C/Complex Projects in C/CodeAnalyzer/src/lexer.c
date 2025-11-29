#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *buffer = (char *)malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);
    return buffer;
}

Token *lex_code(char *code) {
    return NULL; // dummy
}

void print_tokens(Token *tokens) {
    printf("Tokens printed (dummy)\n");
}
