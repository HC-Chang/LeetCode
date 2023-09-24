/*
 * @lc app=leetcode id=799 lang=c
 *
 * [799] Champagne Tower
 */

// @lc code=start
double champagneTower(int poured, int query_row, int query_glass)
{
    double dp[101] = {0};
    dp[0] = poured;
    for (int i = 1; i <= query_row; ++i)
    {
        for (int j = i; j >= 0; --j)
            dp[j + 1] += dp[j] = fmax(0.0, (dp[j] - 1) / 2.0);
    }

    return fmin(1.0, dp[query_glass]);
}
// @lc code=end

// Note: DP