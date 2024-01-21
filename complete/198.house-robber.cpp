/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        if (nums[0] > nums[1])
            nums[1] = nums[0];
        for (int i = 2; i < n; i++)
            nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);

        return nums[n - 1];
    }
};
// @lc code=end

// Note: DP