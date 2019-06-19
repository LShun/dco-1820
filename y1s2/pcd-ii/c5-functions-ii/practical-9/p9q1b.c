/*
Name: p9q1a.c
Desc: Demonstrate how global variable works using an example to calculate marks.
*/

#include <stdio.h>

void getExamMark(int *exam); // function prototypes
void getCourseworkMark(int *cour);
void calculateFinalMark(int *exam, int *cour, int *final);
void printFinalMark(int final);
int markIsValid(int mark, int maxMark);

int main(void)
{
    int exam, cour, final;
    getExamMark(&exam);        // must be from 0 to 100
    getCourseworkMark(&cour);  // must be from 0 to 40
    calculateFinalMark(&exam, &cour, &final); // 60%*exam + coursework
    printFinalMark(final);     // display final mark tidily
}

void getExamMark(int *exam)
{
    do
    {
        printf("Exam Mark (0 to 100) : ");
        scanf("%d", exam);
    } while (!markIsValid(*exam, 100)); // must be from 0 to 100
}

void getCourseworkMark(int *cour)
{
    do
    {
        printf("Coursework Mark (0 to 40) : ");
        scanf("%d", cour);
    } while (!markIsValid(*cour, 40)); // must be from 0 to 40
}
void calculateFinalMark(int *exam, int *cour, int *final)
{
    *final = 0.6*(*exam) + *cour;
}
void printFinalMark(int final)
{
    printf ("Final Mark = %d\n", final);
}

int markIsValid(int mark, int maxMark)
{
    if (mark >= 0 && mark <= maxMark)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

