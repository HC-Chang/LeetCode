/*
 * @lc app=leetcode id=2149 lang=c
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *rearrangeArray(int *nums, int numsSize, int *returnSize)
{
    int p_idx = 0;
    int n_idx = 1;
    int *idx;
    int *ans = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
            idx = &p_idx;
        else
            idx = &n_idx;

        ans[*idx] = nums[i];
        *idx += 2;
    }

    return ans;
}
// @lc code=end

// Note: two pointer