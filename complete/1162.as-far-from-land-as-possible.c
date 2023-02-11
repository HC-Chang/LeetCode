/*
 * @lc app=leetcode id=1162 lang=c
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int maxDistance(int **grid, int gridSize, int *gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];
    int MAX_DISTANCE = rows + cols + 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j])
                grid[i][j] = 0;
            else
            {
                grid[i][j] = MAX_DISTANCE;
                grid[i][j] = min(grid[i][j], min(i > 0 ? grid[i - 1][j] + 1 : MAX_DISTANCE,
                                                 j > 0 ? grid[i][j - 1] + 1 : MAX_DISTANCE));
            }
        }
    }

    int ans = INT_MIN;
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            grid[i][j] = min(grid[i][j], min(i < rows - 1 ? grid[i + 1][j] + 1 : MAX_DISTANCE,
                                             j < cols - 1 ? grid[i][j + 1] + 1 : MAX_DISTANCE));
            ans = max(ans, grid[i][j]);
        }
    }

    return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
}
// @lc code=end
