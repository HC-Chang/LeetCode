/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
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

void dfs(int *nums, int s_len, int *visited, int *arr_index, int *arr, int *arrs_index, int **arrs)
{
    if (*arr_index == s_len)
    {
        push_arrs(arr_index, arr, arrs_index, arrs);
        return;
    }
    for (int j = 0; j < s_len; j++)
    {
        if (visited[j] == 1)
            continue;
        visited[j] = 1;
        arr[(*arr_index)++] = nums[j];
        dfs(nums, s_len, visited, arr_index, arr, arrs_index, arrs);
        (*arr_index)--;
        visited[j] = 0;
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int *visited = calloc(numsSize, sizeof(int));
    int arr_index = 0;
    int *arr = calloc(numsSize, sizeof(int));

    int arrs_count = 1;
    for (int i = 2; i <= numsSize; i++)
        arrs_count *= i;
    int **arrs = malloc(arrs_count * sizeof(int *));
    dfs(nums, numsSize, visited, &arr_index, arr, returnSize, arrs);

    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        returnColumnSizes[0][i] = numsSize;

    return arrs;
}
// @lc code=end

// Note: backtracking