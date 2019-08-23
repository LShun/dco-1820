# Chapter 1: Intro to Object-oriented programming

## Structured design

**Structured design**: Divide problem into smaller segments.

### Steps of structural design

1. Divide
2. Analyze each subproblem
3. Combine all solutions of subproblems

## Object oriented design

### Steps

1. Identify objects
2. Specify relevant data & possible operations for each object
3. Determine how objects interact with each other

## Object characteristics

Each object contains
- Data
- Operations (possible) on data

Final program: Collection of interacting objects

## OOP's 3 basic principles

- **Encapsulation** - ability to combine data & operations in single unit (put data & operations into a capsule)
- **Inheritance** - ability to create new types from existing types (child share parent properties)
- **Polymorphism** - ability to use same expressions to denote different operations.

## Classes

- Encapsulation is accomplished via data types called classes
- For each class, decide:
  - data fields (variables)
  - methods (functions for operations)

## Introduced classes

- `Scanner` class
  - `next()` (takes in one word only)
  - `nextLine()` (takes in entire line)
  - `nextByte()`
  - `nextShort()`
  - `nextInt()`
  - `nextLong()`
  - `nextFloat()`
  - `nextDouble()`
  - `nextBoolean()`

## Console input & output redirection

`C:\java Class < input.txt > out.txt`

## Formatting Output

`printf` syntax: `System.out.printf(format,items);`

`format` is a string with format specifiers
`items` comma separated list of values following the order specified in the `format`

Example: `System.out.printf(“Sales: Qty:%d, Amt:RM%.2f\n”, quantity, salesAmt);`
Assuming that both `quantity` and `salesAmt` is defined

## Character Data Types

- Java characters use **Unicode**
- Example `\u0041`

## Other data types

Similar to C, with the exception that `String` is now a predefined class. Note that however, it is still a `reference type` (similar to C in underlying workings, a string of chars)

## String concatenation

Similar to C, however, all non-string data types will be "converted" into strings first *literally* before being appended.

Ways:
- Use `+` operator, appended literally, supports multiple data types
- Use `concat()`, only string data

Example:
- `String s = "Chapter 2" + 2;` --> `Chapter 22`

## Java naming conventions

### Variables & methods names

- Follow camel-casing

### Class name

- Capitalize first letter of every word
- Example : `ComputeArea`

### Constants

- Capitalize all words, use underscores to connect words
- Example: `PI` and `MAX_VALUE`

## Type casting

- **Explicit cast**: Use functions to "forcefully" convert
- **Implicit cast**: Casting made by the compiler without explicitly stated by user to fix "acceptable inconsistencies" (eg: assigning an `int` to a `float`)

## Exams

The questions for the size of the data types will never be asked

Basic imports, basic input output usually will not come out in test.

Scanner is very important.