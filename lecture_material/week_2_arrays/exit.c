#include <stdio.h>
#include <cs50.h>

// exit status
// main function ability to signal if program was successful

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line arguments\n");
        return 1; // means something is wrong
    }
    printf("hello, %s\n", argv[1]);
    return 0; // means program worked correctly, this is done by default
} // essentially error codes