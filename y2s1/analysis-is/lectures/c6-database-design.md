# C6: Database Design

## SDLC

- Recap: List down the entire process

## File / Table Concepts

**File:** Collection of related data

**Record:** Collection of related items of data

**Field:** 1 logical unit of data

## Key Field

- Meaning: Field to identify one record from another

## Database Concept

- Database -> File -> Record -> Field

## Type of keys

### Primary Key

- Definition: A field/combination of field to uniquely identify particular record. Must be unique

### Concatenated key

- Combination of two primary keys

### Foreign key

- Key in one table must match primary key of another.

## Steps in DB Design

1. Create an initial ERD
   1. No need to ensure entities and relationship are complete/accurate.
2. Assign all data elements to entities
   1. List data elements
   2. Assign key field
   3. Check entity integrity (each must have primary key - unique, not null)
3. Verify all data elements to entities
   1. **Amendments.** Additional entity to make data elements fit
   2. **Resolve many to many relationships.** Introduce associative entities.
4. Relating entities by using foreign key
   1. Assign foreign key
   2. Check referential integrity
   3. Check data integrity
5. Normalize entities
   1. Check later
6. Creating data dictionary entries
   1. Create for all data elements
   2. Group data elements into groups

## Normalisation

### Unnormalised Data

- Group everything in one table

### Normalisation Technique

- 1NF (first normalization form) - No repeating group.
- 2NF - No partial dependency. Each field depending on whole key
- 3NF - No transitive dependency. No non-key fields dependent on another non-key field.

### Example of Data Dictionary Format

- Field name
- Field length
- Field type
- Alias - other names for first entry
- Field content description - Notation for representation content
- Supplementary information - extra information, restriction, limitation

### Uses of data dictionary

- During analysis

  - Help organize information

  Copy whole

## Code Design (popular question)

- Exam will ask you to suggest type of code based on scenario
- **Meaning:** Set of numbers & letters representing item
- **Purpose:** Facilitate identification & retrieval of information
- **Requirements:** Optimum-oriented use, machine efficiency

### Purpose of Code

- **Uniqueness**: Primary key, differentiate one record from another
- **Cost**: Code instead of large details, reduce storage cost.
- **Data entry:** Reduce errors & cost
- **Conceal information:** Hide information, make only understood by certain people

### Type of codes (In EXAM)

- **Sequence codes**: Numbers/letters in specific order
  - Customer number, purchase order number
- **Block Sequence Codes:** Use blocks of different number for classification.
- **Significant alphabetic code:** Use alphabet letters to distinguish. Usually an abbreviation or mnemonic code.
  - Stock Code
- **Significant Digit Code:** Subgroups of digits
- **Derivation codes:** Combine data from item attributes/characteristics
- **Cipher code:** Use keyword to encode number

### Characteristics of good code

- **Uniqueness.** One value with single meaning.
- **Flexibility.** Easy to modify to reflect use.
- **Conciseness.** Fewest possible numbers.
- **Stability.** Do not require frequent updating.
- **Expandability.** Must allow growth.
- **Simplicity.** Easy to use & understand.
- **Meaningfulness.** Easy to remember, useful, convenient, useful to encode & interpret.

## Exercise

- `SHIPPING(SHIPPING_NO, DEST_CODE, PLANE_ID)`
- `DESTINATION(DEST_CODE, DESTINATION)`
- `PLANE(PLANE_ID, NUMBER_OF_SEATS, PLANE_TYPE)`

### Identify primary keys (underline)

- SHIPPING_NO
- DEST_CODE
- PLANE_ID

### Identify foreign keys (star)

- DEST_CODE, PLANE_ID
- DEST_CODE
- PLANE_ID