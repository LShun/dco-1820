/*
Name: p6q4.c
Desc: Display a circle information based on its radius.
*/

#include <stdio.h>
#include <stdlib.h>

//prototypes
void displayCinemaMenu();
void bookATicket();
void displaySeatLayout();

void main()
{
    //variables
    int choice;

    //prompt for choice
    while (1)
    {
        displayCinemaMenu();
        scanf("%d", &choice);
        rewind(stdin);
    
        switch(choice)
        {
            case 1:
                bookATicket();
                break;
            case 2:
                displaySeatLayout();
                break;
            case 3:
                exit(-1);
            default:
                printf("\n" "Invalid choice.\n");

        }
    }
}

void displayCinemaMenu()
{
    printf("\n" "CINEMA Menu\n\n"

           "1. Book a Ticket\n"
           "2. Display Seat Layout\n"
           "3. Exit\n\n"
           
           "Choose an option: ");
}

void bookATicket()
{
    printf("\n" "Under construction.\n\n");
}

void displaySeatLayout()
{
    printf("\n" "Under construction.\n");

}