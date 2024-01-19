/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
public:
    int last_min(int i, int j, vector<vector<int>> &matrix, int m, int n)
    {
        int min = matrix[i - 1][j];
        if (j >= 1)
            min = fmin(min, matrix[i - 1][j - 1]);
        if (j < n - 1)
            min = fmin(min, matrix[i - 1][j + 1]);
        return min;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] += last_min(i, j, matrix, m, n);
        }
        sort(matrix[m - 1].begin(), matrix[m - 1].end());
        return matrix[m - 1][0];
    }
};
// @lc code=end
