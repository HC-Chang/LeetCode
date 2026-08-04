/*
 * @lc app=leetcode id=3731 lang=c
 *
 * [3731] Find Missing Elements
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int *findMissingElements(int *nums, int numsSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), sort);

    int *ans = malloc(100 * sizeof(int));
    *returnSize = 0;
    for (int i = 1; i < numsSize; i++)
    {
        int tmp = nums[i - 1];
        while (nums[i] - tmp != 1)
            ans[(*returnSize)++] = ++tmp;
    }

    return ans;
}
// @lc code=end

// Note: sorting