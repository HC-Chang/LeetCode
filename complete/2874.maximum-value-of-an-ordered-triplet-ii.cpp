/*
 * @lc app=leetcode id=2874 lang=cpp
 *
 * [2874] Maximum Value of an Ordered Triplet II
 */

// @lc code=start
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long max_val = 0, imax = 0, diff = 0;
        for (auto n : nums)
        {
            max_val = max(max_val, diff * n);
            diff = max(diff, imax - n);
            imax = max(imax, (long long)n);
        }
        return max_val;
    }
};
// @lc code=end
