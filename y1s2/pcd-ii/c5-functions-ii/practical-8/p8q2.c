/*
Name: p8q2.c
Desc: Calculates the roots of a polynomial equation with a degree of 2.
*/
//declarations
#include <stdio.h>
#include <math.h>

//definitions

//declarations
int rootsFx(int a, int b, int c, double *x1, double *x2);

int main(void)
{
    //variables
    int a, b, c;
    double x1, x2;

    //ask for the 3 operands for the quadratic equation
    printf("Enter the three operands for a degree 2 quadratic equation (a b c): ");
    scanf("%d %d %d", &a, &b, &c);

    //calculate the two roots

    if (b*b - 4*a*c < 0)
    {
        printf("No real roots, discriminant, b^2-4ac less than 0\n");
    }
    else
    {
        rootsFx(a, b, c, &x1, &x2);

        //print the two roots
        printf("For the equation %dx^2 + %dx + %d\n"
                "The roots are %lf and %lf.\n", a, b, c, x1, x2);
    }

}

int rootsFx(int a, int b, int c, double *x1, double *x2)
{
    *x1 = (-(b) + sqrt(b*b - 4*a*c))/(2*a);
    *x2 = (-(b) - sqrt(b*b - 4*a*c))/(2*a);
}