/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n);

        for (int i = 1, sum = 0; i < n; ++i)
            arr[i] += (sum += (nums[i] - nums[i - 1]) * i);
        for (int i = n - 2, sum = 0; i >= 0; --i)
            arr[i] += (sum += (nums[i + 1] - nums[i]) * (n - i - 1));

        return arr;
    }
};
// @lc code=end

// Note: prefix sum
