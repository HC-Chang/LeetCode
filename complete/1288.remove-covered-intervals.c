/*
 * @lc app=leetcode id=1288 lang=c
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    int *ia = *(int **)a;
    int *ib = *(int **)b;
    if (ia[0] == ib[0])
        return ib[1] - ia[1];
    return ia[0] - ib[0];
}

int removeCoveredIntervals(int **intervals, int intervalsSize,
                           int *intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int *), sort);
    int cnt = 0;
    int last_idx = 0;
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[last_idx][0] <= intervals[i][0] &&
            intervals[last_idx][1] >= intervals[i][1])
            cnt++;
        else
            last_idx = i;
    }

    return intervalsSize - cnt;
}
// @lc code=end

// Note: sorting