package c1GuiComponents;

import javax.swing.*;
import java.awt.*;
import java.io.File;

public class TestImageIcon extends JFrame {

    public TestImageIcon() {
        setLayout(new GridLayout(1, 4, 4, 5));
        ImageIcon usIcon = new ImageIcon(getClass().getResource("images/us.png"));
        ImageIcon myIcon = new ImageIcon(getClass().getResource("images/my.png"));
        add(new JLabel(usIcon));
        add(new JLabel(myIcon));

        setTitle("TestImageIcon");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400 ,100);
        setVisible(true);
    }

    public static void main(String[] args) {
        TestImageIcon tii = new TestImageIcon();
    }
}
