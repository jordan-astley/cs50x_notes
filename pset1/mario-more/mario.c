#include <cs50.h>
#include <stdio.h>

// function declarations
void printSpaces(int n);

int main(void)
{
    int height;
    int width;
    const int GAP = 2;

    // obtain valid user input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // 1 to 8 inclusive

    // set intial width value
    width = 1;
    for (int i = 0; i < height; i++) // for each row
    {
        printSpaces(height - width); // print spaces before the first hash

        for (int j = 0; j < width; j++) // print correct number of hashes
        {
            printf("#");
        }

        printSpaces(GAP); // print fixed width gap between pyramids

        for (int j = 0; j < width; j++)
        {
            printf("#");
        }

        width++; // incremement width for each row to create triangle
        printf("\n"); // moves to new line
    }
}

void printSpaces(int n) // function to print any number of spaces n
{
    for (int j = 0; j < n; j++)
    {
        printf(" ");
    }
}