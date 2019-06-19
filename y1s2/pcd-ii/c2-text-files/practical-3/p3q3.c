/*
Name: p3q3.c
Desc: Read specified integers from a file
*/

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE "./mixed.txt"

void displayRecords();

int main(void)
{
    displayRecords();
    return 0;
}

void displayRecords()
{
    //variables
    char name[40];
    FILE* fp;
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