# Tutorial 3
- [Tutorial 3](#tutorial-3)
    - [Q1](#q1)
    - [Q2](#q2)
    - [Q3](#q3)
    - [Q4](#q4)
    - [Q5](#q5)
    - [Q6](#q6)
## Q1

(I) 
```c
FILE *pOut;
```

(II)
```c
pOut = fopen("sample.txt", "w");
```

(III)
```c
if (pOut == NULL)
{
    printf("File cannot be opened");
    exit(-1);
}
```

(IV)
```
printf("Enter 4 integers (ex: 1 2 3 4)): ");
for(int i = 0; i < 4; i++)
{
    scanf("%d", &num);
    fprintf(num, "%d ", pOut);
}
```

(V)
```
fclose(pOut);
```

## Q2
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //variables
    int code, unit;
    double price;
    FILE* fp = fopen("sales.txt", "w");
    //check if file is succesfully opened.
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

    //input
    //request for item code
    code = 0
    printf("Enter item code, units sold, and price (Ex: 2 4 60), -1 to cancel: ");
    scanf("%d", &code);
    while (code != -1)
    {
        scanf("%d", &unit);
        scanf("%lf", &price);

        //process
        //nothing

        //output
        //write to file contents in variable
        fprintf(fp, "%-10d %10d %10.2f\n", code, unit, price);

        //prompt for new input
        printf("Enter item code, units sold, and price (Ex: 2 4 60), -1 to cancel: ");
        scanf("%d", &code);
    }
    
    //end of job
    printf("Completed.\n");
    
    //close file
    fclose(fp);
}
```


## Q3
(I)
```c
FILE* fPtr = fopen("number.txt", "r");
```

(II)
```c
if (fPtr == NULL)
{
    printf("File cannot be opened.\n");
    exit(-1);
}
```

(III)
```c
int num, sum = 0, count = 0;

while (fscanf(fPtr, " %d", &num) != NULL)
{
    sum += num;
    count++;
}

printf("Sum = %d, Numbers = %d", sum, count);
```

## Q4
Assume that the data is stored with a newline in between. (For convenience, can
also assume that they are one word only. )
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20], job[30], type[30], place[30];
} Alumni;


int main(void)
{
    //variables
    Alumni alumni;
    FILE *fp = fopen("alumni.txt", "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

    //process
    while((fscanf(fp, "%s\n%[^\n]\n%[^\n]\n%[^\n]\n", 
    &alumni.name, &alumni.job, &alumni.type, &alumni.place)) == 4)
    {
        //output    
        //print out contents of the file
        printf("Name: %s\n"
            "Designation: %s\n"
            "Category: %s\n"
            "Location: %s\n",
            alumni.name, alumni.job, alumni.type, alumni.place);   

    }
    //close the file
    printf("Ended.\n");
    fclose(fp);
    return 0;
    }
```

## Q5

```c
/*
Name: Q5.c
Desc: Calculates the monthly commission
*/

#include <stdio.h>
#include <stdlib.h>

//declarations
#define COMM_RATE 2.7
#define IN_FILE "SALES01.txt"
#define OUT_FILE "COMM01.txt"

//structures
typedef struct {
    int month;
    double sales, commission;
} SalesMan;

//prototypes
SalesMan readData(FILE* fp);
int calcCommission(SalesMan *salesMan);
int writeOut(SalesMan salesMan, FILE *fp);
int main(void)
{
    //variables
    SalesMan salesMan;
    FILE *inp, *outp;

    inp = fopen(IN_FILE, "r");
    //check for errors
    if (inp == NULL)
    {
        printf("Input file cannot be opened.\n");
        exit(-1);
    }
    outp = fopen(OUT_FILE, "w");
    if (outp == NULL)
    {
        printf("Output file cannot be opened.\n");
        exit(-1);
    }

    while(1)
    {
        //read the data
        salesMan = readData(inp);

        //calculate the commission
        calcCommission(&salesMan);

        //write into file
        writeOut(salesMan, outp);
    }

    fclose(inp);
    fclose(outp);
}

SalesMan readData(FILE *fp)
{
    //variables
    SalesMan salesMan;

    //read the file into the data structure
    if(fscanf(fp, "%d %lf", &salesMan.month, &salesMan.sales) != 2)
    {
        printf("EOF. Insufficient data to continue.\n");
        exit(-1);
    }

    //return the structure
    return salesMan;
}

int calcCommission(SalesMan* salesMan)
{
    //multiply the sales by the commission rate
    salesMan->commission = salesMan->sales * COMM_RATE;
    return 0;
}

int writeOut(SalesMan salesMan, FILE* fp)
{
    //write structure to output file
    fprintf(fp, "%-6d %-12.2f %-8.2f\n", salesMan.month, salesMan.sales, salesMan.commission);
    
    printf("Write succeed.\n");
    return 0;
}
```

## Q6

(a)
```c
FILE *fPtr1, *fPtr3;
```
(b)
```c
fPtr1 = fopen("membership.txt", "r");
if (fPtr1 == NULL)
{
    printf("File cannot be opened\n");
    exit(-1);
}
```
(c)
```c
    fPtr3 = fopen("membership100to200.txt", "w");
    if (fPtr3 == NULL)
    {
        printf("File cannot be opened\n");
        exit(-1);
    }
//read into structure
    while(fscanf(fPtr1, "%3s%d %s %s %d %d\n", &member.nopart1, &member.nopart2, &member.name, &member.tel, &member.expiry, &member.type) == 6)
    {
        //test structure for members start with 'A' and between 100 and 200
        if (strcmp("A00", member.nopart1) == 0 && (member.nopart2 >= 100 && member.nopart2 <= 200))
        {
            member.expiry = 2025;
            fprintf(fPtr3, "%s%-20d %-20s %-20s %15d %20d\n", member.nopart1, member.nopart2, &member.name, member.tel, member.expiry, member.type);
        }
    }
```
(d)
```c
    while(fscanf(fPtr1, "%3s%d %s %s %d %d\n", &member.nopart1, &member.nopart2, &member.name, &member.tel, &member.expiry, &member.type) == 6)
    {
        //test structure for members start with 'A' and between 100 and 200
        if (strcmp("A00", member.nopart1) == 0 && (member.nopart2 >= 100 && member.nopart2 <= 200))
        {
            member.expiry = 2025;
            fprintf(fPtr3, "%s%-20d %-20s %-20s %15d %20d\n", member.nopart1, member.nopart2, &member.name, member.tel, member.expiry, member.type);
        }

        if (member.type == 3)
        {
            printf("Platinum member: %s\n", member.name);
        }
    }
```

(e)
```c
    fclose(fPtr1);
    fclose(fPtr3);
```

(extra) Full program after testing:
```c
/*
Name: Q5.c
Desc: Calculates the monthly commission
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declarations
#define COMM_RATE 2.7
#define IN_FILE "SALES01.txt"
#define OUT_FILE "COMM01.txt"

//structures
typedef struct {
    char nopart1[4];
    int nopart2;
    char name[20];
    char tel[14];
    int expiry, type;
} Member;

int main(void)
{
    Member member;
    FILE *fPtr1, *fPtr3;

    fPtr1 = fopen("membership.txt", "r");
    if (fPtr1 == NULL)
    {
        printf("File cannot be opened\n");
        exit(-1);
    }
    fPtr3 = fopen("membership100to200.txt", "w");
    if (fPtr3 == NULL)
    {
        printf("File cannot be opened\n");
        exit(-1);
    }
    while(fscanf(fPtr1, "%3s%d %s %s %d %d\n", &member.nopart1, &member.nopart2, &member.name, &member.tel, &member.expiry, &member.type) == 6)
    {
        //test structure for members start with 'A' and between 100 and 200
        if (strcmp("A00", member.nopart1) == 0 && (member.nopart2 >= 100 && member.nopart2 <= 200))
        {
            member.expiry = 2025;
            fprintf(fPtr3, "%s%-20d %-20s %-20s %15d %20d\n", member.nopart1, member.nopart2, &member.name, member.tel, member.expiry, member.type);
        }

        if (member.type == 3)
        {
            printf("Platinum member: %s\n", member.name);
        }
    }

    fclose(fPtr1);
    fclose(fPtr3);
    printf("Done\n");
}
```

