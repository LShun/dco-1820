# Revisions



### Looping

```assembly
	MOV CX, 5
DISPLAY:
	MOV AH, 02H
	MOV DL, "$"
	INT 21H
LOOP DISPLAY
```

### Nested Looping

```assembly
MOV CX, 4
NEXT:
	MOV BX, CX ; keep as temp, can also be variable
	
	MOV CX, 5
	SHOW:
		MOV AH, 02H
		MOV DL, "$"
		INT 21H
	LOOP SHOW
	; NEW LINE
	MOV CX, BX ; move back
```

## JUMPS

### Types

- Conditional (need to compare)

  - | Unsigned No. | Signed No. | Symbolic      |
    | ------------ | ---------- | ------------- |
    | JA           | JG         | `op1>op2`     |
    | JNA          | JNG        | !(op1 > op2)  |
    | JAE          | JGE        | op1 >= op2    |
    | JNAE         | JNGE       | !(op1 >= op2) |
    | JB           | JL         | op1 < op2     |
    | JNB          | JNL        | !(op1 < op2)  |
    | JBE          | JLE        | op1 <= op2    |
    |              | JE         | op1 = op2     |
    |              | JNE        | op1 != op2    |

    

- Unconditional jump

### Jump Syntax

- if-statement (optimized)

```assembly
CMP AL,BL

JNE FINISH
L1: MOV A,2

FINISH: MOV AX, 4C00H
		INT 21H
```

- if-else statement (optimized)

```assembly
CMP AL, BL

JNE L1
MOV A,2
JMP FINISH
L1: MOV B,4

FINISH: MOV AX, 4C00H
		INT 21H
```

## Final ExamQ1


C1-2
Q2
C3,4,5
Q3

Q4
7,8,9,10 (Write program)

- ASk you to write commands
	- Chapter 5
- Same like mid-term test

C11-12 (considered as important, coming out in final exams)