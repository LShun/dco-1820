package c4ExceptionsHandling;

import javax.swing.*;

public class HandleExceptionDemo {
    public static void main(String[] args) {
        try {
            String inputTxt = JOptionPane.showInputDialog("Enter an integer");
            int number = Integer.parseInt(inputTxt);
            JOptionPane.showMessageDialog(null, "The number entered is " + number);
        }
        catch(NumberFormatException ex) {
            JOptionPane.showMessageDialog(null, "Incorrect input: an integer is required.",
                    "Invalid Input", JOptionPane.ERROR_MESSAGE);
        }
    }
}
