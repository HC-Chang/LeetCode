/*
 * @lc app=leetcode id=693 lang=c
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
bool hasAlternatingBits(int n)
{
    int last = n & 1;
    n >>= 1;
    int tmp;
    while (n > 0)
    {
        tmp = n & 1;
        if (last == tmp)
            return false;
        last = tmp;
        n >>= 1;
    }

    return true;
}
// @lc code=end

// Note: bit manipulation