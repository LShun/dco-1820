/*
Name: p1q1a.c
Desc: Display attendance details of a student
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
    int nameLen;

    //assign values of choice ( following the way presented in the illustrated program)
    strcpy(att.studentName, "Tan Ah Kow");
    strcpy(att.programmeCode, "DAC");
    att.yearOfStudy = 1;
    att.groupCode = 'C';
    att.groupNo = 3;
    att.daysAbsent = 3;

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