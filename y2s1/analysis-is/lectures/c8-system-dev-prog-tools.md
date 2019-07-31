## Chapter 8 - System Dev - Prog. Tools

## Prog. Development Stages

### 1. Review Design Document

- **Documentation**: DFD, Process Descripte
- Discuss with System Analyst

### 2. Program Design

- **Techniques:** Decision tables, etc
- **Tools:** Case tools

### 3. Program Coding

- Write program instructions

### 4. Program Testing

- Software testing are carried out (e.g. unit, integration, system, user acceptance)

### 5. Documentation

- **Documentation:** End-user, operation, program, system.

## Program Design

- **Reviewing**: Check for required changes
- **Design tools:** Programmer use to aid logic development (e.g.: Structure chart)

## Structured Programming

### Historical development

- Computer need readable code :arrow_right: Structured Programming
- Used top-down to design maintainable systems
- Expensive programs that don't meet requirements. Little input from user as they don't know what they need.

**Definition:** Translate system design into well-structured program, to make it easier to understand and maintain.

- Each module has one entry and exit point.

## 3 Basic Control Structures

### Sequence Structure

- executes statements in order

### Selection/decision Structure

- If,else

### Repetition/looping structure

- Do,while

## Coding the program

**Purpose:** Writing a program implementing program specifications with a suitable language

- Good **program design** preparation greatly simplifies coding
- For very large programs, subdividing modules is important

## Factors when choosing programming language

**Purpose of language:** Different language different applications & purpose. Using assembly to code a game is like shooting yourself in the head.

**Familiarity with language**: The more familiar, the quicker work can be done. Calling a C++ programmer to code in x8086 is suicide.

**Features of language:** Top-down design & modular approach support is useful.

**Cost: ** Include purchasing, licensing costs.

**Support tools:** Learning curve significantly affects productivity. Telling a programmer to "just do it" :tm: is...."why don't you do it yourself instead".

**Performance:** Some programs require high efficiency to work well. Example, OS Kernel. 

## Programming Languages (PL)

### Generation of languages

#### 1GL - Machine Language

- In 0s and 1s
- Examples: 00100001

#### 2GL - Assembly Language

- In mnemonic codes
- Examples: ADD AX, 8

#### 3GL - 'High-level' PL

- Example: C++, Java

#### 4GL - 'Non-procedural' PL

##### Features

- **User-friendly**: More English-like, easier to 'get'. 
- **Programming tools**: Software tools to increase productivity.
- **Non-procedural**: Encourage users to think about the problem than the solution.

##### Examples

- **Query language.** Request system to display reports.
- **Report generator.** Display well-formatted reports.
- **Application generator.** Generates source code, from given operations and screen layout.

##### Advantages

- **End-users involvement**: End-users can participate, brings commitments.
- **Easy maintenance:** Application development is simpler and more rapid. Easier to maintain.
- **Cost-effective:** Use less time, means less labor, and less money.
- **Generate documentation:** Documentation can be produced together with programs.

## CASE Tools

- **Acronym:** Computer-aided software engineering
- **Definition:** Type of software, allow analysts to develop and maintain system efficiently.

- **Purpose:** Automate development tasks to improve productivity and quality of work
- **Examples:** DFD Diagram drawer, IBM's Rational Software Architect

## CASE Terms & Concepts

### Modelling Tools

- Use to model systems graphically
- Ex: DFD, UML Diagram

### Documentation Tools

- Repository, automatically identify new entries and add to database.
- Automatically check for inconsistent/incomplete information

### Engineering Tools

- **Forward engineering** tools: Translate business process/functions into applications
- **Reverse engineering** tools: Examine existing application, disassemble to understand app.

### Development Tools

#### Application Generator

- Translate logical model into code to develop program rapidly.
- Generate applications and code.

#### Screen Generator

- Interactive tools to assist in creation of data entry screens.
- Control screen elements and user interaction

#### Report Generator

- Automates report making
- Modifies report definition and code into actual report
- Allow insertion of sample values.

### Roles/Benefits

#### 1. Drawing Models

- **Simplify model drawing**. Standard shapes provided.
- **Simplify model storing**. Allow retrieval and amendment anytime.
- **Simplify model updating**. Easy to edit, update, reprint.

#### 2. Enforcing standards

- Ensure models follow standards and conventions.

#### 3. Automatic cross referencing

- Automate cross-referencing between different models.
- Promote consistent view

#### 4. A central Data Dictionary

- Hold data elements for entities in one place
- Makes updating and maintaining easier

#### 5. Automatic File / Program Framework

- Automatically produce physical file and data structure from entities

### Advantages

#### 1. Simplify descriptive diagrams. 

- Diagrams can be drawn easier with standard shapes

#### 2. Producing and maintaining diagrams.

- Graphical editing facilities. Easy changes to models can be made.

#### 3. Adhering to development standards.

- Force IT personnel to adhere to standards.

#### 4. Maintaining data dictionary.

- Stores information about constituent parts of specifications.

#### 5. Prototyping

- Develop screens, reports and layouts easily. Allows linking between contents.

#### 6. Generating Computer Codes

- Converts system specifications into executable source codes and entities into physicalfiles and databases.

### Toolsets to support software development

#### Integrated Development Environment (IDE)

**Definition: ** Software to provide comprehensive facilities to programmers to assist in deveopments

**Advantages:** 

- Maximize programmer productivity, components are tightly-knit, and have similar UI.
- All tools in one place, easy to design.

**Disadvantages:** Complicated, high learning curve.