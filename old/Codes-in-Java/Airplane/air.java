import java.util.Random;
import java.util.Scanner;

public class air {
    static int alt = 1000;
    static int spd = 300;
    static int wnd = 0;
    static int turb = 0;

public static void adjAlt(int adj){
    alt += adj;
    if (alt < 0) alt = 0;
    else if (alt > 10000) alt = 10000;
}
public static void adjSpd(int adj){
    spd += adj;
    if (spd < 100) spd = 100;
    else if (spd > 600) spd = 600;
}   
public static void simWthr(){
    Random rand = new Random();
    wnd = rand.nextInt(21) - 10;
    turb = rand.nextInt(3);
}

public static void showStart() {
    System.out.println("Altitude: " + alt + " feet");
    System.out.println("Speed: " + spd + " knots");
    System.out.println("Wind Speed: " + wnd + " knots");

    if (turb == 0) System.out.println("Turbulence: None");
    else if (turb == 1) System.out.println("Turbulence: Light");
    else System.out.println("Turbulence: Heavy");
}
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();

        int opt, adj;

        while(true){
            simWthr();
            showStart();

            System.out.println("\nChoose:");
System.out.println("1. +Altitude");
System.out.println("2. -Altitude");
System.out.println("3. +Speed");
System.out.println("4. -Speed");
System.out.println("5. Exit");
    opt = scanner.nextInt();

    if(opt == 1){
        System.out.print("Increase altitude (feet):");
        adj = scanner.nextInt();
        adjAlt(adj);
    }
else if (opt == 2){
    System.out.print("Decrease altitude (feet): ");
    adj = scanner.nextInt();
    adjAlt(-adj);

} else if (opt == 3){
    System.out.print("Increase speed (knots): ");
    adj = scanner.nextInt();
    adjSpd(adj);

} else if (opt == 4){
    System.out.print("Decrease speed (knots): ");
    adj = scanner.nextInt();
    adjSpd(-adj);

} else if (opt == 5){
    System.out.println("Exiting.");
    break;
} 
    if (alt <= 0){
        System.out.println("\nCrashed! Game Over.");
        break;
    }
if (alt == 10000) System.out.println("\nMax altitude reached!");
if(spd < 100) System.out.println("\nSpeed too low! Increase to avoid stall.");
if (spd > 600) System.out.println("\nSpeed too high! Reduce to avoid danger.");

    System.out.println();
            
        }
        scanner.close();
    }
}