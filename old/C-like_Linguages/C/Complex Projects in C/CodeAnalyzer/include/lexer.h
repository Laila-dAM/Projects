#ifndef LEXER_H
#define LEXER_H

typedef struct {
    int dummy;
} Token;

char *read_file(const char *filename);
Token *lex_code(char *code);
void print_tokens(Token *tokens);

#endif
