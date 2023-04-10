/*
 * @lc app=leetcode id=263 lang=c
 *
 * [263] Ugly Number
 */

// @lc code=start
bool isUgly(int n)
{
    if (n <= 0)
        return false;
    while (n > 3)
    {
        if (n % 5 == 0)
            n = n / 5;
        else if (n % 3 == 0)
            n = n / 3;
        else if (n % 2 == 0)
            n = n / 2;
        else
            return false;
    }
    return true;
}
// @lc code=end
