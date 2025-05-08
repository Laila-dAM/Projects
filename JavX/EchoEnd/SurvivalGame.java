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

        String input = scannernextLine();
        switch (input){
                
        }
        }
    }
    
}