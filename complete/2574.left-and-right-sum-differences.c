/*
 * @lc app=leetcode id=2574 lang=c
 *
 * [2574] Left and Right Sum Differences
 */

// Difficulty:Easy

// Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

// answer.length == nums.length.
// answer[i] = |leftSum[i] - rightSum[i]|.
// Where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return the array answer.

// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 100000

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *leftRigthDifference(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    if (numsSize == 1)
    {
        nums[0] = 0;
        return nums;
    }
    int *l_sum = calloc(numsSize, sizeof(int));
    int *r_sum = calloc(numsSize, sizeof(int));
    l_sum[1] = nums[0];
    for (int i = 2; i < numsSize; i++)
        l_sum[i] = l_sum[i - 1] + nums[i - 1];

    for (int i = 1; i < numsSize; i++)
        r_sum[0] += nums[i];
    for (int i = 1; i < numsSize - 1; i++)
        r_sum[i] = r_sum[i - 1] - nums[i];

    for (int i = 0; i < numsSize; i++)
        l_sum[i] = abs(l_sum[i] - r_sum[i]);
    free(r_sum);

    return l_sum;
}

// @lc code=end