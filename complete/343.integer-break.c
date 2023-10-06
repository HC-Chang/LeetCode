/*
 * @lc app=leetcode id=343 lang=c
 *
 * [343] Integer Break
 */

// @lc code=start
int integerBreak(int n)
{
    if (n == 2 || n == 3)
        return n - 1;
    if (n == 4)
        return 4;
    n -= 5;
    return (int)pow(3, (n / 3 + 1)) * (n % 3 + 2);
}
// @lc code=end

// Note: DP
