# SQL Plus notes

## Syntax quirks

1. The keywords & table name are non-case sensitive
2. Extra spacing is allowed between each character.
3. The sequence of each `field specifier` when creating a table must be correct, 
   1. This means that: `city VARCHAR(30) NOT NULL` is a valid statement but `city NOT NULL VARCHAR(30)` is an invalid statement and will cause `ORA-00907: missing right parenthesis`.
4. For NULL values
   1. They will not appear if relational queries are used no matter what
   2. For example:
      1. `WHERE GPA > 3.5` and `WHERE GPA <= 3.5` and `WHERE GPA > 3.5 OR GPA <= 3.5` will not show any person who has `GPA` with `NULL`

## Syntaxes

Creating a table
```sql
CREATE TABLE <name of table>
( attribute-1 datatype(size) Constraints,
  attribute-2 datatype(size) Constraints,
   .
   .
   .
  attribute-N datatype(size) Constraints, 
PRIMARY KEY (attribute name, . . ., attribute name)
);
```

### Increase column width

```sql
SQL> COLUMN ENAME FORMAT A4
SQL> /
```

`SQL>` is part of the terminal, no need to include

`/` is used to request the last query

### Inserting records

1. Even if you are `ACCEPT`ing a char, you must add single quotes (`''`) when `INSERT`ing them into a table, as they are passed without being enclosed by them.
2. For most values (unless a constrant is added), it is safe to igore preceding zeroes.

## Error Codes

ORA-00001: unique constraint (SYSTEM.SYS_C007911) violated

> Means a duplicate row is attempted to be inserted

