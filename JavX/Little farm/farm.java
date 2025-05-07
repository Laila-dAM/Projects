import javax.swing. *;
import java.util.Scanner;

public class farm {
    static int crops = 0;
    static int animals = 2;
    static int food = 5;
    static int money = 10;

public static void main(String[] args) {
    showPopup("🌾 Welcome to Retro Farm Simulator 🐮\n(=^･ω･^=) Let's farm!");

    Scanner scanner = new Scanner(System.in);
    boolean running = true;

    while(running) {
        printFarm();
        System.out.println("Choose an action:");
        System.out.println("1. Plant crops 🌱");
        System.out.println("2. Feed animals 🍎");
        System.out.println("3. Sell crops 💰");
        System.out.println("4. Buy food 🛒");
        System.out.println("5. Exit ❌");
        System.out.print("-> ");
String input = scanner.nextLine();

            switch (input) {
                case "1":
                    plantCrops();
                    break;
                case "2":
                    feedAnimals();
                    break;
                case "3":
                    sellCrops();
                    break;
                case "4":
                    buyFood();
                    break;
                case "5":
                    running = false;
                    showPopup("Thanks for playing! (✿◕‿◕)ﾉﾞ");
                    break;
                default:
                    showPopup("Invalid option (⊙_☉)");
            }
        }

        scanner.close();
    }

    static void showPopup(String message) {
        JOptionPane.showMessageDialog(null, message, "Retro Farm", JOptionPane.INFORMATION_MESSAGE);
    }

    static void printFarm() {
        System.out.println("\n╔══════════════════╗");
        System.out.println("║     🐔 Retro Farm 🐮    ║");
        System.out.println("╚══════════════════╝");
        System.out.println("🌾 Crops: " + crops);
        System.out.println("🐑 Animals: " + animals);
        System.out.println("🍖 Food: " + food);
        System.out.println("💰 Money: $" + money);
        System.out.println();
    }

    static void plantCrops() {
        crops += 2;
        System.out.println("You planted crops 🌱 (+2)");
    }

    static void feedAnimals() {
        if (food >= animals) {
            food -= animals;
            System.out.println("You fed all the animals 🐷🐮🐔 (´• ω •`) ♡");
        } else {
            System.out.println("Not enough food! (╥﹏╥)");
        }
    }

    static void sellCrops() {
        if (crops >= 3) {
            crops -= 3;
            money += 5;
            System.out.println("You sold crops for $5 💸");
        } else {
            System.out.println("Not enough crops to sell! (｡•́︿•̀｡)");
        }
    }

    static void buyFood() {
        if (money >= 4) {
            food += 3;
            money -= 4;
            System.out.println("You bought food 🍎 (+3)");
        } else {
            System.out.println("Not enough money! (๑•́ ₃ •̀๑)");


    }
}
}