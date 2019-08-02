package Tutorial6.Q6;

public class FixedDepositAccount extends Account {
    private int savingYears;

    public FixedDepositAccount(int accountNo, String accountHolderName, double accountBalance, double annualInterestRate, int savingYears) {
        super(accountNo, accountHolderName, accountBalance, annualInterestRate);
        this.savingYears = savingYears;
    }

    public int getSavingYears() {
        return savingYears;
    }

    public void setSavingYears(int savingYears) {
        this.savingYears = savingYears;
    }

    @Override
    double calculateInterest() {
        return super.getAccountBalance() * super.getAnnualInterestRate() * this.savingYears;
    }

    @Override
    public String toString() {
        // TODO: Make output according to question
        return super.toString() +
                "FixedDepositAccount{" +
                "savingYears=" + savingYears +
                '}';
    }
}
