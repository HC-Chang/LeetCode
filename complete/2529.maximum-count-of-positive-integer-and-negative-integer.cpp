/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// Difficulty:Easy

// @lc code=start
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int cnt[2];
        for (auto n : nums)
        {
            if (n > 0)
                ++cnt[0];
            else if (n < 0)
                ++cnt[1];
        }
        return cnt[0] > cnt[1] ? cnt[0] : cnt[1];
    }
};
// @lc code=end