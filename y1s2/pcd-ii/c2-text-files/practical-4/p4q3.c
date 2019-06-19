/*
Name: p4q3.c
Desc: Write student records to a file in the format of 
      <Student ID>|<Student Name>|<CGPA>
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OUT_FILE "Student.txt"

typedef struct {
    char id[32], name[50];
    double cgpa;
} Student;

int main(void)
{
    //variables
    FILE* fp;
    char cont;
    Student student;

    //open file for writing
    fp = fopen(OUT_FILE, "w");
    //check for errors
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

    do
    {
        //input
        //ask for ID
        printf("Student ID? (Eg: WAD0001DIA): ");
        gets(student.id);

        //ask for name
        printf("Student Name? (Eg: Thomson Lee): ");
        scanf("%50[^\n]", &student.name);
        rewind(stdin);

        //ask for CGPA
        printf("CGPA? (Eg: 4.00): ");
        scanf("%lf", &student.cgpa);
        rewind(stdin);

        //output
        //write to file
        fprintf(fp, "%s|%s|%.2lf\n", student.id, student.name, student.cgpa);

        //Ask if user want to write more records
        printf("Any more records? (Y/y = yes, others = No): ");
        scanf("%c", &cont);
        rewind(stdin);
    }
    while (toupper(cont) == 'Y');

    //if no, close file
    fclose(fp);
    //exit
    printf("Done.");
    return 0;
}
