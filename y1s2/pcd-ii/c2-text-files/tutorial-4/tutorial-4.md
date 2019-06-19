# Tutorial 4
- [Tutorial 4](#tutorial-4)
    - [Q1](#q1)
    - [Q2](#q2)
    - [Q3](#q3)
    - [Q4](#q4)

## Q1
(a)
```c
typedef struct {
    int sSN;
    char name[30];
    char address[50];
    float salary;
} Employee;
```c
int size = 1000;
Employee employee[size];
int i; //should I declare outside
for (int i = 0; i < size; i++)
{
    employee[i].sSN = 0;
    strcpy(employee[i].name, "");
    strcpy(employee[i].address, "");
    employee[i].salary = 0;
}

(b)
(i)
```c
FILE *inPtr;
```
(ii)
```c
inPtr = fopen("employee.txt", "r");
```

(iii)
```c
if (inPtr == NULL)
{
    printf("File cannot be opened.\n");
    exit(-1);
}
```
(iv)
```c
int i = 0;
while(fscanf(inPtr, "%d %s %s %lf", &employee[i].sSN, employee[i].name, employee[i].address, &employee[i].salary) == 4)
{
    i++;
}
```

## Q2
```c
#include <stdio.h>
#include <stdlib.h>

//(i)
typedef struct {
    int code;
    double cost;
    double price;
    int qty;
} ProdType;


int main(void)
{
    //(ii)
    ProdType newProd;

    //(iii)
    FILE *inPtr;

    //(iv)
    inPtr = fopen("product.txt", "r");
    //(v)
    if (inPtr == NULL)
    {
        printf("File cannot be opened\n");
        exit(-1);
    }
    //(vi)
    while (fscanf(inPtr, "%d %lf %lf %d\n", &newProd.code, &newProd.cost, &newProd.price, &newProd.qty) == 4)
    {
        newProd.price = newProd.price * 1.1;
        printf("Product Code: %d\n"
               "Product Cost: %.2f\n"
               "Product Selling Price: %.2f\n"
               "Product Quantity: %d\n\n", newProd.code, newProd.cost, newProd.price, newProd.qty);
    }
    printf("Completed\n");
    //(vii)
    fclose(inPtr);
    return 0;
}
```

## Q3
(a)
```c
FILE *filePtr1;
filePtr1 = fopen("marks.txt", "r");
```
(b)
```c
FILE *filePtr2;
filePtr2 = fopen("report.txt", "w");
```
(c)
```c
if (filePtr1 == NULL || filePtr2 == NULL)
{
    printf("File opening failed. One of the file cannot be opened or is missing.\n");
    exit(-1);
}
```
(d)
```c
char name[30];
int mark[4], i = 0, sum = 0;
double avg;
fprintf(filePtr2, "%-20s%-20s%-20s\n\n", "NAME:", "MARKS:", "AVERAGE:");
while(fscanf(filePtr1, "%[^\n]\n%d%d%d%d\n", name, &mark[0], &mark[1], &mark[2], &mark[3]) == 5)
{
    sum = 0;
    for (i = 0; i < 4; i++)
    {
        sum += mark[i];
    }
    avg = sum / 4.0;
    fprintf(filePtr2, "%-20s%-3d%-3d%-3d%-11d%.2f%%\n", name, mark[0], mark[1], mark[2], mark[3], avg);
}
(e)
fclose(filePtr1);
fclose(filePtr2);
```
## Q4
### Write a program to read the data from PartTime.txt into a structure variable and display the amount of wages for each of the part-timers, where

### Wage = hourlyRate * hoursWorked

### Your program should display an error message and terminate the program if the file PartTime.txt cannot be opened.

### Given the structure for PartTimer:
```
#include <stdio.h>
#include <stdlib.h>
//declarations
#define IN_FILE "PartTime.txt"
//structures
typedef struct
{
	int payrollNo;
	float hourlyRate;
	int hoursWorked;
} PartTimer;

int main(void)
{
	//variables
	FILE *fp = fopen(IN_FILE, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

	PartTimer partTimer;
    double wage;

    printf("Payroll number        Wage (RM)\n"
           "--------------        ---------\n");
	while (fscanf(fp, "%d%f%d\n", &partTimer.payrollNo, &partTimer.hourlyRate, &partTimer.hoursWorked) == 3)
	{
        wage = partTimer.hourlyRate * partTimer.hoursWorked;
        printf("%-22d%9.2f\n", partTimer.payrollNo, wage);
    }
}
```
## Q5
```c
#include <stdio.h>
#include <stdlib.h>
//declarations
#define IN_FILE "PartTime.txt"
//structures
typedef struct
{
	int payrollNo;
	float hourlyRate;
	int hoursWorked;
} PartTimer;

int main(void)
{
	//variables
	FILE *fp = fopen(IN_FILE, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

	PartTimer partTimer;
    double wage;

    printf("Payroll number        Wage (RM)\n"
           "--------------        ---------\n");
	while (fscanf(fp, "%d%f%d\n", &partTimer.payrollNo, &partTimer.hourlyRate, &partTimer.hoursWorked) == 3)
	{
        wage = partTimer.hourlyRate * partTimer.hoursWorked;
        printf("%-22d%9.2f\n", partTimer.payrollNo, wage);
    }
}
```

