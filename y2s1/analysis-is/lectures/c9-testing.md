# C9: System Dev. - Test. & Doc.

## Testing the Program

### Program Translation

- **Purpose:** Translate program into machine code
- **Areas:** Identify syntax errors
- Correct, eliminates syntax errors and recompile

### Desk Checking

#### Reading/Inspecting

- Reading program, visually & mentally reviewing logic
- **Disadvantage:** Difficult to detect errors

#### Structured Walkthrough

- Present module to review team
- Detect errors, adherence to standards, requirements satisfaction
- Use feedback to further improve

## Types of Testing

![Overview of Testing](lec-pics/c9/overview-testing.png)

### Unit Testing

- **Purpose:** Ensure each individual unit works correctly
- Eliminates syntax, logic, execution errors
- Utilize **test data** to test program on input/output handling
- **Stub testing:**
  - **Stub:** Piece of code to temporarily replace missing function.
  - **Purpose:** Test program individually before integration

### Link / Integration Testing

- **Purpose:** Ensure data passes between functions correctly.
- Test multiple programs working together that interacts together.
- **Test data:** Dummy data

### System Testing

- **Purpose**: Ensure all programs work correctly as whole system.
- **Who perform:** End-users, operations, **project team** (evaluates)
- **Test data:** Live data supplied

#### Scope of system testing

- **Interfaces:** Ensure system communicates with other systems well.
- **Business functionality:** Ensure functions defined in planning are correctly implemented.
- **Performance, volume, load test:** Ensure system can provide good performance under load.
- **Usability:** Ensure the system is consistent, adhere to standards, user-friendly.
- **Stability and reliability:** Ensure system can work reliably and recover for failures. Ensure error reporting mechanisms work.

### Performance (Load, Stress, Volume) Testing

- **Definition:** Exploring the limits of application performance under extreme conditions.
- **Method:** Use specialized simulations software
- **Purpose:** Test whether the system meets performance objective under predicted situations.
- **Importance:** 
  - Understand performance limits
  - Predict performance requirements
  - Understand effects of high load
- **Examples:**
  - **Order online:** Test effects during peak hours
  - **POS System:** Test multiple simultaneous transactions

## Exam Tips

Testing Part & Documentation Part.

Contribution and Significance of Automated Testing Tools - no questions in past year. 