/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = INT_MIN;
        int val = nums[0];
        int idx = 0;
        vector<int> dp(n);
        vector<int> path(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        path[i] = j;
                    }
                }
            }
            if (dp[i] > cnt)
            {
                cnt = dp[i];
                val = nums[i];
                idx = i;
            }
        }

        vector<int> r;
        r.insert(r.begin(), val);
        for (int i = cnt - 2; i >= 0; i--)
        {
            r.insert(r.begin(), nums[path[idx]]);
            idx = path[idx];
        }

        return r;
    }
};
// @lc code=end

// Note: DP + sorting