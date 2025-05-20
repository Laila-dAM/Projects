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
}