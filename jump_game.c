int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    int jumps = 0;       // Number of jumps needed to reach the end
    int curEnd = 0;      // The farthest index that can be reached with the current number of jumps
    int maxReach = 0;    // The farthest index that can be reached with one more jump

    for (int i = 0; i < numsSize - 1; i++) {
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;

        // If we've reached the end of the current range
        if (i == curEnd) {
            jumps++;
            curEnd = maxReach;

            // If the current end can reach or exceed the last index, break out of the loop
            if (curEnd >= numsSize - 1) break;
        }
    }
    
    return jumps;
}
