/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : dp[0];
        for (int i = 2; i < n + 1; ++i)
        {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if ((s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};
// @lc code=end

// Note: DP