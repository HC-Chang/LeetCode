/*
 * @lc app=leetcode id=2406 lang=c
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
int minGroups(int **intervals, int intervalsSize, int *intervalsColSize)
{
    int range_start = INT_MAX;
    int range_end = INT_MIN;
    for (int i = 0; i < intervalsSize; i++)
    {
        range_start = fmin(range_start, intervals[i][0]);
        range_end = fmax(range_end, intervals[i][1]);
    }

    int point_to_count[range_end + 2];
    memset(point_to_count, 0, sizeof(point_to_count));
    for (int i = 0; i < intervalsSize; i++)
    {
        point_to_count[intervals[i][0]]++;
        point_to_count[intervals[i][1] + 1]--;
    }

    int concurrent_intervals = 0;
    int max_concurrent_intervals = 0;
    for (int i = range_start; i <= range_end; i++)
    {
        concurrent_intervals += point_to_count[i];
        max_concurrent_intervals =
            fmax(max_concurrent_intervals, concurrent_intervals);
    }

    return max_concurrent_intervals;
}
// @lc code=end

// Note: greedy + sorting + heap + prefix sum

// Official Solution