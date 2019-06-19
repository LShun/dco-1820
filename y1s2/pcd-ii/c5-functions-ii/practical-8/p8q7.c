/*
Name: p8q7.c
Desc: Generate random addition quizzes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definitions
#define QUESTIONS 5

//prototypes
void additionQuiz (int level, int *correct, int *score);


int main(void)
{
    //variables
    int level, correct, score;
    
    //ask for level desired
    printf("Enter level desired (Ex: 2): ");
    scanf(" %d", &level);
    
    //start quiz
    correct = 0, score = 0;
    additionQuiz(level, &correct, &score);
    printf("You got %d correct answers out of %d questions.\n"
           "Your score\t:%d %%", correct, QUESTIONS, score);

    return 0;

}
void additionQuiz (int level, int *correct, int *score)
{
    //variables
    int i, n, num1, num2, total, answer;

    //set seed random
    srand(time(NULL));

    //redo 5 times
    for(i = 0; i < QUESTIONS; i++)
    {
        //determine range of random numbers
        n = level * 20;

        //generate two random numbers
        num1 = rand() % n + 1;
        num2 = rand() % n + 1;

        //ask for user input
        printf("Q%d:\t%d + %d = ", i, num1, num2);
        scanf(" %d", &answer);

        //calculate the total ( after user input to prevent cheating )
        total = num1 + num2;

        //if user input matches total, increase correct
        if (answer == total)
        {
            //let user know correct
            printf("\tCorrect !\n");
            //increase correct answer
            (*correct)++;
        }
        else
        {
            printf("\tWrong !\n");
        }
    }
    *score = (double) *correct / QUESTIONS * 100;
}

