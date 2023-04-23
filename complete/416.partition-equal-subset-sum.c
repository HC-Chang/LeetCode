/*
 * @lc app=leetcode id=416 lang=c
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
bool canPartition(int *nums, int numsSize)
{
    int half_sum = 0;
    for (int i = 0; i < numsSize; i++)
        half_sum += nums[i];

    if (half_sum % 2 != 0)
        return false;

    half_sum /= 2;
    int *dp = calloc(half_sum + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = half_sum; j >= nums[i]; j--)
            dp[j] = dp[j] || dp[j - nums[i]];
    }

    int r = dp[half_sum];
    free(dp);
    return r;
}
// @lc code=end

// Note: DP