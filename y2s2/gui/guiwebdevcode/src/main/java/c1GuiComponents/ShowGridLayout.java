package c1GuiComponents;

import javax.swing.*;
import java.awt.*;

public class ShowGridLayout extends JFrame {
    public ShowGridLayout() {
        setLayout(new GridLayout(3, 2));

        add(new JLabel("First Name"));
        add(new JTextField(8));
        add(new JLabel("MI"));
        add(new JTextField(1));
        add(new JLabel("Last Name"));
        add(new JTextField(8));

        setTitle("ShowFlowLayout");
        pack();
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        ShowGridLayout frame = new ShowGridLayout();
    }
}
