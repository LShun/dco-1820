package Tutorial5;

import Lecture5.PalindromeIgnoreNonAlphanumeric;

import java.util.Scanner;

public class ValidateID {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String ID;
        System.out.println("ID Validator");
        System.out.println("The ID must be: ");
        System.out.println("Has between 6 and 10 characters");
        System.out.println("Begins with an uppercase letter");
        System.out.println("Consists of only letters and digits");
        System.out.println("Contains at least one lowercase letter and at least one digit");
        System.out.println();
        System.out.print("Enter a ID: ");

        ID = in.nextLine();

        if (validateID(ID)) {
            System.out.println("Valid ID");
        }
        else {
            System.out.println("Invalid ID");
        }
    }
    public static boolean validateID(String loginID) {
        // Has between 6 and 10 characters
        if (loginID.length() < 6 || loginID.length() > 10) {
            return false;
        }
        // Begins with an uppercase letter
        if (Character.isUpperCase(loginID.charAt(0)) == false) {
            return false;
        }
        // Consists of only letters and digits
        for (int i = 0; i < loginID.length(); i++) {
            if (Character.isLetter(loginID.charAt(i)) == false) {
                if (Character.isDigit(loginID.charAt(i)) == false) {
                    return false;
                }
            }
        }
        // Contains at least one lowercase letter and at least one digit
        for (int i = 0; i < loginID.length(); i++) {
            if (Character.isLowerCase(loginID.charAt(i))) {
                for (int j = 0; j < loginID.length(); j++) {
                    if (Character.isDigit(loginID.charAt(j))) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
