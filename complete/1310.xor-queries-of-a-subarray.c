/*
 * @lc app=leetcode id=1310 lang=c
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *xorQueries(int *arr, int arrSize, int **queries, int queriesSize,
                int *queriesColSize, int *returnSize)
{
    int prefix[arrSize];
    prefix[0] = arr[0];
    for (int i = 1; i < arrSize; i++)
        prefix[i] = prefix[i - 1] ^ arr[i];

    int *ans = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++)
    {
        if (queries[i][0] == queries[i][1])
            ans[i] = arr[queries[i][0]];
        else if (queries[i][0] == 0)
            ans[i] = prefix[queries[i][1]];
        else
            ans[i] = prefix[queries[i][1]] ^ prefix[queries[i][0] - 1];
    }
    return ans;
}
// @lc code=end

// Note: bit manipulation + prefix sum