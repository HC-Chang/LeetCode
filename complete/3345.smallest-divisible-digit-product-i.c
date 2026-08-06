/*
 * @lc app=leetcode id=3345 lang=c
 *
 * [3345] Smallest Divisible Digit Product I
 */

// @lc code=start
int smallestNumber(int n, int t)
{
    int val;
    int tmp;
    while (n)
    {
        val = 1;
        tmp = n;
        while (tmp)
        {
            val *= tmp % 10;
            tmp /= 10;
        }
        if (val % t == 0)
            return n;
        n++;
    }
    return -1;
}
// @lc code=end

// Note: math