/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution
{
public:
    bool has_zero(int val)
    {
        while (val)
        {
            if (val % 10 == 0)
                return true;
            val /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (!has_zero(i) && !has_zero(n - i))
                return {i, n - i};
        }
        return {-1, -1};
    }
};
// @lc code=end

// Note: math