# Revision

- Display character
  - `MOV AH, 02H`
  - `MOV DL, CHAR`
- Display digit
  - `MOV AH,02H`
  - `MOV DL, DIGIT`
  - `ADD DL, '0'`

- Display string
  - Add `$`  at the end of string: `STR DB "HELLO$"`
  - `MOV AH, 09H`
  - `LEA DX, STR`
  - `INT 21H`

## Input

- Single character

```assembly
.DATA
	CHAR DB ?
.CODE
	...
	MOV AH, 01H
	INT 21H
	
	; Copy input to other variables
	MOV CHAR, AL
```

- Single digit
  - Note: All input in ASCII, need to subtract if want number

