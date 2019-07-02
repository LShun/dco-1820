package Practical1;

import java.util.Scanner;

public class p1q2_AgeCalc {

    public static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter you age (years): ");
        int y = sc.nextInt();
        printAge(y);
    }
    // Integer -> String
    // prints out the user's age in years, days, and seconds
    public static void printAge(int y) {
        int d = y * 365;
        int s = d * 86400;
        System.out.println("Age in years: " + y + " years \n" +
                "Age in days: " + d + " days\n" +
                "Age in seconds: " + s + " seconds\n" +
                "Process completed.");
    }
}

