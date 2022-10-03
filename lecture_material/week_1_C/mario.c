#include <cs50.h>
#include <stdio.h>


// prints n x n box of hash tags based on user inputted dimensions
int main(void)
{
    int n;
    do
    {
        n = get_int("size: ");
    }
    while (n < 1); // prevents invalid inputs by the user

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }

        // move to next row
        printf("\n");
    }
}
