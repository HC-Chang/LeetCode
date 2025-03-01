/*
 * @lc app=leetcode id=2460 lang=c
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *applyOperations(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    int idx = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
            nums[idx++] = nums[i];
    }

    memset(nums + idx, 0, (numsSize - idx) * sizeof(int));
    return nums;
}
// @lc code=end

// Note: two pointers