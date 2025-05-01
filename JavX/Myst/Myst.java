import java.util.Scanner;
import javax.swing.JOptionPane;

public class Myst{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String playerName;
        int currentRoom = 0;
        boolean gameRunning = true;

        System.out.print("Enter your detective name: ");
        playerName = scanner.nextLine();

        JOptionPane.showMessageDialog(null, "Welcome, Detective " + playerName + "!\n" +
                "Your investigation begins now. Explore the rooms and solve the mystery!");

        while (gameRunning) {
            if (currentRoom == 0) {
                System.out.println("You are standing at the entrance of a dark mansion...");
                System.out.println("ASCII Art: ");
                System.out.println("      _______\n     /       \\\n    |  MANSION |\n     \\_______/ ");
                System.out.println("Kaomoji: (｡•́︿•̀｡)");

                System.out.println("\nWhere do you want to go?");
                System.out.println("1. Enter the hallway");
                System.out.println("2. Check the garden");
                System.out.println("3. Exit the game");
                System.out.print("Choice: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                switch (choice) {
                    case 1:
                        currentRoom = 1;
                        break;
                    case 2:
                        currentRoom = 2;
                        break;
                    case 3:
                        gameRunning = false;
                        JOptionPane.showMessageDialog(null, "Goodbye, Detective! ( ˘︹˘ )");
                        break;
                    default:
                        System.out.println("Invalid choice, try again.");
                }
            } else if (currentRoom == 1) {
                System.out.println("You entered the hallway, the air is cold and damp...");
                System.out.println("ASCII Art: ");
                System.out.println("    ____\n   /    \\\n  | HALL |\n   \\____/");
                System.out.println("Kaomoji: ( •_•)");

                System.out.println("\nWhat will you do?");
                System.out.println("1. Investigate the painting");
                System.out.println("2. Go back to the entrance");
                System.out.println("3. Check the door on the left");
                System.out.print("Choice: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                switch (choice) {
                    case 1:
                        JOptionPane.showMessageDialog(null, "You find a hidden message behind the painting!");
                        break;
                    case 2:
                        currentRoom = 0;
                        break;
                    case 3:
                        JOptionPane.showMessageDialog(null, "A secret door opens... You have discovered a hidden room!");
                        currentRoom = 3;
                        break;
                    default:
                        System.out.println("Invalid choice, try again.");
                }
            } else if (currentRoom == 2) {
                System.out.println("You are in the garden, the flowers look strangely alive...");
                System.out.println("ASCII Art: ");
                System.out.println("    _/\\_/\\_/\\_\\n   |  GARDEN |\\n    \\/\\/ \\/\\/");
                System.out.println("Kaomoji: (｡•́︿•̀｡)");

                System.out.println("\nWhat will you do?");
                System.out.println("1. Examine the flower");
                System.out.println("2. Go back to the entrance");
                System.out.println("3. Look for hidden objects");
                System.out.print("Choice: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                switch (choice) {
                    case 1:
                        JOptionPane.showMessageDialog(null, "A key is hidden inside the flower!");
                        break;
                    case 2:
                        currentRoom = 0;
                        break;
                    case 3:
                        JOptionPane.showMessageDialog(null, "You found a suspicious-looking journal!");
                        break;
                    default:
                        System.out.println("Invalid choice, try again.");
                }
            } else if (currentRoom == 3) {
                System.out.println("You entered a hidden chamber, filled with strange symbols...");
                System.out.println("ASCII Art: ");
                System.out.println("    _____\n   /     \\\n  | SECRET |\n   \\_____/ ");
                System.out.println("Kaomoji: (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧");

                System.out.println("\nWhat will you do?");
                System.out.println("1. Examine the symbols on the wall");
                System.out.println("2. Leave the hidden chamber");
                System.out.println("3. Use the key from the garden");
                System.out.print("Choice: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                switch (choice) {
                    case 1:
                        JOptionPane.showMessageDialog(null, "The symbols seem to lead you to a final clue!");
                        break;
                    case 2:
                        currentRoom = 0;
                        break;
                    case 3:
                        JOptionPane.showMessageDialog(null, "The key fits... a hidden compartment opens revealing the truth!");
                        JOptionPane.showMessageDialog(null, "Congratulations! You've solved the mystery! (｡♥‿♥｡)");
                        gameRunning = false;
                        break;
                    default:
                        System.out.println("Invalid choice, try again.");
                }
            }
        }
        scanner.close();
    }
}
