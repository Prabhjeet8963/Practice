//Given a string and an integer k , find the length of the longest substring that contains at most k distinct characters
//input: s = "aabacbebebe", k = 3
//output: 7("cbebebe")


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Function to check palindrome
bool isPalindrome(char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Recursive function for backtracking
void solve(char *s, int start, char partition[][MAX], int index) {
    int n = strlen(s);

    if (start == n) {
        // Print the partition
        for (int i = 0; i < index; i++) {
            printf("%s ", partition[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++) {
        if (isPalindrome(s, start, i)) {
            // Copy substring s[start..i] into partition array
            int k = 0;
            for (int j = start; j <= i; j++)
                partition[index][k++] = s[j];
            partition[index][k] = '\0';

            // Recurse
            solve(s, i + 1, partition, index + 1);
        }
    }
}

int main() {
    char s[MAX];

    printf("Enter string: ");
    scanf("%s", s);

    char partition[MAX][MAX];

    printf("\nAll Palindrome Partitions:\n");
    solve(s, 0, partition, 0);

    return 0;
}