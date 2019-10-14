package c2EventHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DetectSource extends JFrame {
    private JButton jbtOK = new JButton("OK");
    private JButton jbtCancel = new JButton("Cancel");
    public DetectSource() {
        setLayout(new FlowLayout());
        add(jbtOK);
        add(jbtCancel);
        jbtOK.addActionListener(new ButtonListenerClass());
        jbtCancel.addActionListener(new ButtonListenerClass());
    }
    private class ButtonListenerClass implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == jbtOK)
                JOptionPane.showMessageDialog(null, "OK Button clicked");
            else if (e.getSource() == jbtCancel)
                JOptionPane.showMessageDialog(null, "Cancel button clicked.");
        }
    }

    public static void main(String[] args) {
        DetectSource ds = new DetectSource();
        ds.setTitle("Impressive attempt to detect source");
        ds.setSize(200, 100);
        ds.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ds.setVisible(true);
    }
}


