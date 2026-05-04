/*
 * @lc app=leetcode id=48 lang=c
 *
 * [48] Rotate Image
 */

// @lc code=start
void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int v[matrixSize * matrixSize];
    memset(v, 0, sizeof(v));
    int idx = 0;
    for (int j = 0; j < matrixSize; j++)
    {
        for (int i = matrixSize - 1; i >= 0; i--)
            v[idx++] = matrix[i][j];
    }
    idx = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = v[idx++];
        }
    }
}
// @lc code=end

// Note: math + matrix