# Tutorial 2 Methods

1. Define and provide an illustration for each of the following:
(a) Parameter

```md
A parameter is a value that you can pass to a method in Java. Then the method can use the parameter as though it were a local variable initialized with the value of the variable passed to it by the calling method.
```

```java
public static void main(String args[]);

//args[] is an example of a parameter
```

(b) Argument

```md
The arguments are the data you pass into the method's parameters.
```

```java
calculateTax(500);

// 500 is an example of an argument
```

(c) Method signature

```md
A method signature is the method name and the number, type and order of its parameters.
```

```java
public void setMapReference(int xCoordinate, int yCoordinate)
{
//method code
}

// the method signature is setMapReference(int xCoordinate, int yCoordinate)
// in other words, the name & the parameter list of two integers
```

(d) Method overloading

```md
Method Overloading is a feature that allows a class to have more than one method having the same name, if their argument lists are different. 
```

(e) Method abstraction

```md
Method abstraction refers to the design of a method where there is no default implementation for it and a separate implementing class will provide the details.
```

2. (a) Write a method that takes a integer-typed parameter representing a year and tests
whether it is a leap year. In the Gregorian calendar, 3 criteria must be taken into
account to identify leap years:
 The year is evenly divisible by 4;
 If the year can be evenly divided by 100, it is NOT a leap year, unless;
 The year is also evenly divisible by 400, then it is a leap year.
The Gregorian calendar internationally the most widely used civil calendar, is
named for Pope Gregory XIII, who introduced it in 1582.
Examples of leap years: 1500 and 2000 (1500 is leap year since it was before 1582,
the adoption year of Gregorian calendar)
Examples of non-leap years: 1800, 1900, 2100, 2200

```java
    public static boolean LeapYear(int year) {
        if (year < 1582) {
            return true;
        }
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                }
            }
        }
        return false;
```

(b) Write a main method to prompt a user to enter a year and then invoke your method
from part (a).

```java
public static void main(String args[]) {
        System.out.println("Please enter a year: ");
        Scanner sc = new Scanner(System.in);
        System.out.println(LeapYear(sc.nextInt()));
    }
}
```

3. Write a class that contains 3 overloaded computeNetPay() methods as described below:
 The first one receives 3 values representing hours worked, hourly pay rate and tax
deduction rate
 The second method receives 2 values representing hours worked and hourly pay rate,
and the tax deduction rate is assumed to be 15%.
 The last method receives 1 value representing the hours worked, the hourly pay rate
and tax deduction rate will have the default values of RM8.50 and 15% respectively.
Write another class with a main method to invoke each of the overloaded methods.

```java
public class ComputePay {
    public static void main(String args[]) {
        double hours = 12;
        double tax = 6;
        double pay = 12.00;

        System.in.println(computeNetPay(hours, pay, tax));
        System.in.println(computeNetPay(hours, pay));
        System.in.println(computeNetPay(hours));
    }
    public static double computeNetPay(int hours, double pay, double tax) {
        return hours * pay * (100 - tax);
    }
    public static double computeNetPay(int hours, double pay) {
        double tax = 6
        return hours * pay * (100 - tax);
    }
    public static double computeNetPay(int hours) {
        double pay = 12.00;
        double tax = 6;
        return hours * pay * (100 - tax);
    }
}
```

4. The UML class diagram below lists some of the methods available in the java.lang.Math
class.
java.lang.Math
+max(a: int, b: int): int Returns the maximum of two parameters
+min(a: double, b: double): double Returns the minimum of two parameters.
+pow(a: double, b: double) : double Returns a raised to the power of b.
+random() : double Returns a random double value in the range [0.0, 1.0].
+round(x: float) : int x is rounded down to its nearest integer.
+sqrt(a: double) : double Returns the square root of a.
Using appropriate methods from the Math class, write an expression for each of the
following:
(a) Return the largest number of 3 integers (x, y and z)

```java
public static int maxOfThree(int a, int b, int c) {
    return max(c, max(a, b));
}
```

(b) Return the smallest number of 3 floating point numbers (p, q and r)

```java
public static int maxOfThree(int a, int b, int c) {
    return min(c, min(a, b));
}
```

(c) Return the number √ x

```java
public static double SqrtReciprocal(double x, double y) {
    return sqrt(pow(x, 1/y));
}
```

(d) Generates a random integer number that greater than or equal to 0 and 100.

```java
public static int randomInt() {
    return ((int) (round (random() * 100)));
}
```

5. Write a program that performs the following simulation :

 Generate 20 random number representing students’ test marks in the range 0 and 100.
 Compute the count of the test marks, the average and the standard deviation.
Use the following formula for computing the standard deviation:

```java
import java.lang.Math;

public class AvgStdDev {
    public static void main(String args[]) {
        double sum = 0;
        double sumSquared = 0;
        int studs = 20;

        for (int i = 0; i < studs; i++) {
            current = (int) (round (random() * 100));
            sum += current;
            sumSquared += pow(current, 2);
        }

        double average = sum / studs;
        double stddev = sqrt((sumSquared) - (1/studs) * (pow (sum, 2) / (n - 1)));

        System.out.println("Average: " + average);
        System.out.println("Standard Deviation: " + stddev);
    }
}
```
