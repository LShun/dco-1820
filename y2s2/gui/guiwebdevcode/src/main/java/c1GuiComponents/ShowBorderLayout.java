package c1GuiComponents;

import javax.swing.*;
import java.awt.*;

public class ShowBorderLayout extends JFrame {
    public ShowBorderLayout() {
        setLayout(new BorderLayout(2, 4));

        add(new Button("North"), BorderLayout.NORTH);
        add(new Button("South"), BorderLayout.SOUTH);
        add(new Button("East"), BorderLayout.EAST);
        add(new Button("WEST"), BorderLayout.WEST);
        add(new Button("CENTER"), BorderLayout.CENTER);

        setTitle("Show BorderLayout");
        setSize(200, 150);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        ShowBorderLayout frame = new ShowBorderLayout();
    }
}
