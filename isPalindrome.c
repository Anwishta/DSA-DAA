#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Helper function to check if a character is alphanumeric
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Helper function to convert a character to lowercase
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isAlphanumeric(s[left])) {
            left++;
        }
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isAlphanumeric(s[right])) {
            right--;
        }
        // Compare characters
        if (toLowerCase(s[left]) != toLowerCase(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Test the function
int main() {
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "race a car";

    if (isPalindrome(s1)) {
        printf("'%s' is a palindrome.\n", s1);
    } else {
        printf("'%s' is not a palindrome.\n", s1);
    }

    if (isPalindrome(s2)) {
        printf("'%s' is a palindrome.\n", s2);
    } else {
        printf("'%s' is not a palindrome.\n", s2);
    }

    return 0;
}
