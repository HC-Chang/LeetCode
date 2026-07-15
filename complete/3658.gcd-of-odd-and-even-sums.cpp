/*
 * @lc app=leetcode id=3658 lang=cpp
 *
 * [3658] GCD of Odd and Even Sums
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
    int gcdOfOddEvenSums(int n)
    {
        int even = 0;
        int odd = 0;
        for (int i = 1; i <= n; i++)
        {
            even += i * 2 - 1;
            odd += i * 2;
        }
        return gcd(even, odd);
    }
};
// @lc code=end

// Note: math