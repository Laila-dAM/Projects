import java.util.ArrayList;
import java.util.Scanner;

class Plant {
    String name;
    String type;
    int idealGrowthTime; 
    public Plant(String name, String type, int idealGrowthTime) {
        this.name = name;
        this.type = type;
        this.idealGrowthTime = idealGrowthTime;
    }
 public String getInfo() {
        return name + " (" + type + ") - Ideal Growth Time: " + idealGrowthTime + " days";
    }
}

class Greenhouse {
    double temperature;
    double humidity;
    double lightIntensity;

    public Greenhouse(double temperature, double humidity, double lightIntensity) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.lightIntensity = lightIntensity;
    }
    
    public void adjustEnvironment(double temperature, double humidity, double lightIntensity) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.lightIntensity = lightIntensity;
    }
    
    public void checkEnvironment() {
        if (temperature < 18 || temperature > 30) {
            System.out.println("Warning: Temperature out of optimal range (18-30°C)!");
        }
        if (humidity < 40 || humidity > 80) {
            System.out.println("Warning: Humidity out of optimal range (40-80%)!");
        }
    }


    public int calculateGrowthTime(Plant plant) {
        int growthTime = plant.idealGrowthTime;

        if (temperature < 18 || temperature > 30) {
            growthTime += 2;
        }
        if (humidity < 40 || humidity > 80) {
            growthTime += 3;
        }
        return growthTime;
    }
}
public class SmartGreenhouseSimulator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Plant> plants = new ArrayList<>();
        Greenhouse greenhouse = new Greenhouse(25, 60, 80);

        System.out.println("Smart Greenhouse Plant Growth Simulator");
        
while(true) {
    System.out.println("Choose an option:");
    System.out.println("1. Add a new plant");
    System.out.println("2. Adjust greenhouse environment");
    System.out.println("3. View plant info and estimated growth time");
    System.out.println("4. Exit");

    int choice = scanner.nextInt();
    scanner.nextLine();

    if(choice == 1){
        System.out.println("Enter plant name:");
        String name = scanner.nextLine();
        System.out.println("Enter plant type:");
        String type = scanner.nextLine();
        System.out.println("Enter ideal growth time (in days):");
        int growthTime = scanner.nextInt();
        plants.add(new Plant(name, type, growthTime));
    }
    else if (choice == 2){
    System.out.println("Enter new temperature (°C):");
        double temp = scanner.nextDouble();
        System.out.println("Enter new humidity (%):");
        double hum = scanner.nextDouble();
        System.out.println("Enter new light intensity (%):");
        double light = scanner.nextDouble();
        greenhouse.adjustEnvironment(temp, hum, light);
        greenhouse.checkEnvironment();
    }
    else if (choice == 3){
        for (Plant plant : plants){
            System.out.println(plant.getInfo());
            int growthTime = greenhouse.calculateGrowthTime(plant);
            System.out.println("Estimated growth time: " + growthTime + "days");
            
        }
    }
    else if (choice == 4) {
        break;
    }
    else {
        System.out.println("Invalid choice. Try again.");
    }
}
        scanner.close();
        }
}


