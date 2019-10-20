# C3 Segment Memory Mgmt

## Disclaimer

- These have NOT been cleaned up yet. I am forced to type above 60wpm at all times due to teacher's incredible speech speed. Expect a cleanup in this week

### Segmented Memory Management

- Segment Address
  - Store in Segment Register
  - Ignore the last few digits (since segment register smaller than the actual size)
  - From segment to actual
    - Adjust back to 20bit 
      - Use 2000 times 10, get back 20000
    - Add back the offset
      - Lets say offset 250
      - Add 250 = 20250
- Segment composition
  - `XXXX:XXXX`
  - **First part**: segment address
    - To get back: `XXXX` times 10H
  - **Second part**: offset address
- Challenge
  - Segment: 1234H
  - Offset: 0022H
  - Answer, physical address: 
    - 12340H + 0022H = 12362H
- Challenge
  - Segment: 5BA3H
  - Offset: 3122H
  - Physical address:
    - 5BA30H + 3122H =
    - 5EB52H
- Challenge
  - Segment: 002AH
  - Offset: ?
  - Result: 002C3H
  - Physical address:
    - 002C3H - 002A0H = 0023H

### Segments

#### Segments vs Segment Register

- Segment register stores address
- Segments store stack information
  - 3 types
    - Code segment: Stores code
    - Data segment: Stores data
    - Stack segment: Stores stacks (or states)
    - Extra segment (not in syllabus)

### Program Execution Registers

#### Register

- Temporary memory
- High-speed memory
- In 8086,
  - All registers are 16-bit registers
- AX
  - By default, 16 bits.
  - Can divide into 2
    - AH: 1 byte
    - AL: 1 byte
  - Use for arithmetic, input/output, multiply, divide
  - Double size: EAX (Extended AX)
- BX
  - Break into BH and BL
  - Use for arithmetic, index
- CX
  - Break into CH and CL
  - Use for arithmetic, loop
- DX
  - Break into DH and DL
  - Use for same as AX.
  - DX is usually for bigger number, smaller number is AX

#### Segment

- Registers
  - CS - Code
  - DS - Data
  - SS - Segment
  - ES - Extra
- Stores segment address

#### Pointers

- Registers
  - IP - Instruction
  - SP - Stack
  - BP - Base
- Stores offset address
  - Mandatory matching
  - CS:IP (CS must match with IP)
  - SS:SP
  - SS:BP

### Index

- Types
  - SI - Source Index
  - DI - Destination Index
- To store index if BX is not enough

### Flag (Second Highlight) - Note, finishe entire table

- Indicate state
- Flag registers, only 1, but occupies 16 bits
  - CF
    - Indicate carry bit
    - Set when unsigned too big
    - NC: No carry
  - OF
    - Indicate overflow
    - NO: No overflow
  - AF
    - Auxillary Flag
    - AC: Auxillary Carry
    - NA: No auxillary
  - ZF
    - Indicate zero
    - 
  - SF
    - Indicate sign after operation
  - PF
    - Set if result have even number of 1 bits
    - Even parity
    - Odd parity
    - Use for error checking
  - AF
    - Set when carry from bit 3 to bit 4 *in 8 bit operation*
  - CF
    - TF: Single step
    - IF: Interrupt
    - DF: Directions
- Exercise
  - 0101 1010 + 0000 + 0010 = 0101 1100
    - Flags: NV, UP, EI, PL, NZ, NA, PE, NC
  - 1000 0100 + 1001 0011 = 1 0001 0111
    - Flags: OV, UP, EI, PF, NZ, NA, PE, CY
- Chapter Review
  - Data storage sizes
  - Data addressing
  - Segmented Memory Management
  - 

### Using DOSBox

- ```
  mount c: c\8086
  debug
  -r
  ```


