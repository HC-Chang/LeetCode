/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        int r = INT_MAX;
        for (int i = 0, j = 0, m = nums.size(); i < m; ++i)
        {
            while (j < m && nums[j] < nums[i] + n)
                ++j;
            r = min(r, n - (j - i));
        }
        return r;
    }
};
// @lc code=end
