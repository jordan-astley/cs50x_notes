#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // This doesn't work for large numbers
    // this is because integer type accounts for negative numbers as well
    float x1 = get_float("x: ");
    float y1 = get_float("y: ");

    float z1 = x1 / y1;

    printf("%.2f\n", z1);
    // demonstrate floating point imprecision
    printf("%.50f\n", z1);
    // since floats are finite in size 32 bit, 4 bytes


    // trying the same with integers
    int x2 = get_int("x: ");
    int y2 = get_int("y: ");

    float z2 = x2 / y2;

    printf("%.2f\n", z2); // will result in wrong answer, 0.00
    // C discards anything after decimal point due to int types
    // trying conversion below

    // trying the same with integers - type conversion
    int x3 = get_int("x: ");
    int y3 = get_int("y: ");

    float z3 = (float) x2 / (float) y2; // cast to float (although changing only one is necessary)

    printf("%.50f\n", z3); // closer to right answer, stil has floating point imprecision, but this a bigger issue 

}

