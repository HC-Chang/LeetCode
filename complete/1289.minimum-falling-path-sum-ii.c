/*
 * @lc app=leetcode id=1289 lang=c
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minFallingPathSum(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int res = INT_MAX;
    int dp[n];
    memcpy(&dp, grid[0], sizeof(dp));

    for (int i = 0; i < n - 1; ++i)
    {
        int mn = INT_MAX;
        int idx = -1;
        int sm = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            if (dp[j] < mn)
            {
                sm = mn;
                mn = dp[j];
                idx = j;
            }
            else if (dp[j] < sm)
                sm = dp[j];
        }
        for (int j = 0; j < n; ++j)
            dp[j] = grid[i + 1][j] + (j == idx ? sm : mn);
    }
    qsort(dp, n, sizeof(int), sort);
    return dp[0];
}
// @lc code=end

// Note: DP