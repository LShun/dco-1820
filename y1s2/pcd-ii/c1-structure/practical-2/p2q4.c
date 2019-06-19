/*
Name: p2q4.c
Desc: Employee Details View & Search (by month & year) Program
*/

#include <stdio.h>
#include <string.h>
#define SIZE 5

struct Date
{
    int day, month, year;
};

typedef struct
{
    char id[4], name[20], dept[5];
    struct Date joinDate;
}Employee;


//function prototypes
int displayInfo(Employee* emp);
int search(Employee* emp);

int main(void)
{
    //variables
    Employee emp[SIZE] = {{"E01", "Alice Chin", "R&D", {1, 1, 2000}}, {"E02", "John", "IT", {9, 1, 2010}}, 
                          {"E03", "Vivian", "R&D", {3, 3, 2005}}, {"E04", "Alice Chin", "IT", {4, 4, 2010}}, 
                          {"E05", "Vivien Tan", "HR", {5, 3, 2012}}};   

    //display table of employee information
    displayInfo(emp);

    //allow search by month
    search(emp);
}

int displayInfo(Employee* emp)
{
    //variables
    int i, count = 0;

    //print heading
    printf("%-16s %-16s %-16s %-16s\n\n", "Employee ID", "Name", "Date Joined", "Department");

    //display information
    for (i = 0; i < SIZE; i++)
    {
        printf("%-16s %-16s %02d/%02d/%-10d %-16s\n", emp[i].id, emp[i].name, emp[i].joinDate.day, emp[i].joinDate.month, emp[i].joinDate.year, emp[i].dept);
        count++;
    }
    //display total records
    printf("\n" "%d records found\n\n", count);
}

int search(Employee* emp) //search database for employee
{
    //variables
    int month = 0, year = 0, count = 0, i;
    //prompt for employee's month joined
    printf("Search for employee by month & year joined (eg input: 3 2001 ): ");
    scanf("%d %d", &month, &year);

    while (month < 1 || month > 12)
    {
        printf("Invalid month. Enter again (input: <month> <year> ): ");
        scanf("%d %d", &month, &year);
    }
    
    //print heading
    printf("%-16s %-16s %-16s %-16s\n\n", "Employee ID", "Employee Name", "Date Joined", "Department");

    //linear search through the database
    for (i = 0; i < SIZE; i++)
    {
        if (emp[i].joinDate.month == month && emp[i].joinDate.year == year)
        {
            printf("%-16s %-16s %-16d %-16s\n", emp[i].id, emp[i].name, emp[i].joinDate.day, emp[i].dept);
            count++;
        }
        
    }
    //prompt info regarding employee joined in the particular month and year
    if (count == 0)
    {
        printf("No employee joined at %02d/%d.\n", month, year);
    }
    else
    {
        printf("%d records found for employee's joined at %02d/%d\n", count, month, year);
    }
    
}