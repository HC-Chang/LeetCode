/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3)
            return 0;
        int res = 0;
        bool flag;
        for (int i = 0; i < m - 2; i++)
            for (int j = 0; j < n - 2; j++)
            {
                flag = false;
                if (grid[i + 1][j + 1] != 5 || grid[i][j] == 5)
                    continue;
                if (grid[i][j] + grid[i + 2][j + 2] != 10 ||
                    grid[i + 2][j] + grid[i][j + 2] != 10 ||
                    grid[i + 1][j] + grid[i + 1][j + 2] != 10 ||
                    grid[i][j + 1] + grid[i + 2][j + 1] != 10)
                    continue;
                if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15 ||
                    grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15)
                    continue;
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                        if (grid[i + x][j + y] > 9 || grid[i + x][j + y] < 0)
                        {
                            flag = true;
                            break;
                        }
                if (flag)
                    continue;
                res++;
            }
        return res;
    }
};
// @lc code=end
