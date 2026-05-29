/*
 * @lc app=leetcode id=3300 lang=cpp
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 */

// @lc code=start
class Solution
{
public:
    int sum_val(int n)
    {
        int val = 0;
        while (n)
        {
            val += n % 10;
            n /= 10;
        }
        return val;
    }

    int minElement(vector<int> &nums)
    {
        int min_val = INT_MAX;
        for (auto &n : nums)
            min_val = min(min_val, sum_val(n));
        return min_val;
    }
};
// @lc code=end
