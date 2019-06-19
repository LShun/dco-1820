# Tutorial 6

- [Tutorial 6](#tutorial-6)
    - [Q1](#q1)
    - [Q2](#q2)
    - [Q3](#q3)
    - [Q4](#q4)
    - [Q5](#q5)
    - [Q6](#q6)
    - [Q7](#q7)
    - [Q8](#q8)
        - [(i)](#i)
        - [(ii)](#ii)
        - [(iii)](#iii)
    - [Q9](#q9)
    - [Q10](#q10)
    - [Q11](#q11)
        - [(a)](#a)
        - [(b)](#b)

## Q1
Write a function named inchToCm to convert inches (the input parameter) into
centimeters and return the result (using return statement). (1 inch = 2.54
centimeters.)
*Assume that the inch is in integer
```c
double inchToCm(int inch)
{
    double cm;

    cm = inch * 2.54;

    return cm;
}
```

## Q2
```c
double converter(int h)
{
    //variables
    double acres;

    //convert the hectars to acres
    acres = h * 2.47;

    //return the acres
    return acres;
}
```

## Q3
```c
double hypotenuse(double a, double b)
{
    double hypotenuse;

    hypotenuse = sqrt(a*a + b*b);

    return hypotenuse;
}
```

## Q4
```c
char gradeOf(int score)
{
    if      (score >= 80)
        return 'A';
    else if (score >= 70)
        return 'B';
    else if (score >= 50)
        return 'C';
    else if (score >= 40)
        return 'D';
    else if (score >= 0)
        return 'F';
    else 
        return 'X';
}
```
## Q5
(i)
```c
void f1(int a, double x);
```
(ii)
```
a=1, x=2.000000
a=3, x=4.300000
```

## Q6
(a)
```c
double calEpf(int salary)
{
    double ePF;

    ePF = salary * 0.11;

    return ePF;
}
```
(b)
```c
printf("Enter your salary: ");
scanf("%d", &salary);
ePF = calEpf(salary);
printf("Your EPF charges are: %f", ePF);
```

## Q7
```c
int arMenu(void)
{
    int choice;
    printf("Arithmetic menu.\n\n"
           "1.\t\tAddition Problems\n"
           "2.\t\tSubtraction Problems\n\n"
           "Please enter your choice:");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2)
    {
        return(-1);
    }
    else return (choice);
}
```

## Q8
### (i)
int mainMenu(void)
{
    int choice;

    printf("       Mathematics        \n"
           "       ===========        \n"
           "1. Addition\n"
           "2. Subtraction\n"
           "3. Multiplication\n"
           "4. Exit\n\n"
           "Press a number to make your selection: ");
    scanf("%d", &choice);
    return choice;
} 
###  (ii)
void addition(void)
{
    int answer;
    printf("       Addition           \n"
           "       ========           \n\n"
           "13 + 25 = ?\n\n"
           "Key in your answer and press <Enter>\n");
    scanf("%d", &answer);

    if (answer == (13+25))
        printf("Your answer is correct.\n");
    else
        printf("Your answer is incorrect. \n");
}

### (iii)

int main(void)
{
    int choice;
    do
    {
        choice = mainMenu();
        switch(choice)
        {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                exit(-1);
            default:
                printf("Invalid entry.\n");
        }
    }
    while (choice < 1 || choice > 4);
}

## Q9
```c
void calculateOt (*int* wrkHrs, *float rate*)
{
double ot = 0;
if (wrkHrs > 45)
ot = (wrkHrs – 45) * rate;
return(ot);
}

void main()
{
double ot, total;
int hrs;
float rate;
printf("Please enter the hours worked and pay rate: ");
scanf("%d %f", &hrs, &rate);
ot = calculateOt(wrkHrs, rate);
total = ot + 200;
display(*total*);
}
```

## Q10
```
m = 17
t = 0.71
```

## Q11
### (a)
(i)
```c
int mainMenu(void)
{
    int choice;
    printf("Dungeons and Dragons\n\n"
           "1. Single Player\n"
           "2. Multiplayer\n"
           "3. Setting\n"
           "4. Quit Game\n\n"
           "Choose one > ");
    scanf("%d", &choice);

    return choice;
}
```
(ii)
```c
void subMenu(int choice)
{
    switch(choice)
    {
        case 1:
            printf("Single Player\n\n"
                   "1. New Game\n"
                   "2. Load Game\n"
            );
            break;
        case 2:
            printf("Multiplayer\n\n"
                   "1. New Game\n"
                   "2. Load Game\n");
            break;
        case 3:
            printf("Setting\n\n"
                   "1. Graphics\n"
                   "2. Sound\n"
                   "3. Back\n\n"
                   "Choose one > ");
            setting();
    }
}
```
### (b)
void setting(void)
{
    int choice = 0;
    
    while(choice != 1 && choice !=2 && choice != 3)
    {
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Display Graphics Options\n");
                break;
            case 2:
                printf("Display Sound Options\n");
                break;
            case 3:
                break;
            default:
                printf("Invalid choice! Please enter again: ");
        }
    }
}