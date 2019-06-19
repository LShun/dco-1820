/*
Name: p6q3.c
Desc: Calculates the circle's diameter, circumference and area using the radius
*/

#include <stdio.h>

#define PI 3.14159

void displayCircleInfo();
void welcome();

int main(void)
{
    welcome();
    displayCircleInfo();
    return 0;
}

void displayCircleInfo()
{
    //variables
    double radius, diameter, circumference, area;

    //read in the radius of circle
    printf("Circle information calculator\n"
           "-----------------------------\n"
           "Enter the radius of a circle: "
           );
    scanf("%lf", &radius);
    rewind(stdin);
    //calculate diameter, circumference and area
    diameter = 2 * radius;
    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    //display results
    printf("Diameter     : %.2f\n"
           "Circumference: %.2f\n"
           "Area         : %.2f\n",
           diameter, circumference, area);
}

void welcome()
{
    printf("WELCOME !                       * *\n"
           "This program will calculate  *       *\n"
           "a circle's diameter,         *       *\n"
           "circumference and area.         * *\n\n");
}