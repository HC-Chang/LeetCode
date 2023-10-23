/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;

        unsigned int r1 = log2(n);
        if (pow(2, r1) == n && r1 % 2 == 0)
            return true;
        return false;
    }
};
// @lc code=end
