#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) {
        return 0;
    }
    
    int* candies = (int*)malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;  // Give each child at least one candy
    }
    
    // First pass: from left to right
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    // Second pass: from right to left
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = (candies[i] > candies[i + 1] + 1) ? candies[i] : (candies[i + 1] + 1);
        }
    }
    
    // Sum up the candies
    int totalCandies = 0;
    for (int i = 0; i < ratingsSize; i++) {
        totalCandies += candies[i];
    }
    
    free(candies);
    return totalCandies;
}

int main() {
    int ratings[] = {1, 0, 2};
    int ratingsSize = sizeof(ratings) / sizeof(ratings[0]);
    
    int result = candy(ratings, ratingsSize);
    printf("Total candies needed: %d\n", result);  // Expected output: 5

    return 0;
}
