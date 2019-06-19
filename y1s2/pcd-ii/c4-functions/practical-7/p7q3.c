/*
Name: p7q3.c
Desc: Calculate final mark from practical, coursework and exam mark
*/

#include <stdio.h>
int finalMark(int prac, int cour, int exam);
int markIsValid (int mark, int maxMark);

int main(void)
{
    //variables
    int practicalMark, cour, exam;
    //verify practical mark
    do
    {
        printf("Practical Mark (0 to 30) : ");
        scanf("%d", &practicalMark);
    } while (!markIsValid(practicalMark, 30));
    //verify coursework mark
    do
    {
        printf("Coursework Mark (0 to 20) : ");
        scanf("%d", &cour);
    } while (!markIsValid(cour, 20));
    //verify final exam mark
    do
    {
        printf("Final Exam Mark (0 to 50) : ");
        scanf("%d", &exam);
    } while (!markIsValid(exam, 50));

    printf ("Final Mark = %d\n", finalMark(practicalMark, cour, exam));

}

int finalMark(int prac, int cour, int exam)
{
    return prac + cour + exam;
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

