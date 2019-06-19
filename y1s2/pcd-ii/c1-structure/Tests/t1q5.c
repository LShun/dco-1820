#include <stdio.h>
#include <string.h>

struct MovieTicket {
    char name[25];
    int time;
    double price;
    char seat[3];
};

int main(void)
{
    struct MovieTicket ticket;

printf("Enter the screen time: ");
scanf("%d", &ticket.time);
while (ticket.time != 2 && ticket.time != 5 && ticket.time != 8 && ticket.time != 11)
{
    printf("Invalid screen time, please enter again: ");
    scanf("%d", &ticket.time);
}
}