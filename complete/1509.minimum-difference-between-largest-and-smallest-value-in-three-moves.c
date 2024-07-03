/*
 * @lc app=leetcode id=1509 lang=c
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int minDifference(int *nums, int numsSize)
{
    if (numsSize <= 4)
        return 0;
    qsort(nums, numsSize, sizeof(int), sort);
    int min = INT_MAX;
    for (int i = 0; i < 4; i++)
        min = fmin(min, nums[numsSize - 4 + i] - nums[i]);

    return min;
}
// @lc code=end

// Note: greeding + sorting