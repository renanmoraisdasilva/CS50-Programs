#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

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

    // Keep querying for votes
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

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
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
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k].name) == 0)
        {
            preferences[voter][rank] = k;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int ranking = 0; ranking < candidate_count; ranking++)
        {
            int ops = 0;
            for (int cand = 0; cand < candidate_count; cand++)
            {
                if (preferences[voter][ranking] == cand && candidates[cand].eliminated == 0)
                {
                    candidates[cand].votes += 1;
                    ops = 1;
                
                    break;
                }
                
            }
            
            if (ops == 1)
            {
                break;
            }
        }
    
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Calculating 50%
    int majority = (floor((float)voter_count / 2)) + 1;
    
    // Checking if anyone won
    for (int g = 0; g < candidate_count; g++)
    {
        if (candidates[g].votes >= majority)
        {
            printf("%s\n", candidates[g].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = MAX_VOTERS;
    for (int g = 0; g < candidate_count; g++)
    {
        if (candidates[g].votes <= min && candidates[g].eliminated == 0)
        {
            min = candidates[g].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int tie = 0;
    int eliminated = 0;
    for (int g = 0; g < candidate_count; g++)
    {
        if (candidates[g].votes == min && candidates[g].eliminated == 0)
        {
            tie += 1;
        }
        else if (candidates[g].eliminated == 1)
        {
            eliminated += 1;
        }
    }
    if (tie == candidate_count - eliminated)
    {
        return true;
    }
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int g = 0; g < candidate_count; g++)
    {
        if (candidates[g].votes == min && candidates[g].eliminated == 0)
        {
            candidates[g].eliminated = 1;
        }
    }
    // TODO
    return;
}
