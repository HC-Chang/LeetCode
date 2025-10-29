/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
class Solution
{
public:
    int smallestNumber(int n)
    {
        int val = 0;
        while (val < n)
            val = (val << 1) + 1;

        return val;
    }
};
// @lc code=end

// Note: math + bit manipulation