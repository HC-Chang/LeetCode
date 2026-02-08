/*
 * @lc app=leetcode id=3834 lang=c
 *
 * [3834] Merge Adjacent Equal Elements
 */

// @lc code=start
/**
 * Note: The returned numsay must be malloced, assume caller calls free().
 */
long long *mergeAdjacent(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 1;
    long long *arr = malloc(numsSize * sizeof(long long));
    arr[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        arr[(*returnSize)++] = nums[i];
        while ((*returnSize) > 1 && arr[(*returnSize) - 1] == arr[(*returnSize) - 2])
            arr[--(*returnSize) - 1] *= 2;
    }
    return arr;
}
// @lc code=end
