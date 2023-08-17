/*
 * @lc app=leetcode id=542 lang=c
 *
 * [542] 01 Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes)
{
    int m = matSize;
    int n = matColSize[0];
    *returnSize = m;
    returnColumnSizes[0] = matColSize;

    int **dp = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        dp[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = INT_MAX - 1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                if (i > 0)
                    dp[i][j] = fmin(dp[i][j], dp[i - 1][j] + 1);
                if (j > 0)
                    dp[i][j] = fmin(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (dp[i][j] != 0 && dp[i][j] != 1)
            {
                if (i < m - 1)
                    dp[i][j] = fmin(dp[i][j], dp[i + 1][j] + 1);
                if (j < n - 1)
                    dp[i][j] = fmin(dp[i][j], dp[i][j + 1] + 1);
            }
        }
    }
    return dp;
}
// @lc code=end

// Note: DP . BFS