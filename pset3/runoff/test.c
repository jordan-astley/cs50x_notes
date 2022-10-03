#include <stdio.h>
#include <cs50.h>

int candidate_count = 3;

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

int main (argc, string argv[])
{
     // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }



    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes /// This asks each voter to rank the candidates
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n"); // separates the ranking for each of the voters
    }


}




// Return the minimum number of votes any remaining candidate hasps
int find_min(void)
{
    // create an array of the number of votes for each candidate remaining
    int votes_array[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            votes_array[i] = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%i ", votes_array[i]);
    }

    // sort the votes array (smallest to largest)
    // Bubble sort algorithm

    int swap_count = -1; // starts non-zero

    while(swap_count != 0)
    {
        swap_count = 0;
        // look at adjacent pair
        for (int i = 0; i < (candidate_count - 1); i++)
        {
            if (votes_array[i] > votes_array[i + 1]) // swap condition
            {
                int temp = votes_array[i];
                votes_array[i] = votes_array[i + 1];
                votes_array[i + 1] = temp;
                swap_count++;
                x++;
            }
        }
    }

    // array is sorted, return lowest number of votes from corresponding
    // candidate, index 0
    return votes_array[0];
}