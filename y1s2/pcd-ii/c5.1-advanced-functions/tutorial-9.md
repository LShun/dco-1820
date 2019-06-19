# Tutorial 9
- [Tutorial 9](#tutorial-9)
  - [Q1](#q1)
  - [Q2](#q2)
  - [Q3](#q3)
  - [Q4](#q4)
  - [Q5](#q5)
    - [(i)](#i)
    - [(ii)](#ii)
  - [Q6](#q6)
  - [Q7](#q7)
  - [Q8](#q8)

## Q1

| Individual Elements | Passing (differences) | Whole Array |
| ------------------- | --------------------- | ----------- |
| The variable itself | What is passed | A pointer to the first element of the array |

## Q2

Trace table:

Output:
24
31
14
(Note: `i` starts from `size - 1`)

## Q3

```c
void arrayAverage(int m[], int size, int *total, double *average)
{
    int i;
    for (i = 0; i < size; i++)
        *total += m[i];
    *average = (double) *total / size;
}

arrayAverage(arr, 20, &total, &average);
```

## Q4

```c
From main, before calling the function:
a=1 b=2
c[0] = 10
c[1] = 20
c[2] = 30

 From the function, after modifying the values:
a=-999 b=-999
c[0] = -9
c[1] = -9
c[2] = -9

 From main, after calling the function:
a=-999 b=2
```

## Q5

### (i)

Function:

```c
void displayTitleName(Employee emp)
{
    printf("%s %s", emp.empTitle, emp.empSurname);
}
```

Example of function call:

```c
displayTitleName(emp);
```

### (ii)

Function:

```c
int isDatuk(Employee emp)
{
    if (strcmp(emp.empTitle, "Datuk") == 0))
    {
        return 1;
    }
    else return 0;
}
```

Example of function call:

```c
status = isDatuk(emp);
```

## Q6

```c
Line createLine(Point a, Point b)
{
    Line line = {a, b};
    return line;
}
```

## Q7

```c
int lineDirection(Line line)
{
    if(line.p1.x == line.p2.x)
        return 1; //vertical
    else if (line.p1.y == line.p2.y)
        return 2; //horizontal
    else return 3; //oblique
}
```

## Q8

```c
void getPoint(Point *point)
{
    printf("Enter new point's x-coordinate: ");
    scanf("%d", &point->x);
    printf("Enter new point's y-coordinate: ");
    scanf("%d", &point->y);
}
```

```c
int main(void)
{
    Point A, B;
    Line l;
    int d;
    getPoint(&A);
    getPoint(&B);
    l = createLine(A, B);
    d = lineDirection(l);
    printf("The line is ");

    switch(d)
    {
        case 1: printf("vertical.\n"); break;
        case 2: printf("horizontal.\n"); break;
        default: printf("oblique.\n");
    }
}
```