/*
 * @lc app=leetcode id=322 lang=c
 *
 * [322] Coin Change
 */

// @lc code=start
// Solution: DP
int min(int a, int b) { return a < b ? a : b; }
int coinChange(int *coins, int coinsSize, int amount)
{
    int *dp = malloc((amount + 1) * sizeof(int));
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++)
        dp[i] = amount + 1;

    for (int i = 0; i <= amount; i++)
    {
        for (int j = 0; j < coinsSize; j++)
        {
            if (i < coins[j])
                continue;
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    int min_count = (dp[amount] == amount + 1) ? -1 : dp[amount];

    free(dp);
    return min_count;
}
// @lc code=end

// Note: DP/BFS