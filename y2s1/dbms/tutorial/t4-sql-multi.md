# Tutorial 4: SQL with multiple statements

## Multiple table queries

9. List employees working in the state province of California.

```sql
SELECT E.employee_id, E.first_name, E.last_name, D.department_name
FROM EMPLOYEES E, DEPARTMENTS D, LOCATIONS L
WHERE (E.employee_id = D.department_id) AND
      (D.location_id = L.location_id) AND
      (L.state_province = 'California');
```

10.	List employees working in countries beginning with the letter A.

```sql
SELECT E.employee_id, E.first_name, E.last_name
FROM    EMPLOYEES E, DEPARTMENTS D, LOCATIONS L, COUNTRY C
WHERE   (E.department_id = D.department_id) AND
        (D.location_id = L.location_id)     AND
        (L.country_id = C.country_id)       AND
        (C.country_name LIKE '%A%');
```

11.	List all employees that had worked as a "SALES REPRESENTATIVE" previously (not including the current job).

```sql
SELECT  E.employee_id, E.first_name, E.last_name
FROM    EMPLOYEES E, JOB_HISTORY JH, JOBS J
WHERE   (E.employee_id  =   JH.employee_id)         AND
        (JH.job_id      =   J.job_id)               AND
        (UPPER(J.job_title)   =   'SALES REPRESENTATIVE');
```

Note: Assuming that the JOB_HISTORY table only updates when the employee changes a job

12.  Show the salary details for the IT department.

```sql
FROM 	DEPARTMENTS D, EMPLOYEES E, JOBS J
WHERE   E.JOB_ID = L.JOB_ID AND
        E.department_id = D.department_id AND
        D.department_name = 'IT';
```

