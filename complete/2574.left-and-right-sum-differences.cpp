/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 */

// @lc code=start
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lsum(n), rsum(n);
        for (int i = 1; i < n; i++)
        {
            lsum[i] = lsum[i - 1] + nums[i - 1];
            rsum[n - 1 - i] = rsum[n - i] + nums[n - i];
        }
        for (int i = 0; i < n; i++)
            nums[i] = abs(lsum[i] - rsum[i]);
        return nums;
    }
};
// @lc code=end
