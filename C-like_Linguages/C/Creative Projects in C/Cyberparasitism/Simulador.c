#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define EASY 1
#define MEDIUM 2
#define HARD 3

typedef struct {
    int health;
    int adaptation;
} Virus;

typedef struct {
    int health;
    int defense_pattern[3];
} ImmuneSystem;

void initialize_virus(Virus *virus){
    virus->health = MAX_HEALTH;
    virus->adaptation = 0;
}

void initialize_immune_system(ImmuneSystem *immune_system) {
    immune_system->health = MAX_HEALTH;
        for (int i = 0; i < 3; i++){
            immune_system->defense_pattern[i] = rand() % 3 + 1;
        }
}

int simulate_attack(Virus *virus, ImmuneSystem *immune_system, int difficulty) {
    int attack_pattern = rand() % 3 + 1;
    int defense = immune_system->defense_pattern[attack_pattern - 1];

    printf("Virus attacks with pattern %d. Defense is %d.\n", attack_pattern, defense);

    if(attack_pattern == defense){
        printf("Attack blocked by the immune system!\n");
        virus->health -= 10;
    } else {
        printf("Virus successfully bypassed the defense!\n");
        immune_system->health -= 10;
    
        if(difficulty >= MEDIUM) {
        virus->adaptation += 1;
        if(virus->adaptation >= 5 && difficulty == HARD) {
            printf("Virus adapts its strategy!\n");
            immune_system->defense_pattern[attack_pattern - 1] = rand() % 3 + 1;
            virus->adaptation = 0;
        }
    }
}
    return (virus->health > 0 && immune_system->health > 0);
}
void game_loop(int difficulty) {
    Virus virus;
    ImmuneSystem immune_system;

initialize_virus(&virus);
initialize_immune_system(&immune_system);
    printf("\nCyberparasitism Simulator\n");
    printf("Virus vs Immune System\n");
    printf("Difficulty level: %s\n\n", difficulty == EASY ? "EASY" : (difficulty == MEDIUM ? "Medium" : "Hard"));

    while (simulate_attack(&virus, &immune_system, difficulty)){
        printf("Virus health: %d, Immune System health: %d\n\n", virus.health, immune_system.health);
    }
    if(virus.health <= 0){
        printf("The immune system successfully eliminated the virus!\n");
    } else {
        printf("The virus successfully infected the system!\n");
    }
}
int main() {
    srand(time(NULL));
    int difficulty = MEDIUM;
    game_loop(difficulty);
    return 0;
}
