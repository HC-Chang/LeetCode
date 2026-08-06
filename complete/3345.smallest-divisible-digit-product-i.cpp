/*
 * @lc app=leetcode id=3345 lang=cpp
 *
 * [3345] Smallest Divisible Digit Product I
 */

// @lc code=start
class Solution
{
public:
    int smallestNumber(int n, int t)
    {

        while (n)
        {
            int val = 1;
            int tmp = n;
            while (tmp)
            {
                val *= tmp % 10;
                tmp /= 10;
            }
            if (val % t == 0)
                return n;
            n++;
        }
        return -1;
    }
};
// @lc code=end

// Note: math