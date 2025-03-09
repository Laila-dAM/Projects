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
