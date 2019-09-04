package Practical3;

import java.util.Scanner;

public class fundTransferTotalV2 {
    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int scores;
        double avg;

        // request number of quiz scores to process
        System.out.print("Enter number of quiz scores to process: ");
        scores = in.nextInt();

        int[] score = new int[scores];

        for (int i = 0; i < scores; i++) {
            System.out.print("Score " + (i + 1) + ": ");
            score[i] = in.nextInt();
        }

        // find the average
        avg = average(score);
        System.out.println("The average score is: " + avg);

        // check which score is above and below the average
        System.out.println("Scores higher than average: " + higher(score, avg));

        // print out the numbers of scores above and below the average
        System.out.println("Scores lower than average: " + lower(score, avg));
    }

    // (int[] Integer) -> Double
    // find the average of a list of integers
    // !!!
    public static double average(int[] s) {
        int sum = 0;
        double avg;

        for (int i = 0; i < s.length; i++) {
            sum += s[i];
        }

        avg = (double) sum / s.length;

        return avg;
    }

    // (int[] Integer) Double -> Integer
    // find how many numbers in the array are higher than the given avg
    // !!!
    public static int higher(int[] s, double avg) {
        int count = 0;

        for (int i = 0; i < s.length; i++) {
            if (s[i] > avg) {
                count++;
            }
        }
        return count;
    }

    // (int[] Integer) Double -> Integer
    // find how many numbers in the array are below the given avg
    // !!!
    public static int lower(int[] s, double avg) {
        int count = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] < avg) {
                count++;
            }
        }
        return count;
    }
}
