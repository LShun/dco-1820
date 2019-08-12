# Tutorial 10 - Normalization

## 4. 

### 1NF (Remove Repeating Group)

**Co-curriculumRegistration**(<u>CoCuCode</u>, Desc, AdvisorNo, AdvisorName, <u>StuID</u>, StuName, StuContact, Dat, Time)

Becomes

Co-curriculum(<u>CoCuCode</u>, Desc, AdvisorName)

Student(<u>StuID</u>, StuName, StuContact, Day, Time, <u>CoCuCode*</u>)

### 2NF (Remove Partial Dependencies)

Co-curriculum(CoCuCode, Desc, AdvisorNo, AdvisorName)

StudentRegistration(CoCuCode\*, StuID\*, Day, Time)

Student(StuID, StuName, StuContact)

### 3NF (Remove Transitive Dependencies)

Co-curriculum(CocuCode, Desc, AdvisorNo*)

Advisor(AdvisorNo, AdvisorName)

StudentRegistration(CocuCode\*, StuID\*, Day, Time)

Student(StuID, StuName, StuContact)

## 5. 

Copy from picture

# T10

Note: If question ask for 3NF, must also give 0NF-2NF, because have marks there

## Q1

### (a)

- **Insertion anomaly:** It is not possible to insert a customer without it belong also to a package. (CustomerCode)
- **Modification Anomaly:** CustName / Departate
- **Deletion Anomaly**: PackageNo'

Copy from picture

## Q2

copy from picture

## Q3

