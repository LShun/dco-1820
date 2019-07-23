# IntroDB P8 - SELECT Statements

A

```sql
SELECT  *
FROM    menu M, category C,
WHERE   M.cat_id = C.cat_id AND
        C.description = "Rice main course";
```

B

```sql
SELECT  C.cust_no, C.cust_name, C.email
FROM    CUSTOMER C, FOOD_ORDER F
WHERE   C.cust_no = F.cust_no AND
        F.order_no IN (3001, 3002);
```

C

```sql
SELECT  C.cust_no, C.cust_name, C.email, C.gender AS GENDER
FROM    CUSTOMER C, FOOD_ORDER F
WHERE   C.cust_no = F.cust_no AND
        F.order_no IN (3001, 3002) AND
        C.gender = 'M';
```

D (Note: Cannot use small letter C inside quotes because it is case-sensitive)

```sql
SELECT  *
FROM    menu
WHERE   description LIKE '%C%';
```

E

```sql
SELECT  *
FROM    customer
WHERE   phone IS NULL AND
        cust_name LIKE 'M%';
```

F

```sql
SELECT      description AS MENU
FROM        menu
ORDER BY    description DESC;
```

G 

```sql
SELECT      staff_id, staff_name, salary
FROM        staff
ORDER BY    salary;
```

H

```sql
SELECT      staff_id, staff_name, salary
FROM        staff
ORDER BY    salary DESC;
```

I

```sql
SELECT      staff_id, staff_name, salary
FROM        staff
ORDER BY    staff_name, salary;
```

J

```sql
SELECT      staff_id, staff_name, salary
FROM        staff
WHERE	    salary < &Salary;
```

