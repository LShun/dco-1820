// c1ApA2pg49.java
// program to compute the monthly and total payment of a loan, given the total amount loaned, interest rate (expressed as decimal), and time loaned.

import java.util.Scanner;
import java.lang.Math;

public class c1ApA2pg49 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double loanAmount = sc.nextDouble();
        double monthlyInterestRate = sc.nextDouble();
        int numberOfYears = sc.nextInt();
        
        double monthly = (loanAmount * monthlyInterestRate) / (1 - (1 / Math.pow((1 + monthlyInterestRate), (numberOfYears * 12))));
        double total = monthly * 12 * numberOfYears;

        System.out.println(monthly + " " + total);
    }
}