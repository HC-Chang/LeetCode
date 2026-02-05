/*
 * @lc app=leetcode id=3379 lang=cpp
 *
 * [3379] Transformed Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(nums[(i + nums[i] % n + n) % n]);
        return ans;
    }
};
// @lc code=end
