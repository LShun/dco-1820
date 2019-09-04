# Lecture 2: Database Concepts

## Data vs. Information

- Data
  - Raw facts, unprocessed information
- Information
  - Data processed to reveal meaning

Data + `Grouping` -> Information + `Context` -> Knowledge

## Why process data

- Decision making
- Survival in global environment

## Why do we need database

- Database: Shared, integrated computer structure that houses
  - **Raw facts**: End user data
  - **Metadata**: Data about data

- **DBMS (database management system)**: 
  - Collection of program managing database structure and control access to data

- Why database?
  - **Better access to better-managed data**
    - Less errors
    - Data more consistent
    - Quicker answers

## Flow chart of DBMS

End user <-> DBMS <-> Database Structure

## Type of database

- Single user
- Desktop (difference is on a PC vs Server and etc.)
- Multi-user
- Workgroup
  - Multi-user, small group users/department
- Enterprise
  - Multi user, large group users/company

## Location of Database

- **Centralized**:
  - Data located in one space
- **Distributed**:
  - Data distributed across several site

## Uses of database

- Transactional/production
- Data warehouse
  - **Data massaging**
    - Store data used to generate information
  - Store historical data

## Why database design important

- Avoid redundant data
- Correct approach
- Know expected use

## Manual File System

- Organized within folders based on data expected use
- Adequate for small amount of data
- Finding in large sets of data is time-consuming

## Conversion from MFS to Computer File System

- Hiring *Data Processing (DP) Specialists*
- DP specialist design Databases

## Example of Early Database Design

- Other departments request individual database
  - Cons: Result not consistent

## File based system

- Each file use own system & application to store, retrieve, and modify data
- Each file owned by department that created it.
- No consistency, reliability, accuracy

## Problem with File System Data Management

### Every task need extensive programming

- 3GL (how it must be done)
- 4GL (specify what must be done)

### Programming in 3GL

- Time-consuming, high-level activity
- Increasing complexity may cause malfunction
- Modifications to data structure nearly impossible
- Security features hard to make

### Structural and Data dependence

- Structural dependence
  - Access to file based on structure
- Data dependence
  - Change in DB structure change access way
    - Logical data format (How human see)
    - Physical data format (How computer see)

### Data Redundancy

- Data inconsistent, different, and conflicting
- Error more likely
- Data anomalies develop overtime
  - Modification/update anomalies
  - Insertion/addition anomalies
  - Deletion/removal anomalies

### Database vs File system

- File system
  - Many separate and unrelated files
- Database
  - Logically related data at single point

### Database System Environment

1. HW
2. SW
   1. DBMS
   2. OS
   3. Applications
3. People
4. Procedures
5. Data (some answers write Database/stored data, both are acceptable)

### DBMS Functions

- Perform function that guarantee integrity
  - **Data dictionary management (DDM)**
    - Define data elements & relationships
      - Note: Relationship:
        - one-to-one
        - one-to-many
        - many-to-many
  - **Data storage management (DSM)**
    - Store data & data information (metadata)
  - **Data transformation & presentation (DTP)**
    - Translate logical request into commands to get data
  - **Security management**
    - Enforce database security & data privacy
  - **Multi-user/Concurrency access control**
    - Create structure to allow multiple user to access data
  - **Backup and recovery management**
    - Provide backup and data recovery procedure
  - **Data integrity management**
    - Promotes and enforces integrity rules
      - Integrity rules:
        - *Entity* (ID, primary key)
        - *Referential* (Must be linked correctly)
        - *Domain* (Malaysia - M/F)
  - **Database access languages and API**
    - Receive query language and provide data access
  - **Database communication interfaces**
    - Allow database to accept end-user requests in network environment

Everything behind homework useless

## Exam

Basic terms