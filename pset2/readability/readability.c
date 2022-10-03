#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Coleman-Liau index -- readability test

// prototypes //////////
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float average_letters_per_100_words(int letters, int words);
float average_sentences_per_100_words(int sentences, int words);
////////////////////////

int main(void)
{
    string text = get_string("Enter text: ");
    float index;
    int gradeNum;

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = average_letters_per_100_words(letters, words);
    float S = average_sentences_per_100_words(sentences, words);

    // printf("L: %f\n", L);
    // printf("S: %f\n", S);

    index = 0.0588 * L - 0.296 * S - 15.8;

    // printf("index: %f\n", index);

    gradeNum = (int) round(index); // rounded to nearest int

    // printf("gradeNum: %i\n", gradeNum);

    if (gradeNum >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (gradeNum < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", gradeNum);
    }

    // printf("letters: %i\n", letters);
    // printf("words: %i\n", words);
    // printf("sentences: %i\n", sentences);

    return 0;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)) // alphabet chars
        {
            for (int j = i; j < n; j++)
            {
                if ((text[j] != 32) && (j != n - 1)) // does not = space
                {
                    continue;
                }
                else
                {
                    count++;
                    i = j;
                    break;
                }
            }
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63) // . ! ?
        {
            count++;
        }
    }

    if (n > 0 && count == 0) // for when a single phrase with no fullstops is entered
    {
        count++;
    }

    return count;
}

float average_letters_per_100_words(int letters, int words)
{
    return ((float) letters / words) * 100; // cast a value to float in division to ensure result is a float
}

float average_sentences_per_100_words(int sentences, int words)
{
    return ((float) sentences / words) * 100;
}