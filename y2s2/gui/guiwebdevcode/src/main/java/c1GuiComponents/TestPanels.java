package c1GuiComponents;

import javax.swing.*;
import java.awt.*;

public class TestPanels extends JFrame {
    public TestPanels() {
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4,3));

        for (int i = 1; i <= 9; i++) {
            buttonPanel.add(new JButton("" + i));
        }

        for (String s : new String[]{"0", "Start", "Stop"}) {
            buttonPanel.add(new JButton(s));
        }

        JPanel controlPanel = new JPanel(new BorderLayout());
        controlPanel.add(new JTextField("Time to be displayed here"), BorderLayout.NORTH);
        controlPanel.add(buttonPanel,BorderLayout.CENTER);
        add(controlPanel, BorderLayout.EAST);
        add(new JButton("Food to be placed here"), BorderLayout.CENTER);

        setTitle("The Front View of a Microwave Oven");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 250);
        setVisible(true);
    }

    public static void main(String[] args) {
        TestPanels frame = new TestPanels();
    }

}
