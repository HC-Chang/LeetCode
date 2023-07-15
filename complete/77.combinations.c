/*
 * @lc app=leetcode id=77 lang=c
 *
 * [77] Combinations
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void push_arr(int val, int *arr_index, int *arr)
{
    arr[(*arr_index)++] = val;
}

void pop_arr(int *arr_index)
{
    --(*arr_index);
}

void push_arrs(int *arr_index, int *arr, int *arrs_index, int **arrs)
{
    int *tmp = malloc(*arr_index * sizeof(int));
    memcpy(tmp, arr, (*arr_index) * sizeof(int));

    arrs[(*arrs_index)++] = tmp;
}

void dfs(int i, int k, int *arr_index, int *arr, int *arrs_index, int **arrs)
{
    if (*arr_index == k)
    {
        push_arrs(arr_index, arr, arrs_index, arrs);
        return;
    }
    for (int j = i; j >= k - *arr_index; j--)
    {
        push_arr(j, arr_index, arr);
        dfs(j - 1, k, arr_index, arr, arrs_index, arrs);
        pop_arr(arr_index);
    }
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int *arr = calloc(k, sizeof(int));
    int arr_index = 0;
    int **arrs = malloc(5000 * sizeof(int *));

    dfs(n, k, &arr_index, arr, returnSize, arrs);

    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        returnColumnSizes[0][i] = k;

    arrs = realloc(arrs, *returnSize * sizeof(int *));
    free(arr);
    return arrs;
}
// @lc code=end

// Note: backtracking