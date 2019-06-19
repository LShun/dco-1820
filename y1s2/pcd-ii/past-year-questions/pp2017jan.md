# PP2017 January 24

- [PP2017 January 24](#pp2017-january-24)
  - [1](#1)
    - [a](#a)
    - [b](#b)
      - [i](#i)
      - [ii](#ii)
      - [iii](#iii)
      - [iv](#iv)
      - [v](#v)
      - [vi](#vi)
      - [vii](#vii)
    - [c](#c)
  - [Q2](#q2)
  - [Q3](#q3)
    - [a](#a-1)
    - [b](#b-1)
    - [i](#i-1)
    - [3bii](#3bii)
    - [3biii](#3biii)
    - [3biv](#3biv)
    - [3bv](#3bv)
    - [3c](#3c)
    - [3d](#3d)
  - [Q4](#q4)
    - [4a](#4a)
      - [4ai](#4ai)
      - [4aii](#4aii)
    - [4b](#4b)
    - [4c](#4c)
    - [4d](#4d)

## 1

### a

The definition of a structure is different types of data that are related to each other grouped together.

### b

#### i

```c
typedef struct {
    int day;
    int month;
    int year;
} DATE;
```

#### ii

```c
struct CAR {
    char brand[20], model[30];
    int year;
    DATE regDate;
    double price
};
```

#### iii

`struct CAR NewCar;`

####  iv

```c
printf("Enter car brand: ");
scanf("%s", &NewCar.brand);
rewind(stdin);
printf("Enter car model: ");
scanf("%s", &NewCar.model);
printf("Year made: ");
scanf("%d", &NewCar.year);
printf("Registration date: ");
scanf("%d %d %d", &NewCar.regDate.day, &NewCar.regDate.month, &NewCar.regDate.year);
printf("Price: ");
scanf("%lf", &NewCar.price);
```

NOTE: For `%s` sometimes need to be `%[^\n]`, but in this case not necessary.

#### v

```c
struct CAR CarList[10];
```

#### vi

```c
printf("%s %s\n"
       "%d\n"
       "%d\n"
       "RM: %f\n", CarList[4].brand, CarList[4].model, CarList[4].year, CarList[4].regDate.year, CarList[4].regDate.month, CarList[4].regDate.day, CarList[4].price);
```

#### vii

```c
strcpy(CarList[9].brand, "Toyota");
```

### c

Structure can be returned from a function. An array cannot be returned from a function.

## Q2

```c
char scorer[32], choice = 'Y';
int goals;
int totalGoals;

FILE *fptr;
fptr = fopen("scorer.txt", "r");
if (fptr == NULL)
{
    printf("File cannot be opened.\n");
    exit(-1);
}
printf("%-18s\t\t\t%13s\n"
       "------------------\t\t\t-------------", "Player name", "Goals scored");
totalGoals = 0
while(fptr, fscanf("%[^\n]\n%d\n", &scorer, &age) != EOF)
{
    printf("%-18s\t\t\t%-13d\n", scorer, goals");
    totalGoals += goals;
}
printf("\tTotal goals:\t\t\t%d\n", totalGoals);

fclose(fptr);

fptr = fopen("scorer.txt", "a");
while(choice == 'Y')
{
    printf("Enter new player name: ");
    scanf("%[^\n]", &player);
    printf("Enter goals scored: ");
    scanf("%d", &goals);
    fprintf("%s\n%s\n", player, goals);
    printf("Anymore records? (Y/N): ");
    scanf("%c", &choice);
}
fclose(fptr);
```

## Q3
### a

The contents in the binary file are stored in the same format as they are stored in the memory, or in binary codes.

### b

### i

`CUSTOMER cust;`

### 3bii

`FILE *fp1, *fp2;`

### 3biii

```c
fp1 = fopen("cust.bin", "rb");
fp2 = fopen("shortlist.bin", "wb");
```

### 3biv

```c
while(fread(&cust, sizeof(CUSTOMER), 1, fp1) == 1)
{
    if (cust.income > 5000)
    {
        fwrite(&cust, sizeof(CUSTOMER), 1, fp2);
    }
}
```

### 3bv

```c
fclose(fp1);
fclose(fp2);
```

### 3c

One possible reason is the program does not have sufficient system permission to open the file.

### 3d

1. Pathological coupling
2. Data coupling
3. Sequential cohesion
4. Functional cohesion
5. Modular programming. Modular programming is the practice of breaking up large functions into smaller, more managable functions.

## Q4

### 4a

#### 4ai

```c
#define PERFORMANCE(x) (strcpy(performance, (x)))

void check_performance(EMPLOYEE *emp)
{
    int escore = emp->score;
    if(escore >= 80)
        PERFORMANCE("Excellent");
    else if(escore >= 60)
        PERFORMANCE("Good");
    else if(escore >= 40)
        PERFORMANCE("Average");
    else
        PERFORMANCE("POOR");
}
```

#### 4aii

```c
check_performance(&emp);
```

### 4b

```
Results:
A
B
14
9
9
D
X
X
X
5
6
8
```

### 4c

Extern specifies that a variable is accessible anywhere in the program, and persists until the program terminates. Extern is only a declaration to notify the compiler, no memory space is allocated.

### 4d

Errata:

```c
++p -> ++pv
p1 -> ptr1
p2 -> ptr2
```

Answer:

```c
ptr1=27
ptr2=95
ptr3=8
ptr4=95
pv=8
```

Lecturer highlights: If 96 then GG again.
