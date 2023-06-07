/*
 * @lc app=leetcode id=2220 lang=c
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
int minBitFlips(int start, int goal)
{
    int count = 0;
    while (start > 0 || goal > 0)
    {
        if ((start & 1) != (goal & 1))
            count++;
        start = start >> 1;
        goal = goal >> 1;
    }

    return count;
}
// @lc code=end

// Note: Bit Manipulation