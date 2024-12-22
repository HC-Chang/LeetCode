/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        int j;
        for (int i = 0; i < n - 1; i++)
        {
            j = i + 1;
            while (j + 1 < n && prices[i] < prices[j])
                j++;

            if (prices[i] >= prices[j])
                prices[i] -= prices[j];
        }

        return prices;
    }
};
// @lc code=end

// Note: stack