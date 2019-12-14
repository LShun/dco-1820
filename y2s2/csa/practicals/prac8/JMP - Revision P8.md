# JMP - Revision P8

## Example 1 (AND)

- If range, must be OR

### C-syntax

```c
if (AL == BL && AL == CL) 
    a = 2;
else
    b = 4;
```

### Assembly

```assembly
CMP AL, BL
JNE L1 ; do the else first
CMP AL, CL
JNE L1 ; do the if
MOV A, 2

L1: 	MOV B, 4
```

## Example 2 (OR)

- If choice

### C-syntax

```c
if (AL == BL || AL == CL)
    	a = 2;
else
    	b = 4;
```

### Assembly

```assembly
CMP AL, BL
JE L1
CMP AL, CL
JE L1
MOV B,4
JMP FINISH
L1: MOV A,2	

FINISH: MOV AX, 4CooH
```

