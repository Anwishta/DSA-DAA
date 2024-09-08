#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int index = 0;
    
    int cycleLen = 2 * numRows - 2; // Number of characters in a full cycle

    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < len; i += cycleLen) {
            result[index++] = s[i]; // Adding characters of the current row
            
            // Add the diagonal elements for the rows in between the first and last row
            if (row != 0 && row != numRows - 1 && i + cycleLen - 2 * row < len) {
                result[index++] = s[i + cycleLen - 2 * row];
            }
        }
    }

    result[index] = '\0'; // Null-terminate the result string
    return result;
}
