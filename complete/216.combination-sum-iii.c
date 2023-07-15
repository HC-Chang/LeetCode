/*
 * @lc app=leetcode id=216 lang=c
 *
 * [216] Combination Sum III
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

void dfs(int i, int t, int k, int *arr_index, int *arr, int *arrs_index, int *arrs)
{
    int d = k - *arr_index;
    if (t < 0 || t > (i * 2 - d + 1) * d)
        return;
    if (*arr_index == k)
    {
        push_arrs(arr_index, arr, arrs_index, arrs);
        return;
    }
    for (int j = i; j > d - 1; j--)
    {
        push_arr(j, arr_index, arr);
        dfs(j - 1, t - j, k, arr_index, arr, arrs_index, arrs);
        pop_arr(arr_index);
    }
}

int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int *arr = calloc(k, sizeof(int));
    int arr_index = 0;
    int **arrs = malloc(20 * sizeof(int *));

    dfs(9, n, k, &arr_index, arr, returnSize, arrs);

    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        returnColumnSizes[0][i] = k;

    arrs = realloc(arrs, *returnSize * sizeof(int *));
    free(arr);
    return arrs;
}
// @lc code=end

// Note: backtracking