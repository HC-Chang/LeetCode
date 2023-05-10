/*
 * @lc app=leetcode id=59 lang=c
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    *returnSize = n;
    returnColumnSizes[0] = malloc(n * sizeof(int));
    int **arr = malloc(n * sizeof(int *));
    int **visited = malloc(n * sizeof(int *));
    for (int k = 0; k < n; k++)
    {
        returnColumnSizes[0][k] = n;
        arr[k] = malloc(n * sizeof(int));
        visited[k] = calloc(n, sizeof(int));
    }

    int index_offset = 0;
    int x_offset[4] = {0, 1, 0, -1};
    int y_offset[4] = {1, 0, -1, 0};
    int tmp_x = 0, tmp_y = -1;
    for (int k = 1; k <= n * n; k++)
    {
        tmp_x += x_offset[index_offset];
        tmp_y += y_offset[index_offset];
        while (tmp_x < 0 || tmp_x >= n || tmp_y < 0 || tmp_y >= n || visited[tmp_x][tmp_y])
        {
            tmp_x -= x_offset[index_offset];
            tmp_y -= y_offset[index_offset];
            index_offset = (index_offset + 1) % 4;
            tmp_x += x_offset[index_offset];
            tmp_y += y_offset[index_offset];
        }
        arr[tmp_x][tmp_y] = k;
        visited[tmp_x][tmp_y] = 1;
    }

    for (int k = 0; k < n; k++)
        free(visited[k]);
    free(visited);
    return arr;
}

// @lc code=end
