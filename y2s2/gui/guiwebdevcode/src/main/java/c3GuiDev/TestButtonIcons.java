package c3GuiDev;

import javax.swing.*;

public class TestButtonIcons extends JFrame {
    public TestButtonIcons() {
        ImageIcon usIcon = new ImageIcon(getClass().getResource("images/usIcon.png"));
        ImageIcon calcon = new ImageIcon(getClass().getResource("images/canadaIcon.png"));
        ImageIcon ukIcon = new ImageIcon(getClass().getResource("images/ukIcon.png"));

        JButton jbt = new JButton("Click me", usIcon);
        jbt.setPressedIcon(calcon);
        jbt.setRolloverIcon(ukIcon);
        add(jbt);
    }

    public static void main(String[] args) {
        TestButtonIcons frame = new TestButtonIcons();
        frame.setTitle("Button Icons");
        frame.setSize(250, 100);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
