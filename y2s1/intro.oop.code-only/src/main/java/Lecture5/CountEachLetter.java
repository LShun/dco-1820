package Lecture5;

import java.util.Scanner;

public class CountEachLetter {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String userString;
        int[] charCounts = new int[26];

        System.out.println("Enter a string: ");
        userString = in.nextLine().toLowerCase();

        // intialize entire array to 0
        for (int i = 0; i < userString.length(); i++) {
            charCounts[userString.charAt(i) - 'a'] = 0;
        }

        for (int i = 0; i < userString.length(); i++) {
            charCounts[userString.charAt(i) - 'a']++;
        }

        for (int i = 0; i < charCounts.length; i++) {
            System.out.println((char)('a' + i) + ": " + charCounts[i]);
        }
    }
}
