/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    *returnSize = numRows;
    int **r = calloc(numRows, sizeof(int *));
    returnColumnSizes[0] = calloc(numRows, sizeof(int *));
    for (int i = 0; i < numRows; i++)
    {
        returnColumnSizes[0][i] = i + 1;
        r[i] = calloc(i + 1, sizeof(int));

        if (i < 2)
        {
            for (int j = 0; j < i + 1; j++)
            {
                r[i][j] = 1;
            }
        }
        else
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    r[i][j] = 1;
                }
                else
                {
                    r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
                }
            }
        }
    }

    return r;
}
// @lc code=end
