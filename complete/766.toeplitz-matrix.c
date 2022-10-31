/*
 * @lc app=leetcode id=766 lang=c
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
bool isToeplitzMatrix(int **matrix, int matrixSize, int *matrixColSize)
{
    for (int i = 1; i < matrixSize; i++)
        for (int j = 1; j < matrixColSize[0]; j++)
            if (matrix[i][j] != matrix[i - 1][j - 1])
                return false;
    return true;
}
// @lc code=end
// 判斷斜對角是否相同