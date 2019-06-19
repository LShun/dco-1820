/*
Name: p7q5.c
Desc: Calculate parking fee
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayVehicleRate(char vehicleType);
char getVehicleType(void);
int calcHoursParked(int inHr, int inMin, int outHr, int outMin);
double parkingCharge(char vehicleType, int hrsParked);

int main(void)
{
    //variables
    char vehicleType;
    double hours;
    int inHr, inMin, outHr, outMin;
    
    //get vehicle type
    vehicleType = getVehicleType();
    //get parking hours
    printf("Time entered car park (hh mm)?: ");
    scanf("%d %d", &inHr, &inMin);
    rewind(stdin);
    printf("Time exited car park (hh mm): ");
    scanf("%d %d", &outHr, &outMin);
    rewind(stdin);
    //print headings
    printf("========================================================\n"
           "                      Parking Ticket\n"                  );
    //display rate
    displayVehicleRate(vehicleType);

    //display hours parked
    hours = calcHoursParked(inHr, inMin, outHr, outMin);
    if (hours == -1)
    {
        printf("\n" "Error, please see the management.\n");
        exit(-1);
    }

    printf("Hours parked : %.2f\n", hours);
    
    //get total payment
    printf("Please pay this amount ------> RM %.2f\n", parkingCharge(vehicleType, hours));

    //print footer
    printf("Thank You & Have a Nice Day !\n"
           "========================================================\n");
}

void displayVehicleRate(char vehicleType)
{
    //variables
    char type[10];
    double rate;

    switch (vehicleType)
    {
        case 'c':
            strcpy(type, "CAR");
            rate = 2.00;
            break;
        case 'b':
            strcpy(type, "BUS");
            rate = 3.00;
            break;
        case 't':
            strcpy(type, "TRUCK");
            rate = 4.00;
            break;
        default:
            printf("Invalid vehicle type.\n");
            rate = 0.00;
    }
    printf("Vehicle Type : %s => RM %.2f per hour (or part thereof)\n", type, rate);
}

char getVehicleType(void)
{
    char type;
    do
    {
        printf("Vehicle type : c(ar), b(us), t(ruck)? ");
        scanf("%c", &type);
        rewind(stdin);
    }
    while (type != 'c' && type != 'b' && type != 't');
    return type;
}

int calcHoursParked(int inHr, int inMin, int outHr, int outMin)
{
    //check for validity
    if (inHr < 7 || inHr > 24)
    {
        return -1;
    }
    else if (outHr < 7 || outHr > 24)
    {
        return -1;
    }
    else if (outHr < inHr)
    {
        return -1;
    }
    else if (outHr >= 24 && outMin > 0)
    {
        return -1;
    }
    //variables
    int hours, minutes;
    //obtain hours parked (without fractions)
    hours = outHr - inHr;
    //obtain hours parked (for fractions)
    minutes = outMin - inMin;
    //if its positive then count as one hour
    if (minutes > 0)
    {
        hours++;
    }
    //otherwise dont count
    //if total parked hours exceed 17 hours ( outside of 7am-12pm ), report error
    if(hours > 17)
    {
        return -1;
    }
    return hours;
}

double parkingCharge(char vehicleType, int hrsParked)
{
    //variables
    char rate;
    double charge;

    //check vehicleType
    switch (vehicleType)
    {
        case 'c':
            rate = 2.00;
            break;
        case 'b':
            rate = 3.00;
            break;
        case 't':
            rate = 4.00;
            break;  
    }
    //determine charge
    //multiply by hours parked
    charge = hrsParked * rate;
    //return parking charge
    return charge;
}