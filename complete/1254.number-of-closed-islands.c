/*
 * @lc app=leetcode id=1254 lang=c
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
int dfs(int **grid, int gridSize, int gridColSize, int i, int j)
{
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize)
        return 0;
    if (grid[i][j] > 0)
        return 1;
    grid[i][j] = 2;
    return dfs(grid, gridSize, gridColSize, i + 1, j) * dfs(grid, gridSize, gridColSize, i - 1, j) * dfs(grid, gridSize, gridColSize, i, j + 1) * dfs(grid, gridSize, gridColSize, i, j - 1);
}

int closedIsland(int **grid, int gridSize, int *gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (grid[i][j] == 0)
                count += dfs(grid, gridSize, gridColSize[0], i, j);
        }
    }
    return count;
}
// @lc code=end
