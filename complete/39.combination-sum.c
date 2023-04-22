/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combine(int *arr, int arr_size, int *tmp, int tmp_size, int cur_index, int ***ret, int *returnSize, int **returnColumnSizes, int target)
{
    if (target < 0)
        return;

    if (target == 0)
    {
        *ret = realloc(*ret, sizeof(int *) * (*returnSize + 1));
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        (*ret)[*returnSize] = malloc(sizeof(int) * tmp_size);
        (*returnColumnSizes)[*returnSize] = tmp_size;
        memcpy((*ret)[(*returnSize)++], tmp, sizeof(int) * tmp_size);
        return;
    }

    for (int i = cur_index; i < arr_size; i++)
    {
        tmp[tmp_size] = arr[i];
        combine(arr, arr_size, tmp, tmp_size + 1, i, ret, returnSize, returnColumnSizes, target - arr[i]);
    }
}

int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), sort);
    int max_size = target / candidates[0] + 1;
    int *tmp_arr = malloc(sizeof(int) * max_size);
    int **r = malloc(sizeof(int *));
    *returnColumnSizes = malloc(sizeof(int));
    *returnSize = 0;
    combine(candidates, candidatesSize, tmp_arr, 0, 0, &r, returnSize, returnColumnSizes, target);

    free(tmp_arr);
    return r;
}
// @lc code=end

// Note: backtracking