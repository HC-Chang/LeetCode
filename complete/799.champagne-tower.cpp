/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> dp(query_row + 2);
        dp[0] = poured;
        for (int i = 1; i <= query_row; ++i)
        {
            for (int j = i; j >= 0; --j)
                dp[j + 1] += dp[j] = max(0.0, (dp[j] - 1) / 2.0);
        }
        return min(1.0, dp[query_glass]);
    }
};
// @lc code=end

// Note: DP