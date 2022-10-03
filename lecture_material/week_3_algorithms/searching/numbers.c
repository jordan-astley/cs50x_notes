#include <cs50.h>
#include <stdio.h>

// searching algorithms

int main(void)
{
    // int numbers[7];
    // numbers[0] = 4;
    // numbers[1] = 6;

    // implicit array declaration
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    // linear search
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}