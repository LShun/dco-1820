# Tutorial 6: Inheritance and Polymorphism

1. **Explain the usage of the keyword `super`. Your answer must be supported by relevant example of code**

  > 1. The keyword `super` is used to refer to the immediate superclass of the instance variable.
  > 2. Example: `super.toString()`

2. **What is the output of running class C? Explain your answer.**

   ```java
   public class A {
    public A() {
    System.out.println("A");
    }
   }
   ```

   ```java
   public class B extends A {
    public B() {
    System.out.println("B");
    }
   }
   ```

   ```java
   public class C {
    public static void main(String[] args) {
    B b = new B();
    }
   }
   ```

   > **Output: **
   >
   > A
   >
   > B
   >
   > **Explanation**: The superclass constructors construct the superclass portion of the constructor. The subclass constructors construct the subclass portion of the constructor. When the program is compiled, the entire program is assembled before the program is ran. Therefore, since superclass is always 'on top' of subclasses, superclass's instruction will always be called first.

3. **What is the result of attempting to compile and run the following program? Explain your answer**

   ```java
   public class Employee {
    public Employee(String nm) {}
    }
   public class Manager extends Employee {
    }
    public class Test {
   public static void main(String[] args) {
    Manager mgr = new Manager();
    }
    }
   ```

   > **Error.** This is because `Employee`'s constructor requires parameters to pass in.

4. **Give the output of the class below. Explain how it works.**

   ```java
   public class C {
    public static void main(String[] args) {
    Object[] o = {new A(), new B()};
    System.out.print(o[0]);
    System.out.print(o[1]);
    }
   }
   class A extends B {
    public String toString() {
    return "A";
    }
   }
   class B {
    public String toString() {
    return "B";
    }
   }
   ```

   > Output: AB
   >
   > 
   >
   > When the main function is executed in the `C` class, an array of consisting of `A()` and `B()` is created, and both of them are accessed one-by-one.
   >
   > When the `A()` is executed, the `toString()` function in A is defined. The superclass constructor from B is then called, which attempts to define the superclass's `toString()` method, but fails to do so due to method overriding from the A subclass.
   > When the `B()` is executed, the `toString()` function in B is defined.

5. Differentiate between method overriding and method overloading.

   > **Method overriding**: 
   >
   > - Method overriding requires the method to have the exact same signature and return type.
   > - Provide functionality to override behavior of class inherited from parent class
   >
   > **Method overloading:** 
   >
   > - Method overloading requires the method to have the same name, but can be different signature and return type. 
   > - Provide functionality to reuse method name

6. The following UML diagrams represent the classes in TAR Bank, where the `FixedDepositAccount` and `OverdraftAccount`classes are subclasses of the Account class. 
   ![Account UML Diagram](img/Account-img-T6Q6)

   1. Implement the `FixedDepositAccount` class

      ```java
      public class FixedDepositAccount extends Account {
          private int savingYears;
          
          public FixedDepositAccount()
      }
      ```

      

   2. Write the constructor for the `OverdraftAccount` class. It should define the overdraft information according to the account type as shown in Table 1.

   3. Implement the `cashOut` method of the `OverdraftAccount` class. If the overdrawn balance reaches the overdraft limit, the withdrawal will fail, and the current balance is returned. A proper message should be shown for both situations.

   4.  

   5.  

   6. Define polymorphism and illustrate how the concept of polymorphism is applied in the classes Account, FixedDepositAccount and OverdraftAccount.

      1. Polymorphism refers to the generalization of methods so that one method name can refer to multiple operations under a single class.

   7. 
   
7. 

   1. | Private                                                      | PROTECTED                                                    |
      | ------------------------------------------------------------ | ------------------------------------------------------------ |
      | Only available to be accessed within the class that defined them | Accessible in the class that defines them and in other classes which inherit from that class. |

8. Error, because parent cannot fit into child class

9. ABC
   A -> m1 (Aa) => A

   ^
   |
   B -> m1(Bb) => B
   ^

   |
   C -> m1 (Cc) => C
   ^

   |

   D -> m1(Dd) => D

   Basically go bottom up.

   

10. Differences between 

    | Final variable               | Final method                                                 | Final class                                                  |
    | ---------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
    | Final variable is a constant | Final method is a method that cannot be overridden by any subclasses | Final class is a class that cannot be extended or inherited. |

    

