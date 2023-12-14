/*
 * @lc app=leetcode id=2482 lang=c
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **onesMinusZeros(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes)
{
    int m = gridSize;
    int n = gridColSize[0];
    *returnSize = m;
    returnColumnSizes[0] = gridColSize;

    int x_arr[m];
    int y_arr[n];
    memset(x_arr, 0, sizeof(x_arr));
    memset(y_arr, 0, sizeof(y_arr));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ++x_arr[i];
                ++y_arr[j];
            }
        }
    }

    int **ans = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        ans[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            ans[i][j] = 2 * x_arr[i] - m + 2 * y_arr[j] - n;
    }
    return ans;
}
// @lc code=end
