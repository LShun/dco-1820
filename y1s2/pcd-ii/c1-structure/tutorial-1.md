# Tutorial 1 - Structure I
- [Tutorial 1 - Structure I](#tutorial-1---structure-i)
  - [Q1](#q1)
  - [Q2](#q2)
  - [Q3](#q3)
  - [Q4](#q4)
  - [Q5](#q5)
  - [Q6](#q6)

## Q1
**(i) What is a structure?**

A structure is a collection of related elements with different data types, under a single name. 
It is a data structure that allows us to treat a collection of data with different types in one 
unit.

**(ii) Declare a structure called Science which holds a character called chemistry, a character 
called biology and a character called physics.**

```c
struct Science {
    char chemistry;
    char biology;
    char physics;
};
```
**(iii) From structure Science as declared in part (ii) above, define 3 structure variables called student1,
student2, topStudent.**

```c
struct Science student1, student2, topStudent;
```
**(iv) Assume that the current contents of the structure variables are as shown in the diagram below:**
*Diagram in PDF* 
**What is the output of the following statement?**
```c
printf("student1 obtained Grade %c for Biology\n", student1.biology);
```

`student1 obtained Grade A for Biology`

**(v) Write one statement that will assign all the contents of the variable student2 to the variable topStudent.
Then display topStudent's grade for Physics (use the same output format as in (iv) above).**

`topStudent = student2`

`printf("topStudent obtained Grade %c for Physics\n", topStudent.physics);`

## Q2
**(a) Declare a tagged structure called House and at the same time define a variable called pelangi. The
members of the structure House are as follows:**

- A 20-character string called location
- A character type variable called pattern
- An integer type variable called area
- A double type variable called interestRate
  
**Using another statement, declare a variable alpha, which is of the same structure type.**

```c
struct House {
    char location[20];
    char pattern;
    int area;
    double interestRate;
} pelangi;

struct House alpha;
```
**(b) Write statements to perform the following:**
- assign the values “Setapak” to location of alpha, and "Gelugor" to location of pelangi
- assign the value of 4% to the interestRate member of both variables
- accept a value from the user (keyboard) for pattern of alpha
- accept a value from the user for area of pelangi

```c
strcpy(alpha.location, "Setapak");
strcpy(pelangi.location, "Gelugor");
alpha.interestRate = 0.04;
pelangi.interestRate = 0.04;
alpha.pattern = getchar();
scanf("%d", &pelangi.area);
```

## Q3
**Given this declaration:**
```c
    struct Force {
        char name[40];
        int pointNumber;
        double xForce;
        double yForce;
    };
```
**Correct the errors in each line of code below:**
```c
main() {
    struct wing Force;
    struct.xForce = 15.3;
    wing.xForce.yForce = 28.5;
    wing.name = "DC 10";
    force.pointNumber = 85;
    ... ... ...
}
```
Answer:
```c
main() {
    struct Force wing;
    wing.xForce = 15.3;
    wing.yForce = 28.5;
    strcpy(wing.name, "DC 10");
    wing.pointNumber = 85;
    ... ... ...
```

## Q4
**Assume that the following declaration / definitions have been made:**
```c 
typedef struct {
    int day;
    int month;
    int year;
} Date;

Date mfgDate = {17, 10, 2016}, expiryDate;
```
**Write program segments to perform the following:**

- Display mfgDate in the format dd-mm-yyyy (eg. 17-10-2016).
- Display mfgDate in the format dd-MMM-yyyy (eg. 17-OCT-2016). Hint: use a switch statement.
- Assign all the contents of mfgDate to expiryDate, then change the contents of expiryDate to reflect
the same day and month but 5 years later. 

Finally display a message in the following format, where
MFG is the manufacture date and EXP is the expiry date of a product item:

```
MFG 17 10 2016
EXP 17 10 2021
```

**Answer:**
```c
printf("%d-%d-%d\n", mfgDate.day, mfgDate.month, mfgDate.year);
```
```c
printf("%d-", mfgDate.day);
switch(mfgDate.month)
{
    case 1:
        printf("JAN-");
        break;
    case 2:
        printf("FEB-");
        break;
    case 3:
        printf("MAR-");
        break;
    case 4:
        printf("APR-");
        break;
    case 5:
        printf("MAY-");
        break;
    case 6:
        printf("JUN-");
        break;
    case 7:
        printf("JUL-");
        break;
    case 8:
        printf("AUG-");
        break;
    case 9:
        printf("SEP-");
        break;
    case 10:
        printf("OCT-");
        break;
    case 11:
        printf("NOV-");
        break;
    case 12:
        printf("DEC-");
        break;
}
printf("%d\n", mfgDate.year);
```
```c
expiryDate = mfgDate;
expiryDate.year = mfgDate.year + 5;
```
```c
printf("MFG %d %d %d\n", mfgDate.day, mfgDate.month, mfgDate.year);
printf("EXP %d %d %d\n", expiryDate.day, expiryDate.month, expiryDate.year);
```

## Q5
**Using typedef, declare a structure MovieTicket that can store the following movie ticket details:**
- Movie name (string of suitable length)
- Screen Time (integer - Valid times are 2pm, 5pm, 8pm and 11pm only)
- Price (ticket price in RM, eg. 25.00)
- Seat Number (eg. 005, 112 etc)

From this MovieTicket structure, define a variable ticket.
Write statements to prompt the user to input the Screen Time and store it into the appropriate member of
ticket. Use a loop to ensure that only a valid Screen Time is accepted.

**Answer**
```c
struct MovieTicket {
    char name[25];
    int time;
    double price;
    char seat[3];
};

struct MovieTicket ticket;

printf("Enter the screen time: ");
scanf("%d", &ticket.time);
while (ticket.time != 2 && ticket.time != 5 && ticket.time != 8 && ticket.time != 11)
{
    printf("Invalid screen time, please enter again: ");
    scanf("%d", &ticket.time);
}
```

## Q6
**(i) Using typedef, declare a structure Point that contains 2 integers representing the x and y coordinates of
a point (eg. (3, 4)).**

```c
typedef struct
{
    int x;
    int y;
}Point;
```

**(ii)Define a variable point of this structure type (as in (i) above).**
```c
Point point = {3, 4};
```

**(iii) There are 4 quadrants (numbered I, II, III, IV) in the coordinate plane (refer to the diagram shown).**

Write a program segment that will:
- Request the user for the x and y coordinates of a point, and store them in
the variable point.
- (Using else if) Determine where that point is located: quadrant (I, II, III, IV) or axis (x-axis, y-axis) or the origin (0, 0). Display an appropriate message.
Eg:
        ```The point (3, 4) is in Quadrant I.```
(Hint: if x and y are both positive, then the point lies in Quadrant I.)

```c
printf("Enter x and y coordinate of a point (Eg: 1 -1): ");
scanf("%d %d", &point.x, &point.y);
if (point.x > 0)
{
    if (point.y > 0)
    {
        printf("The (%d, %d) is in Quadrant I", point.x, point.y);
    }
    else if (point.y < 0)
    {
        printf("The (%d, %d) is in Quadrant IV", point.x, point.y);
    }
    else
    {
        printf("The (%d, %d) is in both Quadrant I & Quadrant IV", point.x, point.y);
    }
}
else if (point.x < 0)
{
    if (point.y > 0)
    {
        printf("The (%d, %d) is in Quadrant II", point.x, point.y);
    }
    else if (point.y < 0)
    {   
        printf("The (%d, %d) is in Quadrant III", point.x, point.y);
    }
    else
    {
        printf("The (%d, %d) is in Quadrant II & Quadrant III", point.x, point.y);
    }
}
else
{
    printf("The (%d, %d) is at the origin", point.x, point.y);
}
```