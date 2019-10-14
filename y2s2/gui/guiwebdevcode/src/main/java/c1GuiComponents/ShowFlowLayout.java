package c1GuiComponents;

import javax.swing.*;
import java.awt.*;

public class ShowFlowLayout extends JFrame {
    public ShowFlowLayout() {
        setLayout(new FlowLayout(FlowLayout.LEFT, 10, 20));

        add(new JLabel("First Name"));
        add(new JTextField(8));
        add(new JLabel("MI"));
        add(new JTextField(1));
        add(new JLabel("Last Name"));
        add(new JTextField(8));

        setTitle("ShowFlowLayout");
        setSize(200, 200);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        ShowFlowLayout frame = new ShowFlowLayout();
    }
}
