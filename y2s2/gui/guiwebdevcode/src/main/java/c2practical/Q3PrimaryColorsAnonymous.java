package c2practical;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q3PrimaryColorsAnonymous extends JFrame {
    private JButton redB = new JButton("Red");
    private JButton greenB = new JButton("Green");
    private JButton blueB = new JButton("Blue");
    private JLabel colorL = new JLabel("COLOR");
    private JPanel buttons = new JPanel(new FlowLayout());

    Q3PrimaryColorsAnonymous() {
        colorL.setHorizontalAlignment(JLabel.CENTER);
        add(colorL, BorderLayout.NORTH);
        buttons.add(redB);
        buttons.add(greenB);
        buttons.add(blueB);
        add(buttons, BorderLayout.CENTER);

        // add listeners
        redB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                colorL.setForeground(Color.RED);
            }
        });

        greenB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                colorL.setForeground(Color.GREEN);
            }
        });

        blueB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                colorL.setForeground(Color.BLUE);
            }
        });
    }

    public static void main(String[] args) {
        Q3PrimaryColorsAnonymous pc = new Q3PrimaryColorsAnonymous();
        pc.setTitle("Primary Colors");
        pc.pack();
        pc.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pc.setVisible(true);
    }
}
