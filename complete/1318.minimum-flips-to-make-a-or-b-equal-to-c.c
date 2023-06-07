/*
 * @lc app=leetcode id=1318 lang=c
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
int minFlips(int a, int b, int c)
{
    int count = 0;
    for (int i = 0; i < 31; ++i)
    {
        if ((c >> i) & 1)
            count += ((a >> i) & 1) == 0 && ((b >> i) & 1) == 0;
        else
            count += ((a >> i) & 1) + ((b >> i) & 1);
    }

    return count;
}
// @lc code=end
