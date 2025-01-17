/*
 * @lc app=leetcode id=2683 lang=cpp
 *
 * [2683] Neighboring Bitwise XOR
 */

// @lc code=start
class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ans = 0;
        for (auto d : derived)
            ans ^= d;

        return ans % 2 == 0;
    }
};
// @lc code=end

// Note: bit manipulation