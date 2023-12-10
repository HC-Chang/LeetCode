/*
 * @lc app=leetcode id=2078 lang=c
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
int maxDistance(int *colors, int colorsSize)
{
    int l1 = 0;
    int r1 = colorsSize - 1;
    int l2 = -1;
    int r2 = -1;
    for (int i = 1; i < colorsSize && (l2 == -1 || r2 == -1); i++)
    {
        if (l2 == -1 && colors[i] != colors[0])
            l2 = i;
        if (r2 == -1 && colors[colorsSize - 1 - i] != colors[colorsSize - 1])
            r2 = colorsSize - 1 - i;
    }

    if (colors[0] != colors[colorsSize - 1])
        return r1 - l1;
    return fmax(r1 - l2, r2 - l1);
}
// @lc code=end
