/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int cnt = 0;
        for (auto &n : nums)
            cnt += n % 3 == 0 ? 0 : 1;
        return cnt;
    }
};
// @lc code=end

// Note: math