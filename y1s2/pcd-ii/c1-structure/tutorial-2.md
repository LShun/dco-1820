# Tutorial 2: Structures II
## Q1
i) Declare a tagged structure called Prod that contains integer variables id and year, string variable name
and double variable price.
```c
struct Prod
{
    int id, year;
    char name[40];
    double price;
};
```

ii) By referring to the tagged structure Prod declared in (i) above, declare a 3-element array of this
structure and call it product. At the same time, initialize it with these values.
```c
Prod product[3] = {{1111, 2011, "AAA", 12.50}, {2222, 2012, "BBB", 50.00}, {3333, 2011, "CCC", 38.50}};
```

iii) The diagram gives you an idea of the array of
structures product. What are the values of the
following after the initialization?
```c
2012
"3333"
"AAA"
```

## Q2
Assume the following declaration has been made.

Use typedef to declare a structure called Personal which has the following members:
- An array called name of type character with 20 elements.
- A variable called sex of type character.
- A variable called birthday of the structure type declared above (nested).

Declare a variable called strong of the structure type that you have just created.
```c
typedef struct {
    char name[20];
    char sex;
    Date birthday;
} Personal;

Personal strong;
```
## Q3
The XYZ Company keeps the following records of its employees:
i) Declare a tagged structure called Employee to hold the above information.

```c
struct Employee{
    char employeeName[30];
    char employeeId[10];
    char address[35];
    char phoneNumber[15];
    int salary;
};
```
ii) Define an array emp of type Employee (as in (i) above) that can store 100 sets of employee information.

```c
struct Employee emp[100];
```

iii) Write statements to accept 100 sets of employee data and store them all into the array declared in (ii).

```c
for (int i = 0; i < 100; i++)
{
    printf("Enter employee name: "); //OPTIONAL
    scanf("%[^\n]", &emp[i].employeeName); 
    rewind(stdin);
    printf("Enter employee ID: "); //OPTIONAL
    gets(emp[i].employeeId);
    printf("Enter employee address: "); //OPTIONAL
    scanf("%[^\n]", &emp[i].address);
    rewind(stdin);
    printf("Phone Number:"); //OPTIONAL
    gets(emp[i].phoneNumber);
    printf("Salary: "); //OPTIONAL
    scanf("%lf", &emp[i].salary);
    rewind(stdin);
}
```
iv) Write a statement to change the employeeName of the last employee in the array emp in (ii) to
“Anthony Swamy”.
```c[]
strcpy(emp[100].employeeName, "Anthony Swamy");
```
v) Use typedef to declare a structure called Boss with the following members (including a nested structure):

- An array called departmentCode of type character with 6 elements.
- An array called managerName of type character with 20 elements.
- A variable employee of the type struct employee (defined in (i) above).

Define a variable called boss of the structure type you have just declared.
```c
typedef struct
{
    char departmentCode[6];
    char managerName[20];
    struct Employee employee;
}Boss;

Boss boss;
```

## Q4
(i) Using typedef, declare a structure called Employee which can hold the following details of an employee.
 - ID
 - Name
 - Position
```c
typedef struct{
    char id[32];
    char name[32];
    char position[32];
}Employee;
```
(ii) Using the keyword struct (without typedef), declare a structure called Wrk to store the employee
working record consisting of the following details.

(You must make use of the structure declared in part (i) above.) 

- emp (as in (i) above)
- rate
- hours
- basic
- 
```c
struct Wrk{
    Employee emp;
    double rate;
    int hours;
    double basic;
};
```
(iii) Define an array, called empWrk, of 10 structures of type Wrk declared in part(ii) above. Initialize the
first two records with details as follows:
```c
struct Wrk empWrk[10] = {{"771122", "Mike Wong", "Programmer", 4.62, 40, 1800.00}, {"345906", "Bill John", "Manager", 8.51, 38, 2400.00}};
```
(iv) Write a program segment to display the name and pay for employee Bill John. The formula for pay is:

<- Pay = Rate * Hours + Basic -> 
```c
double pay;
pay = empWrk[1].hours * empWrk[1].rate + empWrk[1].basic;
printf("%s has a pay of %f", empWrk[1].emp.name, pay);
```

## Q5
(i) Using typedef, declare a structure called Schedule which can hold the following details of a class
schedule.
- subject (e.g. PROGRAMMING)
- time (e.g. 10)
- day (e.g Monday)
```c
typedef struct{
    char subject[20];
    int time;
    char day[15];
}Schedule;
```

(ii) Using the keyword struct (without typedef), declare a structure called Address to store an address
consisting the following strings:
- street
- city
- state
- zip

```c
struct Address {
    char street[40];
    char city[32];
    char state[20];
    char zip[10];
};
```

(iii) Use typedef to declare a structure called StudentData that can be used to store the following student data.
You must make use of the structures declared in part (i) and (ii) above.
- Registration Number (string)
- Address (as in (ii) above)
- GPA (double)
- Schedule ( for six different classes) (as in (i) above)
```c
typedef struct {
    char regNum[20];
    struct Address address;
    double gPA;
    Schedule schedule[6];
} StudentData;
```

(iv) Define a variable stud1 of the type declared in part (iii) above.
```c
StudentData stud1;
```

(v) Write a statement to assign the string ”PROGRAMMING” to the member subject in the first class
schedule in stud1.
```c
strcpy("PROGRAMMING", stud1.schedule[0].subject);
```

(vi) Write a statement to assign the value 10 to the member time in the last class schedule in stud1.
```c
stud1.schedule[0].time = 10;
```

## Q6
(i) Declare a tagged structure called Date which consists of the following members: (2m)
 - month (eg. 12)
 - day (eg. 5)
 - year (eg. 2001)
```c
struct Date {
    int month, day, year;
};
```

(ii) Using typedef, declare a structure called Student with the following members:
- studentName (eg. Wilson Tan Wing Soon)
- icNo (eg. 980225-06-0025)
- birthDate (eg. as in (i) shown above)

```c
typedef struct {
    char studentName[50];
    char icNo[30];
    struct Date birthDate;
} Student;
```

(iii) Using typedef, declare a structure called Programme which is used to store data about the
programme. The structure must contain the following details:
- programmeTitle (eg. Diploma in Computer Studies)
- commencingDate (eg. as in (i) above)
- studentData (eg. as in (ii) above, there are 10 of these)

```c
typedef struct {
    char programmeTitle[50];
    struct Date commencingDate;
    Student studentData[10];
} Programme;
```

(iv) Define a variable called ibProgramme of the type Programme which was declared in (iii).
```c
Programme ibProgramme;
```

(v) Write a C program segment that prompts the user to input 10 sets of student records. Store the data
entered into the member studentData in the variable ibProgramme defined in (iv).

```c
#define IB_STUD_DATA ibProgramme.studentData[i]

//do 10 times
for (int i = 1; i <= 10; i++)
    {
        //prompt for student records
        printf("Enter %d/10 Student Name: ", i);
        scanf("%[^\n]", &IB_STUD_DATA.studentName);
        rewind(stdin);
        printf("Enter student IC number: ");
        gets(IB_STUD_DATA.icNo);
        printf("Enter student's birth date (eg: DD/MM/YYYY): ");
        scanf("%d/ %d/ %d", &IB_STUD_DATA.birthDate.day, &IB_STUD_DATA.birthDate.month, &IB_STUD_DATA.birthDate.year);
        rewind(stdin);
    }
```