CC = gcc
CFLAGS = -Wall -std=c99
SRC = src/main.c src/lexer.c src/parser.c src/error_check.c
OBJ = $(SRC.:c=.o)
EXEC = code_analyzer

$(EXEC): $(OBJ)
    $(CC) $(OBJ) -o $(EXEC)

%.o: %.c
    $(CC) $(CFLAGS) -c $<

clean:
    rm -f $(OBJ) $(EXEC)