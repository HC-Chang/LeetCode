/*
 * @lc app=leetcode id=494 lang=c
 *
 * [494] Target Sum
 */

// @lc code=start
int findTargetSumWays(int *nums, int numsSize, int target)
{
    int total_sum = 0;
    for (int i = 0; i < numsSize; i++)
        total_sum += nums[i];
    int n = 2 * total_sum + 1;
    int dp[n];
    memset(dp, 0, sizeof(dp));

    dp[nums[0] + total_sum] = 1;
    dp[-nums[0] + total_sum] += 1;

    int next[n];
    for (int i = 1; i < numsSize; i++)
    {
        memset(next, 0, sizeof(next));
        for (int sum = -total_sum; sum <= total_sum; sum++)
        {
            if (dp[sum + total_sum] > 0)
            {
                next[sum + nums[i] + total_sum] += dp[sum + total_sum];
                next[sum - nums[i] + total_sum] += dp[sum + total_sum];
            }
        }
        memcpy(dp, next, sizeof(dp));
    }

    return abs(target) > total_sum ? 0 : dp[target + total_sum];
}
// @lc code=end

// Note: DP

// Official Solution