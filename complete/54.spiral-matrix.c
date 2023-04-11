/*
 * @lc app=leetcode id=54 lang=c
 *
 * [54] Spiral Matrix
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    *returnSize = matrixSize * matrixColSize[0];
    int *arr = malloc(matrixSize * matrixColSize[0] * sizeof(int));
    int index = 0;
    int i = 0, j = 0;
    while (1)
    {
        if (index == *returnSize)
            break;
        while (j < matrixColSize[0])
        {
            if (matrix[i][j] == 101)
                break;
            arr[index++] = matrix[i][j];
            matrix[i][j] = 101;
            j++;
        }
        j--;
        i++;
        while (i < matrixSize)
        {
            if (matrix[i][j] == 101)
                break;
            arr[index++] = matrix[i][j];
            matrix[i][j] = 101;
            i++;
        }
        i--;
        j--;
        while (j >= 0)
        {
            if (matrix[i][j] == 101)
                break;
            arr[index++] = matrix[i][j];
            matrix[i][j] = 101;
            j--;
        }
        j++;
        i--;
        while (i >= 0)
        {
            if (matrix[i][j] == 101)
                break;
            arr[index++] = matrix[i][j];
            matrix[i][j] = 101;
            i--;
        }
        i++;
        j++;
    }
    return arr;
}
// @lc code=end
