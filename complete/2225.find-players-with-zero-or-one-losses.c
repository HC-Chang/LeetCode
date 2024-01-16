/*
 * @lc app=leetcode id=2225 lang=c
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void push_arr(int val, int *arr, int *idx)
{
    arr[(*idx)++] = val;
}
int **findWinners(int **matches, int matchesSize, int *matchesColSize, int *returnSize, int **returnColumnSizes)
{
    int hash[100001];
    for (int i = 0; i < 100001; i++)
        hash[i] = -1;
    for (int i = 0; i < matchesSize; i++)
    {
        if (hash[matches[i][0]] == -1)
            hash[matches[i][0]] = 0;
        if (hash[matches[i][1]] == -1)
            hash[matches[i][1]] = 0;
        ++hash[matches[i][1]];
    }

    int **ans = malloc(2 * sizeof(int *));
    ans[0] = malloc(100001 * sizeof(int));
    ans[1] = malloc(100001 * sizeof(int));
    *returnSize = 2;
    returnColumnSizes[0] = calloc(2, sizeof(int));
    for (int i = 0; i < 100001; i++)
    {
        if (hash[i] > -1 && hash[i] < 2)
            push_arr(i, ans[hash[i]], &returnColumnSizes[0][hash[i]]);
    }

    return ans;
}
// @lc code=end

// Note: hash table + sorting