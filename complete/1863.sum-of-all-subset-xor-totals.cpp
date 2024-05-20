/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
            nums[0] |= nums[i];
        return nums[0] << n - 1;
    }
};
// @lc code=end

// Note: bit manipulation