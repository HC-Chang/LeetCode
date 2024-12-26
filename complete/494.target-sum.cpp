/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * total_sum + 1, 0);

        dp[nums[0] + total_sum] = 1;
        dp[-nums[0] + total_sum] += 1;

        for (int index = 1; index < nums.size(); index++)
        {
            vector<int> next(2 * total_sum + 1, 0);
            for (int sum = -total_sum; sum <= total_sum; sum++)
            {
                if (dp[sum + total_sum] > 0)
                {
                    next[sum + nums[index] + total_sum] += dp[sum + total_sum];
                    next[sum - nums[index] + total_sum] += dp[sum + total_sum];
                }
            }
            dp = next;
        }

        return abs(target) > total_sum ? 0 : dp[target + total_sum];
    }
};
// @lc code=end

// Note: DP

// Official Solution