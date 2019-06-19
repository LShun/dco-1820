/*
Name: p4q6.c
Desc: Quiz program. 
*/

//directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defined data
#define Q_FILE "Questions.txt"
#define A_FILE "Answers.txt"

//data structures
typedef struct {
    char question[30];
    char answer[30];
} Quiz;

//declarations
int getQuestion(Quiz *quiz, FILE* qFile, FILE* aFile);
int getAnswer(char *userAnswer, Quiz *quiz);
int compareAnswer(Quiz *quiz, char *userAnswer);

int main(void)
{
    //variables
    Quiz quiz;
    FILE *qFile, *aFile;
    char userAnswer[30];
    int correct, questions;
    double score;
    
    qFile = fopen(Q_FILE, "r");
    aFile = fopen(A_FILE, "r");

    while(getQuestion(&quiz, qFile, aFile) != 0)
    {
        getAnswer(userAnswer, &quiz);
        if((compareAnswer(&quiz, userAnswer)) == 1)
        {
            printf("Correct!\n");
            questions++;
            correct++;
        }

        else
        {
            printf("Wrong, answer should be %s\n", quiz.answer);
            questions++;
        }

    }

    //calculate score
    score = (double) correct / questions * 100;

    //display results
    printf("\n" "Number of correct answers\t= %d\n"
           "Total number of questions\t= %d"
           "\n"
           "\tYour score\t>>>>>>>\t%.2f%%", correct, questions, score);
}

//definitions
//get a question from the question file
int getQuestion(Quiz *quiz, FILE* qFile, FILE *aFile)
{
    //get first question, write to question
    if(fscanf(qFile, "%[^\n]\n", &quiz->question) == EOF)
        return 0;
    //get answer
    if(fscanf(aFile, "%[^\n]\n", &quiz->answer) == EOF)
        return 0;
    //return
    return 1;
}

//get an answer from the user
int getAnswer(char *userAnswer, Quiz *quiz)
{
    //ask for input
    printf("%s ", quiz->question);
    //get string
    scanf("%29[^\n]", userAnswer);
    rewind(stdin);
    //return success
    return 0;
}

//check the answer
int compareAnswer(Quiz *quiz, char *userAnswer)
{
    //compare if userAnswer is same as quiz answer
    if (strcmp(quiz->answer, userAnswer) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}