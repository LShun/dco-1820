/*
Name: p8q6.c
Desc: Calculate age of person and display the age in years and month
*/
#include <stdio.h>

#define CUR_YEAR 2018
#define CUR_MONTH 12

void age(int monthBorn, int yearBorn, int *ageYrs, int *ageMths)
{
    *ageYrs = CUR_YEAR - yearBorn;
    *ageMths = CUR_MONTH - monthBorn;
}

int main(void)
{
    int monthBorn, yearBorn, ageYrs, ageMths;

    printf("Enter your month and year of birth (eg: 12 2012): ");
    scanf("%d %d", &monthBorn, &yearBorn);
    age(monthBorn, yearBorn, &ageYrs, &ageMths);
    printf("Age is %d yrs %d mth.\n", ageYrs, ageMths);
}