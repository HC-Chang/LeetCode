/*
 * @lc app=leetcode id=63 lang=c
 *
 * [63] Unique Paths II
 */

// @lc code=start
int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    int **dp = malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
        dp[i] = calloc(n + 1, sizeof(int));
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (obstacleGrid[i - 1][j - 1] == 1)
                dp[i][j] = 0;
            else
            {
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    int r = dp[m][n];
    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);
    return r;
}
// @lc code=end

// Note: DP