/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
int maxProfit(int *prices, int pricesSize)
{
    int price = prices[0];
    int max = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < price)
            price = prices[i];
        if (max < prices[i] - price)
            max = prices[i] - price;
    }

    return max;
}
// @lc code=end
