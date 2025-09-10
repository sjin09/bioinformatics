#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        } 
        // printf("%s\t%d\n", candidates[0].name, candidates[0].votes);
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    int state = 0; 
    int index = 0;
    // printf("%s\n", name);
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("%s\n", candidates[i].name);
        if (strcmp(name, candidates[i].name) == 0)
        {
            state = 1;
            index = i;
            break;
        }
    }
    // printf("%d\n", state);
    if (state == 0)
    {
        return false;
    }
    else if (state == 1)
    {
        candidates[index].votes++;
        return true;
    }
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // maximum number of votes
    int max = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    // find winners
    int count = 0;
    char winners[candidate_count][100];
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("%s\t%d\t%d\n", candidates[i].name, candidates[i].votes, max);
        if (candidates[i].votes == max)
        {
            strcpy(winners[count], candidates[i].name);
            count++;
        }
    }
    // return
    // printf("%d\n", max);
    // printf("%d\n", count);
    // printf("%s\n", winners[0]);
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", winners[i]);
    }

    return;
}

