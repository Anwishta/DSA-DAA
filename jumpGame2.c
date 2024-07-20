bool canJump(int* nums, int numsSize) {
    int maxReach = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            return false; // If we can't reach this point, return false
        }
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;
        if (maxReach >= numsSize - 1) {
            return true; // If we can reach the end, return true
        }
    }
    return false;
}