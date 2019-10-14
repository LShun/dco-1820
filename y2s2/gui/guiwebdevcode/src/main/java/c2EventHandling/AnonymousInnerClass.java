package c2EventHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AnonymousInnerClass extends JFrame {
    private JButton jbtOK = new JButton("OK");
    private JButton jbtCancel = new JButton("Cancel");

    public AnonymousInnerClass() {
        setLayout(new FlowLayout());

        add(jbtOK);
        add(jbtCancel);

        jbtOK.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        JOptionPane.showMessageDialog(null, "OK button clicked");
                    }
                }
        );

        jbtCancel.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        JOptionPane.showMessageDialog(null, "Cancel button clicked");
                    }
                }
        );
    }

    public static void main(String[] args) {
        AnonymousInnerClass frame = new AnonymousInnerClass();
        frame.setTitle("Anonymous Inner Classes");
        frame.setSize(250, 100);
        frame.setLocation(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
