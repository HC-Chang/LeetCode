/*
 * @lc app=leetcode id=2054 lang=c
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    if ((*(int **)a)[0] == (*(int **)b)[0])
        return (*(int **)a)[1] - (*(int **)b)[1];
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize)
{
    int n = eventsSize * 2;
    int **times = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        times[i] = malloc(3 * sizeof(int));

    int idx = 0;
    for (int i = 0; i < eventsSize; i++)
    {
        times[idx][0] = events[i][0];
        times[idx][1] = 1;
        times[idx++][2] = events[i][2];
        times[idx][0] = events[i][1] + 1;
        times[idx][1] = 0;
        times[idx++][2] = events[i][2];
    }

    int ans = 0, max_val = 0;
    qsort(times, n, sizeof(int *), sort);
    for (int i = 0; i < n; i++)
    {
        if (times[i][1])
            ans = fmax(ans, times[i][2] + max_val);
        else
            max_val = fmax(max_val, times[i][2]);
    }

    for (int i = 0; i < n; i++)
        free(times[i]);
    free(times);

    return ans;
}
// @lc code=end

// Note: sorting + binary search + heap