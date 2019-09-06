# AACS3013 DB Dev. & Applications

## 15-09-16 PYQ

## Question 1

### Part A

1. **Data redundancy** refers to the duplication of data that are inconsistent, different, and conflicting. 
   1. As an example, when **storing employee's address on multiple locations**, changes to one end is not automatically reflected on the others.
2. **Data and program independence** refers to the immunity of user applications to changes made in the definition and organization of data, and vice versa.
   1. This is important because it **saves time and reduce errors** as modification done to data will not affect the program end, and vice versa.
3. **Database administration's** task is to **install and upgrade** the database management system. Besides that, they are also responsible to **perform data backup and recovery** to ensure the continuous availability of data.

### Part B

1. **Functions**
   1. F1: **Data Dictionary Management**. Defines the entities and their relationships.
   2. F2: **Data Storage Management.** Stores the data and the metadata.
   3. F3: **Database transformation and presentation.** Translates logical queries into requests to retrieve information.
2. **Indexing** refers to the creation of an auxiliary files that makes it efficient to search for a record in the data file.
   1. Indexing **reduces the time to fetch data**. Because the data is sorted, efficient algorithms such as B-tree can be used to quickly find the data.
   2. Indexing allows an information system to **handle growing sets of data without facing performance issues**. Indexing allows more data to be stored with minimal performance impact, making the system more efficient.

## Question 2

### Part A

Defining clear set of business rules

**Reason 1:** They help to promote creation of an accurate data model in database design.

**Reason 2:** They standardize company's view of data.

### Part B

1. INSERT ERD HERE
2. DBDL
   1. **product_line**(<u>prodLineID</u>, prodLineName)
   2. **product**(<u>prodID</u>, prodDesc, prodFinish, unitPrice, prodLineID\*)
   3. **product_order**(<u>prodID</u>\*, <u>orderID</u>\*)
   4. **order**(<u>orderID</u>, orderDate, totalAmount, customer\*)
   5. **customer**(<u>custID</u>, name, contactNumber, creditLimit, address)

## Question 3

### Part A

1. **Functional dependency** occurs when the value of one or more attributes determine the value of one or a set of second attribute.
2. In the sample data above, the treatID (eg: V01) determins the value of the treatDesc (eg: Rabies Vaccination)

### Part B

1. **Insertion anomaly**: Is the inability to insert new records without also adding redundant data. For example, it is impossible to add a new treatment (treatID) without also adding a Visit (VisitNo) record.
2. **Modification anomaly**: is the inability to maintain data efficiently. Multi-column changes are required for every change. For example, when we change treatDesc (treatID: V01) from "Rabies Vaccination" to "Rabies Treatment", we must also change similar columns. Otherwise, data inconsistency will occur.
3. **Deletion anomaly:** is the inability to delete unwanted data without also deleting wanted data. As an example, when we delete the VisitNo, A104 record, we will also delete treatDesc "Tetanus Vaccination" (treatID: V08).

### Part C

#### [Extra] 0NF: Unnormalized

**TreatmentVisit**(<u>VisitNo</u>, petID, petName, owner, visitDate, <u>treatID</u>, treatDesc, dosage, fee)

#### 1NF: Remove repeating groups

**Visit**(<u>VisitNo</u>, petID, petName, owner, visitDate)

**TreatmentVisit**(<u>treatID</u>, treatDesc, dosage, fee, <u>VisitNo</u>\*)

#### 2NF: Remove partial dependencies

**Visit**(<u>VisitNo</u>, petID, petName, owner, visitDate)

**TreatmentVisit**(<u>treatID</u>\*, dosage, fee, <u>VisitNo</u>\*)

**Treatment**(<u>treatID</u>, treatDesc)

#### 3NF: Remove transitive dependencies

**Visit**(<u>VisitNo</u>, petID*, visitDate)

**Pet**(<u>petID</u>, petName, owner)

**TreatmentVisit**(<u>treatID</u>\*, dosage, fee, <u>VisitNo</u>\*)

**Treatment**(<u>treatID</u>, treatDesc)

## Question 4

### Part A

```mysql
CREATE TABLE site (
  siteCode CHAR(10),
  siteDesc VARCHAR(100),
  ownerID CHAR(10) NOT NULL,
  investAmt DECIMAL(10, 2),
  status VARCHAR(10),
  PRIMARY KEY (siteCode),
  CHECK (investAmt > 1000)
);

```

### Part B

```mysql
SELECT
  *
FROM
  timbercategory
WHERE
  grade = 'A'
ORDER BY
  length DESC;

```

### Part C

```mysql
SELECT
  InvoiceNo,
  saleDate,
  timberCode,
  quantity,
  saleAmt,
  S.siteCode
FROM
  sales S,
  site SI
WHERE
  S.siteCode = SI.siteCode
  AND siteDesc = 'Kg Jawa IOI Group';

```

### Part D

```mysql
SELECT
  E.empID,
  empName,
  contactNo,
  S.siteCode,
  siteDesc,
  ownerID,
  InvestAmt,
  status
FROM
  site S,
  jobSchedule J,
  employee E
WHERE
  S.siteCode = J.siteCode
  AND J.empID = E.empID
  AND TO_CHAR(startDate, 'mmyyyy') = '062016';

```

### Part E

```mysql
SELECT
  SI.siteCode,
  SUM(saleAmt) AS "Total Sale"
FROM
  sales S,
  site SI
WHERE
  S.siteCode = SI.siteCode
  AND investAmt > 15000
GROUP BY
  SI.siteCode;

```

