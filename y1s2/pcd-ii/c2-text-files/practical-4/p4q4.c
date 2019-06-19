/*
Name: p4q4.c
Desc: Read student records from a file in the format of 
      <Student ID>|<Student Name>|<CGPA> and display it in a table
*/

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE "Student.txt"

//prototypes
void heading();
int printDetails(FILE *fp);
void footer();

int main(void)
{
    //variables
    char id[32], name[50];
    double cgpa;
    FILE* fp;

    //open the file
    fp = fopen(IN_FILE, "r");
    //check for errors
    if (fp == NULL)
    {
        printf("Cannot open %s file for reading, does the file exist?\n", IN_FILE);
        exit(-1);
    }

    //print the headings
    heading();

    //print the student details
    printDetails(fp);

    //print the footer
    footer();

    //close the file stream
    fclose(fp);
}

void heading()
{
    //print title
    printf("         LIST OF STUDENTS                   \n"
    //print table column titles
           "Student ID          Name                CGPA\n"

    //print line of "=" signs
           "==========          ====                ====\n");
}

int printDetails(FILE *fp)
{
    //variables
    char id[21], name[21];
    double cgpa;
    
    //repeat till reach EOF
    //read the student ID, name and CGPA to their respective variables
    while (fscanf(fp, "%20[^|]|%20[^|]|%lf\n", id, name, &cgpa) != EOF)
    {
        //print them out appropriately
        printf("%-19s %-19s %-2.2lf\n", id, name, cgpa);
    }
    return 0;
}

void footer()
{
    printf("============================================\n");
}