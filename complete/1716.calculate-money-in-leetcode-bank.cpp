/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution
{
public:
    int totalMoney(int n)
    {
        int sum = 1;
        int idx = 2;
        for (int i = 1; i < n; i++)
        {
            if (i % 7 == 0)
                idx -= 6;
            sum += idx++;
        }

        return sum;
    }
};
// @lc code=end
