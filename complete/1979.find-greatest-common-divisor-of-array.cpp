/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b > a)
            return gcd(b, a);
        if (a == b || b == 0)
            return a;
        return gcd(a % b, b);
    }

    int findGCD(vector<int> &nums)
    {
        int min_val = nums[0];
        int max_val = nums[0];
        for (auto &n : nums)
        {
            if (n < min_val)
                min_val = n;
            else if (n > max_val)
                max_val = n;
        }
        return gcd(max_val, min_val);
    }
};
// @lc code=end

// Note: math(GCD)