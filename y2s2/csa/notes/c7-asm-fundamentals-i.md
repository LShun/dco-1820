# CSA C7: ASM Lang. Fundamentals I

## 1. Basic Elements of Assembly Language

### Numeric Constants

- **radix suffix** add to end
- `d, h, q/o, b`

### Radix suffices

- Binary format: radix suffix - `B`
- Decimal format: radix specifier - `D`
- Hexadecimal format:
  - Use `T` (ten) and `Y` (Binary)
- Real format:
  - Use `R`

### Character/String Constants

- Encode in single/double quote
- Convert to ASCII

### Comments

- **Purpose**: Improve clarity

- **Single-line:** Begin with `;`

- **Multi-line: ** 

  ```assembly
  COMMENT	delimiter [comments]
  				  [comments]
  		delimiter [comments]
  		
  ; delimiters can be any symbols, but usually `+`
  ```

### Identifiers

- Represent item
- Act as place marker for instruction & data.
- 2 types:
  - **Data Label**: Refer to data item (variable)
    - `COUNTER DB 0`
  - **Code Label:** Instruction, procedure, or segment
    - `L10: ADD	AL,50H`
- Rules:
  - First character cannot be `.` or digits
  - Case-insensitive

### Statements

- Program = set of statements
- Types
  - **Instructions**: Become executable when assembled
  - **Directives**: Command embedded in source code, acted by assembler
- General format: `[Identifier] Operation [Operands(s)] [;Comment]`

- Assembly programs consists of one/more segments:
  - **Stack** segment - defines stack storage
  - **Data** segment - defines data items
  - **Code** segment - executable codes
- Segment initialization is required before definition.

### Memory Models

- Tell assembler how to:
  - Use segments
  - Allocate space
  - Optimize code
- Format: `.MODEL memory-model` 
  - `memory-model`: tiny, small, medium, compact, large, huge, flat. (No need to memorize all, just small is usually enough)
    - `tiny`: code + data = 64k
    - `small`: Limit both code & data segment to 64K
    - `medium`: Limit data segment to 64K
    - `compact`: Limit code segment to 64K
    - The rest are unlimited.

### Stack Segment

- Format: `.STACK	[size]`
- Default `size` is 1024 bytes (AKA 1MB)

### Data Segment

- Format: `.DATA`

- Initialize address of DS:

  ```assembly
  MOV AX, @data
  MOV DS, AX
  ```

  - Basically, copy data from code -> `AX`, then dump to `DS`.

### Code Segment

- Format: `.CODE	[segment-name]`
- Default, definition not required: `STACK`, `_DATA`, `_TEXT`. 
  - Can be overridden

### `PROC` Directives

- Code segment, containing executable code, consists of *procedures*.

- Format

  ```assembly
  Procedure-name	PROC	FAR	; Begin Procedure
  ...
  Procedure-name	ENDP		; End procedure
  ```

### `END` Directives

- `END`
  - last statement, ends the program.
- Format: 
  - `END [procedure-name]`

### Ending Program Execution

- Use `INT 21H` in `AH` register. 

  - Specify action to be performed.

- `4C00H` : Request to end program execution, kind of like `return` statement in C.

- Format:

  ```assembly
  MOV	AX,4C00H
  INT	21H
  ```

  - `4C00H`: The `4C` is like `return` in C. The `00` refers to 0. So in C, this statement is equivalent to `return 0`
  -  `INT 21h` means, call the interrupt handler 0x21 which is the DOS Function dispatcher. An equivalence in C is the `;` operator to complete a statement.
  - In this case, the two instructions evaluate to `return 0;` in C.

### Program Template

- Memorize this

```assembly
TITLE 	Program Template
.MODEL	SMALL
.STACK	64
.DATA
		; (insert variables here)
.CODE
MAIN	PROC	FAR
		MOV		AX, @data	; Set address of data segment
		MOV		DS, AX
		; (insert instruction here)
		MOV 	AX, 4C00H	; terminate program
		INT		21H
MAIN	ENDP
		; (insert additional procedures here)
END		MAIN
```

## 2. Defining Data

- Format: `[name]		directive	initializer(initial value)`

| Directive              | Integer size (in bytes) |
| ---------------------- | ----------------------- |
| DB (Define Binary)     | 1                       |
| DW (Define Word)       | 2                       |
| DD (Define Doubleword) | 4                       |
| DQ (Define Quadword)   | 8                       |

- Auto-detect signed/unsigned. Computer do not know two's complement. But will raise flags.
- Text are stored as ASCII integers

### Initializer

- At least 1 required
  - Can be `?`  if undefined

### Symbolic Constants

- Constants & literals. 
- Like C, do not use space, value cannot change at runtime. 
- Assembler replaces all constants with its definition when assembling.

#### Directives

- `EQU` directive: String/numeric constant. 
  - String: can be enclosed in `<>`
- `TEXTEQU` directive

## 4. Data Transfer

### `MOV`

- Copies data
- Operands must same size

- Format: `MOV (register/memory), (register/memory/literal)`

### `MOVZX`

- Copy data, zero-extend in front to 16/32 bits
- Only used with unsigned integers.
- Format: `MOVZX reg16, reg/mem8`

### `XCHG`

- Swap two memory location
- Format: `XCHG reg/mem, reg/mem`

## 5. Arithmetic instruction

### `ADD`

- Add right to left
- Must be same size, can be same operands
- Result may affect flag register
- Format: `ADD destination, source`

### `SUB`

- Opposite of `ADD`
- Cannot be both memory variable

### `INC/DEC`

- Increment & decrement

- All flag except carry are affected.
- Format: `INC/DEC register/memory`

## 6. Display Single Character

- Load character into `DL`, request `INT 21H`

### Syntax

```assembly
MOV AH, 02H ; Request display character
MOV	DL, 61H ; ASCII 'a'
INT	21H		; Call interrupt service
```

