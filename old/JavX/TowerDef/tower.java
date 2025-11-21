import javax.swing.*;
import java.util.*;

public class tower {
    static Scanner sc = new Scanner(System.in);
    static Random rand = new Random();

    static int money = 100;
    static int cityHealth = 50;
    static int wave = 1;

    static Map<String, Integer> buildings = new LinkedHashMap<>();
    static Map<String, Integer> buildingCosts = Map.of(
        "Tower", 30,
        "Wall", 20,
        "Farm", 25
    );
    static Map<String, Integer> buildingDefense = Map.of(
        "Tower", 15,
        "Wall", 10,
        "Farm", 0
    );
    static Map<String, Integer> buildingIncome = Map.of(
        "Tower", 0,
        "Wall", 0,
        "Farm", 15
    );

    public static void main(String[] args) {
        buildings.put("Tower", 0);
        buildings.put("Wall", 0);
        buildings.put("Farm", 0);
        JOptionPane.showMessageDialog(null, "Welcome to City Defense! (｡•̀ᴗ-)✧\nBuild and defend your city!");

        while(cityHealth > 0){
            drawCity();
            cityIncome();
            playerBuild();
            enemyAttack();
            wave++;
        }
        JOptionPane.showMessageDialog(null, "You city has fallen... (╥﹏╥) Game Over.");
        System.exit(0);
    }
    static void drawCity(){
                System.out.println("\nWave: " + wave + "  Money: $" + money + "  City Health: " + cityHealth + " ♥");
                System.out.println("Buildings:");
                buildings.forEach((b, q) -> {
                    String kaomoji = switch (b) {
                        case "Tower" -> "( •_•)>⌐■-■";
                        case "Wall" -> "(╯°□°）╯︵ ┻━┻";
                        case "Farm" -> "(ᵔᴥᵔ)";
                        default -> "";
                    };
                    System.out.println(" - " + b + ": " + q + " " + kaomoji);
                });
                
                System.out.println("\nCity ASCII:");
                for (int i = 0; i < buildings.get("Wall"); i++) System.out.print("🧱");
                System.out.println();

                for (int i = 0; i < buildings.get("Tower"); i++) System.out.print("🏰");
                System.out.println();

                for (int i = 0; i < buildings.get("Farm"); i++) System.out.print("🌾");
                System.out.println();
            }
                static void cityIncome() {
                    int income = buildings.get("Farm") * buildingIncome.get("Farm");
                    money += income;
                    if (income > 0){
                        JOptionPane.showMessageDialog(null, "Farms produced $" + income + " this wave! (＾▽＾)");

                    }
                }
                static void playerBuild() {
                    String[] options = {"Build Tower ($30)", "Build Wall ($20)", "Build Farm ($25)", "Skip Building"};
                    int choice = JOptionPane.showOptionDialog(null, 
                    "Choose what to build:",
                    "Build Menu",
                    JOptionPane.DEFAULT_OPTION,
                    JOptionPane.PLAIN_MESSAGE,
                    null,
                    options,
                    options[0]);

                if (choice < 3) {
                    String building = switch (choice) {
                        case 0 -> "Tower";
                        case 1 -> "Wall";
                        case 2 -> "Farm";
                        default -> "";                    
                };

                if (money >= buildingCosts.get(building)) {
                    money -= buildingCosts.get(building);
                    buildings.put(building, buildings.get(building) + 1);
                    JOptionPane.showMessageDialog(null, building + " built ＼(＾▽＾)／");
                } else {
                    JOptionPane.showMessageDialog(null, "Not enough money! (╯︵╰,)");
                }

        } else {
                    JOptionPane.showMessageDialog(null, "Skipping building phase (¬‿¬)");

        }
    }

    static void enemyAttack() {
        int enemyAttack = wave * 10 + rand.nextInt(11);
        int defend = 0;
        for (var b : buildings.keySet()) {
            defend += buildings.get(b) * buildingDefense.get(b);

        }
        JOptionPane.showMessageDialog(null,
            "Enemies attack with power " + enemyAttack + " (ง'̀-'́)ง\nYour defense is " + defend);

        int damage = enemyAttack - defend;
        if (damage > 0){
            cityHealth -= damage;
            JOptionPane.showMessageDialog(null, "Your city took " + damage + " damage! (ಥ﹏ಥ)");
        } else {
            JOptionPane.showMessageDialog(null, "You defended the city perfectly!  (≧◡≦)");

        }
    }

}