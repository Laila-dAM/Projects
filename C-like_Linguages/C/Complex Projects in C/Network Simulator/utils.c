#include <stdio.h>

void log_event(const char* event){
    printf("Log: %s\n", event);
}

void handle_error(const char* error){
    fprintf(stderr, "Error: %s\n", error);
}