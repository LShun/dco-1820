package Practical6.Question2;

import java.util.Calendar;
import java.util.Date;

public class Account {
    private int accountNo;
    private double balance;
    private String dateCreated = Calendar.getInstance().getTime().toString();
    private static int totalAccounts = 0;

    public Account() {};

    public Account(double balance, String dateCreated) {
        this.accountNo = totalAccounts;
        this.balance = balance;
        this.dateCreated = dateCreated;
        this.totalAccounts++;
    }

    public void deposit(double amt) {
        this.balance += amt;
    }

    public void withdrawal(double amt) {
        if (this.balance < amt) {
            System.out.println("Insufficient balance to withdraw");
        }
        else {
            this.balance -= amt;
        }
    }

    public double getBalance() {
        return balance;
    }

    public int getAccountNo() {
        return accountNo;
    }

    public String getDateCreated() {
        return dateCreated;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void setAccountNo(int accountNo) {
        this.accountNo = accountNo;
    }

    public void setDateCreated(String dateCreated) {
        this.dateCreated = dateCreated;
    }

    @Override
    public String toString() {
        return "Account no: " + this.accountNo + "\n" +
                "Balance : " + this.balance + "\n" +
                "Date Created: " + this.dateCreated + "\n";
    }

    @Override
    public boolean equals(Object obj) {
        Account comp = (Account) obj;
        if (this.accountNo == comp.accountNo) {
            return true;
        }
        else {
            return false;
        }
    }
}
