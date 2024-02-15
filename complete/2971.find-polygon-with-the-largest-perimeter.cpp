/*
 * @lc app=leetcode id=2971 lang=cpp
 *
 * [2971] Find Polygon With the Largest Perimeter
 */

// @lc code=start
class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long preifx_sum = 0;
        for (int i = 0; i < n; i++)
            preifx_sum += nums[i];

        for (int i = n - 1; i >= 2; i--)
        {
            preifx_sum -= nums[i];
            if (preifx_sum > nums[i])
                return preifx_sum + nums[i];
        }

        return -1;
    }
};
// @lc code=end

// Note: sorting + prefix sum + greedy