#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "error_check.h"

int main(int args, char *argv[]) {
    if(argc < 2){
        printf("Pleace provide a source file to analyze.\n");
        return 1;
    }
const char *filename = argv[1];
    char *code = read_file(filename);

Token *token = lex_code(code);
    print_tokens(tokens);

    parse_code(tokens);

    check_for_errors(tokens);
    generate_report(filename);
    generate_visualization(filename);
return 0;
    
}