/*
 * @lc app=leetcode id=2373 lang=c
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes)
{
    int n = gridSize - 2;
    *returnSize = n;
    returnColumnSizes[0] = malloc(n * sizeof(int));

    int **ans = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        ans[i] = malloc(n * sizeof(int));
        returnColumnSizes[0][i] = n;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int x = i; x <= i + 2; ++x)
            {
                for (int y = j; y <= j + 2; ++y)
                    ans[i][j] = fmax(ans[i][j], grid[x][y]);
            }
        }
    }

    return ans;
}
// @lc code=end

// Note: matrix
