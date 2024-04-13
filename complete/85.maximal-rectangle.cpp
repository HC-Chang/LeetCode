/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] != '0')
                {
                    if (j > 0)
                        dp[i][j] = dp[i][j - 1] + 1;
                    else
                        dp[i][0] = 1;
                }
            }
        }

        int mn;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dp[i][j] != 0)
                {
                    mn = dp[i][j];
                    if (mn > res)
                        res = mn;
                    for (int k = i - 1; k >= 0 && dp[k][j] != 0; --k)
                    {
                        if (mn > dp[k][j])
                            mn = dp[k][j];
                        res = max(res, mn * (i - k + 1));
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

// Note: matrix + dp