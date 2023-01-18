/*
 * @lc app=leetcode id=918 lang=c
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
#define max(a, b) a > b ? a : b

int maxSubarraySumCircular(int *nums, int numsSize)
{
    int *left = calloc(numsSize, sizeof(int));
    int sum = 0, maxsum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
            left[i] = sum = maxsum = nums[i];
        else
        {
            sum = max(sum + nums[i], nums[i]);
            maxsum = max(maxsum, sum);
            left[i] = left[i - 1] + nums[i];
        }
    }

    for (int i = 1; i < numsSize; i++)
        left[i] = max(left[i - 1], left[i]);

    int *right = calloc(numsSize, sizeof(int));

    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (i == numsSize - 1)
            right[i] = nums[i];

        else
            right[i] = right[i + 1] + nums[i];
    }
    for (int i = numsSize - 2; i >= 0; i--)
        right[i] = max(right[i], right[i + 1]);

    for (int i = 0; i < numsSize - 1; i++)
        maxsum = max(maxsum, left[i] + right[i + 1]);

    return maxsum;
}
// @lc code=end

// DP
