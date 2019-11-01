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





