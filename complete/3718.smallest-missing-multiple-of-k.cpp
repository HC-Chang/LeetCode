/*
 * @lc app=leetcode id=3718 lang=cpp
 *
 * [3718] Smallest Missing Multiple of K
 */

// @lc code=start
class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        unordered_set<int> u_s;
        for (auto &n : nums)
            u_s.insert(n);
        int idx = 1;
        int val = k;
        while (u_s.find(val) != u_s.end())
            val = k * (++idx);
        return val;
    }
};
// @lc code=end

// Note: hash table