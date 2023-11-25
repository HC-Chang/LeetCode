/*
 * @lc app=leetcode id=1685 lang=c
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getSumAbsoluteDifferences(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *arr = calloc((*returnSize), sizeof(int));

    for (int i = 1, sum = 0; i < numsSize; ++i)
        arr[i] += (sum += (nums[i] - nums[i - 1]) * i);
    for (int i = numsSize - 2, sum = 0; i >= 0; --i)
        arr[i] += (sum += (nums[i + 1] - nums[i]) * (numsSize - i - 1));

    return arr;
}
// @lc code=end

// Note: prefix sum
