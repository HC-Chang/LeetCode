/*
 * @lc app=leetcode id=3068 lang=cpp
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long f0 = 0;
        long long f1 = LLONG_MIN;
        long long t;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            t = max(f1 + nums[i], f0 + (nums[i] ^ k));
            f0 = max(f0 + nums[i], f1 + (nums[i] ^ k));
            f1 = t;
        }
        return f0;
    }
};
// @lc code=end

// Note: greedy + bit manipulation