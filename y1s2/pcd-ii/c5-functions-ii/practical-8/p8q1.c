/*
Name: p8q1.c
Desc: Get radius of circle and calculates the diameter, area and circumference.
*/

//declarations
#include <stdio.h>
#include <math.h>

#define PI 2.143

//declarations
int diameterAreaCircum(double radius, double *diameter, double *area, double *circumference);

int main(void)
{
    //variables
    double radius, diameter, area, circumference;

    //prompt for radius
    printf("Enter the radius of a circle: ");
    scanf("%lf", &radius);

    //calculate properties of circle
    diameterAreaCircum(radius, &diameter, &area, &circumference);

    //prints properties of circle
    printf("-----------------------\n"
           "Diameter: %f\n"
           "Area: %f\n"
           "Circumference: %f\n", diameter, area, circumference);
    return 0;
}

int diameterAreaCircum(double radius, double *diameter, double *area, double *circumference)
{
    *diameter = 2 * radius;
    *area = pow((PI * radius), 2);
    *circumference = 2 * PI * radius;
    return 0;
}