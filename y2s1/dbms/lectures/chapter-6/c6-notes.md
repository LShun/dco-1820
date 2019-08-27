# C6: Advanced SQL

## 1. Terminology

1. **View:** Virtual table based on a SELECT query
2. **Base table:** The table depended by a view

## Virtual Table

- Not an actual table
- No restrictions when inserting and updating

### Types of view

- Simple view
  - Contain query retrieving from ONE table
- READING VIEW
  - view only
- Complex view
  - Retrieve for MULTIPLE table
  - Use grouping / distinct function
  - Contain function call
- Subview
  - View from another view

## Non-equivalent-joins

- AKA Nonequijoins. **Joins which uses a comparison operator** instead of an equality (equivalent-joins) operator.

- Example:

  ```sql
  SELECT	e.last_name, e.salary, j.grade_level
  FROM Employee e JOIN job_grades j
  ON	 e.salary
  	 BETWEEN j.lowest_sal AND j.highest_sal;
  ```

- This join will join these two tables

  - ![Non-equijoins Before](../../intro.oop.non-code/lectures/img/c6-nonequijoins-before)

- Into this table

  - ![Nonequijoins After](../../intro.oop.non-code/lectures/img/c6-nonequijoins-after.png)

## CREATE views

- **Materialized view / View materialization**: Disk based, updated periodically based on query definition.
- **View / View Resolution:**  Virtual only, run query definition each time accessed.

## DROP view

- Syntax: `DROP VIEW ViewName[RESTRICT (default)|CASCADE]`
  - If `RESTRICT (default)` is specified, but there are other objects dependent on the view-to-be-deleted, the command is rejected
  - If `CASCADE` is specified, `DROP VIEW` delete all dependency along with the object.

## JOIN-ON clause

```sql
SELECT 	R.Rno, FName, LName, Pno, VComment
FROM 	Renter R JOIN Viewing V ON R.Rno = V.Rno;
```

Similar to bridge entity.

### Syntax

```sql
FROM TABLE1 T1
	 [LEFT/RIGHT OUTER/INNER]
	 JOIN TABLE2 T2
	 ON (T1.Column1 = T2.Column2);
```

- `INNER` join. 
  - Return matching rows.
  - Unnecessary to be explicitly specified, as all joins are considered `INNER` unless specified.
- `OUTER` join
  - Return non-matching rows.
- `LEFT` join
  - Return non-matching rows from table BEFORE the `JOIN` clause. (AKA the table on the left of the `JOIN` keyword)
