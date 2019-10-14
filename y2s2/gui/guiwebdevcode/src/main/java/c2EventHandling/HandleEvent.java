package c2EventHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class HandleEvent extends JFrame {
    private JButton jbtOK = new JButton("OK");
    private JButton jbtCancel = new JButton("Cancel");

    public HandleEvent() {
        setLayout(new FlowLayout());
        add(jbtOK);
        add(jbtCancel);
        jbtOK.addActionListener(new OKListenerClass());
        jbtCancel.addActionListener(new CancelListenerClass());
    }

    public static void main(String[] args) {
        HandleEvent frame = new HandleEvent();
        frame.setTitle("Handle Event");
        frame.setSize(250, 100);
        frame.setLocation(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class OKListenerClass implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        JOptionPane.showMessageDialog(null, "OK button clicked");
    }
}

class CancelListenerClass implements ActionListener {

    @Override
    public void actionPerformed(ActionEvent e) {
        JOptionPane.showMessageDialog(null, "Cancel button clicked.");
    }
}

