#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_ATTEMPTS 6

void display_hangman(int attempts) {
    const char *stages[] = {
      "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="

    };
    printf("%s\n", stages[attempts]);
}
void play_hangman(const char *word) {
    int word_length = strlen(word);
    char guessed[MAX_WORD_LENGTH] = {0};
    int attempts = 0;
    int correct_guesses = 0;
    char used_letters[26] = {0};
    int used_count = 0;

    for(int i = 0; i < word_length; i++) {
        guessed[i] = '_';
    }
while(attempts < MAX_ATTEMPTS && correct_guesses < word_length) {
    display_hangman(attempts);
    printf("Word: ");
    for(int i = 0; i < word_length; i++){
        printf("%c ", guessed[i]);
    }
    printf("\n");
    printf("Used letters: ");
    for(int i = 0; i < used_count; i++){
        printf("%c ", used_letters[i]);
    }
    printf("\n");

    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);
    guess = tolower(guess);

    if(strchr(used_letters, guess)){
        printf("You already guessed that letter!\n");
        continue;
    }
    used_letters[used_count++] = guess;

    int found = 0;
    for(int i = 0; i < word_length; i++){
        if(word[i] == guess){
            if(guessed[i] == '_'){
                guessed[i] = guess;
                correct_guesses++;
                found = 1;
            }
        }
    }
    if(!found){
        attempts++;
        printf("Wrong guess! Attempts left: %d\n", MAX_ATTEMPTS - attempts);
    }
}
    if(correct_guesses == word_length){
        printf("Congratulations! You guessed the word: %s\n", word);
    }
    else {
        display_hangman(MAX_ATTEMPTS);
                printf("(´×ω×`) You lost! The word was: %s\n", word);

    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    printf("Enter the word to guess (player 1): ");
    scanf("%s", word);

    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
    system("clear");
    play_hangman(word);
    return 0;
}