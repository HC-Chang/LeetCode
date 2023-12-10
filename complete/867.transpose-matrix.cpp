/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = matrix[j][i];

        return ans;
    }
};
// @lc code=end

// Note: matrix