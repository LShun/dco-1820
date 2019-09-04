package Practical2;

import static java.lang.Math.sqrt;

public class NumberAndSqrt {
    public static void main(String args[]) {
        final int NUMBERS = 20;

        System.out.printf("%-10s %-10s\n", "Number", "SquareRoot");
        for (int i = 1; i <= NUMBERS; i++) {
            System.out.printf("%-10d %-10.4f\n", i, sqrt((double) i));
        }
    }
}
