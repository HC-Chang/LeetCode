/*
 * @lc app=leetcode id=2971 lang=c
 *
 * [2971] Find Polygon With the Largest Perimeter
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
long long largestPerimeter(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);

    long long preifx_sum = 0;
    for (int i = 0; i < numsSize; i++)
        preifx_sum += nums[i];

    for (int i = numsSize - 1; i >= 2; i--)
    {
        preifx_sum -= nums[i];
        if (preifx_sum > nums[i])
            return preifx_sum + nums[i];
    }

    return -1;
}
// @lc code=end

// Note: sorting + prefix sum + greedy