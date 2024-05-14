/*
 * @lc app=leetcode id=1219 lang=c
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
int traverse(int i, int j, int tmp, int visited[15][15], int **grid, int m,
             int n)
{
    if (grid[i][j] <= 0 || visited[i][j] == 1)
        return visited[i][j];

    tmp += grid[i][j];
    visited[i][j] = 1;

    int last = tmp;
    if (i > 0)
        tmp = fmax(tmp, traverse(i - 1, j, last, visited, grid, m, n));
    if (i < m - 1)
        tmp = fmax(tmp, traverse(i + 1, j, last, visited, grid, m, n));
    if (j > 0)
        tmp = fmax(tmp, traverse(i, j - 1, last, visited, grid, m, n));
    if (j < n - 1)
        tmp = fmax(tmp, traverse(i, j + 1, last, visited, grid, m, n));
    visited[i][j] = 0;
    return tmp;
}

int getMaximumGold(int **grid, int gridSize, int *gridColSize)
{
    int max = 0;
    int m = gridSize;
    int n = gridColSize[0];
    int visited[15][15];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] > 0)
            {
                memset(visited, 0, sizeof(visited));
                max = fmax(max, traverse(i, j, 0, visited, grid, m, n));
            }
        }
    }
    return max;
}
// @lc code=end

// Note: backtracking + matrix