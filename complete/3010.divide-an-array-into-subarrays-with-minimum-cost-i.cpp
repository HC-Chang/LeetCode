/*
 * @lc app=leetcode id=3010 lang=cpp
 *
 * [3010] Divide an Array Into Subarrays With Minimum Cost I
 */

// @lc code=start
class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        sort(nums.begin() + 1, nums.end());
        for (int i = 0; i < 2; i++)
            nums[0] += nums[i + 1];

        return nums[0];
    }
};
// @lc code=end

// Note: sorting