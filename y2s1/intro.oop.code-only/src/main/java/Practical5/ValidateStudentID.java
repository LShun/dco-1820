package Practical5;

import java.util.Scanner;

public class ValidateStudentID {
    public static void main(String args[]) {
        char[] codes = {'A', 'B'};
        Scanner in = new Scanner(System.in);
        String id;

        System.out.print("Enter a student ID code for verification (format: 'A12345'): ");
        id = in.nextLine();

        if (id.matches("[A-Za-z]{1}[0-9]{5}")) {
            char school = id.charAt(0);
            for (char c: codes) {
                if (school == c) {
                    System.out.println(id + " is a valid id.");
                    return;
                }
            }
        }
        System.out.println(id + " is not a valid id.");
    }

}
