package Tutorial6.Q6;

/*
    Assumptions Made:
    - Assume that the interest rate is same as the overdraftInterestRate
    - Assume that annualInterestRate = 0 because there are no ways to keep track of year in this case
    - Assume that "Premium", "Gold" and "Silver" are not implemented in separate in class, but belong to the same class

 */

public class OverdraftAccount extends Account {
    private String accountType;
    private double overdraftLimit;
    private double overdraftInterestRate;

    public OverdraftAccount(int accountNo, String accountHolderName, double accountBalance, String accountType) {
        super(accountNo, accountHolderName, accountBalance, 0);
        switch (accountHolderName) {
            case "Premium":
                this.accountType = "Premium";
                this.overdraftLimit = -10000;
                this.overdraftInterestRate = 0.05;
                break;
            case "Gold":
                this.accountType = accountType;
                this.overdraftLimit = -5000;
                this.overdraftInterestRate = 0.065;
                break;
            default: // default to "Silver"
                this.accountType = accountType;
                this.overdraftLimit = -2000;
                this.overdraftInterestRate = 0.1;
                break;
        }
    }

    public String getAccountType() {
        return accountType;
    }

    public void setAccountType(String accountType) {
        this.accountType = accountType;
    }

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    public void setOverdraftLimit(double overdraftLimit) {
        this.overdraftLimit = overdraftLimit;
    }

    public double getOverdraftInterestRate() {
        return overdraftInterestRate;
    }

    public void setOverdraftInterestRate(double overdraftInterestRate) {
        this.overdraftInterestRate = overdraftInterestRate;
    }

    public void cashOut(double cash) {
        if (super.getAccountBalance()-cash < this.overdraftLimit) {
            System.out.println("Exceed overdraft limit");
        }
        else super.cashOut(cash);
    }

    @Override
    public double calculateInterest() {
        return super.calculateInterest();
    }

    @Override
    // TODO: Make output according to question
    public String toString() {
        return super.toString() +
                "OverdraftAccount{" +
                "accountType='" + accountType + '\'' +
                ", overdraftLimit=" + overdraftLimit +
                ", overdraftInterestRate=" + overdraftInterestRate +
                '}';
    }
}
