/*
 * @lc app=leetcode id=3783 lang=cpp
 *
 * [3783] Mirror Distance of an Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse_val(int n)
    {
        int val = 0;
        while (n > 0)
        {
            val += n % 10;
            n /= 10;
            if (n > 0)
                val *= 10;
        }

        return val;
    }

    int mirrorDistance(int n)
    {
        return abs(n - reverse_val(n));
    }
};
// @lc code=end

// Note: math