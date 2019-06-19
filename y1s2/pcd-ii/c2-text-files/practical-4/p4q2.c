/*
Name: p4q2.c
Desc: Generate badminton player's information from a file with format Name|Gender|Type|Country|Rank
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_FILE "badmintonPlayers.txt"

//prototypes
void header();
void printDetails();
void footer();

int main(void)
{
    //output
    //print out the header
    header();
    //print player details
    printDetails();
    //print footer
    footer();
}

void header()
{
    printf("                     LIST OF PLAYERS\n"
           "Name         Gender     Country    Game Type         Ranking\n"
           "---------------------------------------------------------\n");
}

void printDetails()
{
    //variables
    char name[12], country[12], type, gender;
    int rank;

    //open file
    FILE *fp = fopen(IN_FILE, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

    //loop till no more
    while (fscanf(fp, "%[^|]|%c|%c|%[^|]|%d\n", name, &gender, &type, country, &rank) != EOF)
    {
        //print name, gender, country
        printf("%-13s %-10c%-11s", name, gender, country);

        //print game type
        //print gender
        switch (gender)
        {
            case 'M':
                printf("%-9s ", "Men's");
                break;
            case 'F':
                printf("%-9s ", "Female's");
                break;
            default:
                printf("%-9s ", "Invalid's");
        }
        //print type
        switch (type)
        {
            case 'S':
                printf("%-9s", "Singles");
                break;
            case 'D':
                printf("%-9s", "Doubles");
                break;
            case 'X':
                printf("%-9s", "Mixed");
                break;
            default:
                printf("%-9s", "Invalid");
        }
        //print ranking
        printf("%4d\n", rank);
    }
    fclose(fp);

}

void footer()
{
    printf("--------------------------------------------------------\n");
}