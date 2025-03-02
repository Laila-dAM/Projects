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
    while (count < ERRORS){
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] != ERROR){
            board[x][y] = ERROR;
            count++;
        }
    }
}
int countAdjacentErrors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            int nx = x + 1, ny = y + j;
                        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == ERROR) {
count++;
}
}
}
return count;
}
void revealCell(int x, int y){
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || display[x][y] != '?') return;
if (board[x][y] == ERROR){
            printf("\nOh no! You triggered a fatal bug! Debugging failed.\n");
exit(0);
}
int adjacent = countAdjacentErrors(x, y);
    display[x][y] = '0' + adjacent;

if(adjacent == 0){
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j ++){
            revealCell(x + i, y + j);
            
        }
    }
}
}
void printBoard(){
    printf("\n   ");
    for (int i = 0; i < SIZE; i++) printf("%d ", i);
    printf("\n");
    for(int i = 0; i < SIZE; i++){
        printf("%d |", i);
        for(int j = 0; j < SIZE; j++){
            printf("%c ", display[i][j]);
        }
printf("|\n");
    }
}
int checkWin(){
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
                        if (board[i][j] == SAFE && display[i][j] == '?') return 0;
        }
    }
return 1;
}
int main() {
    initializeBoard();
    placeErrors();

        printf("Welcome to Mindsweeper! Your mission: debug the code without triggering fatal errors.\n");

    while (1) {
        printBoard();

        int x, y;
        printf("Select a line and column (e.g., 1 2): ");
scanf("%d %d", &x, &y);

    revealCell(x,y);
        if(checkWin()){
            printBoard();
                        printf("\nCongratulations! You successfully debugged the system and saved the project!\n");
break;
        }
    }
    return 0;
}