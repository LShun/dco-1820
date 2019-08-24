# Lecture 3: SQL - Part 1, Basic SQL Manipulation


## Custom notation

1. {something} refers to custom input

2. SQL fits into two broad categories:
   1. Data definition language 
      1. Include commands to create database objects & define access rights
   2. Data manipulation language
      1. commands to insert, update, delete, and retrieve data within database

## Intro to SQL

1. SQL statement: reserved words + user-defined words
   1. reserved words: fixed meaning, 'character-sensitive'
2. Most SQL statements are case insensitive but 'character-sensitive', literal character data must be exact.
3. Use `;`, statement terminator to mark end of SQL statement


## Common SQL data manipulation commands

1. `SELECT`
2. `ORDER BY`
3. Mathematical operators
4. Logical operators
5. Special operators
6. Aggregate functions
7. `INSERT`, `UPDATE`, `COMMIT`, `ROLLBACK`

## Defining a column alias

1. Immediately follow the column name
2. Can be used with `AS` keyword
3. Double quotation: enables the user of space and case-sensitive works
4. In SQL*PLUS, using a column aliases without quotations will display all the titles as full capital letters.

## Duplicate rows

Use `DISTINCT` to exclude duplicate rows

`SELECT DISTINCT department_id FROM employees;`

Duplicate means EXACT duplicate, if even a single place is non-duplicate (like say you have more than one column and it differs), it is displayed

## Restricting and sorting data

### SQL SELECT statement

Syntax:

```sql
SELECT  *|{[DISTINCT] column|expression [alias],...}
FROM    table
[WHERE  condition(s)]
[ORDER BY {column, expr, alias} [ASC|DESC]] ;
```

Oh, remember the `;`, semi-colon at the end.

- Limit rows with:
  - `WHERE` clause
  - Comparison & Logical conditions
- NOTE: Rules of precedence
- Sort rows using the `ORDER BY` clause

- Enclose character strings & dates with single-quotes
- Character is case-sensitive and date values are format-sensitive
- Default date format `DD-MON-YY` in SQL*PLUS (damn why not DD-MM-YY?!)


## Range condition with `BETWEEN`

- Used with `WHERE`
  - Example: `WHERE` salary `BETWEEN` xxx `AND` xxx

## Membership Condition Using the `IN` Operator

- Test for values in a list
  - Eg: `WHERE` manager_id `IN` (100, 101, 201);

## Pattern Matching Using the `LIKE` operator

- Perform wildcard searches of valid string values, conditions can be:

- characters/numbers (case-sensitive)
- Wildcards
  - `%` denotes 0 or more character
  - `_` denotes 1 character
- they can be combined

## Using NULL Condition

`WHERE manager id IS NULL;`

## Logical Operators

1. `AND`
2. `OR`
3. `NOT`
4. Returns `true` if true according to the requirements

## Rules of precedence

1. Arithmetic
2. Concatenation
3. Comparison
4. Negation, Null
5. Betweens
6. Not equal
7. Logical conditions

## `ORDER BY` clause

### Example usage:

```sql
SELECT {key}
FROM   {table}
ORDER BY first_name DESC;
```

- sorting sequence:
  - `ASC` = ascending (default if not specified)
  - `DESC` = descending

- sorting way (pair with sorting sequence, default is `ASC`):
  - `{field_name}` = sort by the field name
  - `{alias}`  = sort by the column's alias
  - `{number}` = sort by the column's numeric position, wher `number` should be n integer.
    - Example: if say your table has `first_name` at position 1 and `last_name` at position 2, entering `ORDER BY 2;` will order it by `last_name`
- Comes last

## Displaying Data from Multiple Statements

### SELECT statement

- Used to query single or multiple tables.
- Clauses
  - `SELECT`: which column
  - `FROM`: which table
  - `WHERE`: condition is specified (for rows)
  - `GROUP BY`: what category
  - `HAVING`: condition specified (for groups)
  - `ORDER BY`: the order and/or the column

### Flow Chart of Processing Statement

![SQL Statement Flow Chart](img/sql-statement-flow.jpg)

### Going from Pseudocode to SQL Statements

1. Identify which table is required
   1. `FROM EMPLOYEES, DEPARTMENTS`
