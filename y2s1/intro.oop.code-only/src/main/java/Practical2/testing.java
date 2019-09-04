package Practical2;

import java.util.Scanner;

public class testing {
    public static boolean LeapYear(int year) {
        if (year < 1582) {
            return true;
        }
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                }
            }
        }
        return false;
    }
    public static void main(String args[]) {
        System.out.println("Please enter a year: ");
        Scanner sc = new Scanner(System.in);
        System.out.println(LeapYear(sc.nextInt()));
    }
}
