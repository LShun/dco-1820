/*
Name: p4q5.c
Desc: Read student records from a file in the format of 
      <Student ID>|<Student Name>|<CGPA> and output student whose CGPA is 3.500 or higher to OUT_FILE.

*/

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE "Student.txt"
#define OUT_FILE "BookPrize.txt"

//prototypes
void heading();
int printDetails(FILE *fin, FILE *fout);
void footer();

int main(void)
{
    //variables
    char id[32], name[50];
    double cgpa;
    int award;
    FILE *fin, *fout;

    //open the file
    fin = fopen(IN_FILE, "r");
    fout = fopen(OUT_FILE, "w");

    //check for errors
    if (fin == NULL)
    {
        printf("Cannot open %s file for reading, does the file exist?\n", IN_FILE);
        exit(-1);
    }

    //print the headings
    heading();

    //print the student details
    award = printDetails(fin, fout);

    //print the footer
    footer(&award);

    //close the file stream
    fclose(fin);
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

int printDetails(FILE *fin, FILE *fout)
{
    //variables
    char id[21], name[21];
    double cgpa;
    int award = 0;
    
    //repeat till reach EOF
    //read the student ID, name and CGPA to their respective variables
    while (fscanf(fin, "%20[^|]|%20[^|]|%lf\n", id, name, &cgpa) != EOF)
    {
        //print them out appropriately
        if (cgpa >= 3.500)
        {
            fprintf(fout, "%-19s %-19s %-2.2lf\n", id, name, cgpa);
            award++;
        }
        
    }
    return award;
}

void footer(int *award)
{
    printf("============================================\n");
    printf("%d record(s) copied to BookPrize.txt\n", *award);
}