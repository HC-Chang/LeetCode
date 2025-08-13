/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */

// @lc code=start

bool isPowerOfThree(int n)
{
    if (n < 0 || n % 2 == 0 || n % 10 == 5)
    {
        return false;
    }

    unsigned int i = 1;

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

// Note: math + recursion

// 3 的次方一定為奇數 
// -> n % 2 != 0
//
// 且 3 的次方除 10 的餘數為 3.9.7.1 其中一個數
// -> n % 10 != 5