package c1practical;

import javax.swing.*;

public class Q1TemperatureConversion {
    public static void main(String[] args) {
        int answer;
        do {
            String fahrenheitInput = JOptionPane.showInputDialog(
                    "Enter fahrenheit:");

            int f = Integer.parseInt(fahrenheitInput);

            double c = 5.0 / 9.0 * (f - 32);

            JOptionPane.showMessageDialog(null,
                    f + " degrees in fahrenheit = " + c + " degrees celcius");

            answer = JOptionPane.showConfirmDialog(null, "Do you want to enter again?", "Confirmation",
                    JOptionPane.YES_NO_OPTION);
        } while (answer == JOptionPane.YES_OPTION);
    }
}
