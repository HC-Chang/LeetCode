/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len_1 = word1.size();
        int len_2 = word2.size();

        vector<int> dp(len_2 + 1);

        for (int j = 1; j <= len_2; ++j)
            dp[j] = j;

        int topleft;
        int top;
        for (int i = 1; i <= len_1; ++i)
        {
            topleft = dp[0];
            dp[0] = i;

            for (int j = 1; j <= len_2; ++j)
            {
                top = dp[j];

                if (word1[i - 1] == word2[j - 1])
                    dp[j] = topleft;
                else
                    dp[j] = min(min(dp[j - 1], top), topleft) + 1;

                topleft = top;
            }
        }

        return dp[len_2];
    }
};
// @lc code=end

// Note: Longest Common Subsequence