/*
 * @lc app=leetcode id=122 lang=c
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start

int maxProfit(int *prices, int pricesSize)
{
    int profit = 0;

    // 相鄰兩數，如相減 > 0，則加總
    int temp = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        temp = prices[i] - prices[i - 1];
        if (temp > 0)
        {
            profit += temp;
        }
    }

    return profit;
}
// @lc code=end
