/*
 * @lc app=leetcode id=123 lang=c
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
int maxProfit(int *prices, int pricesSize)
{
    int *left = calloc(pricesSize, sizeof(int));
    int *right = calloc(pricesSize, sizeof(int));

    int min_price = prices[0];
    int tmp = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        tmp = fmax(tmp, prices[i] - min_price);
        if (min_price > prices[i])
            min_price = prices[i];
        left[i] = tmp;
    }

    int max_price = prices[pricesSize - 1];
    int t_max = 0;
    tmp = 0;
    for (int i = pricesSize - 1; i >= 0; i--)
    {
        tmp = fmax(tmp, max_price - prices[i]);
        if (max_price < prices[i])
            max_price = prices[i];
        right[i] = tmp;
        t_max = fmax(t_max, left[i] + right[i]);
    }
    free(left);
    free(right);
    return t_max;
}
// @lc code=end
