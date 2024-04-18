/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &grid, int gridSize, int gridColSize)
    {
        if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize)
            return 1;
        if (grid[i][j] == 0)
            return 1;
        if (grid[i][j] == -1)
            return 0;
        grid[i][j] = -1;
        int count = dfs(i + 1, j, grid, gridSize, gridColSize);
        count += dfs(i - 1, j, grid, gridSize, gridColSize);
        count += dfs(i, j + 1, grid, gridSize, gridColSize);
        count += dfs(i, j - 1, grid, gridSize, gridColSize);
        return count;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return dfs(i, j, grid, m, n);
            }
        }
        return 0;
    }
};
// @lc code=end

// Note: DFS