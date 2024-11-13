#include <stdio.h>
#include <ctype.h>  // For isalnum() and tolower()

// Function to check if the string is a palindrome
int isPalindrome(char *s) {
    int left = 0, right = 0;

    // First pass: find the length of the string after removing non-alphanumeric characters
    while (s[right] != '\0') {
        if (isalnum(s[right])) {
            right++;
        } else {
            right++;
        }
    }

    right--;  // Adjust for the null terminator
    
    // Two pointer approach to check palindrome
    while (left < right) {
        // Skip non-alphanumeric characters on both ends
        if (!isalnum(s[left])) {
            left++;
        } else if (!isalnum(s[right])) {
            right--;
        } else {
            // Check if the characters at both ends match
            if (tolower(s[left]) != tolower(s[right])) {
                return 0; // Not a palindrome
            }
            left++;
            right--;
        }
    }

    return 1;  // Palindrome
}

int main() {
    char str[100];

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Call the isPalindrome function and print the result
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}