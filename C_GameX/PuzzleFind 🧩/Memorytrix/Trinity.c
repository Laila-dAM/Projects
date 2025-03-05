#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SIZE 5
#define DELAY 3

void clearScreen() {
    printf("\033[H\033[J");
}
void generatePattern(int pattern[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            pattern[i][j] = rand() % 2;
        }
    }
}
void displayPattern(int pattern[SIZE][SIZE]) {
    printf("\n┌───────────────────────────┐\n");
    printf("│  (✧ω✧) Memorize this!    │\n");
    printf("└───────────────────────────┘\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("   ");
        for (int j = 0; j < SIZE; j++) {
            printf("%s ", pattern[i][j] ? "█" : "·");
        }
        printf("\n");
    }
}

void getPlayerInput(int input[SIZE][SIZE]) {
    printf("\n┌─────────────────────────────────────┐\n");
    printf("│  (o_O) Reconstruct the pattern!    │\n");
    printf("└─────────────────────────────────────┘\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &input[i][j]);
        }
    }
}

int comparePatterns(int pattern[SIZE][SIZE], int input[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (pattern[i][j] != input[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

