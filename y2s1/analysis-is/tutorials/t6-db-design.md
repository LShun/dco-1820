# Tutorial 6: Database Design

## Question 1

Consider the following relations (tables) for part of an AIRLINE database.

```sql
FLIGHT (FLIGHT_NO, DEST_CODE)
SCHEDULE (PLANE_ID, FLIGHT_NO, DEPARTURE _DATE)
DESTINATION (DEST_CODE, DESTINATION)
PLANE (PLANE_ID, NUMBER_OF_SEATS, PLANE_TYPE)
```

### Required:

(a) What are primary key and foreign key?

**Primary keys:** A field or combination of fields that uniquely identifies a particular record of an entity.

**Foreign keys:** A field in one table that establish a relationship with another table. It must match another primary key in another table.

(b) Identify all the primary keys and foreign keys in the relations above.

*Primary keys are underlined, foreign keys have an asterisk (*) behind.*

**FLIGHT** (<u>FLIGHT_NO</u>, DEST_CODE\*)
**SCHEDULE** (<u>PLANE_ID*</u>, <u>FLIGHT_NO*</u>, DEPARTURE _DATE)
**DESTINATION** (<u>DEST_CODE</u>, DESTINATION)
**PLANE** (<u>PLANE_ID</u>, NUMBER_OF_SEATS, PLANE_TYPE)

https://www.lucidchart.com/invitations/accept/b330a44e-75c3-43c7-9fa6-48d22bd757f1 [T5Q1B ERP page]

## Question 2

The entity-relationship diagram (ERD) shown below has been drawn for an order processing system.
The diagram is based on the following interview notes.

NOTE: Foreign key is always on the MANY table

### Interview Notes

- A **customer** may place many **orders** but must have placed at least one order. Each order will come from only one customer.
- A particular **product** may be listed on different **orders**. An order will usually contain many products.
- Each **product** can be purchased from a number of **suppliers**. Some of the suppliers supply more than one product. A supplier must supply at least one product.
- An **order** is always dispatched in a single **delivery**. However, sometimes more than one order is listed on the same dispatch note.
- Each **customer** is allocated to a **sales** region. A **sales** region may have more than one **customer** in it. A sales region must have at least one customer in it.

### Required:

(a) Using a standard notation, draw an entity-relationship diagram (ERD) for the above information. Resolve any many-to-many relationships between the entities.

(b) Identify and list the attributes of each entity above. Show clearly both the primary and foreign
keys. You should use the format shown in the example: Order (Order No, Date, Customer_ID*)

https://www.lucidchart.com/invitations/accept/b330a44e-75c3-43c7-9fa6-48d22bd757f1 [On T5Q2a page]

## Question 3

Western Wear is a mail-order firm that offers an extensive selection of casual and recreational clothing for **men and women**. Western Wear launched a new Web site, and the company decided to develop a new set of product codes. Currently, **650** different products exist, with the possibility of adding more in the future. Many products come in various **sizes, styles, and colors**. The marketing manager asked you to develop an individualized product code that can **identify a specific item and its characteristics**. Your initial reaction is that it can be done, but the code might be fairly complex. Back in your office, you review the text material on codes and give the matter some thought.

### Required:

(a) Design a code scheme that will meet the marketing manager’s stated requirements.

- 38TSB0001
  - The first two numbers is size, the next two letters is style, the fourth letter is color, the rest of the letters are product ID

(b) Explain to the marketing manager suggesting at least one alternative to the code she proposed, and state your reasons.

- Derivation code
  - One reason is meaningfulness. The code is easy to remember, useful for users, convenient to use and easy to encode and interpret.
  - These codes combine data from item attributes or characteristics

(c) Suggest a code scheme that will identify each Western Wear customer.

- Sequence Code
- eg. C0001

(d) Suggest a code scheme that will identify each specific order.

- Sequence code
- P0001