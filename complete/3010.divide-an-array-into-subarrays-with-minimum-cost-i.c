/*
 * @lc app=leetcode id=3010 lang=c
 *
 * [3010] Divide an Array Into Subarrays With Minimum Cost I
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int minimumCost(int *nums, int numsSize)
{
    qsort(nums + 1, numsSize - 1, sizeof(int), sort);
    for (int i = 0; i < 2; i++)
        nums[0] += nums[i + 1];

    return nums[0];
}
// @lc code=end

// Note: sorting