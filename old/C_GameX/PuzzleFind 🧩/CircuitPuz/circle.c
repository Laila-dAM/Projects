#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define GRID_SIZE 5

#define WIRE_H "──"
#define WIRE_V "│ "
#define GATE_AND "(&)"
#define GATE_OR "(|)"
#define GATE_NOT "(!)"
#define EMPTY "  "
#define START "[S]"
#define END "[E]"

char *grid[GRID_SIZE][GRID_SIZE];
void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    grid[0][0] = START;
    grid[0][1] = WIRE_H;
    grid[0][2] = GATE_AND;
    grid[1][2] = WIRE_V;
    grid[2][2] = GATE_OR;
    grid[2][3] = WIRE_H;
    grid[2][4] = END;
}

void displayGrid() {
    printf("\n=== Circuit Puzzle ===\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%s ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && strcmp(grid[x][y], EMPTY) == 0;
}

void movePiece(int x1, int y1, int x2, int y2) {
    if (!isValidMove(x2, y2)) {
        printf("\n(╯°□°）╯︵ ┻━┻ Invalid move! Try again.\n");
        return;
    }
    grid[x2][y2] = grid[x1][y1];
    grid[x1][y1] = EMPTY;
}

void gameLoop() {
    int x1, y1, x2, y2;
    char input[10];
    while (1) {
        displayGrid();
        printf("\nEnter move (x1 y1 x2 y2) or 'q' to quit: ");
        fgets(input, sizeof(input), stdin);
        if (tolower(input[0]) == 'q') break;
        if (sscanf(input, "%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
            movePiece(x1, y1, x2, y2);
        } else {
            printf("\n(¬_¬) Invalid input, please try again.\n");
        }
    }
    printf("\n(｡•́︿•̀｡) Game over! Thanks for playing.\n");
}

int main() {
    initializeGrid();
    printf("\n(◕‿◕) Connect the circuit logically to unlock the digital gate!\n");
    gameLoop();
    return 0;
}
