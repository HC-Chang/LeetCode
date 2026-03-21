/*
 * @lc app=leetcode id=3643 lang=c
 *
 * [3643] Flip Square Submatrix Vertically
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int **reverseSubmatrix(int **grid, int gridSize, int *gridColSize, int x, int y,
                       int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    int cnt = k / 2;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < k; j++)
            swap(&grid[x + i][y + j], &grid[x + k - 1 - i][y + j]);
    }
    return grid;
}
// @lc code=end

// Note: matrix