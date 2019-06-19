/*
Name: p8q5.c
Desc: Calculate grade point from grade.
*/

#include <stdio.h>

//prototypes
void getGradeAndGp(char *grade, int *gp);

int main(void)
{
    //variables
    int credits, gp, qp;
    char grade; 

    //get credits
    printf("Enter the number of credits for the subject: ");
    scanf("%d", &credits);
    rewind(stdin);

    //get subject grade and grade point
    getGradeAndGp(&grade, &gp);

    //calculate quality points 
    qp = credits * gp;
    //display quality points 
    printf("Your grade of %c, G.P. %d and credit of %d nets you quality points (QP) are: %d", grade, gp, credits, qp);
    return 0;
}
void getGradeAndGp(char *grade, int *gp)
{
    //variables
    //read grade
    printf("Enter the grade acquired in capital letters (ex: A): ");
    scanf("%c", grade);
    rewind(stdin);
    //write appropriate gp
    switch (*grade)
    {
        case 'A':
            *gp = 4;
            break;
        case 'B':
            *gp = 3;
            break;
        case 'C':
            *gp = 2;
            break;
        case 'D':
            *gp = 2;
            break;
        case 'F':
        default:
            *gp = 0;
    }
}