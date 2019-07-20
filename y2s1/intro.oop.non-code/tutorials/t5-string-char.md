# Tutorial 5: Classes for Strings

## Question 1

### String objects in Java are immutable. Demonstrate what you understand about immutable objects by **illustrating how memory is allocated** during the execution of the program segment below. You must also **indicate the output** of the program segment. 

1. **Output**

   ```java
   s1==s2 is not true
   
   s2==s3 is not true
   ```

## Question 2

### Give the output of the code below:

```java
String s1 = "I Love TAR College Very Much !";
String OOP1 = new String("Introduction to OOP");

System.out.println("ii) " + s1.charAt(19));
System.out.println("iii) " + s1.equalsIgnoreCase("much"));
System.out.println("iv) " + s1.replace('e', 'x'));
System.out.println("v) " + s1.length());
System.out.println("vi) " + s1.indexOf("ege"));
System.out.println("vii) " + s1.lastIndexOf("very", 5));
System.out.println("Sub: " + OOP1.substring(2,8));
```

### Answer

```java
ii) V
iii) false
iv) I Lovx TAR Collxgx Vxry Much !
v) 30
vi) 15
vii) -1
Sub: troduc
```

## Question 3

### Illustrate how memory is allocated during the execution of the program segment below, and determine the output

```java
String s1= new String ("Demo");
String s2 = s1;
String s3= new String (s1);
String s4= new String ("demo");
if (s1 == s2)
 System.out.println("s1 == s2");
if (s1 == s3)
 System.out.println("s1 == s3");
if (s1.equals(s3))
 System.out.println("s1 equals s3");
if (s1.equals(s4))
 System.out.println("s1 equals s4");
if (s1.equalsIgnoreCase(s4))
 System.out.println("s1 equals (ignore case) s4");
```

Output:

```java
s1 == s2
s1 equals s3
s1 equals (ignore case) s4
```

## Question 4

### Suppose the user name of a librarian cannot have any empty space and must have at least 6 characters. Write a method that accepts a user name and performs the necessary validations. The method returns true if the user name is valid, otherwise it returns false. 

### You may need to use some of the following methods in the `String `class

| Method header         | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| `int length()`        | Returns the length of this string.                           |
| `int indexOf(int ch)` | Returns the index within this string of the first occurrence of the specified character, or return -1 if no such character occurs in the string. |

```java
import java.util.Scanner;
public static boolean validateUsername(void) {
   Scanner in = new Scanner(System.in);
    String user = in.nextLine();
    
    if (user.length() >= 6) {
        if (user.indexOf(' ') == -1) {
            return true;
        }
    }
    return false;
}
```

## Question 5

Write a method called validateCreditCardNumber that validates whether a credit card
number is valid or not. A valid credit card number consists of 16 digits. So, your method should
return true if a credit card number has 16 digits and no other characters. The formal parameter,
creditCardNumber, should be of String type. (Hint: You may need to use the following
methods.)

| Class     | Method                     | Description                                       |
| --------- | -------------------------- | ------------------------------------------------- |
| String    | `int length()`             | Returns the length of this string.                |
| String    | `char charAt(int index)`   | Returns the char value at the specified index.    |
| Character | `boolean isDigit(char ch)` | Determines if the specified character is a digit. |

```java
public static boolean validateCreditCardNumber(String ccNum) {
    if (ccNum.length() != 16) {
        return false;
    }
    
    for (int i = 0; i < ccNum.length(); i++) {
        if (Character.isDigit(ccNum.charAt(i)) == false)
            return false;
    }
    
    return true;
}
```

##  Question 6

```JAVA
public static boolean validateID(String loginID) {
        // Has between 6 and 10 characters
        if (loginID.length() < 6 || loginID.length() > 10) {
            return false;
        }
        // Begins with an uppercase letter
        if (Character.isUpperCase(loginID.charAt(0)) == false) {
            return false;
        }
        // Consists of only letters and digits
        for (int i = 0; i < loginID.length(); i++) {
            if (Character.isLetter(loginID.charAt(i)) == false) {
                if (Character.isDigit(loginID.charAt(i)) == false) {
                    return false;
                }
            }
        }
        // Contains at least one lowercase letter and at least one digit
        for (int i = 0; i < loginID.length(); i++) {
            if (Character.isLowerCase(loginID.charAt(i))) {
                for (int j = 0; j < loginID.length(); j++) {
                    if (Character.isDigit(loginID.charAt(j))) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
```

## Question 7

| No.  | StringBuffer                                                 | StringBuilder                                                |
| ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1)   | StringBuffer is *synchronized* i.e. thread safe. It means two threads can't call the methods of StringBuffer simultaneously. | StringBuilder is *non-synchronized* i.e. not thread safe. It means two threads can call the methods of StringBuilder simultaneously. |
| 2)   | StringBuffer is *less efficient* than StringBuilder.         | StringBuilder is *more efficient* than StringBuffer.         |

## Question 8

```java
// Output
Java
Java and HTML
```

