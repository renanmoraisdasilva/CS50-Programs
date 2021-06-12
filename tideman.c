#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
bool loopcheck(int winner, int loser);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp (name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            //printf ("Ranks[%i]:%i\n", rank, ranks[rank]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i < j)
            {
                preferences[ranks[i]][ranks[j]] += 1;
                //printf("preferences[%i][%i] = %i\n", ranks[i], ranks[j], preferences[ranks[i]][ranks[j]]);
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    pair_count = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if (i < j)
            {
                if (preferences[i][j] - preferences[j][i] > 0)
                {
                    
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    //printf("pair[%i].winner = %i\n", pair_count, i);
                    //printf("pair[%i].loser = %i\n", pair_count, j);
                    pair_count += 1;
                }
                else if (preferences[i][j] - preferences[j][i] < 0)
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    //printf("pair[%i].winner = %i\n", pair_count, j);
                    //printf("pair[%i].loser = %i\n", pair_count, i);
                    pair_count += 1;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int sorted = -1;
    while (sorted != 0)
    {
        sorted = 0;
        for (int i = 0; i < pair_count; i++)
        {
            if (preferences[pairs[i+1].winner][pairs[i+1].loser] > preferences[pairs[i].winner][pairs[i].loser])
            {
                int temp1;
                int temp2;
                temp1 = pairs[i+1].winner;
                temp2 = pairs[i+1].loser;
                pairs[i+1].winner = pairs[i].winner;
                pairs[i+1].loser = pairs[i].loser;
                pairs[i].winner = temp1;
                pairs[i].loser = temp2;
                //printf("pair[%i].winner = %i\n", i, pairs[i].winner);
                //printf("pair[%i].loser = %i\n", i, pairs[i].loser);
                //printf("pair[%i].winner = %i\n", i+1, pairs[i+1].winner);
                //printf("pair[%i].loser = %i\n", i+1, pairs[i+1].loser);
                sorted = 1;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(int i = 0; i < pair_count; i++)
    {
        if (!loopcheck(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    
    return;
    }
}

bool loopcheck(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool found = false;
        for (int i = 0; i < candidate_count; i++)
        {
            if(locked[i][winner])
            {
                found = true;
                winner = i;
            }
        }
        if(!found)
        {
            winner = -1;
        }
    }
    if (winner == loser)
    {
        return true;
    }
    return false;
}



// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int col = 0; col < MAX; col++)
    {
        bool found_source = true;
        for (int row = 0; row < candidate_count; row++)
        {
            if (locked[row][col] == true)
            {
                found_source = false;
                break;
            }
        }
        if (found_source)
        {
            printf("%s\n", candidates[col]);
            return;
        }
    }
    return;
}

