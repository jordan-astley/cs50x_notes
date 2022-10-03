#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'i';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);
    printf("ascii: %i %i %i\n", c1, c2, c3);
    // typecasting
    printf("ascii: %i %i %i\n", (int) c1, (int) c2, (int) c3); // explicitly converting chars to ints
    // however C does this implicitly

    // printing the individual ascii numbers, along with an extra memory location
    // string is an array of chars, but s is only 4 bytes long
    // printing the extra element will show the NUL character deliminating the array
    string s = "BYE!";
    printf("%i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[4]);
}