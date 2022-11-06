/*
 * @lc app=leetcode id=1480 lang=c
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *runningSum(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *dp = calloc(numsSize, sizeof(int));

    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = dp[i - 1] + nums[i];
    }

    return dp;
}
// @lc code=end
