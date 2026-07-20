/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        vector<int> v;
        for (auto &g : grid)
            v.insert(v.end(), g.begin(), g.end());
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        int idx = -k % size;
        while (idx < 0)
            idx += size;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (idx == size)
                    idx = 0;
                grid[i][j] = v[idx++];
            }
        }
        return grid;
    }
};
// @lc code=end

// Note: matrix