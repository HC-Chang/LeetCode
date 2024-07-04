/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int sum = 1;
        int end = num;
        for (int i = 2; i < end && i * i <= num; i++)
        {
            if (num % i == 0)
            {
                sum += i + num / i;
                end = num / i;
            }
        }

        return sum == num;
    }
};
// @lc code=end

// Note: math