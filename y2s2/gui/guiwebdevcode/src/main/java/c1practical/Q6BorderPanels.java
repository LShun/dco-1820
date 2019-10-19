package c1practical;

import javax.swing.*;
import java.awt.*;

public class Q6BorderPanels extends JFrame {
    private JPanel p1 = new JPanel();
    private JPanel p2 = new JPanel();
    private JButton btnRed = new JButton("Red");
    private JButton btnGreen = new JButton("Green");

    private Q6BorderPanels() {
        setLayout(new BorderLayout());
        p1.setLayout(new GridLayout(1,2));
        p2.setLayout(new GridLayout(1,2));
        p1.add(btnRed);
        p1.add(btnGreen);
        p2.add(new JButton("Hello"));
        p2.add(new JButton("Flicking"));
        add(p1, BorderLayout.SOUTH);
        add(p2, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        Q6BorderPanels p = new Q6BorderPanels();
        p.setTitle("Panels");
        p.setLocationRelativeTo(null);
        p.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        p.pack();
        p.setVisible(true);
    }
}
