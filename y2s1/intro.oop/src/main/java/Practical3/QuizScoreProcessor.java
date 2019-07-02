package Practical3;

import java.util.Scanner;

public class QuizScoreProcessor {
    public static void main(String args[]) {
        int scores, scoresLower, scoresHigher;
        double avg;
        int[] los;
        Scanner in = new Scanner(System.in);

        // input number of scores
        System.out.print("Enter number of quiz scores to process: ");
        scores = in.nextInt();
        System.out.println();

        los = new int[scores];

        // input individual scores
        for (int s = 0; s < scores; s++) {
            System.out.printf("Score %d: ", s+1);
            los[s] = in.nextInt();
        }

        // pass all individual scores to the function to calculate average
        avg = average(los);

        // pass all individual scores and the average to calculate the number of scores below the average
        scoresHigher = aboveOrEqual(los, avg);

        // pass all individual scores and the average to calculate the number of scores below the average
        scoresLower = below(los, avg);

        System.out.println();
        System.out.println("Results");
        System.out.println("=======");
        System.out.println("Average is " + avg);
        System.out.println("Number of scores above or equal to average is " + scoresHigher);
        System.out.println("Number of scores below the average is " + scoresLower);
    }

    // (listof Integer) -> Double
    // produce the average of all scores inside the list
    // !!!
    public static double average(int[] los) {
        int sum = 0;
        for (int i = 0; i < los.length; i++)
        {
            sum += los[i];
        }
        return (double) sum / los.length;
    }

    // (listof Integer) Double -> Integer
    // produce the number of scores above the average
    // !!!
    public static int aboveOrEqual(int[] los, double avg) {
        int numberAbove = 0;
        for (int i = 0; i < los.length; i++){
            if (los[i] >= avg) {
                numberAbove++;
            }
        }
        return numberAbove;
    }

    // (listof Integer) Double -> Integer
    // produce the number of scores below the average
    // !!!
    public static int below(int[] los, double avg) {
        int numberBelow = 0;
        for (int i = 0; i < los.length; i++){
            if (los[i] < avg) {
                numberBelow++;
            }
        }
        return numberBelow;
    }
}
