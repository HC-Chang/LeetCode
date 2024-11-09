/*
 * @lc app=leetcode id=3133 lang=cpp
 *
 * [3133] Minimum Array End
 */

// @lc code=start
class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long result = x, mask;
        --n;
        for (mask = 1; n > 0; mask <<= 1)
        {
            if ((mask & x) == 0)
            {
                result |= (n & 1) * mask;
                n >>= 1;
            }
        }

        return result;
    }
};
// @lc code=end

// Note: bit manipulation

// Official Solution