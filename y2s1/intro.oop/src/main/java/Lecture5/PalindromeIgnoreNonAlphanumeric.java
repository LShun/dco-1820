package Lecture5;

import java.util.Scanner;

public class PalindromeIgnoreNonAlphanumeric {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        StringBuilder userString = new StringBuilder();

        System.out.println("Enter a new string: ");
        userString.append(in.nextLine());
        StringBuilder original = new StringBuilder(userString);

        for (int i = 0; i < userString.length(); i++) {
            char userChar = userString.charAt(i);
            if ((userChar >= 'a' && userChar <= 'z') || (userChar >= 'A' && userChar <= 'Z')) {
                continue;
            }
            else {
                userString.delete(i, i+1);
                i--;
            }
        }

        userString.reverse();
        System.out.println(userString);
        System.out.println(original);

        if (userString.toString().equals(original.toString())) {
            System.out.println("This is a freaking palindrome!");
        }
        else {
            System.out.println("This is NOT a freaking palindrome!");
        }
    }


}
