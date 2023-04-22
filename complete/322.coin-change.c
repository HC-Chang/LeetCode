/*
 * @lc app=leetcode id=322 lang=c
 *
 * [322] Coin Change
 */

// @lc code=start
// Solution: DP
int coinChange(int *coins, int coinsSize, int amount)
{
    int tmp, min_count;
    int *dp = malloc((amount + 1) * sizeof(int));
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        min_count = -1;
        for (int j = 0; j < coinsSize; j++)
        {
            if (i >= coins[j])
            {
                tmp = i - coins[j];
                if (dp[tmp] == -1)
                    continue;
                if (min_count == -1 || min_count > dp[tmp] + 1)
                    min_count = dp[tmp] + 1;
            }
        }
        dp[i] = min_count;
    }
    min_count = dp[amount];

    free(dp);
    return min_count;
}
// @lc code=end

// Note: DP/BFS