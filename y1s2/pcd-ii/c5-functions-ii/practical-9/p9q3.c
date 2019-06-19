/*
Name: p9q3.c
Desc: Demonstrate how global variable works using an example to calculate marks.
*/

//directives
#include <stdio.h>
#include <math.h>

//macros

//declarations
void menu(void);
double TriangleArea(int a, int b);
double TrianglePerimeter(int a, int b);

int main(void)
{
    int a, b, choice;
    double area, perimeter;

    menu();
    scanf("%d", &choice);
    while (choice == 1 || choice == 2)
    {
        printf("Enter values for sides of the triangle (a,b): ");
        scanf("%d %d", &a, &b);
        rewind(stdin);
        switch(choice)
        {
            case 1:
                area = TriangleArea(a,b);
                printf("Area of triangle: %f\n", area);
                break;
            case 2:
                perimeter = TrianglePerimeter(a,b);
                printf("Perimeter of triangle: %f\n", perimeter);
                break;
        }
        menu();
        scanf("%d", &choice);
    }
    printf("Goodbye.\n");
}

void menu(void)
{
    printf("   /|                  |\\\n"
           "  / | TRIANGLE EXPERT b| \\\n"
           " /__|                  |__\\\n"
           "                        a\n\n"
           "What do you want to calculate?\n"
           "[1] Area of Triangle\n"
           "[2] Perimeter of Triangle\n"
           "[other number] EXIT\n"
           "Your selection (Choose a number): ");
}

//definitions
double TriangleArea(int a, int b)
{
    double area;
    //calculate area
    area = 0.5 * a * b;

    return area;
}
double TrianglePerimeter(int a, int b)
{
    double perimeter;
    //calculate perimeter
    perimeter = a + b + sqrt(a*a + b*b);
    return perimeter;
}