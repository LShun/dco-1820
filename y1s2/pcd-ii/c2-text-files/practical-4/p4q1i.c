/*
Name: p4q1i.c
Desc: Write "REP" amount badminton player's information to a file with format Name|Gender|Type|Country|Rank
*/

#include <stdio.h>
#include <stdlib.h>

#define OUT_FILE "badmintonPlayers.txt"
#define REP 2

typedef struct {
    char name[40], gender, type, country[3];
    int rank;
} Player;

int main(void)
{
    //Variables
    Player p;
    int i;
    FILE* fp;
    //Open the output file
    fp = fopen(OUT_FILE, "w");
    if (fp == NULL)
    {
        printf("Can't open file.\n");
        exit(-1);
    }

    for (i = 0; i < REP; i++)
    {
        //Input
        //Ask user for details of player
        printf("Enter player name: ");
        scanf("%[^\n]", &p.name);
        rewind(stdin);
        printf("Enter player gender (M = Male, F = Female): ");
        scanf("%c", &p.gender);
        rewind(stdin);
        printf("Enter player type (S=singles, D=doubles, X=mixed doubles): ");
        scanf("%c", &p.type);
        rewind(stdin);
        printf("Enter player country code (eg.MAS=Malaysia, CHN=China): ");
        scanf("%s", &p.country);
        rewind(stdin);
        printf("Enter player ranking: ");
        scanf("%d", &p.rank);
        rewind(stdin);

        //Output
        //write details into file
        fprintf(fp, "%s|%c|%c|%s|%d\n", p.name, p.gender, p.type, p.country, p.rank);
    }
    printf("Done.\n");
    fclose(fp);
}   
