/*
 * @lc app=leetcode id=2849 lang=c
 *
 * [2849] Determine if a Cell Is Reachable at a Given Time
 */

// @lc code=start
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
    sx -= fx;
    sy -= fy;
    if (sx == 0 && sy == 0 && t == 1)
        return false;
    return t >= fmax(abs(sx), abs(sy));
}
// @lc code=end
