/*
 * @lc app=leetcode id=2218 lang=c
 *
 * [2218] Maximum Value of K Coins From Piles
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int maxValueOfCoins(int **piles, int pilesSize, int *pilesColSize, int k)
{
    int dp[1002][2002] = {0};
    int **presum = malloc(pilesSize * sizeof(int *));
    int sum;
    for (int i = 0; i < pilesSize; i++)
    {
        presum[i] = calloc(pilesColSize[i] + 1, sizeof(int));
        sum = 0;
        presum[i][0] = sum;
        for (int j = 0; j < pilesColSize[i]; j++)
        {
            sum += piles[i][j];
            presum[i][j + 1] = sum;
        }
    }

    int r = 0;
    for (int i = 0; i < pilesSize; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int t = 0; t <= min(j, pilesColSize[i]); t++)
                dp[i][j] = max(dp[i][j], (i == 0 ? 0 : dp[i - 1][j - t]) + presum[i][t]);

            if (i == pilesSize - 1)
                r = max(r, dp[i][j]);
        }
    }
    for (int i = 0; i < pilesSize; i++)
        free(presum[i]);
    free(presum);
    return r;
}
// @lc code=end

// Note: DP + prefix sum