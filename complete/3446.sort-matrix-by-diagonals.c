/*
 * @lc app=leetcode id=3446 lang=c
 *
 * [3446] Sort Matrix by Diagonals
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int sort1(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int sort2(const void *a, const void *b) { return *(int *)b - *(int *)a; }

void sort_arr(int i, int j, int m, int n, int decrease, int **grid, int *buf)
{
    int k = i;
    int l = j;
    int idx = 0;
    while (k < m && l < n)
        buf[idx++] = grid[k++][l++];
    if (decrease)
        qsort(buf, idx, sizeof(int), sort2);
    else
        qsort(buf, idx, sizeof(int), sort1);
    idx = 0;
    while (i < m && j < n)
        grid[i++][j++] = buf[idx++];
}

int **sortMatrix(int **grid, int gridSize, int *gridColSize, int *returnSize,
                 int **returnColumnSizes)
{
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    int *buf = malloc(fmax(gridSize, gridColSize[0]) * sizeof(int));
    for (int i = gridSize - 1; i >= 0; i--)
        sort_arr(i, 0, gridSize, gridColSize[0], 1, grid, buf);

    for (int i = 1; i < gridColSize[0]; i++)
        sort_arr(0, i, gridSize, gridColSize[0], 0, grid, buf);
    free(buf);
    return grid;
}
// @lc code=end

// Note: sorting + matrix
