/*
 * @lc app=leetcode id=2016 lang=c
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
int maximumDifference(int *nums, int numsSize)
{
    int max_arr[numsSize];
    int min_arr[numsSize];
    max_arr[numsSize - 1] = nums[numsSize - 1];
    min_arr[0] = nums[0];
    for (int i = numsSize - 2; i >= 0; i--)
        max_arr[i] = fmax(max_arr[i + 1], nums[i]);
    for (int i = 1; i < numsSize; i++)
        min_arr[i] = fmin(min_arr[i - 1], nums[i]);
    int max_val = 0;
    for (int i = 0; i < numsSize; i++)
        max_val = fmax(max_arr[i] - min_arr[i], max_val);
    if (max_val == 0)
        return -1;
    return max_val;
}
// @lc code=end
