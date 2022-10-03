#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Implementation of a Substitution Cipher //

// prototypes //////////////////////////////
int validate_cmd_arg(string key, int argc);
int validate_key(string key);
int validate_key_alphabet(string key);
void encrypt(string key, string plaintext);
////////////////////////////////////////////

int main(int argc, string argv[])
{
    string key = argv[1];
    string plaintext = NULL;

    int validation = validate_cmd_arg(key, argc);

    if (validation != 0)
    {
        return 1;
    }

    plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    encrypt(key, plaintext);

    return 0; // program exe correctly
}

int validate_cmd_arg(string key, int argc)
{
    if (argc != 2) // exe call and key expected
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) < 26) // key wrong length
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else if (validate_key_alphabet(key) == 0)
    {
        printf("Key contains non-alphabetic characters\n");
        return 1;
    }
    else if (validate_key(key) == 0)
    {
        printf("Invalid key, does not contain all alphabetical chars once\n");
        return 1;
    }

    return 0; // valid
}

int validate_key_alphabet(string key)
{
    // check for non alphabetical chars in key
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i] == 0))
        {
            return 0;
        }
    }
    return 1;
}

int validate_key(string key)
{
    // check key contains all alphabet chars once
    string alphabet = "abcdefghijklnmopqrstuvwxyz";
    int count = 0;

    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (tolower(key[j]) == alphabet[i])
            {
                count++;
            }
        }
        if (count != 1)
        {
            return 0;
        }
    }
    return 1;
}

void encrypt(string key, string plaintext)
{
    // ascii tables to map a-z or A-Z to ints of 1-26
    int UPPEROFFSET = 64;
    int LOWEROFFSET = 96;

    int asciiVal = 0;
    int mapped_index = 0; // 1-26 converted to 0-25 later
    int mapped_asciiVal = 0;

    int upper = 0; // flag for upper case char in string

    int l = strlen(plaintext);
    for (int i = 0; i < l; i++)
    {
        asciiVal = plaintext[i];

        if (isalpha(asciiVal) == 0 || isspace(asciiVal == 1))
        {
            // leave punctuation, numbers, spaces as they are
            printf("%c", asciiVal);
            continue;
        }

        // decide if val is upper or lowercase and map to 0-26 numbers
        upper = isupper(asciiVal);
        mapped_index = (upper == 0) ? asciiVal - LOWEROFFSET : asciiVal - UPPEROFFSET;

        // preserve cases in the plaintext
        // depends on key format, can deal with upper/lower/mixed
        if (upper != 0)
        {
            // upper case so convert the mapped val to upper if its not already
            mapped_asciiVal = toupper(key[mapped_index - 1]);
        }
        else
        {
            // must be lowercase, convert mapped val to lower if its not already
            mapped_asciiVal = tolower(key[mapped_index - 1]);
        }
        printf("%c", mapped_asciiVal);
    }
    printf("\n");
}

