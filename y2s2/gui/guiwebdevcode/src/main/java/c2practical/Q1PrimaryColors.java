package c2practical;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q1PrimaryColors extends JFrame {
    private JButton redB = new JButton("Red");
    private JButton greenB = new JButton("Green");
    private JButton blueB = new JButton("Blue");
    private JLabel colorL = new JLabel("COLOR");
    private JPanel buttons = new JPanel(new FlowLayout());

    Q1PrimaryColors() {
        colorL.setHorizontalAlignment(JLabel.CENTER);
        add(colorL, BorderLayout.NORTH);
        buttons.add(redB);
        buttons.add(greenB);
        buttons.add(blueB);
        add(buttons, BorderLayout.CENTER);

        // add listeners
        redB.addActionListener(new toRed());

        greenB.addActionListener(new toGreen());

        blueB.addActionListener(new toBlue());
    }

    public static void main(String[] args) {
        Q1PrimaryColors pc = new Q1PrimaryColors();
        pc.setTitle("Primary Colors");
        pc.pack();
        pc.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pc.setVisible(true);
    }

    private class toRed implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            colorL.setForeground(Color.RED);
        }
    }

    private class toGreen implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            colorL.setForeground(Color.GREEN);
        }
    }

    private class toBlue implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            colorL.setForeground(Color.BLUE);
        }
    }
}
