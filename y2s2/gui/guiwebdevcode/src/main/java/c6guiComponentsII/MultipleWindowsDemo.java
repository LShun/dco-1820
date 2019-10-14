package c6guiComponentsII;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MultipleWindowsDemo extends JFrame {
    private JFrame vowelCountFrame = new JFrame();
    private JTextArea jta = new JTextArea();
    private JPanel vowelCountPanel;
    private JButton jbtShowVowelCount = new JButton("Show Vowel Count");

    public MultipleWindowsDemo() {
        add(jta, BorderLayout.CENTER);
        add(jbtShowVowelCount, BorderLayout.SOUTH);
        jbtShowVowelCount.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String text = jta.getText();
                vowelCountPanel = new VowelCountPanel(text);
                vowelCountFrame.add(vowelCountPanel, BorderLayout.CENTER);
                vowelCountFrame.setTitle("Vowel Count");
                vowelCountFrame.setSize(300, 400);
                vowelCountFrame.setVisible(true);
            }
        });
    }

    public static void main(String[] args) {
        MultipleWindowsDemo mwd = new MultipleWindowsDemo();
        mwd.setTitle("MultipleWindowsDemo");
        mwd.setSize(300, 400);
        mwd.setLocationRelativeTo(null);
        mwd.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mwd.setVisible(true);
    }
}
