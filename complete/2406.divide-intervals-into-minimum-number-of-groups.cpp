/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int range_start = INT_MAX;
        int range_end = INT_MIN;
        for (vector<int> interval : intervals)
        {
            range_start = min(range_start, interval[0]);
            range_end = max(range_end, interval[1]);
        }

        vector<int> pointToCount(range_end + 2, 0);
        for (vector<int> interval : intervals)
        {
            pointToCount[interval[0]]++;
            pointToCount[interval[1] + 1]--;
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (int i = range_start; i <= range_end; i++)
        {
            concurrentIntervals += pointToCount[i];
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};
// @lc code=end

// Note: greedy + sorting + heap + prefix sum

// Official Solution