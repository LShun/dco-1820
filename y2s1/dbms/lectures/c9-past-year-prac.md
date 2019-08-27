# Lecture 12: Past Year Practice

2013

Q4

1.

```sql
CREATE TABLE Author (
	Author.ID CHAR(3) NOT NULL,
    Author_Name VARCHAR(30) NOT NULL,
    BookCategory VARCHAR(10) NOT NULL,
    PRIMARY KEY (Author_ID)
)
```

2.

```sql
SELECT Pub_Name, Pub_BranchNo
FROM Publisher
WHERE Pub_ID = '128';
```

3.

```sql
INSERT INTO AUTHOR
VALUES('A08', 'Alex Tan', 'Science');
```

4.

```sql
SELECT	A.Author_ID, Author_Name,
		COUNT(Pub_ID) AS Publisher_Count
FROM	Author A, Publisher P
WHERE	A.Author_ID = P.Author_ID
GROUP BY A.Author_ID, Author_Name;
```

5.

```sql
UPDATE Publisher
SET	Pub_BranchNo = 'BR05'
WHERE	Pub.BranchNo = 'BR03';
```

## 2014-15s1

a)

```sql
CREATE 
```



b)

i)

```sql
SELECT *
FROM BORROWERS
WHERE BorrowerID LIKE 'lec%';
```

ii)

```sql
SELECT	B.BookID, B.Title, B.PubID
FROM	Book B, Borrowing BR, Borrower BO
WHERE 	B.BookID = BR.BookID AND
BR.BorrowerID = BO.BorrowerID AND
BO.BorrowerID = 'stu3127';
```

iii)

```sql
SELECT 	DISTINCT COUNT(BO.BookID)
FROM	Borrower B, Borrowing BR, Book BO
WHERE	B.BorrowerID = BR.BorrowerID AND
BR.BookID = B.BookID AND
B.BorrowerID = 'stu5324' AND TO_CHAR(BorrowDate, 'mmyyyy') = '042014';
```

iv)

```sql
SELECT  CategoryID,
COUNT(BookID)
FROM 	Book
GROUP BY	CategoryID
HAVING COUNT(BookID) > 100;
```

v)

```sql
UPDATE 	Book
SET		CategoryID = 'Bus'

```

## 2015-16s1

b

iv)

```sql
ALTER TABLE Reservation

```

