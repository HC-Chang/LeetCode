/*
 * @lc app=leetcode id=417 lang=c
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void DFS(int i, int j, int **matrix, int **visited, int heightsSize, int *heightsColSize)
{

    int x_dir[4] = {-1, 0, 1, 0};
    int y_dir[4] = {0, 1, 0, -1};
    int m, n;
    for (int k = 0; k < 4; k++)
    {
        visited[i][j] = 1;
        m = i + x_dir[k];
        n = j + y_dir[k];

        if (m < 0 || m == heightsSize || n < 0 || n == heightsColSize[0])
            continue;
        if (visited[m][n] == 1)
            continue;
        if (matrix[m][n] < matrix[i][j])
            continue;

        DFS(m, n, matrix, visited, heightsSize, heightsColSize);
    }
}

void push_arr(int i, int j, int *index, int **column_sizes, int ***arr)
{
    arr[0] = realloc(arr[0], ((*index) + 1) * sizeof(int *));
    column_sizes[0] = realloc(column_sizes[0], ((*index) + 1) * sizeof(int));
    arr[0][*index] = malloc(2 * sizeof(int));

    column_sizes[0][*index] = 2;
    arr[0][*index][0] = i;
    arr[0][*index][1] = j;
    ++(*index);
}

int **pacificAtlantic(int **heights, int heightsSize, int *heightsColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int M = heightsSize;
    if (heightsSize == 0)
        return NULL;

    int **pac = malloc(heightsSize * sizeof(int *));
    int **atl = malloc(heightsSize * sizeof(int *));
    for (int i = 0; i < heightsSize; i++)
    {
        pac[i] = calloc(heightsColSize[0], sizeof(int));
        atl[i] = calloc(heightsColSize[0], sizeof(int));
    }

    for (int j = 0; j < heightsColSize[0]; j++)
        DFS(0, j, heights, pac, heightsSize, heightsColSize);
    for (int i = 1; i < heightsSize; i++)
        DFS(i, 0, heights, pac, heightsSize, heightsColSize);
    for (int j = 0; j < heightsColSize[0]; j++)
        DFS(M - 1, j, heights, atl, heightsSize, heightsColSize);
    for (int i = 0; i < heightsSize - 1; i++)
        DFS(i, heightsColSize[0] - 1, heights, atl, heightsSize, heightsColSize);

    int **r = malloc(sizeof(int *));
    returnColumnSizes[0] = malloc(sizeof(int));
    for (int i = 0; i < heightsSize; i++)
    {
        for (int j = 0; j < heightsColSize[0]; j++)
        {
            if (atl[i][j] == 1 && pac[i][j] == 1)
                push_arr(i, j, returnSize, returnColumnSizes, &r);
        }
    }
    return r;
}
// @lc code=end
