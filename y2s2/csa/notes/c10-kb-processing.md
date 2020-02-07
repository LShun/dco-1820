# CSA C10: KB & Screen Processing

## 1. Screen Features

- 25 rows \* 30 columns

### `INT` (interrupt)

- Handles I/O for most purposes.
- Low-level interrupts (INT 10H)
  - Go to BIOS
  - Screen-handling

- High-level interrupts (INT 21H)
  - Go to OS
  - I/O

### Actions

| INT  | 10H Functions |
| ---- | ------------- |
| 02H  | Set cursor    |
| 06H  | Scroll screen |

| INT  | 21H Functions     |
| ---- | ----------------- |
| 02H  | Display character |
| 07H  | Display character |
| 09H  | Display string    |
| 0AH  | Input from KB     |
| 3FH  | Input from KB     |
| 40H  | Display string    |

## 2. BIOS Interrupt (INT 10H)

### Setting cursor

- Cursor determines next character displayed location
- Function: `02H`

#### Example

```assembly
MOV	AH, 02H		; set function (cursor)
MOV	BH, 00		; set page number 0
MOV	DH, 08		; set row 8
MOV	DL, 15		; set column 15
INT	10H			; call interrupt service
```

### Clearing Screen, `06H`

#### Registers

- `AH` = `06H`
- `AL` = Number of line to scroll, or `00H` for full screen

#### Registers loading

```assembly
AH = function 06H
AL = num. of lines to scroll, or `00H` for fullscreen.
BL = attribute (color, blinking, etc)
CX = starting row:column
DX = ending row:column
```

#### Example

Clearing entire screen

```assembly
MOV	AX, 0600H			; AH = 06 (scroll)
						; AL = 00 (full screen)
MOV BH, 71H				; White BG (7) Blue FG (1)

MOV CX, 0000H			; Upper left row:column
MOV, DX, 184FH			; Lower right row:column
INT 10					; Call interrupt service
```

## 3. MS-DOS Function Calls - `INT 21H`

### Screen display

#### Single Character

- Load character into `DL`, function code `02H` into `AH`

##### Example

```assembly
MOV 	AH,02H	; Request display char
MOV		DL, 61H	; Char to display, ASCII for 'a'
INT 	21H		; Call interrupt service
```

#### String

- Definition of display string in data area + `$` or `24H` delimiter, to end display.

##### Example

```assembly
MSGDB 	'Hello!', '$'
MSG1	DB	'Hello!$'

MOV AH, 09H
LEA DX, MSG	; Load address
INT	21H
```

#### New Line

- Display cursor on new line:
  - Use carriage return (CR): `0DH` +
  - Line Feed (LF) character - `0AH`

##### Example

```assembly
MOV 	AH, 02H		; For character display
MOV		DL, 0DH		; CR
INT		21H			; Display character
MOV		DL, 0AH		; LF
INT 	21H			; Display character
```

### Keyboard Input

#### Single Character

- `01H`: accept single character (with echo)
- `07H`: same but without echo (not displayed on screen, used for passwords)
- Load `01H` in `AH`, then call `INT 21H`, character entrd stored in `AL`.

#### String

- `0AH` : Accept more than one character
- Accepts `<backspace>` but don't add to count.
- Bypass extended Fn keys. (F1, Home, PgUp not included)
  - To include, use `INT 01H` (single char)
- Require parameter list with fields
  - Name of parameter list (Give location)
  - Max characters (First byte, max = 255)
  - Actual character count (2nd byte)
  - Characters entered (3rd byte ++)

##### Example

- Define parameter list for KB input area

```assembly
PARA_LIST 		LABEL	BYTE	; name
MAX_LEN			DB		20		; max chars
ACT_LEN			DB		?		; actual chars
KB_DATA			DB		20	DUP('$') ; area to store chars
```

- Request KB input

```assembly
MOV 		AH, 0AH 		; Request KB input
LEA			DX, PARA_LIST	; Load param. list address
INT			21H				; Call interrupt service
```

#### Clearing Input Area

- Characters remain until replaced
- Solve unwanted, persisted characters problem
- Should only clear position to the right of most recent input

##### Example

```assembly
MOV 	CX, 20
MOV		SI, 0000

L10:
	MOV 	KB_DATA[SI], 20H 	; Move blank to name
	INC 	SI					; Incre. next char
	LOOP	L10					; Repeat 20x
```

### File handles

- KB & Screen similar to "file".

| Code | Function     | Usual  |
| ---- | ------------ | ------ |
| 00   | Input        | KB     |
| 01   | Output       | Screen |
| 02   | Error output | Screen |
| 03   | Aux device   |        |
| 04   | Printer      |        |

#### Example

- Screen output

```assembly
.DATA
	Prompt	DB	'Part Number : ', 0DH, 0AH
.CODE
	MOV	AH, 40H 	; request display
	MOV	BX, 01		; screen output
	MOV CX, 16		; number of chars
	LEA	DX, Prompt
	INT 21H
```

- Keyboard input

```assembly
.DATA
	KBINPUT 	DB		20	DUP('') ; Input area
.CODE
	MOV AH, 3FH 					; for KB
	MOV	BX, 20						; max 20 chars
	LEA	DX, KBINPUT					; Input area
	INT 21H
```

