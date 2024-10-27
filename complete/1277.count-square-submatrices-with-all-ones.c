/*
 * @lc app=leetcode id=1277 lang=c
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
int countSquares(int **matrix, int matrixSize, int *matrixColSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i + 1][j + 1] =
                    fmin(dp[i][j + 1], fmin(dp[i + 1][j], dp[i][j])) + 1;
                ans += dp[i + 1][j + 1];
            }
        }
    }
    return ans;
}
// @lc code=end

// Note: DP

// Official Solution