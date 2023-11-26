/*
 * @lc app=leetcode id=1727 lang=c
 *
 * [1727] Largest Submatrix With Rearrangements
 */

// @lc code=start
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0 && matrix[i][j] == 1)
                    matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = 0; j < n; j++)
                ans = max(ans, (n - j) * matrix[i][j]);
        }

        return ans;
    }
};
// @lc code=end
