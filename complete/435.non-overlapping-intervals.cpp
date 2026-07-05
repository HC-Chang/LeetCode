/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end());

        int res = 0;
        int endLast = intervals[0][1];
        int t;
        for (int i = 1; i < intervals.size(); ++i)
        {
            t = endLast > intervals[i][0] ? 1 : 0;
            endLast =
                (t == 1 ? min(endLast, intervals[i][1]) : intervals[i][1]);
            res += t;
        }
        return res;
    }
};
// @lc code=end
