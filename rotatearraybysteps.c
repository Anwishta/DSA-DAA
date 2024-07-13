#include <stdio.h>

// Helper function to reverse a part of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize; // In case k is greater than numsSize
    if (k == 0 || numsSize <= 1) {
        return;
    }

    // Step 1: Reverse the entire array
    reverse(nums, 0, numsSize - 1);
    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);
    // Step 3: Reverse the remaining numsSize - k elements
    reverse(nums, k, numsSize - 1);
}