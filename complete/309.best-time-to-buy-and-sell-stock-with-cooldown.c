/*
 * @lc app=leetcode id=309 lang=c
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int *prices, int pricesSize)
{
    int buy = INT_MIN;
    int prev_buy;
    int sell = 0;
    int pre_sell = 0;

    for (int i = 0; i < pricesSize; i++)
    {
        prev_buy = buy;
        buy = max(pre_sell - prices[i], prev_buy);
        pre_sell = sell;
        sell = max(prev_buy + prices[i], pre_sell);
    }
    return sell;
}
// @lc code=end
