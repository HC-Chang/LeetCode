/*
 * @lc app=leetcode id=1915 lang=cpp
 *
 * [1915] Number of Wonderful Substrings
 */

// @lc code=start
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long total = 0;
        int nowMask = 0;
        int counts[1024] = {0};
        counts[0] = 1;
        for (auto c : word)
        {
            nowMask ^= (1 << (c - 'a'));
            total += counts[nowMask];
            for (int i = 0; i < 10; ++i)
                total += counts[nowMask ^ (1 << i)];
            ++counts[nowMask];
        }
        return total;
    }
};
// @lc code=end

// Note: bit manipulation