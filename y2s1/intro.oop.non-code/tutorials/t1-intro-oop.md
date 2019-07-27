## Tutorial 1: Introduction to Object-orientation

1. How does structured design work?
   1. You have one system, systems have many different problems. 
   2. Divide all the problems into smaller pieces.
   3. Solve each problem individually.
   4. Combine all the solutions for individual parts.
2. What is the first step in the problem-solving process of object-oriented design?
   1. Identify the objects
3. Think of a business process and identify the main objects for the business process.
   1. Input ("who"): Staff, Employee, Supplier
   2. Process ("building, make decisions"): Resume, Job listing
   3. Output ("product"): Hiring decision
4. What is a method in the context of object-oriented programming?
   1. A method is an action that can be carried out by a class.
5. An example of a predefined class in the Java library is the Scanner class.
   1. Explain the steps that need to be included in a program in order to obtain console input using a Scanner object.
      1. Create a Scanner object
      2. Use the Scanner object to receuive input from user
   2. Illustrate the steps by writing a program called showOddNumber that requests the user to enter TWO (2) values that represent minNum and maxNum. The program should display all the odd numbers in between these two numbers inclusive and the sum of these odd numbers.

```java
import java.util.Scanner;

public class showOddNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner (System.in);
        System.out.print("Enter the minimum number: ");
        int minNumber = input.nextInt();
        System.out.print("Enter the maximum number: ");
        int maxNumber = input.nextInt();
        int sum = 0;
        for (int i = minNum; i < maxNum; i++)
        {
            if (i % 2 == 0)
            {
                System.out.println(i);
                sum += i;
            }
        }
        System.out.println("The sum of the odd number is " + sum);
    }
}
```
## Exam

Have question similar to Q5, sometimes need to remember the construction of the whole program.