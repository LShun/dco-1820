/*
Name: p10q5.c
Desc: Calculate amount of time asleep.
*/

//directives
#include <stdio.h>

//macros
#define FILE_PATH "CSstudents.txt"
//structures
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char iD[5];
    char name[30];
    Date dOB;
} Student;

//prototypes
void getDOB(Date *d);
void getStudentRec(Student *s);

int main(void)
{
    Student s;
    FILE *fp = fopen(FILE_PATH, "a");
    char cont;
    int stored;

    printf("Add new record? (Y/N): ");
    scanf(" %c", &cont);

    stored = 0;
    while(cont == 'Y')
    {
        getStudentRec(&s);
        fprintf(fp, "%s|%s|%d/%d/%d\n", s.iD, s.name, s.dOB.day, s.dOB.month, s.dOB.year);
        printf("Add new record? (Y/N): ");
        scanf(" %c", &cont);
        stored++;
    }
    printf("Total records stored: %d", stored);
    fclose(fp);
}

//definitions
void getDOB(Date *d)
{
    printf("Enter student's date of birth ( DD MM YYYY ): ");
    scanf("%d %d %d", &(d->day), &(d->month), &(d->year));
}

void getStudentRec(Student *s)
{
    printf("Enter student's ID: ");
    scanf(" %s", &(s->iD));
    printf("Enter student's name: ");
    scanf(" %[^\n]", &(s->name));
    getDOB(&(s->dOB));
}