package Practical6.Question2;

import java.util.Scanner;

public class SimpleMenu {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println(
                    "Simple Account Management System\n\n"

                            + "You can open 2 accounts, choose 1: \n"
                            + "1. Savings\n"
                            + "2. Current\n"
                            + "Other. Exit\n\n"

                            + "Enter your selection: "
            );

            switch (in.nextInt()) {
                case 1:
                    savingsAccount();
                    break;
                case 2:
                    currentAccount();
                    break;
                default:
                    return;
            }
        }
    }

    private static void currentAccount() {
        CurrentAccount ca = new CurrentAccount();
        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println(
                    "Current Account Management System\n\n"
                            + "1. View Account Details\n"
                            + "2. Deposit\n"
                            + "3. Withdrawal\n"
                            + "Other. Back\n\n"
                            + "Enter your selection: "
            );

            switch (in.nextInt()) {
                case 1:
                    System.out.println(ca.toString());
                    break;
                case 2:
                    System.out.println("Enter amount: ");
                    ca.deposit(in.nextDouble());
                    System.out.println(ca.toString());
                    break;
                case 3:
                    System.out.println("Enter amount: ");
                    ca.withdrawal(in.nextDouble());
                    System.out.println(ca.toString());
                    break;
                default:
                    return;
            }
        }
    }

    private static void savingsAccount() {
        SavingsAccount sa = new SavingsAccount();
        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println(
                    "Savings Account Management System\n\n"
                            + "1. View Account Details\n"
                            + "2. Deposit\n"
                            + "3. Withdrawal\n"
                            + "4. Add interest\n"
                            + "Other. Back\n\n"
                            + "Enter your selection: "
            );
            switch (in.nextInt()) {
                case 1:
                    System.out.println(sa.toString());
                    break;
                case 2:
                    System.out.println("Enter amount: ");
                    sa.deposit(in.nextDouble());
                    System.out.println(sa.toString());
                    break;
                case 3:
                    System.out.println("Enter amount: ");
                    sa.withdrawal(in.nextDouble());
                    System.out.println(sa.toString());
                    break;
                case 4:
                    System.out.println("Interest increment: " + sa.calculateInterest());
                    sa.addInterest();
                    System.out.println(sa.toString());
                    break;
                default:
                    return;
            }
        }
    }
    /* Required functionalities:

    Savings account
    ===
    Check acc balance
    Depo
    Withdraw in imit
    withdraw over limit
    Add interest

    Current acc
    ===
    Check acc balance
    Depo
    Withdraw in limit
    Withdraw over limit

    General
    ===
    Check balance
    Deposit
    Withdrawal
    Exit
     */


}
