/*
 * @lc app=leetcode id=1155 lang=c
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
int numRollsToTarget(int n, int k, int target)
{
    int dp[target + 1];
    int tmp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        memset(tmp, 0, sizeof(tmp));
        for (int j = 1; j <= k; ++j)
        {
            for (int k = j; k <= target; ++k)
                tmp[k] = (tmp[k] + dp[k - j]) % 1000000007;
        }
        memcpy(dp, tmp, sizeof(dp));
    }
    return dp[target];
}
// @lc code=end

// Note: DP