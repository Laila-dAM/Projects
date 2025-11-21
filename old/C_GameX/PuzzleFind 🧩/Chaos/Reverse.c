#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_intro() {
    printf("╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
    printf("┃     Reverse Logic     ┃\n");
    printf("┃    Welcome to the game┃\n");
    printf("╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
    printf("\nIn this game, you must figure out the opposite of a given rule.\n");
    printf("Each challenge will present a rule, and your task is to provide the opposite solution.\n");
    printf("Let's begin!\n\n");
}

void display_challenge(int challenge_num) {
    switch (challenge_num) {
        case 1:
            printf("\nChallenge 1: Reverse Logic\n");
            printf("Rule: If the alarm rings, it is time to wake up.\n");
            printf("Opposite: If you are not waking up, what is happening with the alarm?\n");
            printf("Your Answer: ");
            break;
        case 2:
            printf("\nChallenge 2: Reverse Logic\n");
            printf("Rule: If you are inside, the door is closed.\n");
            printf("Opposite: If the door is open, where could you be?\n");
            printf("Your Answer: ");
            break;
        case 3:
            printf("\nChallenge 3: Reverse Logic\n");
            printf("Rule: If the sky is clear, you don’t need an umbrella.\n");
            printf("Opposite: If you need an umbrella, what is the sky like?\n");
            printf("Your Answer: ");
            break;
        case 4:
            printf("\nChallenge 4: Reverse Logic\n");
            printf("Rule: If the cat is purring, it’s happy.\n");
            printf("Opposite: If the cat is not happy, what should it be doing?\n");
            printf("Your Answer: ");
            break;
        case 5:
            printf("\nChallenge 5: Reverse Logic\n");
            printf("Rule: If you hear music, someone is playing it.\n");
            printf("Opposite: If there is no one playing music, what could you hear?\n");
            printf("Your Answer: ");
            break;
        case 6:
            printf("\nChallenge 6: Reverse Logic\n");
            printf("Rule: If the light is on, the door is open.\n");
            printf("Opposite: If the door is closed, what is the state of the light?\n");
            printf("Your Answer: ");
            break;
        case 7:
            printf("\nChallenge 7: Reverse Logic\n");
            printf("Rule: If the clock strikes midnight, it is time to sleep.\n");
            printf("Opposite: If you are not sleeping, what time is it?\n");
            printf("Your Answer: ");
            break;
        case 8:
            printf("\nChallenge 8: Reverse Logic\n");
            printf("Rule: If the coffee is hot, you can drink it.\n");
            printf("Opposite: If you cannot drink it, what is the temperature of the coffee?\n");
            printf("Your Answer: ");
            break;
        case 9:
            printf("\nChallenge 9: Reverse Logic\n");
            printf("Rule: If the streetlight is on, it is dark outside.\n");
            printf("Opposite: If it is not dark, what is the state of the streetlight?\n");
            printf("Your Answer: ");
            break;
        case 10:
            printf("\nChallenge 10: Reverse Logic\n");
            printf("Rule: If the doorbell rings, someone is at the door.\n");
            printf("Opposite: If no one is at the door, what could have happened?\n");
            printf("Your Answer: ");
            break;
        default:
            printf("\nInvalid challenge number.\n");
            break;
    }
}
int check_answer(int challenge_num, char answer[]) {
    switch (challenge_num) {
        case 1:
            return (strcmp(answer, "alarm is off") == 0 || strcmp(answer, "no alarm") == 0);
        case 2:
            return (strcmp(answer, "outside") == 0 || strcmp(answer, "open air") == 0);
        case 3:
            return (strcmp(answer, "cloudy") == 0 || strcmp(answer, "rainy") == 0);
        case 4:
            return (strcmp(answer, "meowing") == 0 || strcmp(answer, "hiding") == 0);
        case 5:
            return (strcmp(answer, "silence") == 0 || strcmp(answer, "no music") == 0);
        case 6:
            return (strcmp(answer, "off") == 0 || strcmp(answer, "dark") == 0);
        case 7:
            return (strcmp(answer, "before midnight") == 0 || strcmp(answer, "not midnight") == 0);
        case 8:
            return (strcmp(answer, "cold") == 0 || strcmp(answer, "lukewarm") == 0);
        case 9:
            return (strcmp(answer, "light off") == 0 || strcmp(answer, "daytime") == 0);
        case 10:
            return (strcmp(answer, "no one is ringing") == 0 || strcmp(answer, "malfunction") == 0);
        default:
            return 0;
    }
}

void play_game() {
    int challenge_num = 1;
    char answer[100];
    int correct = 0;
    int attempts = 3;

    display_intro();

    while (challenge_num <= 10) {
        display_challenge(challenge_num);
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;

        if (check_answer(challenge_num, answer)) {
            printf("Correct! (≧◡≦)\n");
            correct++;
            challenge_num++;
        } else {
            printf("Incorrect! (╯︵╰,) You have %d attempts left.\n", --attempts);
            if (attempts == 0) {
                printf("Game over! You couldn't solve all challenges.\n");
                break;
            }
        }
    }

    if (challenge_num == 11) {
        printf("\nCongratulations! You've solved all challenges! (☆^O^☆)\n");
        printf("You are a reverse logic master! (◕‿◕)\n");
    } else {
        printf("Better luck next time! (´∩｡• ᵕ •｡∩`)\n");
    }
}

int main() {
    play_game();
    return 0;
}

