/*
 * @lc app=leetcode id=3643 lang=cpp
 *
 * [3643] Flip Square Submatrix Vertically
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int cnt = k / 2;
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < k; j++)
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
        }
        return grid;
    }
};
// @lc code=end

// Note: matrix