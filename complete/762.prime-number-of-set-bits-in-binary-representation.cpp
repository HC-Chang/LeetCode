/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        set<int> s = {2, 3, 5, 7, 11, 13, 17, 19};
        int cnt = 0;
        for (int i = left; i <= right; i++)
        {
            if (s.find(__builtin_popcount(i)) != s.end())
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// Note: math + bit manipulation