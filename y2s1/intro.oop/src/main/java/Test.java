import java.util.Scanner;

public class Test {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String ccNum = in.nextLine();

        if (ccNum.length() != 16) {
            System.out.println("INVALID");
        }

        for (int i = 0; i < 16; i++) {
            if (Character.isDigit(ccNum.charAt(i)) == false)
                System.out.println("INVALID");
        }

        System.out.println("VALID");
    }
}
