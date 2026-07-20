/*
 * @lc app=leetcode id=1260 lang=c
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **shiftGrid(int **grid, int gridSize, int *gridColSize, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = gridSize;
    returnColumnSizes[0] = gridColSize;
    int size = gridSize * gridColSize[0];
    int *v = malloc(size * sizeof(int));
    int idx = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
            v[idx++] = grid[i][j];
    }

    idx = -k % size;
    while (idx < 0)
        idx += size;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (idx == size)
                idx = 0;
            grid[i][j] = v[idx++];
        }
    }
    free(v);
    return grid;
}
// @lc code=end

// Note: matrix