/*
Name: p2q4.c
Desc: Employee Details View & Edit (based on employee ID) Program
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
int modify(Employee* emp);
int matchPrint(Employee *emp, int i);
int matchModify(Employee *emp, int match, int i);

int main(void)
{
    //variables
    Employee emp[SIZE] = {{"E01", "Alice Chin", "R&D", {1, 1, 2000}}, {"E02", "John", "IT", {9, 1, 2010}}, 
                          {"E03", "Vivian", "R&D", {3, 3, 2005}}, {"E04", "Alice Chin", "IT", {4, 4, 2010}}, 
                          {"E05", "Vivien Tan", "HR", {5, 3, 2012}}};   

    //display table of employee information
    displayInfo(emp);

    //prompt to modify by ID
    modify(emp) == 0;
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

int modify(Employee* emp) //modify database for employee
{
    //variables
    char id[4], i; 
    int match = -1;
    Employee snapshot;

    while (match == -1)
    {
        //prompt for employee's ID
        printf("Modify for employee by ID (eg input: E01 ), input -1 to exit: ");
        scanf("%3s", &id);
        rewind(stdin);

        //if exit code, then exit
        if (strcmp(id, "-1") == 0)
        {
            printf("Exited.\n");
            return 0;
        }
        //else try to match
        for (i = 0; i < SIZE; i++)
        {
            if (strcmp(emp[i].id, id) == 0)
            {
                //track the position of the employee in the array
                match = i;
                //prompt info about matched employee
                matchPrint(emp, match);
                //ask for editing
                matchModify(emp, match, i);
            }
        }
    }
}

int matchPrint(Employee *emp, int i)
{
    //print header
    printf("Modifying for: \n\n" "%-16s %-16s %-16s\n\n", "Employee Name", "Date Joined", "Department");
    printf("%-16s %02d/%02d/%-10d %-16s\n\n", emp[i].name, emp[i].joinDate.day, emp[i].joinDate.month, emp[i].joinDate.year, emp[i].dept);
    return 0;
}

int matchModify(Employee *emp, int match, int i)
{
    //variables
    int choice;
    Employee snapshot;

    //keep a snapshot of the original data
    snapshot = emp[i];

    //ask user which item to edit
    printf("Which particular would you like to edit?\n"
        "1. Name\n"
        "2. Join Date\n"
        "3. Department\n"
        "(Enter : 1-3): ");

    //Get user input for replacement data
    scanf("%d", &choice);
    rewind(stdin);
    printf("Enter the replacement value: ");
    //Replace chosen item with replacement data
    switch (choice)
    {
        case 1:
            scanf("%[^\n]", emp[match].name);
            break;
        case 2:
            scanf("%d/%d/%d", &emp[match].joinDate.day, &emp[match].joinDate.month, &emp[match].joinDate.year);
            break;
        case 3:
            scanf("%[^\n]", emp[match].dept);
            break;
    }
    //Show changes
    printf("Modifed: \n\n" "%-16s %-16s %-16s\n\n", "Employee Name", "Date Joined", "Department");
    printf("From:\n");
    printf("%-16s %02d/%02d/%-10d %-16s\n", snapshot.name, snapshot.joinDate.day, snapshot.joinDate.month, snapshot.joinDate.year, snapshot.dept);
    printf("To  :\n");
    printf("%-16s %02d/%02d/%-10d %-16s\n", emp[match].name, emp[match].joinDate.day, emp[match].joinDate.month, emp[match].joinDate.year, emp[match].dept);
    return 0;
}
