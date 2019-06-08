import org.junit.jupiter.api.Test;

import java.util.Scanner;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class p1q3_CheckDigit {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a credit card number: ");
        int cc = sc.nextInt();
        if(check(cc)) {
            System.out.println("Credit card is valid");
        }
        else {
            System.out.println("Credit card is not valid");
        }
        sc.close();
    }

    // Integer -> Boolean
    // check whether the credit card number is valid
    // the last digit of the result should be 0
    @Test
    public void testCheck() {
        int C1 = 43589795; // valid
        int C2 = 43589785; // invalid

        assertEquals(true, check(C1));
        assertEquals(false, check(C2));
    }
    public static boolean check(int cc) {
        // first digit = total / 10, the remainder
        // second digit = quotient of first digit / 10,
        // get remainder
        // and so on
        int creditCard = cc;
        int evenNum[] = new int[4];
        int oddSum = 0;
        int evenSum = 0;

        for (int i = 0; i < 4; i++)
        {
            oddSum += creditCard % 10;
            creditCard = creditCard / 100;
        }

        creditCard = cc / 10;

        for (int i = 0; i < 4; i++)
        {
            evenNum[i] = creditCard % 10 * 2;
            creditCard = creditCard / 100;
        }


        for (int i = 0; i < 4; i++)
        {
            evenSum += evenNum[i] / 10 + evenNum[i] % 10;
        }

        int totalSum = evenSum + oddSum;
        return (totalSum % 10 == 0);
    }
};
