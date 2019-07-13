package Tutorial4;

import java.util.Scanner;

public class AccountDriver {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        Account acc1 = new Account(909, "Ali Baba", 1000);
        int choice;

        while (true) {
            System.out.print(
                    "Main Menu\n" +
                            "1: Check balance\n" +
                            "2: Cash In\n" +
                            "3: Cash Out\n" +
                            "4: Interest\n" +
                            "5: Exit\n" +
                            "Enter a choice : "
            );

            choice = in.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Your current balance: " + acc1.getBalance());
                    break;
                case 2:
                    System.out.print("Enter amount of cash in: ");
                    acc1.cashIn(in.nextDouble());
                    System.out.println("New balance: " + acc1.getBalance());
                    break;
                case 3:
                    System.out.println("Enter amount to cash out: ");
                    acc1.cashOut(in.nextDouble());
                    System.out.println("New balance " + acc1.getBalance());
                    break;
                case 4:
                    System.out.println("Your interest amount: " + acc1.calculateinterest());
                    break;
                case 5:
                    return;
            }
        }
    }
}
