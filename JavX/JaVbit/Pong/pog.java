import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class pog extends JPanel implements KeyListener, ActionListener {

    private final int WIDTH = 800;
    private final int HEIGHT = 600;

    private final int PADDLE_WIDTH = 10;
    private final int PADDLE_HEIGHT = 100;
    private final int BALL_SIZE = 20;
    private int paddle1Y = HEIGHT / 2 - PADDLE_HEIGHT / 2;
    private int paddle2Y = HEIGHT / 2 - PADDLE_HEIGHT / 2;

    private int ballX = WIDTH / 2 - BALL_SIZE / 2;
    private int ballY = HEIGHT / 2 - BALL_SIZE / 2;

    private int ballSpeedX = 3;
    private int ballSpeedY = 3;

    private int paddleSpeed = 10;

    private int score1 = 0;
    private int score2 = 0;

    private Timer timer;

    private boolean wPressed = false;
    private boolean sPressed = false;
    private boolena upPressed = false;
    private boolean downPressed = false;

    public PongGame(){
        this.setPreferredSize(new Dimension(WIDTH, HEIGHT));
        this.setBackground(Color.BLACK);
        this.setFocusable(true);
        this.addKeyListener(this);

        timer = new Timer(10, this);
        timer.start();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        g.setColor(Color.WHITE);
        for(int i = 0; i < HEIGHT; i += 15){
            g.fillRect(WIDTH / 2 - 2, i, 4, 10);
        }
        g.fillRect(50, paddle1Y, PADDLE_WIDTH, PADDLE_HEIGHT);
        g.fillRect(WIDTH - 50 - PADDLE_WIDTH, paddle2Y, PADDLE_WIDTH, PADDLE_HEIGHT);

        g.fillOval(ballX, ballY, BALL_SIZE, BALL_SIZE);

        g.setFont(new Font("Consolas", Font.BOLD, 36));
        g.drawString(String.valueOf(score1), WIDTH / 4,50);
        g.drawString(String.valueOf(score2), WIDTH * 3 / 4,50);
        
    }

    private void moveBall(){
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        if (ballY <= 0 || ballY >= HEIGHT - BALL_SIZE){
            ballSpeedY = -ballSpeedY;
        }

        if (ballX <= 50 + PADDLE_WIDTH && ballY + BALL_SIZE >= paddle1Y && ballY <= paddle1Y + PADDLE_HEIGHT){
            ballSpeedX = -ballSpeedX;
            ballX = 50 + PADDLE_WIDTH;
        }

        if (ballX + BALL_SIZE >= WIDTH - 50 - PADDLE_WIDTH && ballY + BALL_SIZE >= paddle2Y &&
                ballY <= paddle2Y + PADDLE_HEIGHT) {
            
                }
    }