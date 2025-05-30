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
}