/*
 * @lc app=leetcode id=561 lang=c
 *
 * [561] Sort an Array
 */
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int arrayPairSum(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int r = 0;
    for (int i = 0; i < (numsSize + 1 / 2); i += 2)
        r += nums[i];
    return r;
}
// @lc code=end
