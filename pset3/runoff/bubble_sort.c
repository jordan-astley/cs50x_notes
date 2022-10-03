#include <stdio.h>
#include <cs50.h>

// including optimisation where we ignore the sorted elements
// e.g after first pass {2,... , n} n can be ignored. and this grows.


int main(void)
{
    int a[] = {2,8,7,9,0,6,4,1,5,3};
    int len_a = sizeof(a) / sizeof(a[0]);

    // bubble sort algorithm

    int swap_count = -1; // starts as non-zero
    int x = 0; // optimisation
    while (swap_count != 0) // when no more swaps, breaks loop
    {
        swap_count = 0;

        // look at adjacent pair
        for (int i = 0; i < (len_a - 1 - x); i++)
        {
            if (a[i] > a[i + 1]) // swap
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap_count++;
                x++;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

}