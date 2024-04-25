/*
 * @lc app=leetcode id=2370 lang=cpp
 *
 * [2370] Longest Ideal Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        int dp[26] = {0};

        int ret = 0;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            tmp = 0;
            for (int ch = max(0, s[i] - 'a' - k); ch <= min(25, s[i] - 'a' + k); ch++)
                tmp = max(tmp, dp[ch] + 1);

            dp[s[i] - 'a'] = tmp;
            ret = max(ret, tmp);
        }

        return ret;
    }
};
// @lc code=end

// Note: DP
