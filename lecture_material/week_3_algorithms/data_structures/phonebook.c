#include <cs50.h>
#include <stdio.h>
#include <string.h>

// bad example of uncoupled data of names and phone numbers -- leading into data structures.

int main(void)
{
    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], "David") == 0) // returning 0 means name is the same
        {
            printf("found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}