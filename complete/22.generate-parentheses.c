/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void push_arr(char c, int i, int *arr_index, char *arr)
{
    arr[i] = c;
    *arr_index = i + 1;
}

void push_arrs(int *arr_index, char *arr, int *arrs_index, char **arrs)
{
    char *tmp = malloc((*arr_index + 1) * sizeof(char));
    memcpy(tmp, arr, ((*arr_index) + 1) * sizeof(char));
    arrs[(*arrs_index)++] = tmp;
}

void dfs(int i, int open, int n, int *arr_index, char *arr, int *arrs_index, char **arrs)
{
    if (i == n * 2)
    {
        arr[*arr_index] = 0;
        push_arrs(arr_index, arr, arrs_index, arrs);
        return;
    }
    if (open < n)
    {
        push_arr('(', i, arr_index, arr);
        dfs(i + 1, open + 1, n, arr_index, arr, arrs_index, arrs);
    }
    if (i - open < open)
    {
        push_arr(')', i, arr_index, arr);
        dfs(i + 1, open, n, arr_index, arr, arrs_index, arrs);
    }
}
char **generateParenthesis(int n, int *returnSize)
{
    char *arr = calloc(n * 2 + 1, sizeof(char));
    int arr_index = 0;
    *returnSize = 0;
    char **arrs = malloc(2000 * sizeof(char *));

    dfs(0, 0, n, &arr_index, arr, returnSize, arrs);

    arrs = realloc(arrs, *returnSize * sizeof(char *));
    free(arr);
    return arrs;
}
// @lc code=end

// Note: backtracking