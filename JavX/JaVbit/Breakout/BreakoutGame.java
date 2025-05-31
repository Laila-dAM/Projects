import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BreakoutGame extends JPanel implements KeyListener, ActionListener {

    private boolean play = false;
    private int score = 0;

    private int totalBlocks = 21;
    private Timer timer;
    private int delay = 8;

    private int paddleX = 310;
    private final int paddleWidth = 100;
    private final int paddleHeight = 10;

    private int ballPosX = 120;
    private int ballPosY = 350;
    private int ballXDir = -1;
    private int ballYDir = -2;
    private final int ballSize = 16;

    private MapGenerator map;

    public BreakoutGame() {
        map = new MapGenerator(3, 7);
        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);
        timer = new Timer(delay, this);
        timer.start();
}
    public void paint(Graphics g){
        g.setColor(Color.black);
        g.fillRect(1, 1, 700, 600);

        map.draw((Graphics2D) g);

        g.setColor(Color.white);
        g.fillRect(0, 0, 3, 600);
        g.fillRect(0, 0, 700, 3);
        g.fillRect(697, 0, 3, 600);

        g.setColor(Color.white);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        g.drawString("Score: " + score, 550, 30);

        g.setColor(Color.green);
        g.fillRect(paddleX, 550, paddleWidth, paddleHeight);

        g.setColor(Color.yellow);
        g.fillOval(ballPosX, ballPosY, ballSize, ballSize);
        
    }