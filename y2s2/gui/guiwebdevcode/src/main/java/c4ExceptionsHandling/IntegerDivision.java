package c4ExceptionsHandling;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class IntegerDivision extends JFrame {
    private JLabel jlbl1 = new JLabel("Number 1");
    private JTextField jtf1 = new JTextField(4);
    private JLabel jlbl2 = new JLabel("Number 2");
    private JTextField jtf2 = new JTextField(4);
    private JLabel jlblr = new JLabel("Result");
    private JTextField jlblres = new JTextField(4);
    private JButton jbtDivide = new JButton("Divide");

    public IntegerDivision() {
        setLayout(new GridLayout(2, 1));

        JPanel jpTop = new JPanel(new FlowLayout());
        jpTop.add(jlbl1);
        jpTop.add(jtf1);
        jpTop.add(jlbl2);
        jpTop.add(jtf2);
        jpTop.add(jlblr);
        jpTop.add(jlblres);
        jlblres.setEditable(false);
        add(jpTop);
        JPanel jpBottom = new JPanel(new BorderLayout());
        jbtDivide.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double first = Double.parseDouble(jtf1.getText());
                double sec = Double.parseDouble(jtf2.getText());
                jlblres.setText(String.valueOf(first / sec));
            }
        });
        jpBottom.add(jbtDivide, BorderLayout.CENTER);
        add(jpBottom);
    }

    public static void main(String[] args) {
        IntegerDivision id = new IntegerDivision();
        id.setTitle("IntegerDivision");
        id.setSize(350, 100);
        id.setLocationRelativeTo(null);
        id.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        id.setVisible(true);
    }
}
