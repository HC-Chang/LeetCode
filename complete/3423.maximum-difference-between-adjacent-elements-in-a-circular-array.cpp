/*
 * @lc app=leetcode id=3423 lang=cpp
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */

// @lc code=start
class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int n = nums.size();
        int max_dis = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; i++)
            max_dis = max(abs(nums[i + 1] - nums[i]), max_dis);
        return max_dis;
    }
};
// @lc code=end
