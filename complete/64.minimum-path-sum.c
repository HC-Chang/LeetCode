/*
 * @lc app=leetcode id=64 lang=c
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    int width = gridColSize[gridSize - 1];
    int dp[gridSize][width];
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = i; j < width; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < width; i++)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    int min;
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = 1; j < width; j++)
        {
            min = dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
            dp[i][j] = min + grid[i][j];
        }
    }

    return dp[gridSize - 1][width - 1];
}
// @lc code=end
