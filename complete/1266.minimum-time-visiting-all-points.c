/*
 * @lc app=leetcode id=1266 lang=c
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
int minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize)
{
    int ans = 0;
    for (int i = 1; i < pointsSize; i++)
        ans += fmax(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));

    return ans;
}
// @lc code=end
