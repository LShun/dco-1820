# T11 : IntroDB - View Statements

## Q1

```sql
CREATE VIEW RICH_EMPLOYEE AS
SELECT employee_id, first_name, last_name, email
FROM EMPLOYEES 
WHERE salary > 10000;
```

## Q2

```sql
CREATE 	VIEW HIGH_SALARY AS
SELECT 	employee_id, first_name, last_name, salary*12 AS yearly_salary
FROM 	EMPLOYEES
WHERE	yearly_salary > 10000;
```

or 

```sql
CREATE 	VIEW HIGH_SALARY AS
SELECT 	employee_id, first_name, last_name, salary*12 AS yearly_salary
FROM 	EMPLOYEES
WHERE	salary*12 > 10000;
```



## Q3

If final ask operator, use `||`, if function then use `CONCAT()`

## Q4

```sql
SELECT 	E.employee_id, E.last_name, E.first_name, D.department_name, L.state_province
FROM	
```

## Q5

```sql
SELECT 	E.employee_id, E.first_name, E.last_name, C.country_id, C.country_name
FROM 	EMPLOYEE E 
JOIN 	DEPARTMENT D
ON 		E.department_id = D.department_id
JOIN 	LOCATION L
ON		D.location_id = L.location_id
JOIN 	COUNTRIES C
ON

```



## Q6

```sql
SELECT 	E.employee_id, E.first_name, E.last_name, JH.job_id
FROM	Employees E JOIN Hob_History JH
ON 		E.employee_id = JH.employee_id
JOINS	Jobs J 
ON 		JH.job_id = J.job_id
WHERE	UPPER(J.job_title) = 'SALES REPREENTATIVE';
```