2. Specify your condition
   1. `WHERE EMPLOYEES.Department_ID = DEPARTMENT.department_ID`
3. Specify what to display
   1. `SELECT EMPLOYEES.employee_ID, EMPLOYEES.department_ID, DEPARTMENTS.department_name`
4. Combine them together, starting from `SELECT` to `FROM` and lastly, `WHERE`, then add a `;` to form an SQL statement

```sql
SELECT EMPLOYEES.employee_ID, EMPLOYEES.department_ID, DEPARTMENTS.department_name
FROM EMPLOYEES, DEPARTMENTS
WHERE EMPLOYEES.Department_ID = DEPARTMENT.department_ID
```

### Simplifying SQL statements

1. Use aliases to simplify SQL statement

Example:

```sql
FROM EMPLOYEES E, DEPARTMENTS D
```

then, replace every other occurences of `EMPLOYEES` with `E`, and `DEPARTMENTS` with `D`

### Query Answers

Query: Display employees job history from when he/she was first hired. Include relevant details.

```sql
SELECT E.employee_id, E.first_name, E.last_name, J.start_date 
FROM JOB_HISTORY J, EMPLOYEES E
WHERE J.employee_id = E.employee_id;
```

```sql
SELECT E.first_name, E.last_name, R.region_name
FROM EMPLOYEES E, REGIONS R,
     DEPARTMENTS D, LOCATIONS L,
     COUNTRIES C
WHERE E.department_id = D.department_id          AND D.location_id = L.location_id
      AND L.country_id = C.country_id
      AND C.region_id = R.region_id;
```

## Reporting Aggregated Data Using the Group Functions

Types of group functions:
- `AVG`
- `COUNT`
- `MAX`
- `MIN`
- `SUM`

Note: Functions are always *one-to-one* or *one-to-many*, no function can be *many-to-many*.

## `AVG` and `SUM` functions

- Numeric data
- Use for numeric data, the format is `group_function(column)`
- Example: `AVG(salary)`

## `MIN` and `MAX`

- Numeric, character, and date data 
- Example:

```sql
SELECT  MIN(hire_date), MAX(hire_date)
FROM    employees;
```

## `COUNT`

- return the number of row in a table
- note: only non-null values

```
SELECT  COUNT(*)
FROM    employees
```

## `DISTINCT`

- `COUNT(DISTINCT expr)` return number of *distinct* non-null values of expr.

## `NVL`

- Forces group functions to include null values
- Example: `SELECT AVG(NVL(commission_pct, 0)) FROM emloyees;

## `GROUP BY`

GROUP BY returns one row for each unique combination of fields in the GROUP BY clause. To ensure only one row, you would have to use an aggregate function - COUNT, SUM, MAX - without a GROUP BY clause.

```sql
SELECT    column, group_function(column)
FROM      table
[WHERE    condition]
[GROUP BY group_by_expression]
[ORDER BY column];
```

- columns in `SELECT` that are not in group functions (eg. `AVG`) must be in `GROUP BY` clause
- columns in `GROUP`

## Illegal queries using group functions

- Any column or expression in the `SELECT` which is not in an aggregating function must be in `GROUP BY`, otherwise the DBMS do not know how to combine details which are aggregated and non-grouped together.

## Restricting group results

`HAVING` clause:

1. Rows are grouped.
2. The group function is applied.
3. Group matching the `HAVING` clause are displayed

## Inserting Values

### Inserting new rows

- List value in default order:

Basic syntax: 

```sql
INSERT INTO `table`(`table_fields`)
VALUES (70, 'Public Relations', 100, 1700);
```

### Inserting with null values

- **Implicit method**: Omit from column list
  - Exclude the table fields & values related when using `INSERT INTO`
- **Explicit method**: Specify `NULL` keywords in the `VALUES`

### Inserting special values

- `SYSDATE`
  - records current date & time
  - Entered inside `VALUES` list

- `TO_DATE('MON DD, YYYY')`
  - specific date & time values

### Copying rows from another table

Write `INSERT` statement with subquery:

Syntax:

```sql

INSERT INTO `table2`
SELECT `fields` FROM `table1`
WHERE `condition`;

