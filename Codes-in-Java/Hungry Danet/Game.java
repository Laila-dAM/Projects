import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Random;

public class Game extends JPanel implements ActionListener {
    private final int WIDTH = 800;
    private final int HEIGHT = 600;
    private final int CHARACTER_SIZE = 40;
    private final int TIMER_DELAY = 50;

    private int characterX;
    private int characterY;
    private int score;
    private boolean gameOver;

    private ArrayList<Element> elements;
    private Random random = new Random();

    private Timer timer;
    public Game() {
setPreferredSize(new Dimension(WIDTH, HEIGHT));
setBackground(Color.BLACK);
setFocusable(true);

        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e){
    if (!gameOver) {
        int key = e.getKeyCode();

    if(key == KeyEvent.VK_UP && characterY > 0){
        characterY -= 20;
        } 
        else if (key == KeyEvent.VK_DOWN && characterY < HEIGHT - CHARACTER_SIZE) {
            characterY += 20;
        }
        else if (key == KeyEvent.VK_LEFT && characterX > 0){
        characterX -= 20;
        }
        else if (key == KeyEvent.VK_RIGHT && characterX < WIDTH - CHARACTER_SIZE) {
        characterX += 20;
        }
    }
    else {
        if (e.getKeyCode() == KeyEvent.VK_R){
            restartGame();
        }
    }
 }
});
    initializeGame();
    }

    private void initializeGame(){
        characterX = WIDTH / 2;
        characterY = HEIGHT / 2;
        score = 0;
        gameOver = false;
        elements = new ArrayList<>();
        timer = new Timer(TIMER_DELAY, this);
        timer.start();
        spawnElements();
    }
    
    private void restartGame() {
        initializeGame();
        repaint();
    }

    private void spawnElements(){
        for(int i = 0; i < 10; i++){
            elements.add(new Element(random.nextInt(WIDTH - 50), random.nextInt(HEIGHT - 50), "🍓", 10));
            elements.add(new Element(random.nextInt(WIDTH - 50), random.nextInt(HEIGHT - 50), "🍦", 15));
            elements.add(new Element(random.nextInt(WIDTH - 50), random.nextInt(HEIGHT - 50), "🍰", 20));
            elements.add(new Element(random.nextInt(WIDTH - 50), random.nextInt(HEIGHT - 50), "🧊", -10));
            elements.add(new Element(random.nextInt(WIDTH - 50), random.nextInt(HEIGHT - 50), "🥦", -15));
            elements.add(new Element(random.nextInt(WIDTH - 50), random.nextInt(HEIGHT - 50), "🌶️", -20));

        }
    }
    @Override
    protected void paintComponent(Graphics g){
        super.paintComponent(g);

        if(gameOver) {
            g.setFont(new Font("Monospaced", Font.BOLD, 36));
        if(score >= 100){
            g.setColor(Color.GREEN);
            g.drawString("ദ്ദി ( ᵔ ᗜ ᵔ )", WIDTH / 2 - 150, HEIGHT / 2);
        } else {
            g.setColor(Color.RED);
            g.drawString("(ㅠ﹏ㅠ)", WIDTH / 2 - 100, HEIGHT / 2);
        }
            g.setFont(new Font("Monospaced", Font.PLAIN, 20));
            g.drawString("Final Score:" + score, WIDTH / 2 - 100, HEIGHT / 2 + 50);
            g.drawString("Press 'R' to Try Again", WIDTH / 2 - 150, HEIGHT / 2 + 100);
    return;
        }
        g.setColor(Color.PINK);
        g.setFont(new Font("Monospaced", Font.BOLD, 30));
        g.drawString("ε(´｡•᎑•`)っ", characterX, characterY);

        g.setFont(new Font("Monospaced", Font.BOLD, 20));
        for (Element element : elements){
            if (element.value > 0){
                g.setColor(Color.ORANGE);
            } else {
                g.setColor(Color.BLUE);
            }
        g.drawString(element.symbol, element.x, element.y);
        }
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 18));
        g.drawString("Score:" + score, 10, 20);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        elements.removeIf(element -> {
            Rectangle elementBounds = new Rectangle(element.x, element.y, CHARACTER_SIZE, CHARACTER_SIZE);
            Rectangle characterBounds = new Rectangle(characterX, characterY, CHARACTER_SIZE, CHARACTER_SIZE);

            if(elementBounds.intersects(characterBounds)){
        score += element.value;
        if (score < 0){
            gameOver = true;
            timer.stop();
        }
        return true;
            }
        return false;
        });
if (score >= 100){
    gameOver = true;
    timer.stop();
}
        repaint();
    }
    public static void main(String[] args){
        JFrame frame = new JFrame("Underwater Natigation Game");
        Game game = new Game();

        frame.add(game);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    private static class Element {
        int x, y, value;
        String symbol;

        Element(int x, int y, String symbol, int value){
            this.x = x;
            this.y = y;
            this.symbol = symbol;
            this.value = value;
        }
    }  
}