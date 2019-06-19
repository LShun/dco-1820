/*
Name: p9q1a.c
Desc: Demonstrate how global variable works using an example to calculate marks.
*/

#include <stdio.h>

void getExamMark(); // function prototypes
void getCourseworkMark();
void calculateFinalMark();
void printFinalMark();

int exam, cour, final; // global variables

main()
{
    getExamMark();        // must be from 0 to 100
    getCourseworkMark();  // must be from 0 to 40
    calculateFinalMark(); // 60%*exam + coursework
    printFinalMark();     // display final mark tidily

    system("pause");
}

void getExamMark()
{
    do
    {
        printf("Exam Mark (0 to 100) : ");
        scanf("%d", &exam);
    } while (!markIsValid(exam, 50)); // must be from 0 to 100
}

void getCourseworkMark()
{
    do
    {
        printf("Coursework Mark (0 to 40) : ");
        scanf("%d", &cour);
    } while (!markIsValid(cour, 40)); // must be from 0 to 40
}
void calculateFinalMark()
{
    final = 0.6*exam + cour;
}
void printFinalMark()
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

