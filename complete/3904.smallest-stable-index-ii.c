/*
 * @lc app=leetcode id=3904 lang=c
 *
 * [3904] Smallest Stable Index II
 */

// @lc code=start
int firstStableIndex(int *nums, int numsSize, int k)
{
    int min_arr[numsSize];
    min_arr[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--)
        min_arr[i] = fmin(min_arr[i + 1], nums[i]);

    int max_val = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > max_val)
            max_val = nums[i];
        if (max_val - min_arr[i] <= k)
            return i;
    }

    return -1;
}
// @lc code=end

// Note: prefix sum