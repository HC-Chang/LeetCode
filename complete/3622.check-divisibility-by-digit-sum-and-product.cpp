/*
 * @lc app=leetcode id=3622 lang=cpp
 *
 * [3622] Check Divisibility by Digit Sum and Product
 */

// @lc code=start
class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int sum = 0;
        int product = 1;
        int val = n;
        while (val)
        {
            int tmp = val % 10;
            sum += tmp;
            product *= tmp;
            val /= 10;
        }
        sum += product;
        return n % sum == 0;
    }
};
// @lc code=end

// Note: math