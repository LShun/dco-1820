/*
Name: p3q5.c
Desc: Display occurence of each characters and number of words in a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    //variables
    char ch, dir[50];
    int letter[27] = {0}, words = 0, i;
    FILE* fp;

    //input
    //Prompt for a text file
    printf("Enter file name: ");
    scanf("%[^\n]", &dir);

    //Open text file for reading
    fp = fopen(dir, "r");
    if (fp == NULL)
    {
        printf("%s cannot be opened, please check your path.\n", dir);
        exit(-1);
    }

    //process

    //Read a character ch
    while (fscanf(fp, "%c", &ch) != EOF)
    {
        //Converts it to uppercase
        ch = toupper(ch);

        //If its an alphabet, add 1 to letter[A-1]
        if (isalpha(ch))
        {
            letter[ch - 'A']++;
        }
        else if (ch == ' ')
        {
            letter[26]++;
        }
    }
    //calculate total words
    words = letter[26] + 1;

    //output
    //Print formatting
    printf(" Letter :-\n");

    //Print occurence of each letter
    for (i = 0; i < 26; i++)
    {
        printf("\t%c = %3d\n", 'A' + i, letter[i]);
    }
    
    //Print number of words
    printf(" No. Of Words = %d\n", words);
}