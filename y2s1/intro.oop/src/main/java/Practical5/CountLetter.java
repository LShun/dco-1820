package Practical5;

import java.util.Scanner;

public class CountLetter {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String word;
        char letter;

        System.out.print("Enter a word: ");
        word = in.nextLine();
        System.out.print("Enter the letter you want to count: ");
        letter = in.next().charAt(0);

        System.out.println("The number of " + letter + " inside is: " + countLetter(word, letter));
    }

    // String Char -> Int
    // return the occurrence(s) of ch in str
    public static int countLetter(String str, char ch) {

        int count = 0;

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) {
                count++;
            }
        }

        return count;
    }
}
