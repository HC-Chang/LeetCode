/*
 * @lc app=leetcode id=1582 lang=c
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
int numSpecial(int **mat, int matSize, int *matColSize)
{
    int m[matSize];
    int n[matColSize[0]];
    memset(m, 0, sizeof(m));
    memset(n, 0, sizeof(n));
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matColSize[i]; j++)
        {
            if (mat[i][j] == 1)
            {
                ++m[i];
                ++n[j];
            }
        }
    }
    int count = 0;
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matColSize[0]; j++)
        {
            if (mat[i][j] == 1 && m[i] == 1 && n[j] == 1)
                count++;
        }
    }

    return count;
}
// @lc code=end
