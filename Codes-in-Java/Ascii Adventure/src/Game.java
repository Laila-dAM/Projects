public class Game {
    private Story story;
    private Character player;

public Game(){
    story = new Story();
    player = new Character("Hero", 100);
}
public void start(){
    story.printIntroduction();
}

public void handleChoice(int choice){
    story.handleChoice(choice);
}
}