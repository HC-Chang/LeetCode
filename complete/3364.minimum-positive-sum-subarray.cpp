/*
 * @lc app=leetcode id=3364 lang=cpp
 *
 * [3364] Minimum Positive Sum Subarray
 */

// @lc code=start
class Solution
{
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {
        vector<int> prefix_sum = nums;
        int n = nums.size();
        for (int i = 1; i < n; i++)
            prefix_sum[i] += prefix_sum[i - 1];
        int min = INT_MAX;
        for (int ll = 0; ll <= n - l; ll++)
        {
            for (int rr = ll + l - 1; rr < n && rr - ll + 1 <= r; rr++)
            {
                int tmp = prefix_sum[rr] - prefix_sum[ll] + nums[ll];
                if (tmp > 0 && tmp < min)
                    min = tmp;
            }
        }

        return min == INT_MAX ? -1 : min;
    }
};
// @lc code=end

// Note: prefix sum