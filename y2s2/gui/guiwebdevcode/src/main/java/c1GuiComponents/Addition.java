package c1GuiComponents;

import javax.swing.*;

public class Addition {
    public static void main(String[] args) {
        String firstNumber = JOptionPane.showInputDialog("Enter first integer");
        String secondNumber = JOptionPane.showInputDialog("Enter second integer");

        int firstInt = Integer.parseInt(firstNumber);
        int secondInt = Integer.parseInt(secondNumber);

        int sum = firstInt + secondInt;

        JOptionPane.showMessageDialog(null, "The sum is " + sum);
    }
}
