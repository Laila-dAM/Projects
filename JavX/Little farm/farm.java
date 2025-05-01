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

    }
}
}