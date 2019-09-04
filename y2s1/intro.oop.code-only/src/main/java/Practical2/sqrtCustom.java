package Practical2;

import java.util.Scanner;

public class sqrtCustom {
    public static void main(String args[]) {
        System.out.println("Enter a number to calculate the square root: ");
        Scanner sc = new Scanner(System.in);
        double num = sc.nextDouble();

        double sqrtedNum = calculateSqrt(num);

        System.out.printf("%.7f",sqrtedNum);
    }

    private static double calculateSqrt(double n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n < 0) {
            throw new RuntimeException("Square root of negative number is undefined.\n");
        } else {
            if (n < 1) {
                return ensureAccuracy(n, 1, n);
            }
            else {
                return ensureAccuracy(1, n, n);
            }
        }
    }

    // Double Double -> Double
    // Check if the limits / lower limit has a difference of 1/10^8,
    // if not, recompute the number
    private static double ensureAccuracy(double lower, double upper, double init) {
        if (((upper - lower) / 2.0) > (1.0 / Math.pow(10, 8))) {
            return calcSqrt(lower, upper, init);
        }
        else {
            return ((upper + lower) / 2.0);
        }
    }


    // Double -> Double
    // calculates the approximate square root of the two numbers
    private static double calcSqrt(double lower, double upper, double init) {
        double sqMidpoint, midpoint;

        midpoint = ((lower + upper) / 2);
        sqMidpoint = Math.pow(midpoint, 2);

        if (sqMidpoint >= init) {
            return ensureAccuracy(lower, midpoint, init);
        }
        else {
            return ensureAccuracy(midpoint, upper, init);
        }
    }
}
