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
            if (result == JFileChooser.APROVE_OPTION){
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
        
    }
}
