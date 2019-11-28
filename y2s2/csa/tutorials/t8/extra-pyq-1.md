1. Write an assembly language program by using simplified segment directive to display the ASCII in decimal for a digit that entered by user.

   ```bash
   Sample output:
   Enter a digit: 2
   ASCII for digit 2 is 50
   ```

   1. Marking criteria

   | Criteria                           | Mark(s) |
   | ---------------------------------- | ------- |
   | Overall program structure          | 2       |
   | Definition of necessary data items | 2       |
   | Input                              | 1       |
   | Computation for output             | 3       |
   | Output appropriate result          | 2       |

   1. Answer

   ```assembly
   .MODEL SMALL
   .STACK 100
   .DATA
   	usrq DB "Enter a digit: $"
   	out1 DB "ASCII for digit $"
   	out2 DB " is $"
   	ans  DB ?
   	TEN	 DB 10
   	num1 DB ?
   	num2 DB ?
   	NL   DB 13, 10, "$"
   	
   .CODE
   MAIN PROC
   	MOV AX,@DATA
   	MOV DS,AX
   	
   	; Ask for input
   	MOV AH, 09H
       LEA DX, usrq
       INT 21H
   	
   	MOV AH, 01H
   	INT 21H
   	
   	MOV ans, AL
   	
   	MOV AH, 09H
   	LEA DX, NL
   	INT 21H
   	
   	; Output
   	
   	; display the header
   	MOV AH, 09H
   	LEA DX, out1
   	INT 21H
   	
   	; display original figure
   	
   	MOV AH, 02H
   	MOV DL, ans
   	INT 21H
   	
   	; display the mid
   	MOV AH, 09H
   	LEA DX, out2
   	INT 21H
   	
   	; calc for nums
   	MOV AL, ans
   	MOV AH, 0
   	DIV TEN
   	
   	MOV num1, AL
   	MOV num2, AH
   	
   	; display the numbers
   	MOV AH, 02H
   	MOV DL, num1
   	ADD DL, "0"
   	INT 21H
   	
   	MOV DL, num2
   	ADD DL, "0"
   	INT 21H
   	
   	
   	
   	MOV AX, 4C00H
   	INT 21H	
   MAIN ENDP
   END MAIN
   ```

2. Write an assembly language program by using simplified segment directive to display the ASCII by combining the 2 digits that entered by the user.

   ```bash
   Sample output:
   Enter 1st digit: 6
   Enter 2nd digit: 5
   ASCII for 65 is A
   ```

   

| Criteria                           | Mark(s) |
| ---------------------------------- | ------- |
| Overall program structure          | 1       |
| Definition of necessary data items | 2       |
| Input                              | 2       |
| Computation for output             | 4       |
| Output appropriate result          | 3       |

```assembly
.MODEL SMALL
.STACK 100
.DATA
	d1 DB ?
	d2 DB ?
	ans DB ?
	in1 DB "Enter 1st digit: $"
	in2 DB "Enter 2nd digit: $"
	o1 DB "ASCII for $"
	o2 DB " is $"
	TEN DB 10
	NL DB 13, 10, "$"
.CODE

MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	; Ask for 2 digits
	MOV AH, 09H
    LEA DX, in1
    INT 21H
	
	MOV AH, 01H
	INT 21H
	SUB AH, 30H
	MOV d1, AL
	
	MOV AH, 09H
	LEA DX, NL
	INT 21H
	
	MOV AH, 09H
    LEA DX, in2
    INT 21H
    
	MOV AH, 01H
	INT 21H
	SUB AH, 30H
	MOV d2, AL
	
	MOV AH, 09H
	LEA DX, NL
	INT 21H
	
	; ans = d1 * 10 + d2
	MOV AL, d1
	SUB AL, "0"
	MUL TEN
	ADD AL, d2
	SUB AL, "0"
	
	MOV ans, AL
	
	; Output ans & ASCII representation
	
	MOV AH, 09H
	LEA DX, o1
	INT 21H
	
	MOV AH, 02H
	MOV DL, d1
	INT 21H
	MOV DL, d2
	INT 21H
	
	MOV AH, 09H
	LEA DX, o2
	INT 21H
	
	MOV AH, 02H
	MOV DL, ans
	INT 21H
	
	
	
	MOV AX, 4C00H
	INT 21H
ENDP MAIN
END MAIN
```

