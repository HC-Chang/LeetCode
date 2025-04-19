/*
 * @lc app=leetcode id=435 lang=c
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    if (x[0][0] != y[0][0])
        return x[0][0] - y[0][0];
    return x[0][1] - y[0][1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    if (intervalsSize == 0)
        return 0;
    qsort(intervals, intervalsSize, sizeof(int **), sort);

    int res = 0;
    int endLast = intervals[0][1];
    int t;
    for (int i = 1; i < intervalsSize; ++i)
    {
        t = endLast > intervals[i][0] ? 1 : 0;
        endLast = (t == 1 ? fmin(endLast, intervals[i][1]) : intervals[i][1]);
        res += t;
    }
    return res;
}
// @lc code=end
