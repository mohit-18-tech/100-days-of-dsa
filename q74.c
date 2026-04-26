//Problem StatementGiven an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

#include <stdio.h>
#include <string.h>

#define MAX_VOTES 1000
#define MAX_NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX_VOTES][MAX_NAME_LEN];
    char candidates[MAX_VOTES][MAX_NAME_LEN];
    int count[MAX_VOTES] = {0};
    int unique = 0;

    // Read all votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);

        int found = -1;

        // Check if candidate already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], candidates[j]) == 0) {
                found = j;
                break;
            }
        }

        // If found, increment count; otherwise, add new candidate
        if (found != -1) {
            count[found]++;
        } else {
            strcpy(candidates[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Determine the winner
    int maxVotes = 0;
    char winner[MAX_NAME_LEN];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, candidates[i]);
        } 
        // Tie-breaking using lexicographical order
        else if (count[i] == maxVotes && strcmp(candidates[i], winner) < 0) {
            strcpy(winner, candidates[i]);
        }
    }

    // Output the result
    printf("%s %d\n", winner, maxVotes);

    return 0;
}