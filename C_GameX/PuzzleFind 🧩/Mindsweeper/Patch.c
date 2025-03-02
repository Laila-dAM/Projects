#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define ERRORS 5
#define SAFE '_'
#define ERROR 'X'

char board[SIZE][SIZE];
char display[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            board[i][j] = SAFE;
            display[i][j] = '?';
        }
    }
}
void placeErrors(){
    srand(time(NULL));
    int count = 0;
    white (count < ERRORS){
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] != ERROR){
            board[x][y] = ERROR;
            count++;
        }
    }
}