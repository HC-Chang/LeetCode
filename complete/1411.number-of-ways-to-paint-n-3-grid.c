/*
 * @lc app=leetcode id=1411 lang=c
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
#define MOD (long)(1e9 + 7)

int numOfWays(int n)
{
    long two = 6, three = 6;
    if (n == 1)
        return 12;
    long ntwo;
    long nthree;
    for (int i = 2; i <= n; ++i)
    {
        ntwo = (3 * two + 2 * three) % MOD;
        nthree = (2 * two + 2 * three) % MOD;
        two = ntwo;
        three = nthree;
    }
    return (int)((two + three) % MOD);
}
// @lc code=end

// Note: DP