/*
 * @lc app=leetcode id=2154 lang=cpp
 *
 * [2154] Keep Multiplying Found Values by Two
 */

// @lc code=start
class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        set<int> s;
        for (auto &n : nums)
            if (n % original == 0)
                s.insert(n);
        while (s.find(original) != s.end())
            original *= 2;
        return original;
    }
};
// @lc code=end

// Note: array + hash table + sorting + simulation
