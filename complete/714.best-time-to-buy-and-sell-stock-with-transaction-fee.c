/*
 * @lc app=leetcode id=714 lang=c
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
int maxProfit(int *prices, int pricesSize, int fee)
{
    int dp[2] = {0};
    dp[1] = -1 * prices[0] - fee;
    for (int i = 1; i < pricesSize; i++)
    {
        dp[0] = fmax(dp[0], dp[1] + prices[i]);
        dp[1] = fmax(dp[1], dp[0] - prices[i] - fee);
    }
    return dp[0];
}
// @lc code=end

// Note: DP + greedy