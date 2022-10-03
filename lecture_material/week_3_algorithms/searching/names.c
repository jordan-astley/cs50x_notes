#include <cs50.h>
#include <stdio.h>
#include <string.h>

// searching algorithms -- array of strings

// demonstrates to compare strings you cannot use == since they are not a primitive type

int main(void)
{
    string names[] = {"Robb", "Ned", "Jon", "Daenaries", "Joeffry", "Dunk", "Egg", "Robert"};

    for (int i = 0; i < 7; i++)
    {
        // if (names[i] == "Egg") -- erroneous line cannot compare arrays with ==
        // !strcmp(names[i] == "Egg") -- reverses
        if (strcmp(names[i], "Egg") == 0) // from string.h
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
