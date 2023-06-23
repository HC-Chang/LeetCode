/*
 * @lc app=leetcode id=1027 lang=c
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
int longestArithSeqLength(int *nums, int numsSize)
{
    int r = 0;
    int **dp = malloc(numsSize * sizeof(int *));
    for (int i = 0; i < numsSize; i++)
        dp[i] = calloc(1001, sizeof(int));
    int diff;
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            diff = nums[i] - nums[j] + 500;
            dp[i][diff] = dp[j][diff] + 1;
            if(dp[i][diff] > r)
                r = dp[i][diff];
        }
    }
    for (int i = 0; i < numsSize; i++)
        free(dp[i]);
    free(dp);

    return r + 1;
}
// @lc code=end
