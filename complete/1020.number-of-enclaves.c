/*
 * @lc app=leetcode id=1020 lang=c
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
void dfs(int **grid, int h, int w, int i, int j)
{
    if (i < 0 || j < 0 || i >= h || j >= w || grid[i][j] != 1)
        return;
    grid[i][j] = 0;
    dfs(grid, h, w, i + 1, j);
    dfs(grid, h, w, i - 1, j);
    dfs(grid, h, w, i, j + 1);
    dfs(grid, h, w, i, j - 1);
}

int numEnclaves(int **grid, int gridSize, int *gridColSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (i == 0 || j == 0 || i == gridSize - 1 || j == gridColSize[0] - 1)
            {
                if (grid[i][j] == 1)
                    dfs(grid, gridSize, gridColSize[0], i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (grid[i][j] == 1)
                count++;
        }
    }
    return count;
}
// @lc code=end