```

Note:
`table2` refers to your destination table
`fields` refer to the fields you want to copy (along with their values)
`table1` refers to your source table
`condition` refers to...well 'only copy if this is true'.

## `UPDATE`

- Modify existing values
- Syntax:

```sql
UPDATE  table
SET     column = value[, column = value, ...]
[WHERE  condition];
```

Notes:
`table` refers to the table you intend to update
`column` refers to a column name
`value` refers to the value you want to set the column to.
`[]` represents optional values

### Updating rows in the table

- Caution: If `WHERE` is ommited, all values are modified
  `SET column_name=NULL` to update to `NULL`

### Updating Multiple column with subquery

Same as syntax, but for the `value`, use a `SELECT` statement instead.

## `DELETE` statement

Syntax:

```sql
DELETE [FROM] table
[WHERE        condition];
```

### Deleting rows from tables

Syntax:

same as the original `DELETE`, but for the condition:

`WHERE column_name = value`

Notes:
`column_name` is the column storing the value you are looking for.
`value` is the matching value.

### Deleting rows based on another table

Syntax: same as the original `DELETE`, but for condition's value, you want to put another `SELECT` statement in. Note that it should only return 1 value, therefore, using `*` is a silly idea.

## Extra Notes

```sql
SELECT display columns
FROM some table
WHERE single row condition
GROUP BY group the same item together
HAVING sum(salary) > 10000 (group condition)
ORDER BY arrange for columns ASC (A -> Z) / DESC (Z->A) [Note: if put and question dont ask, will not help you get marks]
```

Sum the total survey for each branch:

`group by`

Sum the total survey for each branch which salary > 10000:

`having`

If question have `each`, need to use `group by`
If how many person, then use `count`
If `count` or `sum up` keywords then use `group by`
If have condition, then use `having`

### SQL Q&A

Q1

```sql
SELECT *
FROM staff;
```

Q2

```sql
SELECT Sno, FName, LName, Salary
FROM staff;
```

Q3

```sql
SELECT Sno, FName, LName, Salary
FROM staff
WHERE Sno = 'SL21';
```

Q4

```sql
SELECT Sno, FName, LName, Salary/12 AS Monthly_Salary
FROM staff
```

Q5

```sql
SELECT Sno, FName, LName, Salary
FROM staff
ORDER BY Salary;
```

Q6

```sql
SELECT Sno, FName, LName, Salary
FROM staff
ORDER BY Salary DESC;
```

Q7

Produce an abbreviated list of properties arranged in order of property type and in descending order
of rent within the same property type

```sql
SELECT Pos, Type, Rooms, Rent
FROM Property_For_Rent
ORDER BY Type, Rent DESC;
```

Q8

List the names of all renters who have viewed a property along any comment supplied.

```sql
SELECT R.Rno, FName, LName, Pno, VComment
FROM Renter R, Viewing V
WHERE R.Rno = V.Rno;
```

Why need `R.`?

Note:

Foreign Key join Foreign Key = Nothing
PK join FK get something

Because the field clash, other didn't problem.

Q9

```sql
SELECT Sno, FName, LName, Salary
FROM Staff S, Branch B
WHERE S.Bno = B.Bno AND street = '163 Main St';
```

Or, the subquery way:

```sql
SELECT Sno, FName, LName, Salary
FROM Staff S
WHERE Bno = (SELECT Bno
             FROM Branch
             WHERE street = '163 Main St');
```

Or the multiple-results way:

```sql
SELECT Sno, FName, LName, Salary
FROM Staff S
WHERE Bno IN (SELECT Bno
             FROM Branch
             WHERE street = '163 Main St');
