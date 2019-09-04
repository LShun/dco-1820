package Practical1;

import java.util.Scanner;

public class p1q1_Welcome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name: ");
        String name = sc.nextLine();
        System.out.println("Enter your year of study: ");
        int year = sc.nextInt();
        System.out.println("What is your target GPA for this semester?: ");
        float gpa = sc.nextFloat();

        System.out.println("Welcome " + name + "!\n" +
                "Work hard to achieve your target GPA of " + gpa + " this semester of your Year " + year + ".");
    }
}