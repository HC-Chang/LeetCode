/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(),
             [](const std::vector<int> &a, const std::vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        int max = INT_MIN;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] - points[i - 1][0] > max)
                max = points[i][0] - points[i - 1][0];
        }
        return max;
    }
};
// @lc code=end

// Note: sorting