
#include <stdio.h> // standard input output header

int main(int argc, char **argv)
{
    int count = 0;
    // char *name;
    // name = argv[1];
    int nameLen = sizeof(*argv[1])/sizeof(*argv[1][0]);
    int i;

    for(i = 0; i < nameLen; ++i)
    {
        if(argv[1][i] == 'a' || argv[1][i] == 'e' || argv[1][i] == 'i' ||
        argv[1][i] == 'o' || argv[1][i] == 'u')
        {
            count++;
        }
    }
    printf("total vowels in %s is %d\n", argv[1], counter);
}