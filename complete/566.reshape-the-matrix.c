/*
 * @lc app=leetcode id=566 lang=c
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c, int *returnSize, int **returnColumnSizes)
{
    if (matSize * matColSize[0] != r * c)
    {
        *returnSize = matSize;
        returnColumnSizes[0] = matColSize;
        return mat;
    }

    int *arr = malloc(matSize * matColSize[0] * sizeof(int));
    int index = 0;
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matColSize[0]; j++)
            arr[index++] = mat[i][j];
    }

    int new_c;
    int new_r;
    if (r > c)
    {
        new_c = c;
        new_r = (index - 1) / new_c + 1;
    }
    else
    {
        new_r = r;
        new_c = (index - 1) / new_r + 1;
    }
    *returnSize = new_r;
    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < new_r; i++)
        returnColumnSizes[0][i] = new_c;

    index = 0;
    int **r_mat = malloc(new_r * sizeof(int *));
    for (int i = 0; i < new_r; i++)
    {
        r_mat[i] = malloc(new_c * sizeof(int));
        for (int j = 0; j < new_c; j++)
            r_mat[i][j] = arr[index++];
    }
    return r_mat;
}
// @lc code=end
