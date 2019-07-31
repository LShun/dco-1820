package Practical6.Question2;

public class SavingsAccount extends Account {
    private static double interest = 0.15;

    public SavingsAccount() {}
    public SavingsAccount(double balance, String dateCreated)
    {
        super(balance, dateCreated);
    }

    public static double getInterest() {
        return interest;
    }

    public static void setInterest(double interest) {
        SavingsAccount.interest = interest;
    }

    public double calculateInterest() {
        return getBalance() * interest;
    }

    public void addInterest() {
        setBalance(getBalance() + getBalance() * interest);
    }

    public String toString() {
        return super.toString() +
                "Interest rate: " + interest + "\n";
    }
}
