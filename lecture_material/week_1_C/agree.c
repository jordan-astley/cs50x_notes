#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user to agree
    char c = get_char("Do you agree? y/n  ");

    // check whether user agreed
    if (c == 'y' || c == 'Y')
    {
        printf("agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("disagreed.\n");
    }
    else
    {
        printf("enter a valid response\n");
    }
}