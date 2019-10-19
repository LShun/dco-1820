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
  - 