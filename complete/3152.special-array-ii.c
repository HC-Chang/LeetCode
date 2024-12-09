/*
 * @lc app=leetcode id=3152 lang=c
 *
 * [3152] Special Array II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *isArraySpecial(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    *returnSize = queriesSize;

    int arr[numsSize];

    int end = 0;

    for (int start = 0; start < numsSize; start++)
    {
        end = fmax(end, start);
        while (end < numsSize - 1 && nums[end] % 2 != nums[end + 1] % 2)
            ++end;

        arr[start] = end;
    }

    bool *ans = malloc((*returnSize) * sizeof(bool));

    for (int i = 0; i < queriesSize; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];

        ans[i] = end <= arr[start];
    }

    return ans;
}
// @lc code=end

// Note: prefix sum

// Official Solution