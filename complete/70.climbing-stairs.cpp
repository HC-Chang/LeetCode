/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
            return n;
        int last = 1;
        int cur = 2;
        int tmp;
        for (int i = 2; i < n; i++)
        {
            tmp = last;
            last = cur;
            cur += tmp;
        }
        return cur;
    }
};
// @lc code=end

// Note: DP