```

Q10

For each branch office, list the names of staff who manage properties, and the properties
they manage. Arrange the branch number, staff number and property number in ascending
order.

```sql
SELECT Sno, S.Sno, FName, LName, Pno
FROM Staff S, Property_For_Rent P
WHERE S.Sno = P.Sno
ORDER BY S.Bno, S.Sno, Pno;
```

Q11

```sql
SELECT B.Bno, B.City, S.Sno, FName, LName, Pno
FROM Branch B, Staff S, Property_For_Rent P
WHERE B.Bno = S.Bno AND S.Sno = P.Sno
ORDER BY B.Bno, S.Sno, Pno;
```

Q12

```sql
SELECT *
FROM staff
WHERE Sno <= 'SG37';
```

Q13

```sql
SELECT *
FROM staff
WHERE Salary > 10000;
```

Note: Don't put dollar sign, because store in column no dollar sign.

Q14

```sql
SELECT *
FROM Viewing
WHERE VDate >= '01-May-1998' AND VDate <= '31-May-1998';
```

```sql
SELECT *
FROM Viewing
WHERE VDate BETWEEN '01-May-1998' AND VDate '31-May-1998';
```

Q15

```sql
SELECT Bno, Street, Area, City, Pcode
FROM branch
WHERE City = 'London' OR City = 'Glasgow';
```

```sql
SELECT Bno, Street, Area, City, Pcode
FROM Branch
WHERE City IN ('London', 'Glasgow');
```

Q16

```sql
SELECT Bno, Street, Area, City, Pcode
FROM Branch
WHERE City = 'London' AND Area = 'Sidcup';
```

Since `Sidcup` is a subset of `London`

```sql
SELECT Bno, Street, Area, City, Pcode
FROM Branch
WHERE Area = 'Sidcup';
```

Q17

```sql
SELECT Sno, FName, LName, Salary
FROM Staff
WHERE Sno NOT LIKE 'SG37';
```

For the last line, we could go with:

```sql
WHERE Sno <> 'SG37';
```

or

```sql
WHERE Sno != 'SG37';
```

Q18

```sql
SELECT *
FROM Staff
WHERE Sex = 'F' AND Position IN ('Manager', 'Assistant');
```

```sql
SELECT *
FROM Staff
WHERE Sex = 'F' AND (Position = 'Manager' OR Position = 'Assistant');
```

Note: Sequence >> brackets first, then `AND`, and `OR`

```sql
(SELECT *
FROM Staff
WHERE Sex = 'F' AND Position = 'Manager';)
UNION
(SELECT *
FROM Staff
WHERE Sex = 'F' AND Position = 'Assistant';)
```

```sql
SELECT *
FROM (SELECT Sno, FName, LName, Salary
      FROM Staff
      WHERE Position IN ('Manager', 'Assistant'))
WHERE Sex = 'F';
```

Q19

```sql
SELECT DISTINCT Pno
FROM Property_For_Rent P, Viewing V
WHERE V.Rno = P.Rno;
```

`DISTINCT` eliminates duplicate values

Extra Notes:

If question ask for count, then use `COUNT`

Q20

```sql
SELECT *
FROM Staff
WHERE Salary BETWEEN 20000 AND 30000;
```

```sql
SELECT *
FROM Staff
WHERE Salary >= 20000 AND Salary <= 30000;
```

Q21

```sql
SELECT *
FROM Staff
WHERE Salary NOT BETWEEN 20000 AND 30000;
```

```sql
SELECT *
FROM Staff
WHERE NOT(Salary BETWEEN 20000 AND 30000);
```

```sql
SELECT *
FROM Staff
WHERE Salary < 20000 OR Salary > 30000;
```

```sql
SELECT *
FROM Staff
WHERE NOT(Salary <= 20000 AND Salary <= 30000);
```

Q22

```sql
SELECT *
FROM Viewing
WHERE Pno = 'PG4' AND VComment IS NULL;
```

Q23

```sql
SELECT *
FROM Viewing
WHERE Pno = 'PG4' AND VComment IS NOT NULL;
```

Q24

```sql
SELECT Sno, FName, LName, Address
FROM Staff
WHERE Address LIKE '%Glassglow%';
```

```sql
SELECT Sno, FName, LName, Address
FROM Staff
WHERE UPPER(Address) LIKE '%GLASSGLOW%';
```

Q25

```sql
SELECT *
FROM Owner
WHERE Tel_No NOT LIKE '0141-%';
```

Q26

```sql
SELECT      Sno, Fname, LName, Position
FROM        Staff
WHERE       Bno IN
            (     SELECT      Bno
                  FROM        Branch
                  WHERE Street IN ('163 Main St', '22 Deer Rd'));
```

```SQL
SELECT      Sno, Fname, LName, Position
FROM        Staff S
WHERE       EXISTS
            (     SELECT      *
                  FROM        Branch B
                  WHERE       S.Bno = B.Bno     AND
                              Street            IN    ('163 Main St', '22 Deer Rd'));
