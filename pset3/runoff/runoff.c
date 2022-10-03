#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];
// int preferences[9][3] = {{0,1,2},{0,1,2},{1,2,0},{1,2,0},{1,2,0},{2,0,1},{2,0,1},{2,1,0},{2,1,0}};

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// void print_candidates(void);
// void print_voters_pref(void);

int main(int argc, string argv[])
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


    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner(); // print the winner and return true if there is a winner
        if (won)
        {
            break; // winner found, exit if won == true
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // printf("min = %i\n", min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated) // print the remaining tied-win candidates
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // check for candidate name in candidates array
    // linear search algorithm
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i; // update the preferences array to include this vote
            return true;                  // i corresponds to candidate number
        }
    }
    return false; // if getting to this line, candidate is invalid
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // iterate thru voters in preferences array
    for (int i = 0; i < voter_count; i++)
    {
        // update candidates.votes whilst checking if candidate is eliminated
        // check for the next non-eliminated preference by incrementing preferences
        for (int pref = 0; pref < candidate_count; pref++)
        {
            int candidate2vote4 = preferences[i][pref];
            if (candidates[candidate2vote4].eliminated)
            {
                continue; // go to next preference (max is number of candidates)
            }
            else
            {
                candidates[candidate2vote4].votes++;
                break; // move to next voters preferences
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority;
    // set majority, more than 50% of vote
    if (voter_count % 2 == 0) // even
    {
        majority = (voter_count / 2) + 1;
    }
    else
    {
        majority = (voter_count + 1) / 2;
    }

    // iterate over candidates array
    // if any candidate has a majority return true
    // linear search algorithm
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].votes >= majority) && (candidates[i].eliminated == false))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // count remaining candidates
    int x = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            x++;
        }
    }

    // create an array of the number of votes for each candidate remaining
    int votes_array[x];
    for (int i = 0; i < x; i++)
    {
        if (candidates[i].eliminated == false)
        {
            votes_array[i] = candidates[i].votes;
        }
    }

    // sort the votes array (smallest to largest)
    // Bubble sort algorithm
    int swap_count = -1; // starts non-zero

    while(swap_count != 0)
    {
        swap_count = 0;
        // look at adjacent pair
        for (int i = 0; i < (x - 1); i++)
        {
            if (votes_array[i] > votes_array[i + 1]) // swap condition
            {
                int temp = votes_array[i];
                votes_array[i] = votes_array[i + 1];
                votes_array[i + 1] = temp;
                swap_count++;
            }
        }
    }
    // sorted array, return lowest number of votes found @ index 0
    return votes_array[0];
}

// Return true if the election is tied between all remaining candidates, false otherwise
bool is_tie(int min)
{
    // iterate through the candidates
    // count the number of remaining candidates
    // count number of candidates with votes = min
    int remaining = 0;
    int has_min_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            remaining++;
        }
        if (candidates[i].votes == min)
        {
            has_min_votes++;
        }
    }

    // return true if number of candidates with min votes == number of remaining candidates
    bool x = (remaining == has_min_votes) ? true : false;
    return x;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // another linear search
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}



//     /////////debugging/////////


// void print_candidates(void)
// {
//     for (int i = 0; i < candidate_count; i++)
//     {
//         printf("%s: %i -- eliminated: ", candidates[i].name, candidates[i].votes);
//         if (candidates[i].eliminated)
//         {
//             printf("true\n");
//         }
//         else
//         {
//             printf("false\n");
//         }
//     }
// }

// void print_voters_pref(void)
// {
//     for (int i = 0; i < voter_count; i++)
//     {
//         printf("voter %i   ", i);
//         for (int j = 0; j < candidate_count; j++)
//         {
//             printf("%i. %s ", j, candidates[preferences[i][j]].name);
//         }
//         printf("\n");
//     }
// }