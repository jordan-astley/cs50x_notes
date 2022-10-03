#include <stdio.h>

// function declaration
void meow(void); // prototype declaration
void meow2(int n);
void meow3(int n);

int main(void)
{
    meow();
    printf("\n   now second function\n\n");
    meow2(3);
    printf("\n   now third function\n\n");
    meow3(3);
}



// void meow  means returns nothing explicity
//(void) explicity states no inputs
void meow(void)
{
    int i;
    for (i = 0; i < 3; i++) // (;;) endless
    {
        printf("meow\n");
    }
}

// further refinements
void meow2(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow...meow\n");
    }
}

// alternative while loop version
void meow3(int n)
{
    int i = 0;
    while (i < n)
    {
        printf("meow...meow...meow\n");
        i++;
    }
}