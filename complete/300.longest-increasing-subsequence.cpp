/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int dp_max = 1;
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > dp_max)
                dp_max = dp[i];
        }

        return dp_max;
    }
};
// @lc code=end

// Note: DP / greedy + B-Search