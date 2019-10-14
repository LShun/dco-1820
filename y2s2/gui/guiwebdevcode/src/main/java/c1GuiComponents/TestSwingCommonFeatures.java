package c1GuiComponents;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.awt.*;

public class TestSwingCommonFeatures extends JFrame {
    private JPanel p1 = new JPanel();
    private JButton jbtLeft = new JButton("Left");
    private JButton jbtCenter = new JButton("Center");
    private JButton jbtRight = new JButton("Right");

    public TestSwingCommonFeatures() {
        jbtLeft.setBackground(Color.WHITE);
        jbtCenter.setForeground(Color.GREEN);
        jbtRight.setToolTipText("This is the Right button");

        p1.add(jbtLeft);
        p1.add(jbtCenter);
        p1.add(jbtRight);
        p1.setBorder(new TitledBorder("Three Buttons"));

        Font largeFont = new Font("TimesRoman", Font.BOLD, 20);
        Border lineBorder = new LineBorder(Color.BLACK, 2);

        JPanel p2 = new JPanel(new GridLayout(1, 2));
        JLabel jlblRed = new JLabel("Red");
        JLabel jlblOrange = new JLabel("Orange");

        jlblRed.setForeground(Color.RED);
        jlblOrange.setForeground(Color.ORANGE);
        jlblRed.setFont(largeFont);
        jlblOrange.setFont(largeFont);
        jlblRed.setBorder(lineBorder);
        jlblOrange.setBorder(lineBorder);
        p2.add(jlblRed);
        p2.add(jlblOrange);
        p2.setBorder(new TitledBorder("Two Labels"));

        setLayout(new GridLayout(2,1));
        add(p1);
        add(p2);

        setTitle("TestSwingCommonFeatures");
        setSize(300, 150);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        TestSwingCommonFeatures testSwingCommonFeatures = new TestSwingCommonFeatures();
    }
}
