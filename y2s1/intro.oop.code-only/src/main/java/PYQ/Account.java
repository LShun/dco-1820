package PYQ;

public class Account {
    private String accountNo;
    private String holderName;
    private double balance;
    private static double interestRate;

    Account() {
        this.accountNo = null;
        this.holderName = null;
        this.balance = 0.0;
    }

    public void setBalance(double amount) {
        this.balance = amount;
    }

    public double calculateInterest() {
        return this.balance * interestRate;
    }
}
