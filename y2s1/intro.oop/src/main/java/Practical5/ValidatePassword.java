package Practical5;

import java.util.Scanner;

public class ValidatePassword {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String password;

        System.out.println("Password Validator");
        System.out.println("The password must be: ");
        System.out.println("- >= 7 characters");
        System.out.println("- only letters and digits");
        System.out.println("Contain at least 1 letter & 1 digit");
        System.out.println();
        System.out.print("Enter a password: ");

        password = in.nextLine();

        if (isValid(password)) {
            System.out.println("Valid password");
        }
        else {
            System.out.println("Invalid password");
        }
    }
    // String -> Boolean
    // returns true if the password is valid, else return false
    public static boolean isValid(String pw) {
        if (pw.length() >= 7 && containsAlNum(pw.toLowerCase()))
        {
            return true;
        }
        else {
            return false;
        }

    }

    private static boolean containsAlNum(String pw) {
        for (int i = 0; i < pw.length(); i++) {
            if (pw.charAt(i) >= 'a' && pw.charAt(i) <= 'z') {
                for (int j = 0; j < pw.length(); j++) {
                    if (pw.charAt(j) >= '0' && pw.charAt(j) <= '9') {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
