#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 4
#define TIME_LIMIT 30

char grid[GRID_SIZE][GRID_SIZE][5];
int score = 0;
time_t start_time;

void initializeGrid() {
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int num = rand() % 16;
            sprintf(grid[i][j], "%04d", (num & 8) >> 3, (num & 4) >> 2, (num & 2) >> 1, num & 1);
        }
    }
}

