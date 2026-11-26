/*
 * @lc app=leetcode id=3360 lang=c
 *
 * [3360] Stone Removal Game
 */

// @lc code=start
bool canAliceWin(int n)
{
    char cnt = 0;
    int tmp = 10;
    while (n >= 0)
    {
        n -= tmp;
        --tmp;
        cnt++;
    }

    return cnt % 2 == 0;
}
// @lc code=end

// Note: math