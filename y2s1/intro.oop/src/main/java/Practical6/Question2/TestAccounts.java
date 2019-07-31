package Practical6.Question2;

public class TestAccounts {
    public static void main(String args[]) {
        CurrentAccount ca = new CurrentAccount(1950, "10/5/2019");
        SavingsAccount sa = new SavingsAccount(1900, "10/6/2019");

        ca.deposit(1000);
        ca.withdrawal(500);

        System.out.println(ca.toString());

        sa.deposit(1000);
        sa.withdrawal(100);
        System.out.println("Calculated interest: " + sa.calculateInterest());

        System.out.println("Before adding interest: \n" + sa.toString());

        sa.addInterest();
        System.out.println("After adding interest: \n" + sa.toString());

        System.out.println(sa.equals(ca));
        System.out.println(sa.equals(sa));
    }

}
