/*
 * @lc app=leetcode id=3727 lang=c
 *
 * [3727] Maximum Alternating Sum of Squares
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
long long maxAlternatingSum(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
            nums[i] *= -1;
    }
    qsort(nums, numsSize, sizeof(int), sort);
    long long sum = 0;
    for (int i = 0; i < numsSize / 2; i++)
        sum -= nums[i] * nums[i];
    for (int i = numsSize / 2; i < numsSize; i++)
        sum += nums[i] * nums[i];
    return sum;
}
// @lc code=end

// Note: sorting