```

Q27

Note: If have `EXISTS` must have join condition

```sql
SELECT      Sex, FName, LName, Position
FROM        Staff
WHERE       Sno   NOT   IN    (SELECT     DISTINCT    Sno
                               FROM                   Property_For_Rent);
```

```sql
SELECT      Sno, FName, LName, Position
FROM        Staff S,
WHERE       NOT   EXISTS      (SELECT *
                               FROM   Property_For_Rent P
                               WHERE  S.Sno = P.Sno);
```

Q28

```sql
SELECT      COUNT(*)    AS    PropertyCount
FROM        Property_For_Rent
WHERE       RENT  >  350;
```

```sql
SELECT      COUNT(Pno)  AS    PropertyCount
FROM        Property_For_Rent
WHERE       RENT  >  350;
```

Note:
COUNT(*)    = count number of rows in table
COUNT(Pno)  = count number of rows in Pno attribute (skip the `NULL` values)

Q29

```sql
SELECT      COUNT(DISTINCT Pno)  AS DifferentPropertyCount
FROM        Viewing
WHERE       VDate BETWEEN '01-MAY-98' AND '31-May-98'
```

Q30

```sql
SELECT      COUNT(Sno)  AS ManagerCount, SUM(Salary) AS SumSalary
FROM        Staff
WHERE       Position = 'Manager';
```

Q31

Note, when question is "projection", then don't update. If `UPDATE`, then use `INSERT`

```sql
SELECT      SUM(Rent)         AS CollectionBeforeIncrement,
            SUM(Rent*1.1)     AS CollectionAfterIncrement,
            SUM(Rent*1.1) - SUM(Rent) AS DifferentValue
FROM        Property_For_Rent;
```

Q32

```sql
SELECT      MIN(Salary) AS MinSalary,
            MAX(Salary) AS MaxSalary,
            AVG(Salary) AS AverageSalary
FROM        Staff;
```

Q33

```sql
SELECT      Sno, FName, LName, Position, Salary
FROM        Staff
WHERE       Salary = (SELECT MAX(Salary) FROM Staff);
```

Q34

```sql
SELECT      Sno, FName, LName, Salary/12 AS Monthly_Salary
FROM        Staff
WHERE       Salary = (SELECT  MIN(salary) FROM Staff);
```

Q35

```sql
SELECT      Sno, FName, LName, Position,
            Salary - (SELECT  AVG(Salary)
                      FROM    Staff) AS Set_Diff;
FROM        Staff
WHERE       Salary = (SELECT  AVG(Salary)
                      FROM    Staff);
```

Q36

Keyword: Each branch

```sql
SELECT      Bno, COUNT(Sno) AS StaffCount, SUM(Salary) AS SumSalary
FROM        Staff
GROUP BY    Bno
ORDER BY    Bno;
```

Note: Everything in front, without an aggregate function in `SELECT` must be placed inside `GROUP BY`

Q37

```sql
SELECT      S.Bno, P.Sno, COUNT(Pno) AS PHCount
FROM        Staff S, Property_For_Rent P
WHERE       S.Sno = P.Sno
GROUP BY    S.Bno, P.Sno
ORDER BY    S.Bno, P.Sno;
```

Q38

Keyword: Because "each branch" and must more than 1 people, so need `HAVING`

```sql
SELECT      Bno, COUNT(Sno) AS StaffCount, SUM(Salary) AS SumSalary,
FROM        Staff
GROUP BY    Bno
HAVING      COUNT(Sno) >= 1
ORDER BY    Bno;
```

Q39 (Not coming out in final)

Note: Use `TRUNCATE` to cut off decimal point

```sql
SELECT      FName, LName, TRUNC((SYSDATE - DOB) / 365.25) AS Age
FROM        Staff
WHERE       (TRUNC((SYSDATE - DOB) / 365.25) BETWEEN 30 AND 50);
```

Q40

```sql
SELECT      FName || '' || LName AS "Full Name"
            EXTRACT(YEAR FROM (SYSDATE - DOB) YEAR TO MONTH) AS Age
