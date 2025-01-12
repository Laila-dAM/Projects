#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void displayIntroduction();
std::string chooseGenre();
void generateScene(const std::string& genre);
void audienceReaction();

int main() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

displayIntroduction();
    std::string genre = chooseGenre();
    std::cout <<"\n🎭 Scene begins:\n";
    generateScene(genre);

std::cout <<"\n ✨ Audience reacts:\n";
    audienceReaction();
std::cout << "\n🎬 The End. Thank you for visiting the Virtual Theater of Kaomojis!\n";
return 0;
}

void displayIntroduction(){
std::cout << "Welcome to the Virtual Theater of Kaomojis!\n";
std::cout << "Here, adorable kaomojis act out scenes just for you.\n\n";
std::cout << "You can choose the genre of the performance and enjoy the show.\n";
std::cout << "Sit back, relax, and let the theater begin!\n\n";
}

std::string chooseGenre(){
std::string genre;
std::cout << "Choose a genre (romance, action, comedy): ";
std::cin >> genre;
return genre;
}

void generateScene(const std::string& genre){
    if(genre == "romance"){
    std::cout << "(⁄ ⁄•⁄ω⁄•⁄ ⁄) \"I think I like you...\"\n";
    std::cout << "(｡♥‿♥｡) \"Oh! I've liked you all along!\"\n";
    std::cout << "(///▽///) \"Will you be mine?\"\n";
    std::cout << "(✿◕‿◕) \"Forever and always!\"\n";
} 
else if(genre == "action"){
     std::cout << "(ง'̀-'́)ง \"This ends now!\"\n";
    std::cout << "(*≧ω≦)ﾉ \"Not if I end you first!\"\n";
    std::cout << "(╯°□°）╯︵ ┻━┻ \"Prepare for battle!\"\n";
    std::cout << "ヽ( `д´*)ノ \"Take this!\" 💥\n";
} 
else if (genre == "comedy"){
    std::cout << "(¬‿¬) \"Why did the kaomoji cross the road?\"\n";
    std::cout << "(o_O)? \"Why?\"\n";
    std::cout << "(¬‿¬) \"To get to the other side~ (＾▽＾)\"\n";
    std::cout << "(ಠ_ಠ) \"...\"\n";
    std::cout << "(≧▽≦) \"It’s funny, right? Right?!\"\n";
} 
else {
    std::cout << "(o_O) \"Oops! Invalid genre. The kaomojis are confused!\"\n";
}
}

void audienceReaction(){
    std::vector<std::string> reactions = {
 "(＾◡＾)っ✂✨ \"Bravo! Wonderful!\"",
"(¬､¬) \"Boo! Do better!\"",
"(✿◕‿◕) \"Amazing performance!\"",
"(ಠ_ಠ) \"Meh, I've seen better.\"",
"(≧◡≦) \"Encore! Encore!\""
};

for(int i = 0; i < 3; ++i){
    int randomIndex = std::rand() % reactions.size();
    std::cout << reactions[randomIndex] << "\n";
}
}
