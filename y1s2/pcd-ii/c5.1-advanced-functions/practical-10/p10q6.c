/*
Name: p10q6.c
Desc: Pluralize words and write to a file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 30
#define OUT_FILE "./nouns.dat"

typedef struct {
    char singular[WORD_LEN];
    char plural[WORD_LEN];
} Noun;

void pluralize(Noun *noun);
int addNouns(Noun *noun);

int main(void)
{
    //variables
    Noun noun;

    //request for a singular noun

    while (1)
    {
        printf("Enter a singular noun (Enter -1 to stop): ");
        scanf("%30s", &noun.singular);
        rewind(stdin);
        //if its -1, stop
        if (strcmp(noun.singular, "-1") == 0)
        {
            printf("Done.\n");
            exit(0);
        }
        //pluralize the noun
        pluralize(&noun);
        printf("\n" "Singular: %s\nPlural:%s\n", noun.singular, noun.plural);

        //store into file
        if (addNouns(&noun) == 1)
        {
            printf("\n" "Added both singular and plural noun to %s\n", OUT_FILE);
        }
        else
        {
            printf("\n" "Matching noun in file: %s -- %s\n", noun.singular, noun.plural);
        }
        return 0;
    }
}

void pluralize(Noun *noun)
{
    //variables
    char buffer[WORD_LEN];
    int length;

    //copy the word into buffer
    strcpy(buffer, noun->singular);

    //go through the noun
    //use strlen to check length of noun
    length = strlen(buffer);
    //if last letter is y
    if (buffer[length-1] == 'y')
    {
        //overwrite starting from last word with ies
        strcpy(&buffer[length-1], "ies");
    }
    //if last letter(s) is s, ch, sh or x
    else if (buffer[length-1] == 's' || (buffer[length-2] == 'c' && buffer[length-1] == 'h') || (buffer[length-2] == 's' && buffer[length-1] == 'h') || buffer[length-1] == 'x')
    {
        //add es
        strcat(buffer, "es");

    }
    //others
    //add s
    else
    {
        strcat(buffer, "s");
    }

    //write buffer to struct
    strcpy(noun->plural, buffer);
}

int addNouns(Noun *noun)
{
    //variables
    FILE* fp;
    Noun check;

    //open a binary file for appending
    fp = fopen(OUT_FILE, "ab+");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

    //check if a match is found in the binary file
    
    
    while (!feof(fp))
    {
        if (strcmp(noun->singular, check.singular) == 0) //if found
        {
            return 0;
        }
        fread(&check, sizeof(Noun), 1, fp);
    }

    //else, write structure into binary file
    if(fwrite(noun, sizeof(Noun), 1, fp) == 1)
    {
        fclose(fp);
        return 1;
    }
    //if writing fail, return 0
    else
    {
        fclose(fp);
        return 0;
    }
}
