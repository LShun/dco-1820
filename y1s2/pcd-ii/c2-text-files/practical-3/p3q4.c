/*
Name: p3q4.c
Desc: Allow use to add entries into mixed.txt for use in p3q3
*/

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE "./mixed.txt"

void displayRecords();
void addRecords();
int main(void)
{
    addRecords();
    displayRecords();
    return 0;
}

void addRecords()
{
    //variables
    FILE *fp;
    char name[40];
    int mark, additions;

    //open the file to write
    fp = fopen(IN_FILE, "a");
    if (fp == NULL)
    {
        printf("Cant open %s. Exiting.", IN_FILE);
        exit(-1);
    }
    //formatting
    printf("Add Records\n"
            "-----------\n");
    //ask user if want to add another entry
    printf("Add another record (Y = yes)? ");
    while (getc(stdin) == 'Y')
    {
        getc(stdin);
        //prompt user for name
        printf("\tName : ");
        scanf("%[^\n]", &name);
        rewind(stdin);
        //prompt user for mark
        printf("\tMark : ");
        scanf("%d", &mark);
        rewind(stdin);
        //write to file
        fprintf(fp, "%s\n%d\n", name, mark);
        //inform user status
        printf("Record successfully added...\n\n");
        //increase count
        additions++;
        //ask user if repeat
        printf("Add another record (Y = yes)? ");
    }
    //Inform user total additions made
    printf("%d records have been added to mixed.txt\n", additions);

    //close the file
    fclose(fp);
}

void displayRecords()
{
    //variables
    char name[40];
    FILE *fp;
    int mark, records;
    
    //open file
    fp = fopen(IN_FILE, "r");
    if (fp == NULL)
    {
        printf("Cant open %s. Exiting.", IN_FILE);
        exit(-1);
    }

    //print heading
    printf("LIST OF RECORDS - mixed.txt\n"
           "\tNAME\t\t\tMARK\n"
           "\t====\t\t\t====\n"
    );

    //print from file
    while (fscanf(fp, "%[^\n] %d\n", &name, &mark) != EOF)
    {
        printf("\t%s\t\t%d\n", name, mark);
        records++;
    }
    
    printf("\n" "\tNumber of records = %d\t", records);
    fclose(fp);
}