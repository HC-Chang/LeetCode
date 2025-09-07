/*
 * @lc app=leetcode id=1304 lang=c
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumZero(int n, int *returnSize)
{
    int *ans = malloc(n * sizeof(int));
    *returnSize = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        ans[(*returnSize)++] = i;
        ans[(*returnSize)++] = -i;
    }
    if (n % 2 == 1)
        ans[(*returnSize)++] = 0;
    return ans;
}
// @lc code=end

// Note: math