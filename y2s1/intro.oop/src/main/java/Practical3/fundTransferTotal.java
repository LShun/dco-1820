package Practical3;

import java.util.Scanner;

public class fundTransferTotal {
    public static void main(String args[]) {
        int[] lod = {100, 50, 20, 10, 5, 1};
        int[] qod = new int[lod.length];
        int[] sod = new int[lod.length];
        int grandTotal;

        Scanner in = new Scanner(System.in);

        System.out.printf("%20s%10s%20s\n", "Denomination (RM)", "", "Quantity");
        // print each denomination and ask for quantity
        for (int i = 0; i < lod.length; i++) {
            System.out.printf("%20d%25s", lod[i], "");
            qod[i] = in.nextInt();
            sod[i] = lod[i] * qod[i];
        }

        //calculate the total of all the denominations
        grandTotal = findGrandTotal(sod);


        // print out the grand total
        System.out.print("Total = RM " + grandTotal);
    }

    public static int findGrandTotal(int[] sod) {
        int gt = 0;
        for (int i = 0; i < sod.length; i++) {
            gt += sod[i];
        }
        return gt;
    }
}
