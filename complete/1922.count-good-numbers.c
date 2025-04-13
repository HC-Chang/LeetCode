/*
 * @lc app=leetcode id=1922 lang=c
 *
 * [1922] Count Good Numbers
 */

// @lc code=start
#define MOD 1000000007
long long quickmul(int x, long long y)
{
    long long ret = 1;
    long long mul = x;
    while (y > 0)
    {
        if (y % 2 == 1)
            ret = (ret * mul) % MOD;

        mul = (mul * mul) % MOD;
        y /= 2;
    }
    return ret;
}

int countGoodNumbers(long long n)
{
    return (int)(quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % MOD);
}
// @lc code=end

// Note: math + recursion

// Official Solution