/*
 * @lc app=leetcode id=3379 lang=c
 *
 * [3379] Transformed Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *constructTransformedArray(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *ans = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
        ans[i] = nums[(i + nums[i] % numsSize + numsSize) % numsSize];
    return ans;
}
// @lc code=end
