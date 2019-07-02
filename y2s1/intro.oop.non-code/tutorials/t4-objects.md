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

Constructors are invoked using the new operator when an bject is created. Constructors plays the role of initializing objects.

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

## Question 7



### Q7a

| Instance Variable                                                                                                                                                      | Static variable                                                                     |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| Instance variable can be accessed by calling the variable name inside the class. However, within static methods, they should be called using the fully qualified name. | Static variable can be accessed by calling with the cla name. Eg: Customer.num = 2; |

### Q7b



When to use instance and when to use static. For static we can direct use the class name and direct call in. But for instance, we can directly get the values. However for the instances we need to create the obkect to call the values.

When we craete the instance, make sure all the getters and setters are based on what we create.

If you put static, for the methods you also have to create as static. (Static must go along with static).

For static, you need to use the objects to get it. For non-static, you can access it directly through the class.


