/*
 * @lc app=leetcode id=1547 lang=c
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int min(int a, int b) { return a < b ? a : b; }
int minCost(int n, int *cuts, int cutsSize)
{
    qsort(cuts, cutsSize, sizeof(int), sort);
    int m = cutsSize + 2;
    int *arr = malloc(m * sizeof(int));
    arr[0] = 0;
    for (int i = 0; i < cutsSize; i++)
        arr[i + 1] = cuts[i];
    arr[m - 1] = n;

    int **dp = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        dp[i] = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            dp[i][j] = INT_MAX;
    }

    for (int i = 0; i + 1 < m; i++)
        dp[i][i + 1] = 0;

    for (int len = 3; len <= m; len++)
    {
        for (int i = 0; i + len - 1 < m; i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], arr[j] - arr[i] + dp[i][k] + dp[k][j]);
        }
    }
    int r = dp[0][m - 1];
    free(arr);
    for (int i = 0; i < m; i++)
        free(dp[i]);
    free(dp);
    return r;
}
// @lc code=end
