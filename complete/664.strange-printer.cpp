/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
class Solution
{
public:
    int strangePrinter(string s)
    {
        int s_len = s.size();
        vector<vector<int>> dp(s_len, vector<int>(s_len));
        for (int i = s_len - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < s_len; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j];
                else
                {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }

        return dp[0][s_len - 1];
    }
};
// @lc code=end

// Note: DP