# Chapter 2: Methods & Exception Handling

1. **Method**: **function** in Java.
2. **Method signature**: Method name + parameter list
   1. Eg: `max(int num1, int num2)`
3. **Formal parameters**: Variables defined in method header
   1. Eg: `int num1`
4. **Actual parameters**: The passed value, or an **argument** to a parameter of a method.
5. **Passing parameters**: Argument must match **order, number, compatibility**
6. **Pass by value**: Variable used **not affected** regardless of change made to passed parameter.
   1. Eg: Pass `p` to `date`, you can access both `p` and `date`, modify `date`, `p` is unchanged
7. **Return value type**: Data type of value the method returns

## Caution

For now, a `return` statement must be present within an `else` or exist as an individual statement to ensure a `return` can be reached regardless of anything.

## Modifiers

Reserved words, specify **data, methods, and class** and their usage.

Examples:
1. `public`
   1. Can be accessed by other programs
2. `private`
   1. Opposite of `public`
3. `static`
4. `final`: constants

## Method overloading

2 or more methods with same name, different parameter lists

Can be different:
1. type
2. no. of parameters

Java compiler determine which version using *method signature*

## Ambiguous Invocation

Two or more possible matches for invocation, cannot determine match.

Example: Two functions accept `int` and `double` in different order. Sending two `int`s work on both functions.

## Scope of local variables

- Local variables start from declaration till end of block containing the variable.
- Parameter is also local variable, covers entire method
- Put it simply, local variables try to be as `local` as they can. If you're wondering whether they should have a bigger or smaller coverage, the smaller one is usually a safe bet.
- local variables can be declared multiple times in different non-nesting blocks in a method.

## Method Abstraction

Think of it as a black box, you only know what to put in, not what's inside.

## Benefits of methods

1. Write once, use it everywhere
2. Hides implementation from user
3. Reduce complexity

## `Math` Class

1. Contains basic mathematical constants & methods
2. Common:
   1. Class constants:
      1. PI
      2. E
   2. Class methods
      1. Trig methods (including arc-variants)
      2. Exponent methods
      3. Rounding methods
      4. `min`, `max`, `abs`, `random` methods
      5. `pow`, `sqrt` methods
3. `min`, `max` takes in 2 arguments
4. `random` generates between 0<=x<1.0
   1. generally, `a + Math.random() * b`
      1. where `a` is the lowest value possible generated, and the highest value generated is always below `b`

## Exception handling

**exception handler**: automatically executed when error occurs

Keywords (total 5, 2 are covered in exams):

1. `try`
2. `catch`
3. `finally`, located after `try` and `catch`, execute regardless of what happens

`try` and `catch` works together as two separate blocks, when `try` fails, `catch` starts its work.

Exam usually won't ask `finally` (what a pun), just `try` and `catch`.

