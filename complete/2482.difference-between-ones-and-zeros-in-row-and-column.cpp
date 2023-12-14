/*
 * @lc app=leetcode id=2482 lang=cpp
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> x_arr(m);
        vector<int> y_arr(n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ++x_arr[i];
                    ++y_arr[j];
                }
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                ans[i][j] = 2 * x_arr[i] - m + 2 * y_arr[j] - n;
        }
        return ans;
    }
};
// @lc code=end
