/*
 * @lc app=leetcode id=867 lang=c
 *
 * [867] Transpose Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **transpose(int **matrix, int matrixSize, int *matrixColSize, int *returnSize, int **returnColumnSizes)
{
    int m = matrixColSize[0];
    int n = matrixSize;
    *returnSize = m;
    returnColumnSizes[0] = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        returnColumnSizes[0][i] = n;

    int **ans = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        ans[i] = malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            ans[i][j] = matrix[j][i];
    }
    return ans;
}
// @lc code=end

// Note: matrix