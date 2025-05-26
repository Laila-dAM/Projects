import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PongGame extends JPanel implements KeyListener, ActionListener {

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

    }