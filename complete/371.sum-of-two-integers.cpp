/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = a;

        while (b != 0)
        {
            sum = a ^ b;
            b = (unsigned)(a & b) << 1;
            a = sum;
        }

        return sum;
    }
};
// @lc code=end

// Note: math + bit manipulation