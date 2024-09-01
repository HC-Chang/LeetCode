/*
 * @lc app=leetcode id=2022 lang=c
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **construct2DArray(int *original, int originalSize, int m, int n, int *returnSize, int **returnColumnSizes)
{
    if (originalSize != m * n)
    {
        *returnSize = 0;
        return NULL;
    }

    int **arr = malloc(m * sizeof(int *));
    *returnSize = m;
    returnColumnSizes[0] = malloc(m * sizeof(int));
    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        arr[i] = malloc(n * sizeof(int));
        returnColumnSizes[0][i] = n;
        for (int j = 0; j < n; j++)
            arr[i][j] = original[idx++];
    }
    return arr;
}
// @lc code=end

// Note: array . matrix