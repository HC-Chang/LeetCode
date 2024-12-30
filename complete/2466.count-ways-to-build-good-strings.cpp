/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int mod = 1e9 + 7;
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 1; i < high + 1; i++)
        {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % mod;
        }
        int r = dp[low];
        for (int i = low + 1; i < high + 1; i++)
            r = (r + dp[i]) % mod;
        return r;
    }
};
// @lc code=end

// Note: DP