# Revision: Output



## Display string:

```assembly
.DATA
	STR DB "GOOD NIGHT", 13, 10, $
	
... 09H
```

### Input

```assembly
MOV AH, 01H
INT 21H
; Result store in AL
```

- If digit, `SUB AL, 48`

- Output, add, input, subtract

### Multiply & Divide

- Divide: `AX/some int = AH (remainder), AL (quotient)`

### Display 2 digits

- Split 2 digits, divide by 10, AL = first, AH = second digit.

