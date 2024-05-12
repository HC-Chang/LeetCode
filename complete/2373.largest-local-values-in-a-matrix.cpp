/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size() - 2;
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int x = i; x <= i + 2; ++x)
                {
                    for (int y = j; y <= j + 2; ++y)
                        ans[i][j] = max(ans[i][j], grid[x][y]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// Note: matrix
