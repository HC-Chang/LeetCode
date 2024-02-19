/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        long int x = n;
        if (n && !(n & (x - 1)))
            return true;
        return false;
    }
};
// @lc code=end

// Note: bit manipulation