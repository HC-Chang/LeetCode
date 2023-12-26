/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            vector<int> tmp(target + 1);
            for (int j = 1; j <= k; ++j)
            {
                for (int k = j; k <= target; ++k)
                    tmp[k] = (tmp[k] + dp[k - j]) % 1000000007;
            }
            dp.assign(tmp.begin(), tmp.end());
        }
        return dp[target];
    }
};
// @lc code=end

// Note: DP