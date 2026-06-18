/*
 * @lc app=leetcode id=1344 lang=c
 *
 * [1344] Angle Between Hands of a Clock
 */

// @lc code=start
double angleClock(int hour, int minutes)
{
    if (hour >= 12)
        hour -= 12;
    double h = hour * 30 + (double)minutes / 2;
    double m = minutes * 6;

    double ans = m - h;
    if (ans < 0)
        ans += 360;

    return fmin(ans, 360 - ans);
}
// @lc code=end
