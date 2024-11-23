/*
 * @lc app=leetcode id=1861 lang=c
 *
 * [1861] Rotating the Box
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char **rotateTheBox(char **box, int boxSize, int *boxColSize, int *returnSize, int **returnColumnSizes)
{
    int m = boxSize;
    int n = boxColSize[0];
    char **mat = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = malloc(m * sizeof(char));
        for (int j = 0; j < m; j++)
            mat[i][j] = box[m - 1 - j][i];
    }

    *returnSize = boxColSize[0];
    returnColumnSizes[0] = malloc(boxColSize[0] * sizeof(int));
    for (int i = 0; i < boxColSize[0]; i++)
        returnColumnSizes[0][i] = boxSize;

    m = *returnSize;
    n = returnColumnSizes[0][0];
    int bottom;

    for (int i = 0; i < n; i++)
    {
        bottom = m - 1;
        while (bottom > 0 && mat[bottom][i] != '.')
            bottom--;

        for (int j = bottom - 1; j >= 0; j--)
        {
            if (mat[j][i] == '#')
            {
                mat[j][i] = '.';
                mat[bottom--][i] = '#';
                while (bottom > 0 && mat[bottom][i] != '.')
                    bottom--;
            }
            else if (mat[j][i] == '*')
            {
                bottom = j - 1;
                while (bottom > 0 && mat[bottom][i] != '.')
                    bottom--;
                j = bottom;
            }
        }
    }
    return mat;
}
// @lc code=end

// Note: two pointers + matrix