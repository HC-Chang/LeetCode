/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if(a[0] == b[0])
                return a[1] > b[1];
                return a[0] < b[0]; });
        int n = intervals.size();
        int cnt = 0;
        int last_idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[last_idx][0] <= intervals[i][0] && intervals[last_idx][1] >= intervals[i][1])
                cnt++;
            else
                last_idx = i;
        }

        return n - cnt;
    }
};
// @lc code=end

// Note: sorting