/*
 * @lc app=leetcode id=1572 lang=c
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
int diagonalSum(int **mat, int matSize, int *matColSize)
{
    int sum = 0;
    for (int i = 0; i < matSize / 2; i++)
        sum += mat[i][i] + mat[i][matSize - 1 - i] + mat[matSize - 1 - i][i] + mat[matSize - 1 - i][matSize - 1 - i];
    if (matSize % 2 == 1)
        sum += mat[matSize / 2][matSize / 2];

    return sum;
}
// @lc code=end
