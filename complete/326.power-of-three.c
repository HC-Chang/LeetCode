/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */

// @lc code=start

bool isPowerOfThree(int n)
{
    if (n <= 2 || n % 2 == 0)
    {
        if (n == 1)
        {
            return true;
        }

        return false;
    }

    unsigned int i = 3;

    while (i <= n)
    {
        if (i == n)
        {
            return true;
        }
        else
        {
            i *= 3;
        }
    }
    return false;
}
// @lc code=end
// 3 的次方一定為奇數