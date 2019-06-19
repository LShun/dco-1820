#include <stdio.h>
#include <stdlib.h>
//declarations
#define IN_FILE "PartTime.txt"
//structures
typedef struct
{
	int payrollNo;
	float hourlyRate;
	int hoursWorked;
} PartTimer;

int main(void)
{
	//variables
	FILE *fp = fopen(IN_FILE, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

	PartTimer partTimer;
    double wage;

    printf("Payroll number        Wage (RM)\n"
           "--------------        ---------\n");
	while (fscanf(fp, "%d%f%d\n", &partTimer.payrollNo, &partTimer.hourlyRate, &partTimer.hoursWorked) == 3)
	{
        wage = partTimer.hourlyRate * partTimer.hoursWorked;
        printf("%-22d%9.2f\n", partTimer.payrollNo, wage);
    }
}