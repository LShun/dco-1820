# IntroDB T12 2019 - Manipulating Data

## Question 1

#### a) Insert the first row of data without specifying the columns in the INSERT clause 

```sql
INSERT INTO
  COMPUTER
VALUES(230, 'XPZ', 4000, 'DELLY', 'Black');
```

#### b) Insert the second row of data and explicitly specify the columns in the INSERT clause 

```sql
INSERT INTO
  COMPUTER (
    COMP_ID,
    COMP_MODEL,
    COMP_PRICE,
    COMP_MANUFACTURER,
    COMP_COLOUR
  )
VALUES(231, 'Macbook Airy', 13200, 'EPAL', 'Gold');
```

## Question 2

#### a) Modify your SQL in 1(a) and prompt the user to give an input for data to be inserted in COMPUTER table.

```sql
ACCEPT v_comp_id 	number PROMPT 'ENTER COMPUTER ID: '
ACCEPT v_comp_model char PROMPT 'ENTER COMPUTER MODEL: '
ACCEPT v_comp_price number PROMPT 'ENTER PRICE: '
ACCEPT v_comp_man char PROMPT 'ENTER PRICE: '
ACCEPT v_comp_color char PROMPT 'ENTER COLOR: '
```

#### b) Make the changes of your SQL in 2(a) permanents.

```sql
INSERT INTO
  COMPUTER
VALUES(
    &v_comp_id,
    '&v_comp_model',
    &v_comp_price,
    '&v_comp_man',
    '&v_comp_color'
  );
```

#### c) Change the price for XPZ to become RM5670.

```sql
UPDATE COMPUTER
SET COMP_PRICE = 5670
WHERE COMP_MODEL = 'XPZ';
```

#### d) Change the colour to black elegant for all the models in Black colour.

```sql
UPDATE
  COMPUTER
SET
  COMP_PRICE = 5670
WHERE
  COMP_MODEL = 'XPZ';
```

#### e) Delete ACERS from the database.

```sql
DELETE FROM
  COMPUTER
WHERE
  COMP_MANUFACTURER = 'ACERS';
```

#### f) Delete all the rows from COMPUTER table.

```sql
DELETE FROM
  COMPUTER;
```

#### g) Retrieve back the data that you have deleted in 2(f).

```sql
ROLLBACK;
```

#### h) Make the changes permanent.

```sql
COMMIT;
```

