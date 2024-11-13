#include <stdio.h>
#include <string.h>

// Function to check if str2 is a subsequence of str1
int isSubsequence(const char *str1, const char *str2) {
    int i = 0, j = 0;
    int len1 = strlen(str1), len2 = strlen(str2);

    // Traverse through both strings
    while (i < len1 && j < len2) {
        if (str1[i] == str2[j]) {
            j++;  // Move to the next character in str2
        }
        i++;  // Always move to the next character in str1
    }

    // If we've matched all characters of str2, then it's a subsequence
    return (j == len2);
}

int main() {
    char str1[100], str2[100];

    // Input two strings
    printf("Enter the original string: ");
    scanf("%s", str1);
    printf("Enter the subsequence string: ");
    scanf("%s", str2);

    // Check if str2 is a subsequence of str1
    if (isSubsequence(str1, str2)) {
        printf("\"%s\" is a subsequence of \"%s\".\n", str2, str1);
    } else {
        printf("\"%s\" is NOT a subsequence of \"%s\".\n", str2, str1);
    }

    return 0;
}