FROM        Staff
WHERE       EXTRACT(YEAR FROM (SYSDATE- DOB) YEAR TO MONTH) > 21;
```

Q41

```sql
SELECT      *
FROM        (SELECT     Sno, FName, LName, Salary
             FROM       Staff
             ORDER BY   Salary DESC)
WHERE       ROWNUM <= 3;
```

EXTRA EXERCISE (Homework):

E01. List all the staff with his/her staff number, staff name and position who work at London.

ANSWER:

```sql
SELECT  Sno, FName, LName, Position
FROM    Staff
WHERE   Bno IN (SELECT Bno FROM Branch WHERE City = 'London');
```

NOTE: 2 branch where city is London

E02. For each staff, list the staff number, first name, last name, number of property handled for those staff that handles any properties.

```sql
SELECT  P.Sno, FName, LName, COUNT(Pno) AS Property_Count
FROM    Staff S, Property_For_Rent P
WHERE   S.Sno = P.Pno
GROUP BY P.Sno, FName, LName
```

E03. For **each** staff, list the staff number, first name, last name, number of property handled for those staff that handles **more than 1 property**.

```sql
SELECT  P.Sno, FName, LName, COUNT(Pno) AS Property_Count
FROM    Staff S, Property_For_Rent P
WHERE   S.Sno = P.Pno
GROUP BY P.Sno, FName, LName
HAVING COUNT(Pno) > 1
```

E04. For each staff, list the staff number, first name, last name for those staff that did not handles any properties.

```sql  **ASK**
SELECT  S.Sno, FName, LName, COUNT(Pno) AS "Property Handled"
FROM    Staff S, Property_For_Rent P
WHERE   S.Sno = P.Pno AND COUNT(Pno) = 0
GROUP BY S.Sno, FName, LName
```

ANSWER:

```sql
SELECT  S.Sno, FName, LName
FROM    Staff
WHERE   S.Sno NOT IN (SELECT DISTINCT Sno FROM Property_For_Rent);
```

ANSWER 2:

```sql
SELECT      Sno, FName, LName
FROM        Staff S
WHERE NOT EXIST (SELECT * FROM Property_For_Rent P WHERE S.Sno = P.Pno);
```

E05. For each staff, list the staff number, first name, last name, number of property handled for those staff that handles any properties. Arrange your output for number of property handled in descending order.

```sql
SELECT  P.Sno, FName, LName, COUNT(Pno) AS Property_Count
FROM    Staff S, Property_For_Rent P
WHERE   S.Sno = P.Pno
GROUP BY S.Sno, FName, LName
ORDER BY COUNT(Pno) DESC;
```

E06. For **each** staff, list the staff number, first name, last name, number of property handled for those staff that handles **more than 1 property**. Arrange your output for first name in ascending order.

```sql
SELECT  S.Sno, FName, LName, COUNT(Pno) AS "Property Handled"
FROM    Staff S, Property_For_Rent P
WHERE   S.Sno = P.Pno
GROUP BY S.Sno, FName, LName
HAVING COUNT(Pno) > 1
ORDER BY FName DESC
```

If got each, and also count and sum, at the same time having condition, then must use `HAVING`.

E07. List the renter number, renter name, property number, property address, property owner name, date viewed and comment for property that being viewed.

```sql
SELECT  R.FName, R.LName, P.Pno, P.Street, P.Area, P.City, P.Pcode, O.FName, O.LName, V.VDate, V.VComment
FROM    Renter R, Property_For_Rent P, Owner O, Viewing V
WHERE   V.Rno = R.Rno AND
        V.Pno = P.Pno AND
        P.Ono = O.Ono

```

E08. For each branch, list the branch number, branch city and its total monthly salary for all its staff.

```sql
SELECT      B.Bno, B.City, SUM(S.Salary/12) AS Total_Monthly_Salary
FROM        Branch B, Staff S
WHERE       B.Bno = S.Bno
GROUP BY    S.Bno, B.City
```

ASK: Can we use `B` instead of `S`? Answer: Yes.

E09. For each branch, list the branch number, branch city and its total monthly salary for all its staff which more than 3000.

```sql
SELECT      B.Bno, B.City, SUM(S.Salary/12) AS Total_Monthly_Salary
FROM        Branch B, Staff S
WHERE       B.Bno = S.Bno
GROUP BY    B.Bno, B.City
HAVING      SUM(S.Salary/12) > 3000
```

E10. List all the staff name and his/her age between the age of 40 to 60 years old and the salary between 5,000 to 20,000.

```sql
SELECT      FName, LName, TRUNC((SYSDATE - DOB) / 365.25) AS AGE
FROM        Staff
WHERE       TRUNC((SYSDATE - DOB) / 365.25) BETWEEN 40 AND 60
            AND Salary >= 5000 AND
            Salary <= 20000
