/*
 * @lc app=leetcode id=2784 lang=cpp
 *
 * [2784] Check if Array is Good
 */

// @lc code=start
class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1)
            return false;
        return (nums[0] == 1) && (nums[n - 2] == n - 1) && (nums[n - 1] == n - 1) && (((2 + n) * (n - 1) / 2) == accumulate(nums.begin(), nums.end(), 0));
    }
};
// @lc code=end

// Note: sorting