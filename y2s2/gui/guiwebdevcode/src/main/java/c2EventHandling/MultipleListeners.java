package c2EventHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MultipleListeners extends JFrame {
    private JButton jbtOK = new JButton("OK");
    private JButton jbtCancel = new JButton("Cancel");
    private int countOKs = 0;
    private int countCancels = 0;

    public MultipleListeners() {
        setLayout(new FlowLayout());
        add(jbtOK);
        add(jbtCancel);

        jbtOK.addActionListener(new OKListenerClass());
        jbtCancel.addActionListener(new CancelListenerClass());

        CountListenerClass countListener = new CountListenerClass();
        jbtOK.addActionListener(countListener);
        jbtOK.addActionListener(countListener);
    }

    private class CountListenerClass implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == jbtOK) {
                countOKs++;
            }
            else {
                countCancels++;
            }
        }
    }

    private class OKListenerClass implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(null,
                    "OK button clicked total of " + countOKs + " times.");
        }
    }

    private class CancelListenerClass implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(null, "Cancel button clicked total of " + countCancels + " times.");
        }
    }
}
