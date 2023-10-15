/*
 * @lc app=leetcode id=1269 lang=c
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
int numWays(int steps, int arrLen)
{
    int column = fmin(arrLen - 1, steps);
    int dp[steps + 1][column + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= steps; i++)
    {
        for (int j = 0; j <= column; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;
            if (j + 1 <= column)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000007;
        }
    }
    return dp[steps][0];
}
// @lc code=end

// Note: DP
// Official Solution
