- [Q1](#q1)
  - [a)](#a)
  - [b)](#b)
  - [c)](#c)
  - [d)](#d)
  - [e)](#e)
    - [i)](#i)
    - [ii)](#ii)
- [Q2](#q2)
  - [a](#a)
  - [b](#b)
  - [c](#c)
  - [d](#d)
  - [e](#e)
  - [f](#f)
- [Q3](#q3)
  - [a](#a-1)
  - [b](#b-1)
  - [c](#c-1)
    - [i](#i)
    - [ii](#ii)
  - [d](#d-1)
- [Q4](#q4)
  - [a](#a-2)
  - [b](#b-2)
    - [i](#i-1)
    - [ii](#ii-1)
  - [c)](#c-1)
    - [i](#i-2)
    - [ii](#ii-2)

# Q1

## a)

```c
struct House {
    char location[20];
    char type;
    int lotNum;
    float price;
};
```

## b)

```c
struct House johnHouse = {"Damansara", 'D', 325, 5600.00};
```

## c)

```c
typedef struct {
    char projName[35];
    int projId;
    struct House building[250];
} Project; 

Project companyProj;
```

## d)

```c
printf("Enter the project name: ");
scanf(" %[^\n]", &companyProj.projName);
printf("Enter the project ID: ");
scanf(" %d", &companyProj.projId);
```

## e)

### i)

```c
for (int i = 0; i < 250; i++)
{
    printf("Enter building's location: ");
    scanf(" %[^\n]", &companyProj.building[i].location);
    printf("Enter building's type: ");
    scanf(" %c", &companyProj.building[i].type);
    printf("Enter building's lot number: ");
    scanf(" %d", &companyProj.building[i].lotNum);
    printf("Enter building's price: ");
    scanf(" %f", &companyProj.building[i].price);
}
```

### ii)

```c
companyProj.building[4].lotNum = 288;
```

# Q2

## a

```c
FILE *vfile, *vselect;
```

## b

```c
vfile = fopen("vehicle.txt", "r");
```

## c

```c
if (vfile == NULL)
{
    printf("File cannot be opened.\n");
    exit(-1);
}
```

## d

```c
vselect = fopen("vselection.bin", "wb");
```

## e

```c
while(fscanf(vfile, "%[^|]|%d|%d|%f\n", &vh.model, &vh.quantity, &vh.year, &vh.price) != EOF)
{
    if (vh.quantity < 5)
    {
        fwrite(&vh, sizeof(CAR), 1, vselect);
    }
}
```

## f

The first difference is type of data stored. A text file stores data in text characters. A binary file stores data in memory location format or binary format.

The second difference is human readability. A text file is human readable. A binary file is almost or completely unreadable by humans.

# Q3

## a

The first difference is their visibility. A global variable is visible to the entire C program. A local variable is only visible to the scope it is declared.

The second difference is their duration. A global variable persist until the program terminates. A local variable persist until the end of the smallest scope it is declared in.

LECTURE ANSWERS:
**Global variable:** A variable whose value can be accessed and modified by any statement in a program, not just within a sinle routine in which it is defined.

**Local variable:** A variable whose value can be accessed and modified within a single routine (function) in which it is declared.

## b

```c
void increaseRate(float M[])
{
    for(int i = 0; i < 5; i++)
    {
        if(M[i] < 15.0)
        {
            M[i] = M[i] * 1.05;
        }
    }
}
```

## c

### i

```c
float calculateMonthlyExp(float petrol, float utilities, float food)
{
    float monthly = petrol + utilities + food
    return monthly;
}
```

### ii

```c
void calculateHouseholdExp(float month, float installment, float *household)
{
    *household = month + installment;
}
```

## d

The first difference is change persistence. Changes towards variables passed by value are reverted after the function return. Changes towards variable passed by value persist after the function returns.

The second difference is the object passed. Pass by value passes the actual variable to the function. Pass by address passes the address to the variable to the function.

# Q4

## a

Coupling is a measure of the strength of connection between two functions. Functions with strong coupling cannot function well without the presence of the other function, while function with weak coupling can make do without.

The 4 levels of coupling are:

1. Data coupling
2. Control coupling
3. External coupling
4. Pathological coupling

## b

```c
typedef {
    char name[35];
    int score;
    char performance[25];
}candidate;

candidate people;
```

### i

```c
void verifyPerformance(candidate *people)
{
    if (people->score >= 80)
        strcpy(people->performance, "Excellent");
    else if (people->score >= 60)
        strcpy(people->performance, "Good");
    else if (people->score >= 40)
        strcpy(people->performance, "Average");
    else
        strcpy(people->performance, "Poor");
}
```

### ii

```c
verifyPerformance(&people);
```

## c)

### i

Storage class of a variable determines its visibility, duration and location.

The four storage classes are:

1. auto
2. static
3. extern
4. register

### ii

Output:
5 7
8 5
9 6
10 7
5 10