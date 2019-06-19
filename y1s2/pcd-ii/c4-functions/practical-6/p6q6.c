/*
Name: p6q2.c
Desc: Calculates the area of a right angle triangle
*/
#include <stdio.h>

double triangleArea();

int main(void)
{
    double area1;

    area1 = triangleArea();
    printf("Area of 1st triangle: %.2f\n\n", area1);

    printf("Area of 2nd triangle: %.2f\n\n", triangleArea());
    return 0;
}

double triangleArea()
{
    //variables
    double a, b, area;

    //input
    //obtain two perpendicular sides
    printf("Enter two perpendicular sides a, b, of a right-angled triangle ( Ex: 2.5 4): ");
    scanf("%lf %lf", &a, &b);
    rewind(stdin);

    //process
    //calculate area
    area = 0.5 * a * b;

    //display area
    return area;
}