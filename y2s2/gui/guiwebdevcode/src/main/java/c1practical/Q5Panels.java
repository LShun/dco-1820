package c1practical;

import javax.swing.*;
import java.awt.*;

public class Q5Panels extends JFrame {
    private JPanel p1 = new JPanel();
    private JPanel p2 = new JPanel();
    private JButton btnRed = new JButton("Red");
    private JButton btnGreen = new JButton("Green");

    private Q5Panels() {
        p1.setLayout(new FlowLayout());
        p2.setLayout(new FlowLayout());
        p1.add(btnRed);
        p1.add(btnGreen);
        p2.add(new JButton("Hello"));
        p2.add(new JButton("Flicking"));
        add(p1);
        add(p2);
    }

    public static void main(String[] args) {
        Q5Panels p = new Q5Panels();
        p.setLayout(new FlowLayout());
        p.setTitle("Panels");
        p.setLocationRelativeTo(null);
        p.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        p.pack();
        p.setVisible(true);
    }
}
