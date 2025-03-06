/*
 * @lc app=leetcode id=2965 lang=c
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findMissingAndRepeatedValues(int **grid, int gridSize, int *gridColSize, int *returnSize)
{
    *returnSize = 2;
    int n = gridSize * gridSize;
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    int *ans = malloc(2 * sizeof(int));
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            if (++arr[grid[i][j]] == 2)
                ans[0] = grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            ans[1] = i;
            break;
        }
    }
    return ans;
}
// @lc code=end

// Note: hash table