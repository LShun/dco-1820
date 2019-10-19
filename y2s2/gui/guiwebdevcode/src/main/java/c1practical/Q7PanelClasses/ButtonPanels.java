package c1practical.Q7PanelClasses;

import javax.swing.*;
import java.awt.*;

class ButtonPanels extends JPanel {
    private JButton btn1, btn2;

    ButtonPanels() {
        setLayout(new GridLayout(1,2));
        btn1 = new JButton("Button 1");
        btn2 = new JButton("Button 2");
        add(btn1);
        add(btn2);
    }

    ButtonPanels(String b1, String b2) {
        setLayout(new GridLayout(1, 2));
        btn1 = new JButton(b1);
        btn2 = new JButton(b2);
        add(btn1);
        add(btn2);
    }
}
