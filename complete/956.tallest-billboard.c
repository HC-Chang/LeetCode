/*
 * @lc app=leetcode id=956 lang=c
 *
 * [956] Tallest Billboard
 */

// @lc code=start
int tallestBillboard(int *rods, int rodsSize)
{
    int *dp = malloc(5001 * sizeof(int));
    int *cur = malloc(5001 * sizeof(int));
    dp[0] = 0;
    for (int i = 1; i < 5001; i++)
        dp[i] = INT_MIN;

    for (int i = 0; i < rodsSize; i++)
    {
        memcpy(cur, dp, 5001 * sizeof(int));
        for (int d = 0; d + rods[i] < 5001; ++d)
        {
            dp[d + rods[i]] = fmax(dp[d + rods[i]], cur[d]);
            dp[abs(d - rods[i])] = fmax(dp[abs(d - rods[i])], cur[d] + fmin(d, rods[i]));
        }
    }
    int r = dp[0];
    free(dp);
    free(cur);
    return r;
}
// @lc code=end
