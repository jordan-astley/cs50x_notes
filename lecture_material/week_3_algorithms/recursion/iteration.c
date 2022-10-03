#include <cs50.h>
#include <stdio.h>

// example recursion algorithm
// print a mario pyramid

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

// prints
// #
// ##
// ###
// ####

void draw(int n)
{
    for (int i = 0; i < n; i++) // i goes up to number of bricks to print
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}