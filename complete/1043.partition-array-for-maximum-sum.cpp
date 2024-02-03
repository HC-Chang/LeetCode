/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1);
        int mmax;
        int sum;
        int cur;
        for (int i = 0; i < n; i++)
        {
            mmax = 0;
            sum = 0;
            for (int j = i; j >= max(0, i - k + 1); j--)
            {
                mmax = max(mmax, arr[j]);
                cur = mmax * (i - j + 1) + dp[j];
                sum = max(sum, cur);
            }
            dp[i + 1] = sum;
        }

        return dp[n];
    }
};
// @lc code=end

// Note: DP