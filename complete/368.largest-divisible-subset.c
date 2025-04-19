/*
 * @lc app=leetcode id=368 lang=c
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int *largestDivisibleSubset(int *nums, int numsSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), sort);

    int n = numsSize;
    int cnt = INT_MIN;
    int val = nums[0];
    int idx = 0;
    int dp[n];
    int path[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] % nums[j] == 0)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
        }
        if (dp[i] > cnt)
        {
            cnt = dp[i];
            val = nums[i];
            idx = i;
        }
    }

    *returnSize = cnt;
    int *r = malloc(*returnSize * sizeof(int));
    r[cnt - 1] = val;
    for (int i = cnt - 2; i >= 0; i--)
    {
        r[i] = nums[path[idx]];
        idx = path[idx];
    }

    return r;
}
// @lc code=end

// Note: DP + sorting