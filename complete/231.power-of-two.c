/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start
bool isPowerOfTwo(int n)
{
    if (n == 1)
        return true;
    else if (n % 2 == 1 || n <= 0)
        return false;
    unsigned int tmp = 2;
    while (tmp <= n)
    {
        if (tmp == n)
            return true;
        else
            tmp *= 2;
    }
    return false;
}
// @lc code=end

// Note: bit manipulation