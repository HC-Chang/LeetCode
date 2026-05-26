/*
 * @lc app=leetcode id=3120 lang=cpp
 *
 * [3120] Count the Number of Special Characters I
 */

// @lc code=start
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int hash1 = 0, hash2 = 0;
        for (auto &c : word)
        {
            if (isupper(c))
                hash1 |= 1 << (c - 'A');
            else
                hash2 |= 1 << (c - 'a');
        }
        return __builtin_popcount(hash1 & hash2);
    }
};
// @lc code=end

// Note: hash table