/*
 * @lc app=leetcode id=279 lang=c
 *
 * [279] Perfect Squares
 */

// @lc code=start
int numSquares(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = i;
        for (int j = 1; i >= j * j; j++)
            dp[i] = fmin(dp[i], dp[i - j * j] + 1);
    }

    return dp[n];
}
// @lc code=end

// Note: DP