/*
 * @lc app=leetcode id=258 lang=c
 *
 * [258] Add Digits
 */

// @lc code=start
int addDigits(int num)
{
    int d = 0;
    while (num / 10 > 0)
    {
        while (num / 10 > 0)
        {
            d += num % 10;
            num = num / 10;
        }
        d += num;
        num = d;
        d = 0;
    }
    return num;
}
// @lc code=end
