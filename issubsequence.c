#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    // Pointers to iterate through s and t
    int i = 0, j = 0;
    
    // Traverse both strings
    while (s[i] != '\0' && t[j] != '\0') {
        // If characters match, move pointer on s
        if (s[i] == t[j]) {
            i++;
        }
        // Always move pointer on t
        j++;
    }
    
    // If we've matched all characters in s, it's a subsequence
    return s[i] == '\0';
}
