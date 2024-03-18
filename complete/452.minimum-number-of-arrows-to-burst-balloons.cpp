/*
 * @lc app=leetcode id=452 lang=c
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return b[1] > a[1]; });
        int count = 1;
        int max_x = points[0][1];
        int n = points.size();
        for (int i = 1; i < n; i++)
        {
            if (points[i][0] > max_x)
            {
                max_x = points[i][1];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
