#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
char labyrinths[5][SIZE][SIZE] = {
    {
        "S   E",
        "|/  |",
        " |/ |",
        "   | ",
        "  |  "
    },
    {
        "S   E",
        "|/  |",
        " |/ |",
        "|  | ",
        "   | "
    },
    {
        "S   E",
        "|/  |",
        "|/  |",
        " | | ",
        "   | "
    },
    {
        "S  E",
        "|/ | ",
        " |/ | ",
        "| |  |",
        "   |  "
    },
    {
        "S  E",
        "|/ | ",
        "|/ | ",
        "| |/|",
        "   |/ "
    }
};
void printLabyrinth(char labyrinth[SIZE][SIZE]){
    for(int i=0; i < SIZE; i++){
        printf("%s\n", labyrinth[i]);
    }
}
int movePlayer(int *x, int *y, char direction, char labyrinth[SIZE][SIZE]) {
    int newX = *x;
    int newY = *y;

if(direction == 'w') newX--;
    else if(direction == 's') newX++;
    else if(direction == 'a') newY--;
    else if(direction == 'd') newY++;

if(newX >= 0 && newX < SIZE && newY >= 0 && newY >= 0 && newY < SIZE && labyrinth[newX][newY] != '|' && labyrinth[newX][newY] !='/' && labyrinth[newX][newY] !='\\' && labyrinth[newX][newY] !='#') {
    *x = newX;
    *y = newY;
    return 1;
}
    return 0;
}
int main() {
    int level = 0;
    int x = 0, y = 0;
    char direction;
    int won = 0;

while (level < 5){
    printf("\nLevel %d\n", level + 1);
    printLabyrinth(labyrinths[level]);
if(labyrinths[level][x][y] == 'S'){
    printf("\nPlayer status: (˶˃ ᵕ ˂˶)\n");
}
while(!won){
    printf("\nUse w, a, s, d to move (q to quit): ");
    scanf(" %c", &direction);
if(direction == 'q'){
    printf("Quitting game...\n");
    return 0;
}
if(movePlayer(&x, &y, direction, labyrinths[level])) {
    if(labyrinths[level][x][y] == 'E'){
        won = 1;
        printf("\nPlayer status: ٩(^ᗜ^ )و ♪\n");
        printf("You found the exit!\n");
    } else {
        printf("\nPlayer status: (˶˃ ᵕ ˂˶)\n");
    }
}
    else {
        printf("\nPlayer status: (,,>.<,,)!\n");
        printf("You hit a wall!\n");
        
    }
}
    level++;
    won = 0;
    x = 0;
    y = 0;
}
    printf("\nCongratulations! You completed all levels!\n");
    printf("Player status: ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧\n");

    return 0;
}