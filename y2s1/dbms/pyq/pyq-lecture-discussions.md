# PYQ - Lecture Discussions

## Question 1 (6-Apr-16)

(a) Define the following terms in the context of database systems

1. **Data models**: Data models is a collection of conceptual tools for describing data, data relationships, data semantics and data constraints.
2. **Entity:** is a person, place, an object, an event, or a concept in the user environment that the organization stores as data.
3. **Relational database:** is a database that represents data as a collection of tables in which all data relationships are represented by common values in related tables.

## Question 3 (28-Aug-2014)

The four functions of DBMS are as follows:

1. **Data dictionary management**: DBMS stores definitions of data elements and their relationships in data dictionary. Any changes made are automatically recorded in the data dictionary.
2. **Data storage management:** DBMS creates and manages complex structures required for data storage. It provides storage for related data entry forms or screen definitions, input definitions, data validation rules, procedural code, structure to handle video and picture formats, and so on.
3. **Data transformation and presentation**: DBMS transform entered data to conform to required data structures - no need for users to differentiate between logical and physical data format.
4. **Security management:** DBMS creates a security system that enforces user security and data privacy within the database. Different success privileges or different data items can only be accessed or assigned to authorized users.

## Question 4 (25-Aug-2015)

### Question (I'm not exactly sure)

Why we can't user independent software (such as MS Office) to create a database?

### Answer

1. These are independent, standalone software, and therefore unable to share their content, MS Office packages may be able to import/export to each other but there is no guarantee that all productivity software can share their files with each other.
2. An information system needs to have a database that is structured to store relevant data for later analysis. Productivity software can only create individual files that are not related/linked to one another.
3. The software cannot be used to comprehensively define the processing requirement of an information system, unable to enforce various business rules.
4. Such a system will not be scalable to match the growth of a business
5. 7 marks for
   1. elaboration and explanation along the lines of
      1. ill defined
      2. loosely coupled
      3. not integrated
      4. not structured
      5. not scalable

## Question 5 (16-Apr-2014)

The advantages of DBMS

1. **Improve data sharing.** Different parts of the enterprise to use consistent shared data to analyze information across the whole of the enterprise.
2. **Improved data security.** DBMS contain features which can protect data from unauthorized users' access.
3. **Better data integration.** Integrated data provides integrated view of the organization's operation and reduce the redundant effects of data integration.
4. **Minimized data inconsistency.** Inconsistency occurs when there are different values of same data stored in a number of places. In databases, such redundancy is reduced and hence reduce data inconsistency problem.

## Question 6 (22-08-2013) Q1a(i)

1. Problems of file-based database
   1. **Limited data sharing and availability**: Manufacturing companies send daily updates of inventory to determine the purchasing plan. This requires that the inventory and purchasing departments share data and update data consistently for better decision making.
   2. **Data Redundancy** : There are many copies of form filled-out daily by sales personnel to distribute to the production, inventory and accounting department. This causes paperwork to increase, redundant data to increase in effect of duplicate copies.
   3. **Data integrity/consistency problem:** Human error occurs when the same data is entered many times causing data integrity. The consistency problem may occur when the data is not updated regularly. For eg. Filling the form with the same product name for many customers and the change in product name may not be made known to other departments.
   4. **Program and data dependence:** The program created is for a specific file containing data. Any changes in the program may affect all the files related to the program. For eg. A change in the calculation of discount will affect all the order files with the discount for that specific product.
   5. **Difficulty in producing ad hoc report:** Since data is not centralized, the system cannot retrieve data from various departments and merge it to produce ad hoc report for abnormalities during operation

* Note: Any 2 suitable listed (2 x 1 marks) = 2 marks
* Correct explanation (2 x 2 marks) = 4 marks

## Question 7 (25-08-2015) Q1a

Three solutions of problems faced by file-based database systems:

1. Problem: **Duplication of data**
   1. Solution: A database does not have uncontrolled redundancy. There is only one database managed by the DBMS that will ensure the database is updated and always consistent.
2. Problem: **Limited data sharing**
   1. Solution: the DBMS will allow data sharing among all authorized users. Different outlets can have different applications running but still able to contact to the database and share data.
3. Problem: **Excessive program maintenance**
   1. Solution: Programs can be maintained easily, changes to program logic does not affect database structure and vice versa.
4. Problem: **Program data dependence**
   1. Solution: When using a database and DBMS, changes to a file/table/database structure will require none or minimal efforts in reprogramming and testing. Program and data are independent, especially in a 3-tier (or more) architecture.

## Question 8 (Unknown)

Reasons why business rules are important to database design:

- They are a **communication tool** between users and creators, and they also help **standardize the company's view of the data**
- They help to **define a conceptual model** of the business of an organization and how they are applied in information system.
- They are used for the organization that stores or uses data to be an **explanation** of policy, procedures and principles.

(Any 3 reasons: 2 marks \* 3 = 6 marks)

## Question 9 (16-04-2014)

5 components in database system environments:

- **Software**: software include operation system (OS), database management system (DBMS), and Database applications (accounting system)

- **Hardware**: Hardware include Server (eg. Mainframes), clients (eg. PC)
- **People:** People involve in the database are end-users, system administrators, database administrators, database designers, other IT personnel.
- **Procedures:** procedures are instructions and rules that govern the design and use of the database systems eg. log onto the DBMS, start and stop the DBMS, backup etc.
- **Database**: collection of files that are interlinked with common keys

Five components: 1 mark \* 5 = 5 marks

## Question 10: (28-08-2014)

1. Define **data** & **metadata**
   1. **data:** raw facts that have not been processed
   2. **metadata:** data that describe
2. **File-based system**
   1. Files are normally not shared with other applications, files owned by department that created it
   2. Access to files is controlled by application programs
3. **Database management system**
   1. Data not own by any individual department, centrally located and sharable
   2. Access to data controlled by DBMS

