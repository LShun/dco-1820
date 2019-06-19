# Tutorial 8

- [Tutorial 8](#tutorial-8)
  - [1.](#1)
  - [2.](#2)
  - [3.](#3)
    - [a)](#a)
    - [b)](#b)
    - [c)](#c)
  - [Q4](#q4)
    - [a](#a)
- [5.](#5)
  - [(a)](#a)
  - [(b)](#b)
- [6.](#6)
  - [(a)](#a-1)
  - [(b)](#b-1)
- [Q7](#q7)
  - [a)](#a-1)
  - [b)](#b-1)
  - [c)](#c-1)
  - [d)](#d)
  - [e)](#e)
  - [(i)](#i)
  - [(ii)](#ii)
- [Q8](#q8)
  - [(i)](#i-1)
  - [(ii)](#ii-1)
  - [(iii)](#iii)
- [Q9.](#q9)
  - [(a)](#a-2)
  - [(b)](#b-2)
  - [(c)](#c)

## 1.
- `auto`
    - The default type for formal parameters and local variables
    - Automatically allocated and deallocated on stack when function is called
      and returns.
- `static`
    - Space for static local variables are allocated and initialized once,
      conceptually at
      compile time
    - Persistent, not destroyed when function terminates.
    - Remain allocated until program terminates
- `register`
    - Suggests the compiler to try storing the variable in the register to speed
    up access time
    - Does not have a memory location. Cannot be passed by address as a parameter.
- `extern`
    - Any variable defined outside function is `extern` by default.
    - Available without declaration to any function appearing after definition
      in same source file.
    - Also known as global variable.
    - Does not allocate memory, simply provides type information to compiler.
## 2.
```
The purpose of the `register` keyword is to suggest to the compiler to place the variable in the register of the CPU. This is to speed up access time and reduce bytecode size at the cost of referencing by address causes undefined behavior.
```

## 3. 
### a)
| Local variable | Global Variable |
| -------------- | --------------- |
| Destroyed when function ends | Destroyed when program terminates |

### b)
`static`

### c)
A variable can be made accessible by declaring it as a global variable or an
`extern` variable. The variable has the scope of the whole source file,
therefore is not deallocated when any function returns. The inherent danger is
that unwanted modifications can be done to the global variable because it exists
throughout the entire program, and can be hard or near impossible to trace in
large programs.

## Q4
### a
| Variable | Visibility | Storage Class |
| -------- | ---------- | ------------- |
| x at line 6 | Entire program | `extern` |
| z at line 23 | In fun2() | `auto` |

(b)
```

2   
4   
12   
48
4
```
# 5.
## (a)
A = extern
B = auto
C = auto
D = static
E = auto

## (b)
22
22
23
43
24
65

# 6.
## (a)
| Variable Name | Line Number | Storage Class | Scope (Line Num) |
| ------------- | ----------- | ------------- | ---------------- |
| x | 3 | `extern` | 3-26 |
| c | 7 | `auto` | 7-10 |
| y | 12 | `static` | 12-26 |
| x | 16 | `auto` | 16-18 |
| d | 20 | `extern` | 20-26 |
| w | 22 | `auto` | 22-26 |
| v | 24 | `static` | 24-26 |

## (b)
1. `register` variables cannot be referenced/dereferenced. This is because they
   are stored in the CPU registers, which does not have memory location
   associated.
2. Register storage size is extremely limited. Therefore, in default, the
   compiler will automatically allocate variables into registers in the best way
   possible. Using `register` keyword suboptimally can lead to degraded performance.


# Q7

## a)
SC: extern
scope: 2-20
## b)
SC: auto
scope: 10-14
## c)
SC: static
scope: 11-14
## d)
SC: extern
scope: 15-20
## e)
SC: auto
scope: 16-20

## (i) 
C
## (ii) 
11

# Q8
## (i)
extern
## (ii)
auto
## (iii)
auto

Static variable is a type of variable in which it is only accessible in the scope it is declared, but retains value between function calls.

# Q9.
## (a)
| Variable | Scope |
| -------- | ----- |
| x at line 02 | 02-21 |
| num at line 04 | 04-18 |
| printXLine at line 02 | 02-28 |
| v at line 01 | 01-28 |

## (b)
| Variable | Storage class |
| -------- | ------------- |
| v        | extern        |
| w        | auto          |

## (c)
| Variable | Value |
| -------- | ----- |
| v at line 19 | 777 |
| w at line 19 | 22 |
| v at line 27 | 777 |
| w at line 27 | 33 |