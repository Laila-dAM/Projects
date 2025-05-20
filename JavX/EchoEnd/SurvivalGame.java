import javax.swing.*;
import java.util.Scanner;

public class SurvivalGame {
    static int health = 10;
    static int food = 5;
    static int wood = 3;
    static int shelter = 0;
    static boolean npcRescued = false;

    public static void main(String[] args) {
        showPopup("☢️ Welcome to the Wasteland ☠️\nCan you survive? (⌐■_■)");
        Scanner scanner = new Scanner(System.in);
        boolean playing = true;

        while (playing && health > 0){
            printStatus();
            System.out.println("Choose an action:");
            System.out.println("1. Search for food 🍄");
            System.out.println("2. Gather wood 🌲");
            System.out.println("3. Build shelter 🛖");
            System.out.println("4. Explore ruins 🏚️");
            System.out.println("5. Rest 😴");
            System.out.println("6. Exit ❌");
            System.out.println("->");

        String input = scanner.nextLine();
        switch (input){
                            case "1":
                    searchFood();
                    break;
                case "2":
                    gatherWood();
                    break;
                case "3":
                    buildShelter();
                    break;
                case "4":
                    exploreRuins();
                    break;
                case "5":
                    rest();
                    break;
                case "6":
                    playing = false;
                    showPopup("Game Over. Thanks for playing! (｡•́︿•̀｡)");
                    break;
                default:
                    showPopup("Invalid option (⊙_☉)");
            }

            health--;
        }

        if (health <= 0) {
            showPopup("You didn't survive... (×_×;)");
        }

        scanner.close();
    }

    static void showPopup(String message) {
        JOptionPane.showMessageDialog(null, message, "Wasteland Survival", JOptionPane.INFORMATION_MESSAGE);
    }

    static void printStatus() {
        System.out.println("\n╔════════════════════╗");
        System.out.println("║  ☢️ Wasteland Status ☢️  ║");
        System.out.println("╚════════════════════╝");
        System.out.println("❤️ Health: " + health);
        System.out.println("🍞 Food: " + food);
        System.out.println("🪵 Wood: " + wood);
        System.out.println("🏠 Shelter: " + (shelter > 0 ? "Built" : "None"));
        System.out.println("🧍‍♂️ NPC Rescued: " + (npcRescued ? "Yes" : "No"));
        System.out.println();
    }

    static void searchFood() {
        int found = (int)(Math.random() * 3);
        food += found;
        System.out.println("You found " + found + " food 🍄");
    }

    static void gatherWood() {
        int collected = (int)(Math.random() * 3) + 1;
        wood += collected;
        System.out.println("You gathered " + collected + " wood 🌲");
    }

    static void buildShelter() {
        if (wood >= 5) {
            wood -= 5;
            shelter = 1;
            System.out.println("You built a shelter 🛖 (＾▽＾)");
        } else {
            System.out.println("Not enough wood! (╯︵╰,)");
        }
    }

    static void exploreRuins() {
        int event = (int)(Math.random() * 4);
        if (event == 0) {
            System.out.println("You got hurt in the ruins! (-2 health) (╥﹏╥)");
            health -= 2;
        } else if (event == 1) {
            System.out.println("You found supplies! (+2 food, +2 wood)");
            food += 2;
            wood += 2;
        } else if (event == 2) {
            System.out.println("You encountered a survivor... and saved them! (´｡• ᵕ •｡`) ♡");
            npcRescued = true;
        } else {
            System.out.println("Nothing found... just silence. (￣︿￣)");
        }
    }

    static void rest() {
        if (shelter > 0) {
            health += 2;
            food -= 1;
            System.out.println("You rested in your shelter. (+2 health, -1 food) (๑˃ᴗ˂)ﻭ");
        } else {
            health += 1;
            food -= 2;
            System.out.println("You rested without shelter. (+1 health, -2 food) (＞﹏＜)");
        }

        if (food < 0) {
            System.out.println("You're starving! (-3 health)");
            health -= 3;
            food = 0;
        }
    }
}