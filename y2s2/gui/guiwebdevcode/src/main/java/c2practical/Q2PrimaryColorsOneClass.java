package c2practical;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q2PrimaryColorsOneClass extends JFrame {
    private JButton redB = new JButton("Red");
    private JButton greenB = new JButton("Green");
    private JButton blueB = new JButton("Blue");
    private JLabel colorL = new JLabel("COLOR");
    private JPanel buttons = new JPanel(new FlowLayout());

    Q2PrimaryColorsOneClass() {
        ChangeColor colorChanger = new ChangeColor();
        colorL.setHorizontalAlignment(JLabel.CENTER);
        add(colorL, BorderLayout.NORTH);
        buttons.add(redB);
        buttons.add(greenB);
        buttons.add(blueB);
        add(buttons, BorderLayout.CENTER);

        // add listeners
        redB.addActionListener(colorChanger);

        greenB.addActionListener(colorChanger);

        blueB.addActionListener(colorChanger);
    }

    public static void main(String[] args) {
        Q2PrimaryColorsOneClass pc = new Q2PrimaryColorsOneClass();
        pc.setTitle("Primary Colors");
        pc.pack();
        pc.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pc.setVisible(true);
    }

    private class ChangeColor implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == redB) {
                colorL.setForeground(Color.RED);
            }
            else if (e.getSource() == blueB) {
                colorL.setForeground(Color.BLUE);
            }
            else if (e.getSource() == greenB) {
                colorL.setForeground(Color.GREEN);
            }
        }
    }
}




