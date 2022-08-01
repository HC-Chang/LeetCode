/*
 * @lc app=leetcode id=300 lang=c
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

int max(int a, int b)
{
    return a > b ? a : b;
}

int lengthOfLIS(int *nums, int numsSize)
{
    int dp_max = 0;
    int *dp = calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (dp[i] > dp_max)
        {
            dp_max = dp[i];
        }
    }

    return dp_max;
}
// @lc code=end
