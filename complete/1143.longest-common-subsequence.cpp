/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.size();
        int len2 = text2.size();

        vector<int> dp(len2 + 1);

        int prev;
        int tmp;
        for (int i = 1; i <= len1; i++)
        {
            prev = dp[0];
            for (int j = 1; j <= len2; j++)
            {
                tmp = dp[j];

                if (text1[i - 1] == text2[j - 1])
                    dp[j] = prev + 1;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                prev = tmp;
            }
        }

        return dp[len2];
    }
};
// @lc code=end

// Note: Longest Common Subsequence