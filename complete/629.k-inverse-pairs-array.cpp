/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                if (j >= i)
                    dp[i][j] = (mod + dp[i][j] - dp[i - 1][j - i]) % mod;
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

// Note: DP

// Official Solution