/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n][n];
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }

        return dp[0][n - 1] >= 0;
    }
};
// @lc code=end

// Note: dp