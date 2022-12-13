/*
 * @lc app=leetcode id=931 lang=c
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
int min_matrix(int **matrix, int i, int j, int size)
{
    if (i - 1 < 0)
        return matrix[i][j];
    int min = matrix[i - 1][j];
    if (j - 1 >= 0)
        min = min < matrix[i - 1][j - 1] ? min : matrix[i - 1][j - 1];
    if (j + 1 < size)
        min = min < matrix[i - 1][j + 1] ? min : matrix[i - 1][j + 1];
    return min;
}
int minFallingPathSum(int **matrix, int matrixSize, int *matrixColSize)
{
    int **dp = calloc(matrixSize, sizeof(int *));
    for (int i = 0; i < matrixSize; i++)
        dp[i] = calloc(matrixSize, sizeof(int));
    for (int i = 0; i < matrixSize; i++)
        dp[0][i] = matrix[0][i];

    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
            dp[i][j] = matrix[i][j] + min_matrix(dp, i, j, matrixSize);
    }

    int min = dp[matrixSize - 1][0];
    for (int i = 1; i < matrixSize; i++)
    {
        if (dp[matrixSize - 1][i] < min)
            min = dp[matrixSize - 1][i];
    }
    return min;
}
// @lc code=end
