//Problem Statement Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

// Function to find the first non-repeating character
char firstNonRepeatingChar(const char *s) {
    int freq[26] = {0};  // Frequency array for lowercase letters

    // First pass: Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Second pass: Find the first character with frequency 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // If no non-repeating character is found
    return '$';
}

int main() {
    char s[1000];

    // Input string
    printf("Enter the string: ");
    scanf("%s", s);

    char result = firstNonRepeatingChar(s);

    // Output result
    printf("%c\n", result);

    return 0;
}