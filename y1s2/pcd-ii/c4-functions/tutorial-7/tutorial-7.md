# Tutorial 7

- [Tutorial 7](#tutorial-7)
  - [Q1](#q1)
  - [Q2](#q2)
  - [Q3](#q3)
    - [a](#a)
    - [a(ii)](#aii)
    - [b](#b)
  - [Q4](#q4)
  - [Q5](#q5)
  - [Q6](#q6)
  - [Q7](#q7)
    - [(i)](#i)
    - [(ii)](#ii)
    - [(iii)](#iii)
  - [8.](#8)
    - [(a)](#a)
    - [(b)](#b)
    - [(c)](#c)
  - [Q9](#q9)
    - [(i)](#i-1)
    - [(ii)](#ii-1)
    - [(iii)](#iii-1)
  - [Q10](#q10)
  - [Q11](#q11)
  - [Q12](#q12)
  - [Q13](#q13)

## Q1
Explain the difference between pass by value and pass by address in parameter
passing.
```
Ans:
Pass by value gives a copy of the variable itself. Pass by address gives a copy
of the address pointing to the variable to the function.
```
Local variables passed by value will be destroyed after the function ends. Local
variables passed by address are not destroyed after the function ends.

## Q2
Write a function prototype for a function named calculate that returns void and
contains an integer value parameter x, and a reference parameter to a long
double, y.
 
Ans:
`void calculate(int x, long double* y);`

## Q3
### a
`void func1(int b, int c);`

### a(ii)
`a = 5, b = 2`

### b
```c
int funct2(int p, int q, int *product)
{
    *product = p * q;

    return p-q;
}
```
## Q4
```c
int upgrade(int mark, int *newMark)
{
    if (mark < 40)
        *newMark = mark + 10;
    else
        *newMark = mark;
        
    if (newMark == mark)
        return 0;
    else
        return 1;
}
```

## Q5
```c
int upgrade(int mark, int *newMark)
{
    if (mark < 40 && newMark == mark)
        *newMark = mark + 10;
        printf("Yes");
    else
        *newMark = mark;
        printf("No");
}
```

## Q6
```c
void sumAvg(double num1, double num2, double num3, double *sum, double *average);
{
    *sum = num1 + num2 + num3;
    *average = *sum / 3;
}
```

## Q7
### (i)
```c
void squareOf(int number, int *square)
{
    *square = number * number;
}
```

### (ii)
```c
int cubeOf(int number)
{
    int cube;

    cube = number * number * number;

    return cube;
}
```

### (iii)
```c
void formulaCalc()
{
    int x, xSq, xCu, y;
    printf("Enter an integer: ");
    scanf("%d", &x);

    squareOf(x, &xSq);
    xCu = cubeOf(x);

    y = x + xSq + xCu;

    printf("Y= %d", y);
}
```

## 8.
### (a)
```c
int calculateVolume(int length, int width, int height)
{
    int volume;
    volume = length * width * height;

    return volume;
}
```
### (b)
```c
void calculatePerimeter(int length, int width, int height, int *perimeter)
{
    *perimeter = length*2 + width*2 + height*2;
}
```

### (c)
```c
void main(void)
{
    int volume, perimeter, length, width, height;

    printf("Enter length, width, height of cuboid (Eg: 12 12 12): ");
    scanf("%d %d %d", &length, &width, &height);

    volume = calculateVolume(length, width, height);
    calculatePerimeter(length, width, height, &perimeter);

    printf("Volume: %d\n", volume);
    printf("Perimeter: %d", perimeter);
}
```

## Q9
### (i)
```c
int addition(int x, int y)
{
    int sum;

    sum = x + y;

    return sum;
}
```

### (ii)
```c
int division(int x, int y, int *remainder)
{
    int quotient;

    quotient = x / y;
    *remainder = x % y;

    return quotient;
}
```

### (iii)
```c
void main(void)
{
    int x, y, sum, quotient, remainder;

    printf("Enter two integer: ");
    scanf("%d %d", &x, &y);
    
    sum = addition(x, y);
    quotient = division(x, y, &remainder);

    printf("Results:\n"
           "     Sum:           %d\n"
           "     Quotient:      %d\n"
           "     Remainder:     %d\n",
           sum, quotient, remainder);
}
```

## Q10
```
The net rate for your deposit is 6%
The deviation from the acceptable rate is 2%
```
Reason: Integer division = 0;

```c
#define MINIMUM_RETURN_RATE 2

void netRateCalc(int depositRate, int marginalRate, int *netRate)
{
    *netRate = depositRate - depositRate * marginalRate / 100;
}

void displayAnalysis(int depositRate, int marginalRate)
{ 
    int netRate;
    netRateCalc(depositRate, marginalRate, &netRate);
    printf("The net rate for your deposit is %d%%\n", netRate);
    printf("The deviation from the acceptable rate is %d%%\n", netRate - MINIMUM_RETURN_RATE);
}

void main()
{ 
    int depositRate, marginalRate;
    scanf("%d%d", &depositRate, &marginalRate);
    displayAnalysis(depositRate, marginalRate);
}
```
## Q11
before calling fun1 : u =2 v =4
within fun1: u =0 v =0
after calling fun1 : u =2 v =4
before calling fun2 : u =2 v =4
within fun2 : *pu =2 *pv =4
after calling fun2 : u =2 v =4

## Q12
Numbers: 8 10 23  13 23  13

Note: Take note, the parameter "i" is not passed into the function, therefore,
it is invisible to the function. The function can only access the "i" available
in the global variable.

## Q13  
x = 10, y = 5
ch = N
x = 10
x = 8, y = 15

Note: In this case, the parameter require is passed to the correct function,
therefore, the variable is available for use.