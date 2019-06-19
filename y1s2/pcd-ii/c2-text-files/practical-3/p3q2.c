/*
Name: p3q2.c
Desc: Count total characters, alphabets, and words in a file
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IN_FILE "./text.txt"

typedef struct {
    int chars, letters, vowels, consonants, blanks, words;
} CharList;

int checkLetter(CharList* charList, char* character);

int main(void)
{
    //variables
    CharList charList = {0};
    char fchar; 
    int newWord = 1;

    //open a file
    FILE *fp = fopen(IN_FILE, "r");
    if (fp == NULL)
    {
        printf("Unable to open the input file, please check IN_FILE.\n");
        exit(-1);
    }

    //process

    //while read character != EOF
    while (fscanf(fp, "%c", &fchar) != EOF)
    {
        //if its a new word
        if (newWord == 1)
        {
            charList.words++;
            //flag as part of word
            newWord = 0;
        }
        //add 1 to total characters
        charList.chars++;

        //check if its a space/blank
        if (fchar == ' ')
        {
            charList.blanks++;
            //flag as beginning of another word
            newWord = 1;
        }
        //check if its a alphabet
        else if (isalpha(fchar))
        {
            checkLetter(&charList, &fchar);
        }
        //otherwise skip
    }
    //display results
    printf("%30s: %03d\n"
           "%30s: %03d\n"
           "%30s: %03d\n"
           "%30s: %03d\n"
           "%30s: %03d\n"
           "%30s: %03d\n",
           "Total number of characters", charList.chars,
           "Number of letters", charList.letters,
           "Number of vowels", charList.vowels,
           "Number of consonants", charList.consonants,
           "Number of blanks (spaces)", charList.blanks,
           "Approx no. of words", charList.words);

           fclose(fp);
}

int checkLetter(CharList* charList, char* character)//check if its a letter -- function
{
    switch(toupper(*character))
    {
        //check if its a vowel
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            charList->vowels++;
            break;
        //otherwise its a consonant
        default:
            charList->consonants++; 
    }
    //+1 to total letter
    charList->letters++;
}