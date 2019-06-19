/*
Name: p1q1b.c
Desc: Ask for user input, and display attendance details of a student
*/

#include <stdio.h>
#include <string.h>

struct Attendance {
    char studentName[40];
    char programmeCode[4];
    int yearOfStudy;
    char groupCode;
    int groupNo;
    int daysAbsent;
};

int main(void)
{
    //variables
    struct Attendance att;

    //assign values of choice ( following the way presented in the illustrated program)
    printf("Enter student name: ");
    fgets(att.studentName, 39, stdin); //40 is string limit, don't forget \0
    att.studentName[strcspn(att.studentName, "\n")] = 0;
    printf("Enter programme code, year of study (Eg. DAC 2): ");
    fscanf(stdin, "%3s %d", &att.programmeCode, &att.yearOfStudy);
    rewind(stdin);
    printf("Enter group code, group number (Eg: A 3): ");
    fscanf(stdin, "%c %d", &att.groupCode, &att.groupNo);
    printf("Enter days absent (Eg: 2): ");
    fscanf(stdin, "%d", &att.daysAbsent);

    //display student details
    printf("Name\t\t"
           "Programme code\t"
           "Year of study\t"
           "Group Code\t"
           "Group No\t"
           "Days absent\t"
           "Action\n"
    );
    printf("%-16.16s%-16s%-16d%-16c%-16d%-16d", att.studentName, att.programmeCode, att.yearOfStudy, att.groupCode, att.groupNo, att.daysAbsent);

    //display approp. action
    switch (att.daysAbsent)
    {
        case 1:
        case 2:
            printf("Warning to student.\n");
            break;
        case 3:
        case 4:
            printf("Inform parents\n");
            break;
        default: //assuming valid entries = 1 - infinity
            printf("Bar from exam.\n");
            break;
    }
    //print rest of name if cant fit
    if (strlen(att.studentName) > 16)
    {
        printf("%s\n", &att.studentName[17]);
    }
}