//Problem Statement Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    scanf("%s", s);

    int visited[26] = {0};  // To track occurrences of characters

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        
        if (visited[index] == 1) {
            // Second occurrence found
            printf("%c\n", s[i]);
            return 0;
        }
        
        visited[index] = 1;
    }

    // If no repeated character is found
    printf("-1\n");
    return 0;
}