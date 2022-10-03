# include<stdio.h>
#include <cs50.h>

// Type of data to store multiple of the same type of variables
// stores multiple variables with the same variable, eliminates a huge amount of variable names
// stores one varible with some n number of locations

int main(void)
{
    // example of where an array would be useful
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;

    int n = get_int("How many scores to enter: ");

    int scores[3]; // declares an array of size 3

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i);
    }

    printf("Average = %f\n", (scores[0] + scores[1] + scores[2])/3.0);
}
