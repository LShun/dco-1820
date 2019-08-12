package Tutorial6.Q6;

abstract class Account {
    private int accountNo;
    private String accountHolderName;
    private double accountBalance;
    private double annualInterestRate = 0.06;

    public Account(int accountNo, String accountHolderName, double accountBalance, double annualInterestRate) {
        this.accountNo = accountNo;
        this.accountHolderName = accountHolderName;
        this.accountBalance = accountBalance;
        this.annualInterestRate = annualInterestRate;
    }

    public int getAccountNo() {
        return accountNo;
    }

    public void setAccountNo(int accountNo) {
        this.accountNo = accountNo;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }

    public void setAccountHolderName(String accountHolderName) {
        this.accountHolderName = accountHolderName;
    }

    public double getAccountBalance() {
        return accountBalance;
    }

    public void setAccountBalance(double accountBalance) {
        this.accountBalance = accountBalance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public void cashIn(double cash) {
        this.accountBalance += cash;
    }

    public void cashOut(double cash) {
        this.accountBalance -= cash;
    }

    public double calculateInterest() {
        return this.accountBalance * this.annualInterestRate;
    };

    @Override // reason to use: https://stackoverflow.com/questions/94361/when-do-you-use-javas-override-annotation-and-why/94411
    public String toString() {
        // TODO: Make output according to question
        return "Account{" +
                "accountNo=" + accountNo +
                ", accountHolderName='" + accountHolderName + '\'' +
                ", accountBalance=" + accountBalance +
                ", annualInterestRate=" + annualInterestRate +
                '}';
    }
}
