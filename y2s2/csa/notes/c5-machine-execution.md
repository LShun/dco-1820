# CSA C5: Machine Execution

### USING THE DEBUG PROGRAM

## 1. Instruction Format

- Generally, 3 parts:

  - | Syntax  | [Label] | Operation | Operand(s) |
    | ------- | ------- | --------- | ---------- |
    | Example | MOV     | AX,       | BX         |

### 2-operand instruction

| Syntax   | OPERATION | DESTINATION | SOURCE |
| -------- | --------- | ----------- | ------ |
| Examples | MOV       | AX,         | BX     |

### Instruction with label

- Example: `START:	MOV AX, BX`
- Label must follow with colon sign (:)

### 1-operand instruction

- Syntax: `OPERATION operand`
- Example: `JMP START`

## Registers as Operand

- Operands can be registers
- Examples:
  - `MOV AX, BX`
- Both registers MUST same type (8-bit cannot mix with 16-bit)

## Operand (Constants)

- For 2-operand instruction, only as 2nd operand
- Ex: `MOV AX,0148H` , CANNOT in front

## Footnote (Instruction Format)

- Cannot add 2 constants (20H, 30H)
- Cannot add different size (AH & 0123H)
- Cannot have missing operands (JMP without operands)
- Cannot set value of CS & IP registers (MOV CS,BX)

## 2. Machine Language Instructions

- Assembly language uses symbolic codes

- Assembler

  | Symbolic Codes | Object Code (HEX) | Number of Bytes |
  | -------------- | ----------------- | --------------- |
  | MOV BX, AX     | 8BD8              | 2               |
  | MOV AX,0123H   | B82301            | 3               |

- Instruction

  - Vary in length
  - Stored, executed sequentially

## 3. Instruction execution

- Processor procedure for each instruction:
  - Fetch next instruction based on IP (instruction pointer)
  - Decode instruction, increment IP for next instruction
  - Execute decoded instruction

- Example (IF instruction 2 bytes long):
  - **CS:IP**: Give address of next instruction
  - 05BE0H + 2H = 05BE2H
  - Stored back: 05BE:2H (Remember 16bit:16bit system)

## 4. Introduction to DEBUG program

### General functions

- View memory
- Edit memory
- Trace execution
- Debug executable program

### Commands

| Command           | Purpose                                                      | Examples           |
| ----------------- | ------------------------------------------------------------ | ------------------ |
| `A` - Assemble    | Symbolic code :arrow_right: Machine code                     | `A 100`            |
| `U` - Un-assemble | Machine code (in memory) :arrow_right: Symbolic Code         | `U 100, 107`       |
| `D` - Dump        | Machine code  (in memory):arrow_right: Hex code              | `D CS:100`         |
| `E` - Enter       | Enter data :arrow_right: memory starting from specific location | `E CS:100 A1 ....` |
| `H` - Hex         | Perform hex arithmetic.                                      | `H ABC0 0FFF`      |
| `Q` - Quit        | Quit `DEBUG` session                                         |                    |
| `R` - register    | Display content of one/multiple registers                    |                    |
| `T` - trace       | Trace execution of one instruction                           |                    |

#### Peculiarities

- Commands are NOT case-sensitive.
- Assume all number in hexadecimal.
- Space is used to separate parameters.
- Segment & offset specified with colon. AKA: `segment:offset`

#### Assemble, `A`

##### Example

```assembly
A	100
MOV	CL, 42
MOV	DL, 2A
ADD	CL, DL
JMP	100
```

- Note: Press `<enter> ` twice to end.

#### Un-assemble, `U`

##### Example

```assembly
U 100, 107
```

#### Debug, `D`

##### Example

`D CS:100`

- Display machine code in code segment 100, in hex format.

- Result: Right side is ASCII representation of byte.

#### Enter, `E`

##### Example

- `E CS:100 A1 00 02 03 06 02 02`

#### Hex, `H`

##### Example

```assembly
H	ABC0	0FFF
```

Find physical address of CS:IP

- If `CS=ABC0`, `IP=0FFF`
- Note: Remember both are 16-bit, offset is simply added onto the code segment.

##### Result

- `BBBF	9BC1`. First is sum (N1+N2), second is difference (N1-N2).
