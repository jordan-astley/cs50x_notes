#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>


int main(void)
{
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    string s2 = "zyxwvussrqponmlkjihgfedcba";
    int count = 0;

    for (int i = 0, n = strlen(s1); i < n; i++)
    {
        count = 0;
        char character = s1[i];
        for (int j = 0; j < n; j++)
        {
            if (s2[j] == character)
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("%c  %i\n", character, count);
            printf("invalid key\n");
            return 1;
        }
    }
    printf("valid key\n");
    return 0;
}