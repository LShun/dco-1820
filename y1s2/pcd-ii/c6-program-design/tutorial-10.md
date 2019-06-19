# T10 - Program Design

- [T10 - Program Design](#t10---program-design)
  - [Q1](#q1)
  - [Q2](#q2)
  - [Q3](#q3)
    - [(i) Pathological coupling](#i-pathological-coupling)
    - [(ii) Simple data coupling](#ii-simple-data-coupling)
    - [(iii) Coincidental cohesion](#iii-coincidental-cohesion)
  - [Q4](#q4)
    - [(i) Pathological](#i-pathological)
    - [(ii) Control Coupling](#ii-control-coupling)
    - [(iii) Communicational Cohesion](#iii-communicational-cohesion)
  - [Q5](#q5)
  - [Q6](#q6)
  - [Q7](#q7)
  - [Q8](#q8)
  - [Q9](#q9)
  - [Q10](#q10)
  - [Q11](#q11)

## Q1

Levels of cohesion in program design.

- Most desirable: *Functional cohesion* 
  - Lecturer note: Better functional cohesion instead of function cohesion
- Sequential cohesion
- Communicational cohesion
- Procedural cohesion
- Logical cohesion
- Temporal cohesion
- Least desirable: Coincidental cohesion

## Q2

6 types of cohesion.

- Functional cohesion
  - Function performs 1 task
  - Example: Compute cosine of angle
- Sequential cohesion
  - Function performs more than 1 task, all the tasks are related through data, and sequence is important
  - Example: Module format and cross validation of record
    - Use raw record
    - Format raw record
    - Cross-validate fields in raw record
    - Return formatted cross-validated record
- Communicational cohesion
  - Same as sequential cohesion, but sequence is not important.
  - Example: Determine customer details
- Procedural cohesion
  - Function perfors more than 1 task, all tasks are related by logic, and sequence is important
  - Example: Write, read, and edit something
- Logical cohesion
  - Same as procedural cohesion, but sequence is not important
  - Example: Display record in staff depending on the record type

Answer given by lecturer:

- **Coincidental** cohesion occurs when **there is no meaningful relatioship among the elements of a module.** Coincidental cohesion can occur if an existing program is modularized by chopping it into pieces and making different pieces modules.
- A module has **logical cohesion** if there is **some logical relationship between the elements of a module**, and the elements perform functions that fill in the same logical class. A typical example of this kind of cohesion is a module that performs all the inputs or all outputs.
- **Temporal cohesion** is the same as logical cohesion, ecept the elements are also related in time and are executed together. Modules that perform activities like "initialization", "clean-up", and "termination" are usually temporary bound.
- A **procedurally cohesive module** contains elements that belong to a common procedural unit. For example, a loop or a sequence of decision statements in a module may be combined to form a separate module.
- A module with **communicational cohesion** has elements that are related by a reference to the same input or output data. That is, in a communicationally bound module, the elements are together because they operate on the same input or output data.
- When elements are together in a module because the output of one forms the input to another, we get **sequential cohesion**.
- **Functional cohesion** is the strongest cohesion. In a functionally bound module, all the elements of the module are not related to performinga single functon. By function, we do not mean simply mathematical functions; modules accomplishing a single goal are also included.

## Q3

### (i) Pathological coupling

A type of coupling where a function modify other function's data.
L.Ans: Modules changes each others data

### (ii) Simple data coupling

A type of coupling where function share data by passing parameters, and returning results.
L.Ans: Modules share data by parameter passing

### (iii) Coincidental cohesion

A type of cohesion in functions where the function performs more than 1 task which are completely unrelated to each other. The tasks just happens to be in a same function.
L.A.: No meaninful relationship among the elements of a module.

## Q4

Define the following terms:

### (i) Pathological

Changes in one place result in changes in another place.

### (ii) Control Coupling

A main module is used to control the functions.
L.A.: 2 module communicating with a control flag (first tells second what to do via flag)

### (iii) Communicational Cohesion

Function which perform more than 1 task, its contents are related by data, but does not have to be in sequence.

## Q5

**What is coupling? List any 3 levels of coupling.**

A. Coupling is the measure of the strength of connection between two functions.
L.A.: Coupling is the measurement of the strength of interconnection between 2 modules.

The three levels of coupling are:

- Data coupling
- Control coupling
- External & common coupling

## Q6

**Define Tight coupling and Loose coupling.**

Tight coupling is where functions are closely related to each other. Changes in one function will affect another function. There are also many data paths and these functions are hard to debug and error prone.

Loose coupling is where functions are not closely related to each other. Changes in one function will not affect another function. The data also flows in a single path, and therefore make this kind of functions easy to debug and more error resistant.

**Which is the most intimate way to share data?**

The most intimate way to share data is pathological coupling. Pathological coupling is where two or more functions share data. Changes in one function will affect another function in consequence.

L.Ans: Tight Coupling 
Note: Could also be pathological coupling, but marking scheme is tight coupling.

## Q7

Define the following:

**(i) Control Coupling**
Control coupling is a type of coupling where a main program is used to control the program.

**(ii) Sequential Cohesion**
Sequential cohesion is a type of cohesion where a function does more than one task, all the tasks in the function are related by data, and the tasks must be in sequence.

**(iii) Functional Cohesion**
Functional cohesion is a type of cohesion where a function only does one task and is very specific.

## Q8

**(i) Describe any 2 levels of cohesion.**
The first level of cohesion is functional cohesion. Functional cohesion is where a function only performs one task.

The second level of cohesion is coincidential cohesion. Coincidental cohesion is where a function does more than 1 task, they are not related in any way and simply happens to be together.

**(ii) What is the highest level of cohesion?**
The highest level of cohesion is functional cohesion.

**(iii) What is the lowest level of cohesion?**
The lowest level of cohesion is coincidental cohesion.

## Q9

- Functional cohesion
- Sequential cohesion
- Communicational cohesion
- Procedural cohesion
- Logical cohesion
- Temporal cohesion
- Coincidental cohesion

## Q10

Coupling is the measure of the strength of connection between two modules. Cohesion is the measure of the internal strength of individual modules.
L.A.: Cohesion is a measure of how well the module fit together.

## Q11

1. Data coupling
2. Control coupling
3. Pathological coupling
4. Functional cohesion
5. Logical cohesion
