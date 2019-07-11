# Chapter 7: Procedural Design

## Structured Techniques

- **Functional primitive**, lowest level of explosion
- Variety of techniques to describe
- Mainly to describe:
  - Input validation logic
  - Computation logic
  - Output processing & reporting logic

## Main Techniques for Logic Definition

- Highlighted

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

#### EXERCISE - Copy later

### Disadvantages of SE

- **Not easy to use.** Unrestricted, indiscriminate use of command borrowed.
- **For small activities.** Only suitable for small & specific code