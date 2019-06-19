#include <stdio.h>
#include <stdlib.h>

#define WORD_LEN 30
#define IN_FILE "nouns.dat"
#define OUT_FILE "nouns.txt"

typedef struct {
    char singular[WORD_LEN];
    char plural[WORD_LEN];
} Noun;

int main(void)
{
    FILE *fIn, *fOut;
    Noun buffer;

    //open the file
    fIn = fopen("nouns.dat", "rb");
    fOut = fopen("nouns.txt", "w");
    if (fIn == NULL)
    {
        printf("Input file cannot be opened\n");
        exit(-1);
    }
    if (fOut == NULL)
    {
        printf("Output file cannot be opened\n");
        exit(-1);
    }
    fprintf(fOut, "%-20s %-20s\n"
            "%-20s %-20s\n", "Singular", "Plural", "======", "====");
    printf("%-20s %-20s\n"
            "%-20s %-20s\n", "Singular", "Plural", "======", "====");
    //read data from file into buffer
    while(fread(&buffer, sizeof(Noun), 1, fIn) != 0)
    {
        fprintf(fOut, "%-20s %-20s\n", buffer.singular, buffer.plural);
        printf("%-20s %-20s\n", buffer.singular, buffer.plural);
    }
    fclose(fIn);
    fclose(fOut);
}
