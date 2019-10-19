package c1practical;

import javax.swing.*;
import java.awt.*;

public class Q4GridStudentInfoFrame extends JFrame {
    JLabel regNo = new JLabel("Registration Number");
    JLabel name = new JLabel("Name");
    JLabel progCode = new JLabel("Programme Code");
    JTextField regField = new JTextField(10);
    JTextField nameField = new JTextField(20);
    JTextField progField = new JTextField(5);
    JButton submit = new JButton("Submit");

    Q4GridStudentInfoFrame() {
        this.setLayout(new GridLayout(4, 2));
        add(regNo);
        add(regField);
        add(name);
        add(nameField);
        add(progCode);
        add(progField);
        add(new JLabel());
        add(submit);
    }

    public static void main(String[] args) {
        Q4GridStudentInfoFrame s = new Q4GridStudentInfoFrame();
        s.setTitle("Student Information");
        s.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        s.setLocationRelativeTo(null);
        s.pack();
        s.setVisible(true);
    }
}