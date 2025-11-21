import javax.swing.*;
import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;

public class ImageToAsciiArt {
    public static void main(String[] args){
        SwingUtilities.invokeLater(() -> new ImageToAsciiArt().createAndShowGUI());
    }

    private void createAndShowGUI(){
        JFrame frame = new JFrame("Image to ASCII");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

    JButton selectImageButton = new JButton("Select Image");
        JTextArea asciiArea = new JTextArea();
        asciiArea.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
        asciiArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(asciiArea);

    JButton copyButton = new JButton("Copy ASCII");
        selectImageButton.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showOpenDialog(frame);
            if (result == JFileChooser.APPROVE_OPTION){
                try {
                    File selectedFile = fileChooser.getSelectedFile();
                    BufferedImage image = ImageIO.read(selectedFile);
                    String ascii = convertToAscii(image, 2);
                    asciiArea.setText(ascii);
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(frame, "Error loading image:" + ex.getMessage());
                }
            }
        });
    copyButton.addActionListener(e -> {
        StringSelection selection = new StringSelection(asciiArea.getText());
        Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
        clipboard.setContents(selection, selection);
        JOptionPane.showMessageDialog(frame, "ASCII copied to clipboard!");
    });
        JPanel panel = new JPanel();
        panel.add(selectImageButton);
        panel.add(copyButton);

        frame.getContentPane().add(panel, BorderLayout.NORTH);
frame.getContentPane().add(scrollPane, BorderLayout.CENTER);
        frame.setVisible(true);
    }
    private String convertToAscii(BufferedImage image, int scale){
        final String ASCII_CHARS = "@#S%?*+;:,. ";
        int scaleX = scale;
        int scaleY = scale * 2;

        int width = image.getWidth() / scaleX;
        int height = image.getHeight() / scaleY;

        BufferedImage resized = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = resized.createGraphics();
        g.drawImage(image, 0, 0, width, height, null);
        g.dispose();

        StringBuilder ascii = new StringBuilder();

        for(int y = 0; y < resized.getHeight(); y++){
            for(int x = 0; x < resized.getWidth(); x++){
                int pixel = resized.getRGB(x, y);
                int alpha = (pixel >> 24) & 0xFF;
                if (alpha < 128) {
                    ascii.append(" ");
                } else {
                    int red = (pixel >> 16) & 0xFF;
                    int green = (pixel >> 8) & 0xFF;
                    int blue = pixel & 0xFF;
                    int gray = (red + green + blue) / 3;
                    int index = gray * (ASCII_CHARS.length() - 1) / 255;
                    ascii.append(ASCII_CHARS.charAt(index));
                }
            }
        ascii.append("\n");
        }
        return ascii.toString();
    }
}
