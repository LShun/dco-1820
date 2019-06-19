/*
Name: p7q4.c
Desc: Accept a mark and return a grade
*/

#include <stdio.h>
char markToGrade(int mark);

int main(void)
{
    //variables
    int mark;
    char grade;

    printf("Exam Mark (0 to 50): ");
    scanf("%d", &mark);
    
    grade = markToGrade(mark);

    printf("RESULTS:       Final Mark = %d      GRADE = %c\n", mark, grade);
}

char markToGrade(int mark)
{
    if (mark >= 80)
        return 'A';
    else if (mark >= 65)
        return 'B';
    else if (mark >= 50)
        return 'C';
    else if (mark >= 40)
        return 'D';
    else if (mark >= 0)
        return 'F';
    else
        return 'Z';
}

