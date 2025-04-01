/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n);

        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i)
            dp[i] = max(dp[i + 1], ((i + questions[i][1] + 1 < n)
                                        ? dp[i + questions[i][1] + 1]
                                        : 0) +
                                       questions[i][0]);

        return dp[0];
    }
};

// @lc code=end

// Note: DP