#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    if (numsSize == 0) return result;
    
    // Allocate memory for two temporary arrays to hold the products
    int* leftProducts = (int*)malloc(numsSize * sizeof(int));
    int* rightProducts = (int*)malloc(numsSize * sizeof(int));
    
    // Initialize the first element of leftProducts and the last element of rightProducts
    leftProducts[0] = 1;
    rightProducts[numsSize - 1] = 1;
    
    // Fill leftProducts array
    for (int i = 1; i < numsSize; ++i) {
        leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
    }
    
    // Fill rightProducts array
    for (int i = numsSize - 2; i >= 0; --i) {
        rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
    }
    
    // Fill the result array with the product of elements in leftProducts and rightProducts
    for (int i = 0; i < numsSize; ++i) {
        result[i] = leftProducts[i] * rightProducts[i];
    }
    
    // Free temporary arrays
    free(leftProducts);
    free(rightProducts);
    
    return result;
}
