/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    int is_not_zero(vector<vector<char>> &grid, int gridSize, int gridColSize)
    {
        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridColSize; j++)
            {
                if (grid[i][j] != '0')
                    return 1;
            }
        }

        return 0;
    }

    void find_island(vector<vector<char>> &grid, int gridSize, int gridColSize, int x,
                     int y)
    {
        if (x > gridSize - 1 || x < 0 || y > gridColSize - 1 || y < 0)
            return;
        if (grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        find_island(grid, gridSize, gridColSize, x, y - 1);
        find_island(grid, gridSize, gridColSize, x, y + 1);
        find_island(grid, gridSize, gridColSize, x - 1, y);
        find_island(grid, gridSize, gridColSize, x + 1, y);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0)
            return 0;

        int island_count = 0;

        do
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] != '0')
                    {
                        find_island(grid, m, n, i, j);
                        island_count++;
                        break;
                    }
                }
            }

        } while (is_not_zero(grid, m, n));

        return island_count;
    }
};

// @lc code=end
