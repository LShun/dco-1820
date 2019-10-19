package c1practical.Q7PanelClasses;

import javax.swing.*;
import java.awt.*;

public class BorderClassPanels extends JFrame {
    ButtonPanels b1;
    ButtonPanels b2;

    BorderClassPanels() {
        setLayout(new BorderLayout());
        b1 = new ButtonPanels();
        b2 = new ButtonPanels();
        add(b1, BorderLayout.SOUTH);
        add(b2, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        BorderClassPanels bcp = new BorderClassPanels();
        bcp.setTitle("Panels with buttons");
        bcp.setLocationRelativeTo(null);
        bcp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        bcp.pack();
        bcp.setVisible(true);
    }
}
