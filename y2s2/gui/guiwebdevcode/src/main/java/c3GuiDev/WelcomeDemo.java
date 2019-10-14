package c3GuiDev;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WelcomeDemo extends JFrame {
    private JLabel jlblName = new JLabel("Name");
    private JTextField jtfName = new JTextField(30);
    private JLabel jlblProgramme = new JLabel("Programme");
    private JTextField jtfProgramme = new JTextField(5);
    private JButton jbtSubmit = new JButton("Submit");
    private JLabel jlblMessage = new JLabel();

    public WelcomeDemo() {
        JPanel jpCenter = new JPanel(new GridLayout(3, 2));
        jpCenter.add(jlblName);
        jpCenter.add(jtfName);
        jpCenter.add(jlblProgramme);
        jpCenter.add(jtfProgramme);
        jpCenter.add(new JLabel(""));
        jpCenter.add(jbtSubmit);
        add(jpCenter, BorderLayout.CENTER);
        JPanel jpSouth = new JPanel();
        jpSouth.add(jlblMessage);
        add(jpSouth, BorderLayout.SOUTH);

        Font font = new Font("TimesRoman", Font.BOLD, 15);
        jlblName.setFont(font);
        jlblProgramme.setFont(font);
        jbtSubmit.setFont(font);

        jbtSubmit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String programme = jtfProgramme.getText();
                String message = "Programme: " + programme;
                JOptionPane.showMessageDialog(null, message);
            }
        });
        jtfName.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                jlblMessage.setText("Welcome, " + jtfName.getText());
                jtfProgramme.requestFocusInWindow();
            }
        });
    }

    public static void main(String[] args) {
        WelcomeDemo frame = new WelcomeDemo();
        frame.setTitle("Welcome Demo");
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
