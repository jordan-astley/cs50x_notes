#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// convert lowercase strings to upper case
// exploits ascii +32 to value to convert from a lower case char to upper

int main (void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i])); // to upper returns original char if upper case or not in alphabet
    }
    printf("\n");
}


// void convert_to_uppercase(s) // manual function showing underlying principle
// // uses knowledge of the ascii table
// {
//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         if (islower(s[i])) // islower returns non-zero (true) when char is lower
//         // one method (s[i] >= 'a' && s[i] <= 'z') // is current letter lowercase
//         {
//             printf("%c", s[i] - 32);
//         }
//         else
//         {
//             printf("%c", s[i]);
//         }
//     }
//     printf("\n");
// }