# Chapter 3: Arrays

## Table of contents

- [Chapter 3: Arrays](#Chapter-3-Arrays)
  - [Table of contents](#Table-of-contents)
  - [Tips](#Tips)
  - [Arrays](#Arrays)
    - [Declaring arrays](#Declaring-arrays)
    - [Creating arrays](#Creating-arrays)
    - [Array initialization](#Array-initialization)
    - [Array initializers](#Array-initializers)
    - [Array properties](#Array-properties)
    - [Copying arrays](#Copying-arrays)
      - [`arraycopy()`](#arraycopy)
    - [Passing Array to methods](#Passing-Array-to-methods)
    - [Anonymous Array](#Anonymous-Array)
  - [`foreach` loop](#foreach-loop)
  - [Pass by value and by reference](#Pass-by-value-and-by-reference)
    - [Pass by value](#Pass-by-value)
    - [Pass by reference](#Pass-by-reference)
  - [Stack and Heap](#Stack-and-Heap)

## Tips

Ignore all optional topics, they wont come out in exams

## Arrays

- Data structures that represent a collection of data with same type.
- Once they are created, its size cannot be changed
- Array indices are 0-based, and can be referred by: `arrayRefVar[index]`. `index` is an integer.
- By default, on creation, arrays will have these value:
  - `0` for numeric data types
  - `\u0000` for `char`-typed arrays
  - `false` for `boolean`-typed arrays

### Declaring arrays

- `datatype[] arrayRefVar;` < preferred. Reading as: `arrayRefVar` is a variable with datatype of `datatype` array.
- `datatype arrayRefVar[];` < not preferred (the first option indicates the data type clearer). Reading as: `arrayRefVar` is an array with `datatype`.

### Creating arrays

Syntax:

```java
arrayRefVar = new datatype[arraySize];
```

where `datatype` is a data type, `arraySize` is an integer.

### Array initialization

```java
datatype[] arrayRefVar = new datatype[arraySize];
```

### Array initializers

Declaring, creating and initializing in 1 step.

```java
datatype[] arrayRefVar = {values, seperated, by, commas};
```

Note: 
- in this case, the `new` operator is NOT required
- The shorthand notation `{}` can only be used together, splitting them will cause syntax error.

### Array properties

`length` gets the size of the array.

### Copying arrays

- Use a loop
- Use `arraycopy()` method from `java.lang.System`

#### `arraycopy()`

Note: `arraycopy()` do not allocate any memory space, a memory space MUST be given beforehand.

Syntax:

```java
arraycopy(sourceArray, src_position, targetArray, target_position, length);
```

### Passing Array to methods

Inside the parameter specifier, proper notation must be used, `datatype[] identifier`

### Anonymous Array

Arrays can be created without an explicit reference, useful if its going to be passed directly into a function.

Syntax:

```java
new dataType[]{contents,seperated,by,comma};
```

where `dataType` is a valid data type.

## `foreach` loop (This is so important that you can stick it on your refrigerator)

Traverses entire array sequentially without index variable.

Syntax:

```java
for (dataType varName: array) {
    ... varName;
}
```

## Pass by value and by reference

### Pass by value

A duplicated copy is passed to a method.

- Java use `pass by value` to pass arguments to method

### Pass by reference

A "map" to the same copy is passed to a method.

- By default, java use `pass by reference` to pass an array to a method

## Stack and Heap

A computer has two main parts of memory, which are `Stack` and `Heap`.

`Stack` is considered very fast, but small memory. Put it this way, its easier to look for something within 10 numbers than within 100.

`Heap` is considered slower, but larger memory.

By default, all arrays are stored on the `heap`, while pointers, and other smaller data are stored on the `stack` to improve performance. Because once you "locate" something, it takes the same amount of time to access it because they are still part of the computer memory.

