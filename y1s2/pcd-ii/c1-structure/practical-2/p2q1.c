/*
Name: p2q1.c
Desc: CD Database Manager
*/

#include <stdio.h>
#include <string.h>

#define CD 10
#define YR_LIM 2014

typedef 
struct Cd
{
    char performer[40];
    char name[30];
    int year;
    double cost;
    double playTime;
}Cd;

//prototypes
int printMenu(Cd *cdList);
int search(Cd *cdList);

int main(void)
{
    //variables
    int i;

    //initialize database
    Cd cdList[CD] = {"BlueSky", "Dazzling Moon", 2021, 123, 1.61};

    for (i = 0; i < CD; i++)
    {
        cdList[i] = cdList[0];
    }
    //print entire database
    printMenu(cdList);

    //search database for CD using performer name
    search(cdList);
}

int printMenu(Cd *cdList)
{
    //variables
    int count = 0, i;
    
    //print all CD information
    //print heading
    printf("%-16s %-16s %-16s %-16s %-16s\n", "Performer", "CD Name", "Year", "Cost", "Play Time (Mins)");

    //for each CD
    for (i = 0; i < CD; i++)
    {
        //access each entries and print them
        printf("%-16s %-16s %-16d %-16.2f %-16.2f\n", cdList[i].performer, cdList[i].name, cdList[i].year, cdList[i].cost, cdList[i].playTime);
    }
    
    //print information for CD released before 2014
    //print heading
    printf("\n%-16s %-16s %-16s\n", "Performer", "CD Name", "Cost");
    //for each CD, check if the year is less than 2014
    for (i = 0; i < CD; i++)
    {
        if (cdList[i].year < YR_LIM)
        {
            printf("%-16s %-16s %-16.2f\n", cdList[i].performer, cdList[i].name, cdList[i].cost);
            count++;
        }
    }
    //print total CD released before 2014 count
    printf("Total CD's released before %d: %d\n", YR_LIM, count);
}

int search(Cd *cdList) //search database for CD by performer name
{
    //variables
    char performer[30];
    int count = 0, i;
    //prompt for performer's name
    printf("Performer's Name to search: ");
    scanf("%s", &performer);

    //print heading
    printf("%-16s %-16s %-16s %-16s\n", "CD Name", "Year", "Cost", "Play Time (Mins)");

    //linear search through the database
    for (i = 0; i < CD; i++)
    {
        if (strcmp(cdList[i].performer, performer) == 0)
        {
            printf("%-16s %-16d %-16.2f %-16.2f\n", cdList[i].name, cdList[i].year, cdList[i].cost, cdList[i].playTime);
            count++;        
        }
        
    }
    printf("%d records found for Performer's Name = %s\n", count, performer);
}