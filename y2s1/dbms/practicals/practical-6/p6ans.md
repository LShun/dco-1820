a. The manager of this restaurant wants to retrieve all data from the menu table in their restaurant’s
schema. Write SQL statement to fulfil the request. (1 Mark)

```sql
SELECT *
FROM MENU;
```



b. Write the SQL statement to get the employee number and the employee’s salary. (1 Mark)

```sql
SELECT EMPLOYEE_ID, SALARY
FROM EMPLOYEES;
```



c. Write the SQL statement to retrieve employee name, salary and the new salary of each employee.

Assume that the increment for each employee is $700. (2 Marks)

```sql
SELECT FIRST_NAME, LAST_NAME, SALARY, SALARY+700 AS NEW_SALARY
FROM EMPLOYEES;
```

d. Select unique customer number in order_lists’ table and rename it as “Customer No”. (2 Marks)

```SQL
SELECT 	DISTINCT CUST_NO
FROM 	ORDER_LIST OL, FOOD_ORDER FO
WHERE 	(OL.ORDER_NO = FO.ORDER_NO);
```



e. “Christina’s staff number is 1001”. Show the SQL for the output as above. (2 Marks)

```SQL
SELECT  STAFF_NAME || '''s staff number is ' || STAFF_ID
FROM 	STAFF

```

f. Select all data from staff table separate each column from the table with ‘-‘. (2 Marks)

```sql
SELECT STAFF_ID || '-' || STAFF_NAME || '-' || DATE_JOIN || '-' || BIRTH_DATE || '-' || SALARY AS STAFF_DATA
FROM STAFF;
```

OR

```sql
SET COLSEP '-'
SELECT *
FROM STAFF;
```