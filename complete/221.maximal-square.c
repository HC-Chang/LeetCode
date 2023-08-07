/*
 * @lc app=leetcode id=221 lang=c
 *
 * [221] Maximal Square
 */

// @lc code=start
int maximalSquare(char **matrix, int matrixSize, int *matrixColSize)
{
    int dp[matrixSize + 1];
    memset(dp, 0, (matrixSize + 1) * sizeof(int));
    int tmp = 0;
    int pre = 0;
    int res = 0;
    for (int j = 0; j < matrixColSize[0]; ++j)
    {
        for (int i = 1; i <= matrixSize; ++i)
        {
            tmp = dp[i];
            if (matrix[i - 1][j] == '1')
            {
                dp[i] = fmin(dp[i], fmin(dp[i - 1], pre)) + 1;
                res = fmax(res, dp[i]);
            }
            else
                dp[i] = 0;
            pre = tmp;
        }
    }
    return res * res;
}
// @lc code=end

// Note: DP
