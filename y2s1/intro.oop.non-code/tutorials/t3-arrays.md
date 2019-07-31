# Tutorial 3: Arrays

1. Which of the following statements are invalid? Explain why.
   1. `float number[];`
      1. Valid
   2. `int[] number = [1, 2, 3, 4];`
      1. Invalid, the `[]` should be `{}`.
   3. `double[] number = new double[23];`
      1. Valid.
   4. `float number = {1.0, 2.0f};`
      1. Invalid, the `float` should be `float[]`
   5. `number = new array[23];`
      1. Invalid. the `array` should've been a data type, and `array` is not one.
   6. `double [] number = new double[] {3,5,6,9};`
      1. Valid.

2. Consider the following program segment. Determine the output at line 4 and 5. What happens at line 6?

```java
1. int x = 30;
2. int [] numbers = new int[x];
3. x = 60;
4. System.out.println("x is " + x);
5. System.out.println("The size of number is " + numbers.length);
6. System.out.println(numbers[30]);
```

Output at line 4:

`x is 60`

Output at line 5:

`The size of number is 30`

At line 6:

it will print out `{}`.

3. Identify and fix the errors in the following code:

```java
1 public class Q5 {
2   public static void main(String[] args) {
3       double[100] r;
4
5       for (int i = 0; i < r.length(); i++);
6           r(i) = Math.random * 100;
7   }
8 }
```

Answer:

```java
1 public class Q5 {
2   public static void main(String[] args) {
3       double[] r = new double[100];
4
5       for (int i = 0; i < r.length; i++);
6           r[i] = Math.random() * 100;
7   }
8 }
```

Errors: Line 3, does not have `[]`
        Line 5, the `length` should not have bracket because it is not a function
        Line 6, `r(i)` should be `r[i]`
        Line 6, `Math.random` should be `Math.random()` because it is a function

4. Consider the segment of code shown below.
When is the memory allocated for the array myList?
Does the statement in Line 3 resize the array?

```java
1 int[ ] myList;
2 myList = new int[5];
3 myList = new int[10];
```

- The memory is allocated for the array myList in both line 2 and line 3.
- Yes, although it does not copy the old list.

5. What is wrong with the following method that aims to fill an array with random numbers?

```java
1. public static void fillWithRandomNumbers(double[] values){
2.  double[] numbers = new double[values.length];
3.  for (int i = 0; i < numbers.length; i++)
4.      numbers[i] = Math.random();
5.      values = numbers;
6. }
```

Answer: The problem lies in that the array being passed in is completely unchanged on the memory address space. By pointing `values` to where `numbers` is pointing, the old array `values` was pointing lost its tracking pointer, and did not updated.

6. Write a method that returns the average of an array of integers. Use for-each loop.

```java
public static double average(int[] aoi) {
    double total = 0;
    for (int i: aoi) {
        total += aoi[i];
    }
    return (double) total / aoi.length;
}
```

7. Write a method that returns the largest element in an array of integers. Use for-each loop.

```java
public static int largest(int[] aoi) {
    int largest = aoi[0];
    for (int i: aoi) {
        if (largest < i) {
            largest = i;
        }
    }
    return largest;
}
```

8. Which of the following statements are valid array declarations? Explain why.

(a) `int[] array = {{1, 2}, {2, 3}, {6, 1}} ;`
(b) `double[][] array = new double[2][7];` 
(c) `int[][] = new array[][];`

Answer:

(a) is invalid because the array only supports 1 level of assignment
(b) is valid
(c) is invalid, because the size is not specified for a definition.


## Exam tips

In exam also will come out 2D arrays.
IN exam will come out minimum and maximum value.
In exam will come out `for-each`, if say `for-each` and you use `for` loop, instant 0 marks.

