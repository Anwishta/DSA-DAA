#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper function to reverse a portion of a string
void reverse(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

// Helper function to trim leading and trailing spaces, and reduce multiple spaces
char* cleanSpaces(char* s) {
    int i = 0, j = 0;
    int len = strlen(s);

    while (isspace(s[i])) i++; // Skip leading spaces

    while (i < len) {
        if (!isspace(s[i])) {
            s[j++] = s[i++];
        } else if (isspace(s[i]) && j > 0 && !isspace(s[j-1])) {
            s[j++] = ' ';
            i++;
        } else {
            i++;
        }
    }

    // Remove any trailing space
    if (j > 0 && isspace(s[j-1])) j--;

    s[j] = '\0'; // Null-terminate the string
    return s;
}

char* reverseWords(char* s) {
    // Clean up spaces
    s = cleanSpaces(s);

    // Reverse the entire string
    int len = strlen(s);
    reverse(s, s + len - 1);

    // Reverse each word
    char* start = s;
    char* end = s;
    while (*start) {
        while (*start && isspace(*start)) start++; // Skip spaces
        end = start;
        while (*end && !isspace(*end)) end++; // Find the end of the word
        reverse(start, end - 1); // Reverse the word
        start = end;
    }

    return s;
}

int main() {
    char s[] = "   hello   world   this  is C  ";
    printf("Original: \"%s\"\n", s);
    printf("Reversed: \"%s\"\n", reverseWords(s));
    return 0;
}
