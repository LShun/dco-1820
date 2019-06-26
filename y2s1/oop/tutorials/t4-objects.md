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

