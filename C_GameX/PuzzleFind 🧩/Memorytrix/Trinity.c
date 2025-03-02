#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define ATTEMPTS 3

void generateCorruptedMatrix(int matrix[SIZE][SIZE]) {
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++){
        matrix[i][j] = rand() % 2;
}
}
}
void displayMatrix(int matrix[SIZE][SIZE]) {
for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
        printf("%d ", matrix[i][j]);
    }
printf("\n");
}
}
void copyMatrix(int source[SIZE][SIZE], int destination[SIZE][SIZE]) {
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++){
                    destination[i][j] = source[i][j];
    }
}
}