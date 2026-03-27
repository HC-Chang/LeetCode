/*
 * @lc app=leetcode id=2946 lang=c
 *
 * [2946] Matrix Similarity After Cyclic Shifts
 */

// @lc code=start
bool areSimilar(int **mat, int matSize, int *matColSize, int k)
{
    int flag = -1;
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < *matColSize; j++)
        {
            flag *= -1;
            if (mat[i][(j + flag * k % *matColSize + *matColSize) % *matColSize] != mat[i][j])
                return false;
        }
    }

    return true;
}
// @lc code=end
