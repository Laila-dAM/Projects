import java.util.*;

public class GameUtils {
    private Player player;
    private List<Ghost> ghosts;
    private Fruit fruit;

    public GameUtils() {
        player = new Player();
        ghosts = new ArrayList<>();
        ghosts.add(new Ghost("Pink"));
        ghosts.add(new Ghost("Blue"));
        ghosts.add(new Ghost("Green"));
        ghosts.add(new Ghost("Purple"));
        fruit = new Fruit();
    }

    public void startGame() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to Pac-Man! Press 's' to start.");
        while (scanner.nextLine().equals("s")) {
            playTurn();
        }
    }

    private void playTurn() {
        System.out.println("Player: " + player.getState());
        System.out.println("Ghosts: ");
        for (Ghost ghost : ghosts) {
            System.out.println(ghost.getState());
        }
        System.out.println("Fruit: " + fruit.getState());
        System.out.println("Press 'e' to eat fruit or 'd' to die.");
        Scanner scanner = new Scanner(System.in);
        String action = scanner.nextLine();

        if (action.equals("e")) {
            player.eatFruit();
            for (Ghost ghost : ghosts) {
                ghost.escape();
            }
            System.out.println("Player: " + player.getState());
            System.out.println("Ghosts after escape: ");
            for (Ghost ghost : ghosts) {
                System.out.println(ghost.getState());
            }
        } else if (action.equals("d")) {
            player.die();
            System.out.println("Player: " + player.getState());
        }
    }
}
