/*
 * @lc app=leetcode id=1475 lang=c
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *finalPrices(int *prices, int pricesSize, int *returnSize)
{
    *returnSize = pricesSize;
    int j;
    for (int i = 0; i < pricesSize - 1; i++)
    {
        j = i + 1;
        while (j + 1 < pricesSize && prices[i] < prices[j])
            j++;

        if (prices[i] >= prices[j])
            prices[i] -= prices[j];
    }

    return prices;
}
// @lc code=end

// Note: stack