#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // This doesn't work for large numbers
    // this is because integer type accounts for negative numbers as well
    int x1 = get_int("x1: ");
    int y1 = get_int("y1: ");
    printf("%i\n", x1 + y1);

    // method for larger numbers
    long int x2 = get_int("x2: ");
    long int y2 = get_int("y2: ");
    long int z2 = x2 + y2;
    printf("%li\n", z2);
    // can the same be achieved with unsigned int???
}

