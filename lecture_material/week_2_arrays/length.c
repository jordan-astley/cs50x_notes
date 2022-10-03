# include <stdio.h>
# include <cs50.h>
# include <string.h>

// figures out the length of the string
int string_length(string name);

int main (void)
{
    string name = get_string("Name: ");

    int length = string_length(name);

    printf("Using my function len = %i\n", length);

    // redundunt given the str_len function in string.h
    int length2 = strlen(name);

    printf("Using the string.h library len = %i\n", length2);

}

int string_length(string s) // abstracted
{
    int i = 0;
    while (s[i] != '\0') // \0 is numerical equilvalent of NUl
    {
        i++;
    }
    return i;
}