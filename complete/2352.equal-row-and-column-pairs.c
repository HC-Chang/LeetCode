/*
 * @lc app=leetcode id=2352 lang=c
 *
 * [2352] Equal Row and Column Pairs

 */

// @lc code=start
unsigned long hash_row(int *arr, int count)
{
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 4) + hash) + arr[i];
    return hash;
}
unsigned long hash_col(int index, int **grid, int count)
{
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 4) + hash) + grid[i][index];
    return hash;
}

int equalPairs(int **grid, int gridSize, int *gridColSize)
{
    unsigned long *hash_rows = malloc(gridSize * sizeof(unsigned long));
    unsigned long *hash_cols = malloc(gridColSize[0] * sizeof(unsigned long));
    for (int i = 0; i < gridSize; i++)
        hash_rows[i] = hash_row(grid[i], gridColSize[0]);
    for (int i = 0; i < gridSize; i++)
        hash_cols[i] = hash_col(i, grid, gridSize);

    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (hash_rows[i] == hash_cols[j])
                count++;
        }
    }
    
    free(hash_rows);
    free(hash_cols);
    return count;
}
// @lc code=end

// Note: Topological Sort