#  Tutorial 1 - Database Development and Application

Keywords in italics

1. You are trying to justify a computerized data management system to your supervisor. You work in a service industry that deals directly with customers.

- How could collecting information about your customers provide a competitive advantage

> Collecting information about customers reveal the customers buying preferences and trends, minimizing wastage by reducing unnecessary employment.

- What kind of software would you need to detect trends and make projections about customer activities?

> (Note: Answer verified)
> Data Warehouse, Analytical Processing, CRM

1. Explain why a comprehensive and effective information system cannot be built with software such as MS Word, MS Excel and MS PowerPoint.

> The software listed is unable to handle large amount of data at any point of time. They do not have efficient algorithms built-in to handle different forms of data with varying complexity.
> The software listed does not have proper data redundancy and integrity mechanism built-in. Errors and corruptions can easily destroy the entire database stored.
> The software listed has no proper way to handle multi-user access. A database built usng the software listed is unable to properly handle thousands of users simultaneously without causing excessive delay due to change-protections.

3. Consider a company such as Amazon.com

- What is the purpose of the largest databases used by e-commerce companies such as Amazon.com?

> To track the status of various orders and understand the customers trends when purchasing products. Allow the companies to take advantage of peak seasons by stocking up appropriately.

- How do the e-commerce companies use these databases?

> E-commerce companies use these databases by storing the ????

4. Explain the relationship between information, data and knowledge. Use a relevant example for each of the following organization:

- Health care facility

When issuing medicine to a patient, the patient's sickness, age, and overall wellbeing is entered into the system as pieces of data. The system will use the knowledge of medicine to evaluate the patient's medical requirements, and use the knowledge to issue the patient's medicine dosage and type as information for the pharmacies.

- Institution of higher learning

>> Leave until first one is accepted.

- Law enforcement agency

>> Leave until first one is accepted.

## What is DBMS?

A *software system* that enables users to *define, create, maintain, and control access* to the database. << Frequently asked in exams >>

5. What is data redundancy, and which characteristics of the file system can lead to it?

Data redundancy is a condition created within a database or data storage technology in which the same piece of data is held in two separate places. This can mean two different fields within a single database, or two different spots in multiple software environments or platforms. When properly configured, it can lead to a file system having a failure-resilient characteristics. When poorly configured, it can lead to a file system having multiple storage points, requiring complex or multiple update procedures to ensure data stored is accurate at all times across all points of data storage.

6. What is data independence, and why is it important?

Data independence is the type of data transparency that matters for a centralized DBMS. It refers to the immunity of user applications to changes made in the definition and organization of data. Application programs should not, ideally, be exposed to details of data representation and storage. 

Data independence is important because it ensures that the user's daily operation is not impacted due to underlying changes. Besides that, data independence also ensures that the underlying operation is not exposed to the user to prevent possible security issues.

7. Discuss the lack of data independence in file systems.

Data independence is changing the data storage characteristics without affecting the program’s ability to access the data. It lacks in file systems because it holds no practical significance to the logical data format or the physical data format.

8. What is a DBMS, and what are its functions?

DBMS is a collection of programs that manages the database structure and controls access to the data stored in the database. Functions include data dictionary management, data storage management, and database communication interfaces. 

9. What is the main storage media for databases? Why? Could a flash drive be used for storing a database? Explain.

The main storage media for databases are hard disks. The reason hard disks are used is because it can handle the sustained read & writes required for a database to function without failing prematurely. A flash drive can be used for storing a database, but it is not ideal. This is because flash drive is built for archival purpose, having averagely lower speeds and supports only a low amount of writes before wearing out.

1.  What is an index? Describe the different types of indexes and give examples to illustrate when each of them is useful.

A database index is a data structure that improves the speed of data retrieval operations on a database table at the cost of additional writes and storage space to maintain the index data structure. Indexes are used to quickly locate data without having to search every row in a database table every time a database table is accessed.

A few different types of indexes are bitmap index, dense index, sparse index, and reserve index.

1. Bitmap index
   1. A bitmap index is a special kind of indexing that stores the bulk of its data as bit arrays (bitmaps) and answers most queries by performing bitwise logical operations on these bitmaps.
   2.  the bitmap index is designed for cases where the values of a variable repeat very frequently
2. A dense index in databases is a file with pairs of keys and pointers for every record in the data file.
3. A sparse index in databases is a file with pairs of keys and pointers for every block in the data file. Every key in this file is associated with a particular pointer to the block in the sorted data file.
4. A reverse-key index reverses the key value before entering it in the index. E.g., the value 24538 becomes 83542 in the index. Reversing the key value is particularly useful for indexing data such as sequence numbers, where new key values monotonically increase.