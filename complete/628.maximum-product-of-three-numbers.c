/*
 * @lc app=leetcode id=628 lang=c
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int maximumProduct(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);

    return fmax(nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3], nums[0] * nums[1] * fmax(nums[2], nums[numsSize - 1]));
}
// @lc code=end

// Note: sorting