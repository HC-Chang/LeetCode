/*
 * @lc app=leetcode id=1920 lang=c
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *buildArray(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *ans = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
        ans[i] = nums[nums[i]];
    return ans;
}
// @lc code=end
