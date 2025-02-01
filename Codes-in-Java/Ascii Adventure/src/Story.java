import java.util.Scanner;
public class Story {
    private Scanner scanner;
    private Character player;

public Story(){
    scanner = new Scanner(System.in);
    player = new Character("Hero", 100);
}
public void printIntroduction(){
    System.out.println("Welcome to the Adventure Game!");
    System.out.println("You find yourself in front of a dragon (≧∇≦)/");
    System.out.println("What do you want to do?");
    System.out.println("1. Attack (╯°□°）╯︵ ┻━┻");
    System.out.println("2. Flee (ಥ﹏ಥ)");
    System.out.println("3. Talk (｡♥‿♥｡)");

    int choice = scanner.nextInt();
    handleChoice(choice);
}
public void handleChoice(int choice){
    switch (choice){
case 1:
Action attack = new Action("Attack", Kaomoji.getKaomoji("Attack"));
Dialog.printDialog(attack.getKaomojis());
break;

case 2:
Action flee = new Action("Flee", Kaomoji.getKaomoji("Flee"));
Dialog.printDialog(flee.getKaomojis());
break;

case 3:
Action talk = new Action("Talk", Kaomoji.getKaomoji("Talk"));
Dialog.printDialog(talk.getKaomojis());
break;

default:
System.out.println("Invalid choice. Please try again.");
break;

}
}
}