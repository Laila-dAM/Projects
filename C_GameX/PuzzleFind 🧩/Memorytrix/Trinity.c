#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SIZE 5
#define DELAY 3

void clearScreen() {
    printf("\033[H\033[J");
}
