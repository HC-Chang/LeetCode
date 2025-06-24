/*
 * @lc app=leetcode id=2200 lang=c
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findKDistantIndices(int *nums, int numsSize, int key, int k, int *returnSize)
{
    *returnSize = 0;
    int *ans = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == key)
        {
            for (int j = i - k; j <= i + k; j++)
            {
                if (j < 0 || j >= numsSize)
                    continue;
                if (*returnSize == 0 || j > ans[(*returnSize) - 1])
                    ans[(*returnSize)++] = j;
            }
        }
    }
    return ans;
}
// @lc code=end

// Note: two pointers