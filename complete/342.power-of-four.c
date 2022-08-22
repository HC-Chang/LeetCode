/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */

// @lc code=start

bool isPowerOfFour(int n)
{
    if (n == 0)
    {
        return false;
    }

    unsigned int r1 = log2(n);
    if (pow(2, r1) == n && r1 % 2 == 0)
    {
        return true;
    }

    return false;
}
// @lc code=end
// 4^n = 2^(2*n)