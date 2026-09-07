#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximum number of candidates
#define MAX 9

// A new data structure that stores the names and vote information of the candidates. (Struct)
typedef struct
{
    string name;
    int votes;
} candidate;

// The global array where we will store the candidates (Array)
candidate candidates[MAX];

// Total number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Command-line check (Has a candidate been entered?)
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Determine the number of candidates and populate the array.
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Collect votes in a loop.
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // If the voted name is invalid, warn the user.
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Announce the winner
    print_winner();
}

// =================================================================
// 1. TASK: vote Function
// =================================================================
bool vote(string name)
{
    // A loop that goes through all the candidates one by one. (Linear Search)
    for (int i = 0; i < candidate_count; i++)
    {
        // If the entered name matches the name of the candidate on the list
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++; // Increase the vote by 1
            return true;           // Mission successful, terminate function.
        }
    }
    // If the loop finishes but no name is found, the vote is invalid.
    return false;
}

// =================================================================
// 2. TASK: print_winner (Announce the Winner) Function
// =================================================================
void print_winner(void)
{
    int max_votes = 0;

    // 1. Step: Finding the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // 2. Stage: Displaying everyone with the maximum number of votes on the screen.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
