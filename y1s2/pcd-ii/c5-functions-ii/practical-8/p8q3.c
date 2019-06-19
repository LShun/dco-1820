/*
Name: p8q3.c
Desc: Find which number is bigger and/or smaller
*/
//declarations
#include <stdio.h>

//prototypes
int bigger(int *x, int *y);
int smaller(int *x, int *y);
void hiLo(int *x, int *y, int *z, int *highest, int *lowest);

int main(void)
{
    //variables
    int x = 3, y = 4, z = 5, highest, lowest;
    hiLo(&x, &y, &z, &highest, &lowest);
    printf("Highest: %d, Lowest: %d\n", highest, lowest);
}

int bigger(int *x, int *y)
{
    //compare the numbers
    //if x > y, then return x
    if (*x > *y)
    {
        return *x;
    }
    //else return y
    else
    {
        return *y;
    }
}

int smaller(int *x, int *y)
{
    //compare the numbers
    //if x < y, then return x
    if (*x < *y)
    {
        return *x;
    }
    //else return y
    else
    {
        return *y;
    }
}

void hiLo(int *x, int *y, int *z, int *highest, int *lowest)
{
    //test for highest number
    //compare x and y, which is largest
    *highest = bigger(x, y);
    //compare bigger value with z
    *highest = bigger(highest, z);

    //test for lowest number
    //compare x and y, which is smaller
    *lowest = smaller(x, y);
    //compare smaller value with z
    *lowest = smaller(lowest, z);
}