```

Note: `AGE` is a column name, not a formula, therefore, we cannot use it inside `WHERE`

E11. List all the area and city of branch with post code that end with 'H','U','X'.

```sql
SELECT      Area, City
FROM        Branch
WHERE       Pcode LIKE IN ('%H', '%U', '%X')
```

Question: Can we use `IN`? 

E12. List all staff details with the salary more than or equals to average.

```sql
SELECT *
FROM Staff
WHERE Salary >= (
            SELECT AVG(Salary)
            FROM   Staff
);
```

E13. How many staff earn more than David Ford. ASK

```sql
SELECT COUNT(*) AS Staff_Count
FROM Staff
WHERE Salary > (
            SELECT Salary
            FROM   Staff
            WHERE  FName = 'David' AND
                   LName = 'Ford'
)
```

E14. Find the different between the higher salary and lowest salary

```sql
SELECT MAX(Salary) - MIN(Salary) AS Diff
FROM Staff
```

Q42

```sql
INSERT INTO Staff
VALUES('SG16', 'Alan' 'Brown', '67 Endrick Rd, Glasglow G32XQX', '014-223-3333', 'Assistant', 'M', DATE '1987-05-255', 6300, 'WN848391R', 'B3');
```

Q43

```sql
INSERT INTO Staff(Sno, FName, LName, Position, Sex, Salary, Bno) VALUES ('SG44', 'Anne', 'Jones', 'Assistant', 'F', 8910, 'B3');
```

OR

```sql
INSERT INTO Staff
VALUES ('SG44', 'Anne', 'Jones', NULL, NULL, 'Assistant', 'F', NULL, NULL, NULL, 'B3');
```

Q44 (WON'T COME OUT IN FINAL)

```sql
INSERT INTO Staff_Handling_Count(Sno, FName, LName, PCount)
SELECT      P.Sno, FName, LName, COUNT(Pno)
FROM        Staff S, Property_For_Rent P
WHERE       S.Sno = P.Sno
GROUP BY    P.Sno, FName, LName;
```

Note: Assume Staff_Handling_Count table already created in DreamHome database;

Q45

```sql
UPDATE      STAFF
SET         Salary = Salary * 1.03;
```

Q46

```sql
UPDATE      STAFF
SET         Salary = Salary * 1.05;
WHERE       Position = 'Manager';
```

NOTE: `AND` is only used in `WHERE`

Q47

```sql
UPDATE      STAFF
SET         Position = 'Manager', Salary = 18000
WHERE       Sno = 'SG14';
```

Note: Update by reference and delete by reference very popular

Q48

```sql
UPDATE Staff
SET    Salary = Salary * 1.05
WHERE Bno IN (SELECT Bno
FROM Branch
WHERE City = 'London');
```

Q49

```sql
DELETE FROM Viewing;
```

Q50

```sql
DELETE FROM Viewing
WHERE Pno = 'PG4';
```

Q51

```sql
DELETE FROM Viewing
WHERE Pno IN (SELECT    Pno
              FROM      Property_For_Rent
              WHERE     City = 'Glasglow');
```

Q52

```sql
ALTER TABLE Branch
MODIFY      (Tel_No VARCHAR(14));
```

Note: You can only extend, cannot cut short

Q53

```sql
ALTER TABLE Branch
ADD (Branch_Email VARCHAR(50));
```

Q54

```sql
ALTER TABLE Branch
DROP COLUMN Fax_No;
```

Q55

```sql
ALTER TABLE Staff
MODIFY SEX DEFAULT NULL;

ALTER TABLE Staff
MODIFY      Position DEFAULT 'Assistant';
```

Q56

```sql
DROP TABLE Branch;
```