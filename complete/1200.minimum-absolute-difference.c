/*
 * @lc app=leetcode id=1200 lang=c
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    qsort(arr, arrSize, sizeof(int), sort);

    int min_val = INT_MAX;
    int **ans = malloc((arrSize - 1) * sizeof(int *));
    returnColumnSizes[0] = malloc((arrSize - 1) * sizeof(int));
    for (int i = 0; i < arrSize - 1; i++)
    {
        ans[i] = malloc(2 * sizeof(int));
        returnColumnSizes[0][i] = 2;
    }

    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] - arr[i - 1] < min_val)
        {
            *returnSize = 0;
            min_val = arr[i] - arr[i - 1];
            ans[*returnSize][0] = arr[i - 1];
            ans[(*returnSize)++][1] = arr[i];
        }
        else if (arr[i] - arr[i - 1] == min_val)
        {
            ans[*returnSize][0] = arr[i - 1];
            ans[(*returnSize)++][1] = arr[i];
        }
    }

    return ans;
}
// @lc code=end

// Note: sorting