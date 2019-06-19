/* 
Name: p7q1.c
Desc: Converts inches to centimeters. Note: Accepts inches in integers.
 */

//directives
#include <stdio.h>

//prototypes
double inchToCm(int inch);

int main(void)
{
    //variables
    int inch;
    double cm;

    //ask for input in inches
    printf("Enter inches in integers (ex: 6): ");
    scanf("%d", &inch);
    //convert to cm
    cm = inchToCm(inch);
    //print the measurement in centimeters
    printf("%d inch = %f cm", inch, cm);

    return 0;
}

//definitions
double inchToCm(int inch)
{
    double cm;

    cm = inch * 2.54;

    return cm;
}