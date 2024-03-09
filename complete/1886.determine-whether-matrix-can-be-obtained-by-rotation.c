/*
 * @lc app=leetcode id=1886 lang=c
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start
int tmp[10][10];

bool mat_cmp(int **mat, int **target, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] != target[i][j])
                return false;
        }
    }
    return true;
}

void rotate_90(int **mat, int matSize)
{
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matSize; j++)
            tmp[i][j] = mat[i][j];
    }

    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matSize; j++)
            mat[i][j] = tmp[matSize - j - 1][i];
    }
}

bool findRotation(int **mat, int matSize, int *matColSize, int **target, int targetSize, int *targetColSize)
{
    if (mat_cmp(mat, target, matSize))
        return true;
    for (int i = 0; i < 3; i++)
    {
        rotate_90(mat, matSize);
        if (mat_cmp(mat, target, matSize))
            return true;
    }
    return false;
}
// @lc code=end
