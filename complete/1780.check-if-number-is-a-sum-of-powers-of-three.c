/*
 * @lc app=leetcode id=1780 lang=c
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
bool checkPowersOfThree(int n)
{
    while (n > 0)
    {
        if (n % 3 == 2)
        {
            return false;
        }
        n /= 3;
    }
    return true;
}
// @lc code=end

// Note: math