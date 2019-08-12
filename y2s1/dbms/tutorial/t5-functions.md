# T5 - Aggregate functions

15.	How many employees had been a Stock Clerk previously? (???)

```sql
SELECT  COUNT(*) AS PREVIOUS_STOCK_CLERK
FROM    JOB_HISTORY JH, JOBS J
WHERE   (JH.job_id  = J.job_id) AND
        (J.job_title   = 'Stock Clerk');
```

16.	How many current Stock Clerks are there?

```sql
SELECT  COUNT(*) AS Current_SC
FROM    EMPLOYEES E, JOBS J
WHERE   (E.job_id = J.job_id) AND
        (J.job_id = 'Stock Clerk');
```

17.	What is the total salary of all employees in the Marketing department?

```sql
SELECT  SUM(salary) AS  TOTAL_SALARY
FROM    EMPLOYEES E, DEPARTMENTS D
WHERE   (E.department_id = D.department_id) AND
        (D.department_name = 'Marketing');
```

Note: Variable names are acceptable as long as they make sense (aka: Don't use something like 'Individual Salary' for total salary)

18.	What is the average salary of all the Purchasing Clerk?

```sql
SELECT  AVG(salary) AS  Average_Salary
FROM    EMPLOYEES E, JOBS J
WHERE   (E.job_id  = J.job_id          )     AND
        (job_title = 'Purchasing Clerk');
```

19.	How many employees are there in Singapore?

```sql
SELECT  COUNT(*) AS EMPLOYEES_SG
FROM    EMPLOYEES E, DEPARTMENTS D, LOCATIONS L, COUNTRIES C
WHERE   (E.department_id = D.department_id) AND
        (D.location_id   = L.location_id)   AND
        (L.country_id    = C.country_id)    AND
        (C.country_id    = 'Singapore');
```

20.	What is the total salary of each department located in Singapore?

```sql
SELECT      D.department_id, D.department_name, SUM(E.Salary) AS Total_Salary_SG
FROM        EMPLOYEES E, DEPARTMENTS D, LOCATIONS L, COUNTRIES C
WHERE       (E.department_id = D.department_id) AND
            (D.location_id   = L.location_id)   AND
            (L.country_id   = C.country_id)     AND
            (C.country_id    = 'Singapore')
GROUP BY    D.department_id, D.department_name;
```

21.	What are the departments in Australia that have at least 5 employees?

```sql
SELECT      D.department_id, D.department_name, COUNT(*) AS Total_Employees
FROM        EMPLOYEES E, DEPARTMENTS D, LOCATIONS L, COUNTRIES C
WHERE       (E.department_id = D.department_id) AND
            (D.location_id   = L.location_id)   AND
            (L.country_id   = C.country_id)     AND
            (C.country_id    = 'Australia')
GROUP BY    D.department_id, D.department_name
HAVING      (Total_Employees > 5);
```

Alternative answer:

Subquery -- 

```sql
SELECT department_id, department_name, Employees
FROM	(	SELECT	D.department_id,
         			D.department_name, 		
         			COUNT(*) AS Employees
					FROM	EMPLOYEES E, DEPARTMENTS D
                    WHERE	(E.department_id = D.department_id)
         			GROUP BY	D.department_id, D.department_name
					)
WHERE	Employees >= 5;
```

Put it simply, the inner subquery fetches all the departments with their respective employee counts. The outer query filters the outputs from the inner subquery by only selecting those with employee count more than 5.

22.	How many employees earn more salary than John Russel?

```sql
SELECT      COUNT(*) AS 'Higher than John Russel'
FROM        Employees E1, Employees Others
WHERE       (E1.first_name = 'John') AND
            (E1.last_name  = 'Russel') AND
            (Others.salary > E1.salary);
```

## Sub-query

23.	Identify the employee with the highest salary.

```sql
SELECT  employee_id, first_name, last_name, salary
FROM    Employees
WHERE   salary  = (SELECT MAX(salary)
                   FROM   employees);
```

24.	Identify the employee for the job that has the highest salary. Include relevant information.

```sql
SELECT  employee_id, first_name, last_name, E.job_id, E.job_title, salary
FROM    Employees E, Jobs J
WHERE   E.job_id IN
        (SELECT job_id
         FROM   jobs
         WHERE  max_salary  =   (SELECT MAX(MAX_SALARY)
                                 FROM   jobs) AND
                                    E.job_id = J.job_id);
```

