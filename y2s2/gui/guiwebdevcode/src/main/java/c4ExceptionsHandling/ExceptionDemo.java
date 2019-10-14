package c4ExceptionsHandling;

import javax.swing.*;

// PROBLEM: Throw NumberFormatException
public class ExceptionDemo {
    public static void main(String[] args) {
        String inputTxt = JOptionPane.showInputDialog("Enter an integer");
        int number = Integer.parseInt(inputTxt);
        JOptionPane.showMessageDialog(null, "The number entered is " + number);
    }
}
