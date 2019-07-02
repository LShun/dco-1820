import java.util.Scanner;

// MonetaryUnits.java
// Converts dollars and cents to the monetary equivalent dollars, quarters, dimes, nickels and pennies.

public class MonetaryUnits {
    public static void main(String args[]) {
        float amount = 50;

        int remainingAmount = (int)(amount * 100);

        // Find the remaining of one dollars
        int numberOfOneDollars = remainingAmount / 100;
        remainingAmount = remainingAmount % 100;

        // Find the number of quarters in the remaining amount
        int numberOfQuarters = remainingAmount / 25;
        remainingAmount = remainingAmount % 25;

        // Find the number of dimes in the remaining amount
        int numberOfDimes = remainingAmount / 10;
        remainingAmount %= 10;

        // Find the number of nickles in the remaining amount
        int numberOfNickels = remainingAmount / 5;
        remainingAmount %= 5;

        // Find the number of pennies in the remaining amount
        int numberOfPennies = remainingAmount;
    }
}