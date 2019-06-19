/*
Name: p2q3.c
Desc: Employee Details View & Search (by name) Program
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

    //allow search by name
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
    printf("\n" "%d records found\n", count);
}

int search(Employee* emp) //search database for employee by name
{
    //variables
    char employee[30];
    int count = 0, i;
    //prompt for employee's name
    printf("Employee's Name to search: ");
    scanf("%[^\n]", &employee);

    //print heading
    printf("%-16s %-16s %-16s\n\n", "Employee ID", "Date Joined", "Department");

    //linear search through the database
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(emp[i].name, employee) == 0)
        {
            printf("%-16s %02d/%02d/%-10d %-16s\n", emp[i].id, emp[i].joinDate.day, emp[i].joinDate.month, emp[i].joinDate.year, emp[i].dept);
            count++;
        }
        
    }
    if (count == 0)
    {
        printf("No such employee.\n");
    }
    else
    {
        printf("%d records found for employee's Name = %s\n", count, employee);
    }
    
}