package Practical6.Question2;

public class CurrentAccount extends Account {
    private static int freeTx = -1;
    private static double nominalFee = 4.00;
    private int tx;

    public CurrentAccount() {
    }

    public CurrentAccount(double balance, String dateCreated)
    {
        super(balance, dateCreated);
    }

    @Override
    public void withdrawal(double amt) {
        if (this.tx <= freeTx) {
            super.withdrawal(amt);
            this.tx++;
        }
        else {
            super.withdrawal(amt + nominalFee);
        }
    }

    @Override
    public void deposit(double amt) {
        super.deposit(amt);
    }

    public String toString() {
        return super.toString() +
                "Free Transactions: " + freeTx + "\n" +
                "Nominal fee: " + this.nominalFee + "\n" +
                "Transactions made: " + this.tx + "\n";
    }
}
