/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for (auto n : nums)
        {
            for (int i = sum; i >= n; i--)
                dp[i] |= dp[i - n];
        }
        return dp[sum];
    }
};
// @lc code=end

// Note: DP