#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");

    // int length = strlen(s); // but even more efficient below
    for (int i = 0, n = strlen(s); i < n; i++) // can declare multiple variables at the same time in the for loop
    {
        printf("%c", s[i]);
    }
    printf("\n");
}