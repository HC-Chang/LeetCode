/*
 * @lc app=leetcode id=1605 lang=c
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **restoreMatrix(int *rowSum, int rowSumSize, int *colSum, int colSumSize,
                    int *returnSize, int **returnColumnSizes)
{
    int n = rowSumSize;
    int m = colSumSize;

    int **origMatrix = malloc(n * sizeof(int *));
    *returnSize = n;
    returnColumnSizes[0] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        origMatrix[i] = calloc(m, sizeof(int));
        returnColumnSizes[0][i] = m;
    }

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        origMatrix[i][j] = fmin(rowSum[i], colSum[j]);

        rowSum[i] -= origMatrix[i][j];
        colSum[j] -= origMatrix[i][j];

        rowSum[i] == 0 ? i++ : j++;
    }
    return origMatrix;
}
// @lc code=end

// Note: greedy + matrix

// Official Solution