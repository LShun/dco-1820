# Tutorial 3: SQL

Discussion: Write a SQL queries to each of the following questions.

## Basic idea on how to write

1. Start with the `FROM`, to know which table you neeed
2. Proceed with `WHERE` to specify condition, skip if unnecessary
3. Finish off with `SELECT` to complete the entire statement

Modify where necessary.

## Q&A

4. Write SQL statements to do the following simple queries:

a. Show the manager for each department, include relevant information

```sql
SELECT manager_id, department_id, department_name
FROM DEPARTMENTS;
```

b. Show *all* employees with the first name ‘Alexander’.

```sql
SELECT *
FROM EMPLOYEES
WHERE first_name = 'Alexander';
```

c. Show *all* employees belonging to department 170.

```sql
SELECT *
FROM EMPLOYEES
WHERE department_id = 170;
```

d. Show all employees earning less than 10,000 belonging to department 170, ordering
the result from the highest to the lowest salary.

```sql
SELECT *
FROM EMPLOYEES
WHERE salary < 10000 AND department_id = 170
ORDER BY salary DESC;
```

e. Show all jobs that pay at least 15,000 salaries.

```sql
SELECT *
FROM JOBS
WHERE (min_salary >= 15000) OR 
      (max_salary >= 15000);
```

Note: parenthesis is usually not required, but is recommended to prevent possible undesired operator precedence.

f. List all locations with a street address that has the lucky number “8” in it.

```sql
SELECT *
FROM LOCATIONS
WHERE street_address LIKE '%8%';
```

g. List all locations with a post code that ends with “18” or “28” or “98”.

```sql
SELECT *
FROM LOCATIONS
WHERE (postal_code LIKE '%18') OR
      (postal_code LIKE '%28') OR
      (postal_code LIKE '%38');
```

Note: Multiple conditions can also be used without parenthesis -- `()`.

h. List all employees between the ages of 45 to 50 years old

```sql
SELECT *
FROM EMPLOYEES
WHERE   (age >= 45) AND
        (age <= 50);
```

*Note: Assuming that `age` is a field