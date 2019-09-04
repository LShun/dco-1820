package Practical5;

import java.util.Scanner;

public class UpVowelX {
    public static void main(String args[]) {
        String user;
        Scanner in = new Scanner(System.in);

        System.out.print("Enter a string: ");
        user = in.nextLine();

        System.out.println(user.toUpperCase().replaceAll("[aeiouAEIOU]", "x"));

    }

    // String -> String
    // Converts all characters to uppercase

}
