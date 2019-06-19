/*
Name: p9q4.c
Desc: Performs basic arithmetic operations
*/
#include <stdio.h>

void sum(int a, int b);
void difference(int a, int b);
void product(int a, int b);
void quotient(int a, int b);

int main(void)
{
    int a, b, choice;
    printf("Enter 2 numbers (Eg: a b): ");
    scanf("%d %d", &a, &b);
    printf("1. Sum\n2. Difference\n3. Product\n4. Quotient\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            sum(a,b);
            break;
        case 2:
            difference(a,b);
            break;
        case 3:
            product(a,b);
            break;
        case 4:
            quotient(a,b);
            break;
    }
}

void sum(int a, int b)
{
    int sum;

    sum = a+b;

    printf("%d + %d = %d\n", a, b, sum);
}

void difference(int a, int b)
{
    int difference;

    difference = a-b;

    printf("%d - %d = %d\n", a, b, difference);
}

void product(int a, int b)
{
    int product;
    product = a*b;

    printf("%d * %d = %d\n", a, b, product);
}

void quotient(int a, int b)
{
    int quotient;

    quotient = a/b;

    if (b == 0)
    {
        printf("Error: Division by zero.\n");
    }
    else
    {
        printf("%d / %d = %d\n", a, b, quotient);
    }
}