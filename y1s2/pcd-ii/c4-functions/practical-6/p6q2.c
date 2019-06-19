/*
Name: p6q2.c
Desc: Calculates the area of a right angle triangle
*/
#include <stdio.h>

void doTriangleArea();

int main(void)
{
    doTriangleArea();
    return 0;
}

void doTriangleArea()
{
    //variables
    double a, b, area;

    //input
    //obtain two perpendicular sides
    printf("Enter two perpendiculat sides a, b, of a right-angled triangle ( Ex: 2.5 4): ");
    scanf("%lf %lf", &a, &b);
    rewind(stdin);

    //process
    //calculate area
    area = 0.5 * a * b;

    //display area
    printf("Area of triangle is: %f\n", area);
}