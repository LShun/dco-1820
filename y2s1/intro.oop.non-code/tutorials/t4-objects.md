# T4 Objects and classes

## Question 1

### Part A: Relationship between classes and objects

A class is a factory for creating objects. Classes are the content that define objects.

Example:

```java
public class Employee {
    String name;
    String address;

    get/set
}
```


### Part B: Object and constructor

Constructors are invoked using the new operator when an object is created. Constructors plays the role of initializing objects.

Example:

```java
public class Staff {
    
}
```

## Question 3

Exam for sure will have, to be safe, write getter and setter even though it is public and `getter` is not necessary.

### Question 3a

Methods are used to modify private properties, for example setter or set methods (mutator).

Has the following method signature:

```java
public void setPropertyName(data type property value)
```

### Question 3b

Methods used to read private properties, as known as getter or get methods. (Accessor)

```java
public class Employee {
    public String name;

    public void setName(String name)
}
```

## Question 4

```java
1 public class Question {
2   private int no1;
3   int no2;
4
5   // constructor
6   public void Question(int a, int b) {
7       no1 = a;
8       no2 = b;
9   }
10
11  public void sum() {
12      return no1 + no2;
13  }
14 }
15
16 class TestQuestion {
17  public static void main(String[] args) {
18      Question q = new Question();
19      q.no1 = 1;
20      q.no2 = 2;
21      System.out.println("Sum = " + q.sum);
22 }
```

Line 06: It is (specified) a constructor, must not have `void`
Line 12: Void functions cannot return any value, must change to `int`
Line 18: `Question()` must have parameters inside because the class only have one constructor
Line 19: Must use a setter function
Line 21: Sum is a method, not a variable, and therefore must be called with sum().


## Question 5

```java
public class Customer{
 private static int lastAssignedNumber = 1000;
 private String custNo;

public Customer() {
 custNo = lastAssignedNumber;
lastAssignedNumber ++;
}
// parameterized constructor
}
With the aid of a diagram, illustrate how memory is allocated in the system for the following
statements:
Customer c1 = new Customer ();
Customer c2 = new Customer ();
```

## Question 6


### Question 6a


### Question 6b

```java
public class Q6b {
    public static void main(String args[]) {
        Airplane a1 = new Airplane();
        Airplane a2 = newAirplane("XY2000", 250000, 2005, 100);
        a1.setId("AWX003");
        a1.setNameOfPassenger(190)
        System.out.println(a1.toString() + a1.calCurrentVal());
        System.out.println(a2.toString() + a2.calCurrentVal());
    }
}
```

## Question 7

### Q7a

| Instance Variable                                            | Static variable                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Instance variable can be accessed by calling the variable name inside the class. However, within static methods, they should be called using the fully qualified name. | Static variable can be accessed by calling with the class name. Eg: Customer.num = 2; |

### Q7b

When to use instance and when to use static. For static we can direct use the class name and direct call in. But for instance, we can directly get the values. However for the instances we need to create the object to call the values.

When we create the instance, make sure all the getters and setters are based on what we create.

If you put static, for the methods you also have to create as static. (Static must go along with static).

For static, you need to use the objects to get it. For non-static, you can access it directly through the class.

*To put it simply. A variable should be implemented as an instance variable if we do not want the values to be inherited by the other objects with the same class. However a variable should be implemented as a static variable if we intend the values to be inherited by the other objects with the same class.*

## Question 9

| Public | Private |
|---|---|
| Public means you can access it anywhere. | Private means you can only access it inside its own class. |

## Question 10

You are working for TAR Bank. As a programmer, you are required to write a Java class to store bank account information as shown in the class diagram below:

### Question 10(a)

Explain why the `balance` data field has been made private. What would be the problems if it has been made public?

> The value `balance` has to be encapsulated in the object itself. This is to prevent direct access by other classes. 

> If the class has been made public, then other classes can simply access to the data field and update the `balance` without going through the proper procedures.

### Question 10(b)

Why is it useful to declare `annualInterestRate` as `static`?

The annual interest for all accounts of a certain type are fixed. Therefore, it makes it easier to set and modify all the annual interest rate at once in the future.

### Question 10(c)

```java
public class Account {
    private int accountNo;
    private String accountHolderName;
    private double balance;
    static int accountCount;
    private static double annualInterestRate;

    public Account(int accountNo, String accountHolderName, double balance) {
        this.accountNo = accountNo;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
        accountCount++;
    }

    public int getAccountNo() {
        return accountNo;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }

    public double getBalance() {
        return balance;
    }

    public int getAccountCount() {
        return accountCount;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }


    public void setAccountHolderName(String accountHolderName) {
        this.accountHolderName = accountHolderName;
    }

    public static void setAnnualInterestRate(double annualInterestRate) {
        Account.annualInterestRate = annualInterestRate;
    }

    public void cashIn(double cash) {
        this.balance += cash;
    }

    public void cashOut(double cash) {
        this.balance -= cash;
    }

    public double calculateinterest() {
        return this.balance * annualInterestRate;
    }
}
```

### Question 10(d)

```java
import java.util.Scanner;

public class AccountDriver {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        Account acc1 = new Account(909, "Ali Baba", 1000);
        int choice;

        while (true) {
            System.out.print(
                    "Main Menu\n" +
                            "1: Check balance\n" +
                            "2: Cash In\n" +
                            "3: Cash Out\n" +
                            "4: Interest\n" +
                            "5: Exit\n" +
                            "Enter a choice : "
            );

            choice = in.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Your current balance: " + acc1.getBalance());
                    break;
                case 2:
                    System.out.print("Enter amount of cash in: ");
                    acc1.cashIn(in.nextDouble());
                    System.out.println("New balance: " + acc1.getBalance());
                    break;
                case 3:
                    System.out.println("Enter amount to cash out: ");
                    acc1.cashOut(in.nextDouble());
                    System.out.println("New balance " + acc1.getBalance());
                    break;
                case 4:
                    System.out.println("Your interest amount: " + acc1.calculateinterest());
                    break;
                case 5:
                    return;
            }
        }
    }
}

```

## Question 11

Explain clearly the following terms:

(a) Class abstraction

> Its main goal is to handle complexity by hiding unnecessary details from the user. That enables the user to implement more complex logic on top of the provided abstraction without understanding or even thinking about all the hidden complexity.

(b) Class encapsulation

> It refers to the bundling of data with the methods that operate on that data. Encapsulation is used to hide the values or state of a structured data object inside a class, preventing unauthorized parties' direct access to them.

## Question 12

### Question 12a

The object-oriented approach organizes programs in a way that mirrors the real world, in which all objects are associated with both attributes and activities. Compare the object oriented and procedural paradigm.

| Procedural paradigm | Object Oriented |
|---|---|
| Data and methods are loosely coupled | Couples data and methods together into objects. |
| Software design focuses on designing methods | Software design focuses on objects and operation on objects |
| As data and operations are separate, this methodology requires sending data to methods. | Places data and the operations pertaining to the data within a single entity called an object. |

### Question 12b

Describe any TWO (2) benefits of object-oriented programming over procedural programming.

**Benefit 1:** Better access control compared to 

## Question 13

```java
public class Item {
    
}
```