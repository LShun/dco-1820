# Chapter 7: Procedural Design

## Structured Techniques

- **Functional primitive**, lowest level of explosion
- Variety of techniques to describe
- Mainly to describe:
  - Input validation logic
  - Computation logic
  - Output processing & reporting logic

## Main Techniques for Logic Definition

- Program Flowchart
- Box Diagram
- Structured English :star:
- Pseudocode
- Decision Tables :star2:
- Decision Trees :star:

### 1. Program Flowchart (Not covered)

- Graphical tool, excellent description of procedure.

### 2. Box Diagram (Not covered)

- Sequence structure
  - Sequence
- Selection structure
  - if-then-else
- Selection structure
  - Selection
- Repetition structure
  - Repetition

### Structured English

- **Features:** Similar to spoken English. Describe operations & processes.
- **Weakness:** Limited and restricted vocabulary.
- **Strengths:** Easy to understand, resembles programming language

#### Sequence Statement: 

```
Obtain customer details
Subtract 1 from stock on hand
Print customer invoice
```

#### Repetition Blocks - Calculate daily total orders & updating customer records

```pseudocode
ASSIGN daily-total = 0

DO WHILE there are orders in ORDERS
	READ next order in ORDERS
	DISPLAY invoice-number, customer-number, total-amount
	
ENDDO

DISPLAY daily-total

REPEAT UNTIL (end of file)
	Update CUSTOMER record
ENDREPEAT
```

####  Conditional Block - Decide % discount based on quantity

```pseudocode
ASSIGN daily-total = 0

IF (quantity ordered is >= 50) THEN
	Allow 5% discount

ELSE (quantity ordered is >= 10 AND <= 49)
	Allow 2% discount

ENDIF
```

### Disadvantages of SE

- **Not easy to use.** Unrestricted, indiscriminate use of command borrowed.
- **For small activities.** Only suitable for small & specific code.

### Pseudocode

- **Borrowed vocabulary.** Similar to Programming Language (PL).
- **Supplement.** Mix style and syntax from English & PL.
- **Not language dependent.** Not language-dependent (no syntax error).
- **More time.** No need to worry syntax error, more time to think about logic.
- **No standard.** Follow programmer style.

#### Advantages of Pseudocode

- **Easy to Use/Understand.**
- **Program Design.** Easy to translate to code.
- **Supplement.** Use with natural language.
- **Initialization.** Code details are wrote.
- **Language independent.** Ignore language-dependent details.

#### Disadvantages

- **Double coding**. Might as well start with coding.
- **Limit flexibility.** Cause programmer to bias to coding than design.
- **Not suitable for control structures.** Control structures difficult to describe, eg. nested decisions.

### Decision Table (:star: Very popular  :star:)

#### Definition

- Cause-effect charts

- Describe action to be taken in different condition

- Used in system testing

- Note: Use the halving rule, to split Yes and No systematically.

- Typical format:

  - | Condition Heading    | Decision Rule Number |
    | -------------------- | -------------------- |
    | Condition Statements | Condition Entries    |
    | Action statements    | Action entries       |

- Example (notice the halving effect, YYNN are halves, followed by YN and YN, another two halves):

  |                    | 1    | 2    | 3    | 4    |
  | ------------------ | ---- | ---- | ---- | ---- |
  | Is it 8 o'clock?   | Y    | Y    | N    | N    |
  | Is it the weekend? | Y    | N    | Y    | N    |
  | Get up?            |      | :x:  |      |      |
  | Don't get up?      | :x:  |      | :x:  | :x:  |



### Decision Tree

- A means to define complex relationships
- Design tool, provide graphical representation in a tree form.
- From left to right, :arrow_left: = conditions, :arrow_right: = actions.

#### General Format - Decision Tree

- Similar to Probability Tree, but the probability are replaced by Y/N.

## System Design Specification

- Set documents, records design details.
- Prepared by System Analysts

## Good Design Characteristics

### Modularity

**Definition:** A system, partitioned into sub-systems/modules. Each module = 1 task.

**Benefit:** Easy to understand, code, maintain.

### Coupling

**Definition:** Degree of dependence between modules. Highly-connected = high-coupling

#### Disadvantages

- A bug can infect another module.
- Modification can easily cause side-effects.

### Cohesion

**Definition:** Measure the functional relationship between the codes inside a function.  Cohesive if every line accomplish one task.

#### Advantages

- More efficient
- Easy to code & debug due to good structure

## Exam Tips

- Conversion between Decision Table, Structured English, and Decision Tree.

