#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "error_check.h"
#include <stdlib.h>

void generate_report(const char *filename) {
    char command[512];
#ifdef _WIN32
    sprintf(command, "python reports/generate_report.py %s", filename);
#else
    sprintf(command, "python3 reports/generate_report.py %s", filename);
#endif
    system(command);
}

void generate_visualization(const char *filename) {
    char command[512];
#ifdef _WIN32
sprintf(command, "python visualizations\\generate_visualizations.py %s", filename);
#else
    sprintf(command, "python3 visualizations/generate_visualization.py %s", filename);
#endif
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a source file to analyze.\n");
        return 1;
    }

    const char *filename = argv[1];
    char *code = read_file(filename);
    if (!code) {
        printf("Error reading file %s\n", filename);
        return 1;
    }

    Token *tokens = lex_code(code);
    print_tokens(tokens);

    parse_code(tokens);
    check_for_errors(tokens);

    generate_report(filename);
    generate_visualization(filename);

    free(code);
    return 0;
}
