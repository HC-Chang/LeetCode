/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 */

// @lc code=start
// Solution 2: DP
int uniquePaths(int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, 0, (m + 1) * (n + 1) * sizeof(int));
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    return dp[m][n];
}
// @lc code=end

// Note: DP

// Solution 1:
// int uniquePaths(int m, int n)
// {
//     long ans = 1;
//     for (int i = 1; i <= n - 1; ++i)
//         ans = ans * (m - 1 + i) / i;
//     return ans;
// }