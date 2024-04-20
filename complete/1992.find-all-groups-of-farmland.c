/*
 * @lc app=leetcode id=1992 lang=c
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void bfs(int i, int j, int **ans, int *ans_size, int m, int n,
         int **land)
{
    int *tmp = malloc(4 * sizeof(int));
    tmp[0] = i;
    tmp[1] = j;
    int ii = i;
    int jj = j;
    while (ii + 1 < m && land[ii + 1][j] == 1)
        ii++;
    while (jj + 1 < n && land[i][jj + 1] == 1)
        jj++;

    land[i][j] = 0;
    for (int x = i; x <= ii; x++)
    {
        for (int y = j; y <= jj; y++)
            land[x][y] = 0;
    }
    tmp[2] = ii;
    tmp[3] = jj;
    ans[(*ans_size)++] = tmp;
}
int **findFarmland(int **land, int landSize, int *landColSize, int *returnSize,
                   int **returnColumnSizes)
{
    int m = landSize;
    int n = landColSize[0];
    int **ans = malloc((m * n + 1) / 2 * sizeof(int *));
    *returnSize = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (land[i][j])
                bfs(i, j, ans, returnSize, m, n, land);
        }
    }

    returnColumnSizes[0] = malloc(*returnSize * sizeof(int *));
    for (int i = 0; i < *returnSize; i++)
        returnColumnSizes[0][i] = 4;
    return ans;
}

// @lc code=end

// Note: DFS / BFS + matrix