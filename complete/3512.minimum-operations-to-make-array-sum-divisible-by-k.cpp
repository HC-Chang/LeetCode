/*
 * @lc app=leetcode id=3512 lang=cpp
 *
 * [3512] Minimum Operations to Make Array Sum Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int tmp = 0;
        for (auto &n : nums)
            tmp += n % k;
        return tmp % k;
    }
};
// @lc code=end

// Note: math