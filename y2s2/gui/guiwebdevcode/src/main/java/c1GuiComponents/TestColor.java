package c1GuiComponents;

import javax.swing.*;
import java.awt.*;

public class TestColor extends JFrame {
    private JButton jbtEast = new JButton("East");
    private JButton jbtWest = new JButton("West");
    private JButton jbtNorth = new JButton("North");
    private JButton jbtSouth = new JButton("South");
    private JButton jbtCenter = new JButton("Center");

    public TestColor() {
        jbtEast.setBackground(Color.MAGENTA);
        jbtEast.setForeground(Color.WHITE);
        jbtWest.setBackground(new Color(255, 255, 255));
        jbtWest.setForeground(new Color(0, 0, 0));
        jbtCenter.setBackground(Color.YELLOW);
        jbtCenter.setForeground(new Color(100, 50, 200));

        add(jbtEast, BorderLayout.EAST);
        add(jbtWest, BorderLayout.WEST);
        add(jbtNorth, BorderLayout.NORTH);
        add(jbtSouth, BorderLayout.SOUTH);
        add(jbtCenter, BorderLayout.CENTER);

        setTitle("TestColor");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new TestColor();
    }
}
