/*
 * @lc app=leetcode id=1751 lang=c
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    return x[0][1] - y[0][1];
}

int maxValue(int **events, int eventsSize, int *eventsColSize, int k)
{
    qsort(events, eventsSize, sizeof(int *), sort);
    int **arrs = malloc((eventsSize + 1) * sizeof(int *));
    arrs[0] = calloc(3, sizeof(int));
    for (int i = 1; i < eventsSize + 1; i++)
        arrs[i] = events[i - 1];

    long long **dp = malloc((eventsSize + 1) * sizeof(long long *));
    for (int i = 0; i < eventsSize + 1; i++)
        dp[i] = calloc(k + 1, sizeof(long long));

    int l, r, mid;
    for (int i = 1; i <= eventsSize; i++)
    {
        l = 0;
        r = i - 1;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (arrs[mid + 1][1] >= arrs[i][0])
                r = mid;
            else
                l = mid + 1;
        }

        dp[i][0] = 0;
        for (int j = 1; j <= k; j++)
            dp[i][j] = fmax(dp[i - 1][j], dp[l][j - 1] + arrs[i][2]);
    }

    int ret = dp[eventsSize][k];
    free(arrs[0]);
    free(arrs);
    for (int i = 0; i < eventsSize + 1; i++)
        free(dp[i]);
    free(dp);

    return ret;
}
// @lc code=end

// Note: sorting + binary search + DP
