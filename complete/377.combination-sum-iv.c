/*
 * @lc app=leetcode id=377 lang=c
 *
 * [377] Combination Sum IV
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int combinationSum4(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), sort);

    unsigned int dp[target + 1];
    memset(dp, 0, (target + 1) * sizeof(unsigned int));
    dp[0] = 1;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i < nums[j])
                break;
            dp[i] += dp[i - nums[j]];
        }
    }
    return dp[target];
}
// @lc code=end

// Note: DP