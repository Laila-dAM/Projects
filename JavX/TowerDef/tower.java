import javax.swing.*;
import java.util.*;

public class tower {
    static Scanner sc = new Scanner(System.in);
    static Random rand = new Random();

    static int money = 100;
    static int cityHealth = 50;
    static int wave = 1;

    static Map<String, Integer> building = new LinkedHashMap<>();
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
    }
}