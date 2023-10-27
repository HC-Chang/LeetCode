/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.size();

        if (size == 0 || size == 1)
            return s;

        vector<vector<int>> dp(size, vector<int>(size, 1));

        int maxLen = 0;
        int start = size - 1;
        int end = start;

        for (int i = 1; i < size; i++)
        {
            for (int j = 0, k = i; k < size; j++, k++)
            {
                if (s[j] == s[k] && dp[j + 1][k - 1])
                {
                    if (maxLen < k - j + 1)
                    {
                        maxLen = k - j + 1;
                        start = j;
                        end = k;
                    }
                    dp[j][k] = dp[j + 1][k - 1];
                }
                else
                    dp[j][k] = 0;
            }
        }

        string r = "";
        for (int i = start; i <= end; i++)
            r += s[i];
        return r;
    }
};
// @lc code=end

// Note: DP