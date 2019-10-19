package c1practical;

import javax.swing.*;
import java.awt.*;

public class Q2Frame extends JFrame {
    JButton helloBtn = new JButton("Hello");

    Q2Frame() {
        add(helloBtn, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        Q2Frame f = new Q2Frame();
        f.setTitle("One Frame");
        f.setSize(500, 600);
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