- `RIGHT` join
  - Return non-matching rows from table AFTER the `JOIN` clause. (AKA the table on the RIGHT of the `JOIN` keyword.

## Set Operators

![Oracle Set Operators](../../intro.oop.non-code/lectures/img/c6-set-operators-circles.png)

### Set Operator Guidelines

- **Come back later**

- Syntax:

  ```sql
  SELECT ...
  FROM   ...
  SETOPERATOR
  SELECT ...
  FROM   ...
  ```

  - Where `SETOPERATOR` is one of the Oracle SQL's set operator

### Set Operator Behaviors

- **Duplicate rows**: automatically eliminated except in `UNION ALL`
- **Column names**: from first query
- **Default sorting**: Ascending order except in `UNION ALL`

### Oracle SQL Set Operators

#### `UNION` Operator

#### Behavior

- Return rows from both queries. 
- Eliminate duplicates.

#### Usage

Specification: 

- For each employee, display current and previous job details. 
- No duplicate employees.

Syntax:

```sql
SELECT 	employee_id, job_id
FROM   	employees
UNION  	
SELECT 	employee_id job_id
FROM 	job_history;	
```

#### `UNION ALL` Operator

##### Behavior

- Return rows from both queries. 
- **Keep duplicates**.

##### Usage Example

- Display current and previous department of employees

#### `INTERSECT` Operator

##### Behavior

- Return rows common to both queries.

##### Usage Example

- Display employees who have changed jobs, but returned to the same job (if they went back to same job, then their current job should match with a row on their job history)

#### `MINUS` Operator

##### Behavior

- Return distinct rows in first query
- **Condition:** Rows must not be in second query

##### Usage Example

- Display employee who never changed jobs. (If they have changed jobs, their employee's ID should present in their job history)

## Matching Statements

- When performing table joining, several rules must be followed

### Matching `SELECT` statements

- **Columns not present in one table:** 
  - Must be matched (using TO_CHAR, or other conversion functions) when columns do not exist.
- Example (if `state_province` and `sales` is not found in first table)

```sql
SELECT 	location_id, 
		TO_CHAR(NULL) "Warehouse location", 
		0
FROM   	departments
UNION
SELECT 	location_id, 
		state_province,
		sales
FROM 	locations;
```

### Using `ORDER BY` clause

#### Condition

- Can only appear once at the end of the compound query.
  - Means cannot have individual `ORDER BY`

#### Behavior

- Recognize only columns of first `SELECT`query
- **Default:** Sort in ascending by first column of first `SELECT` query.

## Exercise Questions

Q57 (No restriction)

```sql
CREATE OR REPLACE VIEW B5Manager AS {
	SELECT *
	FROM Staff
	WHERE Bno = 'B5';
}

SELECT * FROM B5Manager;

INSERT INTO B5Manager(Sno, FName, LName, Position,Se, Salary, Bno) VALUES('SS02', 'Raymond', 'Alvin', 'Technician', 'M', 2500.00, 'B2');
```

Q57 (Read only)

```sql
CREATE OR REPLACE VIEW B5Manager AS {
	SELECT *
	FROM Staff
	WHERE Bno = 'B5'
	WITH READ ONLY CONSTRAINT read_only;
}

SELECT * FROM B5Manager;

INSERT INTO B5Manager(Sno, FName, LName, Position,Se, Salary, Bno) VALUES('SS02', 'Raymond', 'Alvin', 'Technician', 'M', 2500.00, 'B2');
```

- Will cause error, ORA-43299, cannot perform DML operation on read-only view. Never come out in assignment

Q58

```sql
CREATE OR REPLACE VIEW B5Staff AS
SELECT	Sno, FName, LName, Position, Tel_No
FROM	B5Manager;
```

Q59

```sql
DROP VIEW B5Staff;
```

Q60 (Don't just JOIN ON as much as possible, unless question ask)

```sql
/* Avoid this as much as possible */
SELECT 	R.Rno, FName, LName, Pno, VComment
FROM	Renter R, JOIN Viewing V ON R.Rno = V.Rno;
/* Natural join, use this */
SELECT 	R.Rno, FName, LName, Pno, VComment
FROM	Renter R, Viewing V
WHERE	R.Rno = V.Rno;
```

Q61

```sql
/* Avoid this as much as possible */
SELECT 		B.Bno, B.City, S.Sno, FName, LName, Pno
FROM 		Branch B JOIN Staff S ON B.Bno = S.Bno
			JOIN Property_For_Rent P ON S.Sno = P.Sno
ORDER BY 	B.Bno, S.Sno, Pno;

/* Natural join, use this */
SELECT 		B.Bno, B.City, S.Sno, FName, LName, Pno
FROM 		Branch B, Staff S, Property_For_Rent P
WHERE		B.Bno = S.Bno AND S.Sno = P.Sno
ORDER BY 	B.Bno, S.Sno, Pno;
```

Q62 (Recursive Query) - Exam never come out

```sql
SELECT	S.Sno, S.Fname, S.MGR_Sno, M.FName, M.LName
FROM	Staff S, Staff1 M,
WHERE	S.MRG=Sno = M.Sno
ORDER BY	S.MGR_Sno;
```

Q63 :star: HOT TOPIC 

- LEFT JOIN means focus on left table, and find joining on RIGHT table
- RIGHT JOIN means focus on right table, and find joining on LEFT table

- INNER JOIN means intersect/and in math.
- OUTER JOIN means union/or in math.
- FULL JOIN two add together.

**Right outer join**

```sql
SELECT	B.*, P.*
FROM	Branch1 B RIGHT OUTER JOIN Property_For_Rent1 P
		ON B.Bno = P.Bno;
```

Q65

```sql
SELECT	B.*, P.*
FROM	Branch1 B RIGHT FULL JOIN Property_For_Rent1 P
		ON B.Bno = P.Bno;
```

Set Operations

UNION: Remove duplicate

UNION ALL: Remain Duplicate

Q66

```sql
SELECT * FROM StaffA
UNION ALL
(SELECT * FROM StaffB);
```



## Past Year Exercise

| Staff_Code | Staff_Name | Position   |
| ---------- | ---------- | ---------- |
| M01        | John Tan   | Manager    |
| E01        | Ahmad      | Executive  |
| S01        | Gopal      | Supervisor |

| Project_no | Staff_Code |
| ---------- | ---------- |
| 1010       | M01        |
| 1011       | E01        |
| 1012       | E01        |
| 1013       | C01        |

Staff Right Outer JOIN Project

| Staff_Code | Staff_Name | Position  | Project_No |
| ---------- | ---------- | --------- | ---------- |
| M01        | John Tan   | Manager   | 1010       |
| E01        | Ahmad      | Executive | 1011       |
| E01        | Ahmad      | Executive | 1012       |
| C01        |            |           | 1013       |

Staff Left Outer JOIN Project

| Staff_Code | Staff_Name | Position   | Project_No |
| ---------- | ---------- | ---------- | ---------- |
| M01        | John Tan   | Manager    | 1010       |
| E01        | Ahmad      | Executive  | 1011       |
| E01        | Ahmad      | Executive  | 1012       |
| S01        | Gopal      | Supervisor |            |

**Note: No marks are penalized for improper order**

# Practice

```SQL
SELECT 	location_id, department_name "Department", TO_CHAR(NULL) "Warehouse location"
FROM	departments
UNION
SELECT 	LOCATION_ID, TO_CHAR(NULL) "Department", state_province
FROM	locations;
```

```sql
SELECT employee_id, job_id, salary
FROM 	employees
UNION
SELECT 	employee_id, job_id, 0
FROM 	job_history
```

