/*
 * @lc app=leetcode id=885 lang=c
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void push_val(int i, int j, int *matrix_index, int rows, int cols, int **matrix)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        return;
    matrix[*matrix_index][0] = i;
    matrix[*matrix_index][1] = j;
    ++*matrix_index;
}

int **spiralMatrixIII(int rows, int cols, int rStart, int cStart, int *returnSize, int **returnColumnSizes)
{
    *returnSize = rows * cols;
    int **matrix = malloc(*returnSize * sizeof(int *));
    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        returnColumnSizes[0][i] = 2;
        matrix[i] = malloc(2 * sizeof(int));
    }

    int matrix_index = 0;
    push_val(rStart, cStart, &matrix_index, rows, cols, matrix);
    int d = 2;
    while (matrix_index < *returnSize)
    {
        push_val(rStart, ++cStart, &matrix_index, rows, cols, matrix);
        for (int i = 1; i < d; ++i)
            push_val(++rStart, cStart, &matrix_index, rows, cols, matrix);
        for (int i = 0; i < d; ++i)
            push_val(rStart, --cStart, &matrix_index, rows, cols, matrix);
        for (int i = 0; i < d; ++i)
            push_val(--rStart, cStart, &matrix_index, rows, cols, matrix);
        for (int i = 0; i < d; ++i)
            push_val(rStart, ++cStart, &matrix_index, rows, cols, matrix);
        d += 2;
    }

    return matrix;
}
// @lc code=end
