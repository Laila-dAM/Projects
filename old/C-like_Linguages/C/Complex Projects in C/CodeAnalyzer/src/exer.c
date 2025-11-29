#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(length + 1);
    if (!buffer) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);
    return buffer;
}

Token *lex_code(char *code) {
    // Minimal dummy implementation
    return NULL;
}

void print_tokens(Token *tokens) {
    // Minimal dummy implementation
    printf("Tokens printed (dummy function)\n");
}
