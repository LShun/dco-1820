# C4: Exception Handling

## Motivations

- TL;DR: Avoiding that "oh shit" feel when your teacher found out that **runtime error**.

## Types of Errors

- Syntax, Runtime, Logic

### Syntax

- Not following rules of language
- Detected by compiler
- Easy to detect & correct

### Runtime

- Environment detects impossible operation when running program

### Logic error

- Wrong results

## Exceptions

- **Runtime error**, indicate problem during execution.
- Examples:
  - Invalid input
  - File does not exist
  - Out-of-bound array element

### Exception Handling

- Mechanism to handle exceptions
- Prevents abnormal behavior of program

#### Benefits

- Program can continue/terminate gracefully
- Robust & fault-tolerant
- Allow removal of error-handling code from "main line" of execution.
  - Improve clarity
  - Enhance flexibility

### Types

#### System Errors, part of `Error` class (Unchecked)

- Internal system error
- Almost nothing can do except notify user.

#### Exceptions, part of `Exception` class (Checked)

- Your program or external factors fault.
- Can be caught and handled.

#### Runtime Exceptions, part of `RuntimeException` class (Unchecked)

- Programming errors
- Thrown by JVM.

#### Unchecked exceptions

- Compiler don't ensure they're present in code.
- Basically `RuntimeException` , `Error` and their subclasses. Everything else checked.

#### Checked exceptions

- AKA my way or the highway. 
- Enforce a catch-or-declare requirement.
- Syntax error if missing.

### Dealing with exceptions

- Declaring: `throws` 
- (Re)throwing: `throw` 
- Catching: `try-catch`

- Finally: `try-catch-finally`

#### Declaring exceptions

- Definition: Stating what checked exceptions a method might throw.
- Example: (Eg: `method() throws X,Y,Z`)

#### Throwing exceptions

- Upon error, program will create an instance of appropriate exception type and throw it.

- Syntax:

  - `throw new X()`,

  - ```java
    X ex = new X();
    throw X;
    ```

#### Catching exceptions

- If multiple matching catch blocks, use first matching catch block.
- Ex: `try {} catch (ClassType X){} catch (ClassType X){}`
- Catching order is *important*, 
  - if catch blocks are under one class, more specific catch block must come before general.
- Catch-or-declare mechanism (for checked exceptions)
  - In 'defining' block, must declare. Eg: `void p1() throws Exception`
  - In 'calling' block, must catch. Eg: `try { p1() } catch (Exception e) {...}`

#### Rethrowing Exceptions

- Throwing exceptions in 'catching' block, hence the 'rethrow'.

#### `finally` clause

- Optional, placed after last `catch` block.
- Usually used in I/O programming to release resources (E.g.: `output.close()`)
- Executed regardless of any exceptions (unless exit early via `System.exit()`)

## Exceptions in GUI

- Methods are executed on threads. If exception = kill thread, then print message on console.
- GUI = many threads running together. If exception on one thread = kill that one ONLY.
- Since not all thread is killed, program keeps working.

### Exception Pitfalls

- Exception handling requires more time and resources
- Only use exceptions with unexpected error conditions.
- Avoid using if simple `if` statement is enough.

### Getting Information from `Throwable` class

- `printStackTrace`: Output stack trace to standard error stream.
- `getStackTrace`: Same as above but to a `StackTraceElement` array
- `getMessage`: Return message in exception
- `toString`: Get a string with name of exception + message

### Chained Exceptions

- Exceptions often have 'domino effect' where one leads to another

- However, only the top-level exception will be thrown to caller. Hence the lower-level ones are gone.

- To ensure the information is not lost, we need to attach the 'chain of exceptions' along.

- `getCause` returns culprit exception

- `initCause` set exception cause

- Example:

  ```java
  // In this case, the IOException is caught and attached into SampleException (like description) before being passed to the calling class.
  
  try {
  
  } catch (IOException e) {
      throw new SampleException("Other IOException", e);
  }
  ```

### Custom Exception Classes

- Extend `Exception` (or one of subclass)
- Typically contain:
  - No-arg constructor: give default exception message to superclass.
  - Parameterized constructor: Receive customized message as String, then pass to superclass.