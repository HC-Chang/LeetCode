/*
 * @lc app=leetcode id=1470 lang=c
 *
 * [1470] Shuffle the Array
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shuffle(int *nums, int numsSize, int n, int *returnSize)
{
    *returnSize = numsSize;
    if (numsSize < 3)
        return nums;
    int *r = calloc(numsSize, sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        r[2 * i] = nums[i];
        r[2 * i + 1] = nums[n + i];
    }

    return r;
}
// @lc code=end
