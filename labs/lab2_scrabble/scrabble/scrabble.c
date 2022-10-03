#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//              a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,  q, r, s, t, u, v, w, x, y,  z
//              1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24,25, 26

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        printf("Player 2 wins!");
    }
    printf("\n");
    // printf("score 1 %i, score 2 %i\n", score1, score2);

    return 0;
}

int compute_score(string word)
{
    int sum = 0;
    int letter;
    int to_add = 0;
    char character;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 97 && word[i] <= 122) // lowercase
        {
            letter = (int) word[i] - 96; // convert to value for score look up
            sum += POINTS[(int) letter - 1];
        }
        else if (word[i] >= 65 && word[i] <= 90) // uppercase
        {
            letter = (int) word[i] - 64;
            sum += POINTS[(int) letter - 1];
        }
        else // not in alphabet
        {
            continue;
        }
    }

    return sum;
}