#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
class Participant {
public:
    string name;
    int health;
    bool eliminated;

    Participant(string name) : name(name), health(100), eliminated(false) {}

void takeDamage(int damage) {
    health -= damage;
    if(health <= 0){
        health = 0;
        eliminated = true;
    }
}
void heal(int amount){
    health += amount;
    if(health > 100) health = 100;
}
bool isEliminated() const{
    return eliminated;
}
void printStatus() const{
            cout << name << " | Health: " << health << " | " << (eliminated ? "Eliminated" : "In Game") << endl;

}
};
class Narrator{
public:
static void announceElimination(Participant& participant){
    cout << participant.name << " has been eliminated! The drama is heating up!" << endl;
}
static void randomEvent(Participant& participant) {
    int event = rand() % 3;
    switch(event){
        case 0:
        cout << "A mysterious storm hits the camp! " << participant.name << " loses 20 health!" << endl;
        participant.takeDamage(20);
        break;

        case 1:
        cout << participant.name << " found a hidden health pack! " << participant.name << " gains 20 health!" << endl;
        participant.heal(20);
        break;

        case 2:
        cout << participant.name << " was caught in a prank! They lose 10 health!" << endl;
        participant.takeDamage(10);
        break;
}
}
static void commentOnGame(const vector<Participant>& participants) {
    for(const auto& participant : participants){
        if(!participant.isEliminated()){
        cout << participant.name << " is still in the game. They're a tough competitor!" << endl;

}
}
}
};

class RealityShow{
private:
    vector<Participant> participants;
public:
    RealityShow(vector<string>names){
        for(const string& name : names){
            participants.push_back(Participant(name));
        }
    }
void startEliminationRound(){
    int remaining = 0;
    for(auto& participant : participants){
        if(!participant.isEliminated()){
            remaining++;
        }
    }
if(remaining <= 1) {
    cout << "The game is over! Only one participant left!" << endl;
    return;
    
}
    int randomIndex;
    do{
        randomIndex = rand() % participants.size();
    } while(participants[randomIndex].isEliminated());
        participants[randomIndex].eliminated = true;
    Narrator::announceElimination(participants[randomIndex]);
}
void triggerRandomEvent(){
    int randomIndex = rand() % participants.size();
    while(participants[randomIndex].isEliminated()){
        randomIndex = rand() % participants.size();
    }
    Narrator::randomEvent(participants[randomIndex]);
}
void showParticipants(){
    cout << "\nParticipants Status:\n";
    for(const auto& participant : participants) {
        participant.printStatus();
        
    }
}
void showFinalWinner(){
    for(auto& participant : participants){
        if(!participant.isEliminated()){
            cout << participant.name << " is the winner!" << endl;
            break;
            
        }
    }
}
void playGame(){
    int round = 1;
    while(true) {
        cout << "\n--- Round" << round << " ---\n";
        Narrator::commentOnGame(participants);
        showParticipants();

        triggerRandomEvent();
        startEliminationRound();

        round++;
        int remaining = 0;
        for(const auto& participant : participants){
            if(!participant.isEliminated()){
                remaining++;
            }
        }
        if(remaining <= 1){
            break;
        }
    }
    showFinalWinner();
}
};
int main() {
    srand(time(0));
    vector<string> names = {"Apple", "Banana", "Cherry", "Dragonfruit", "Elderberry"};

    RealityShow show(names);
    show.playGame();
    return 0;
}
