/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        for (const auto &n : nums)
        {
            if (++hash[n] >= 2)
                return n;
        }
        return nums[0];
    }
};
// @lc code=end

// Note: hash table