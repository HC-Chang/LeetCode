/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int r = n;
        for (int i = 0; i < n; i++)
            r ^= i ^ nums[i];
        return r;
    }
};
// @lc code=end
