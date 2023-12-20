/*
 * @lc app=leetcode id=2706 lang=c
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        sort(prices.begin(), prices.end());
        prices[0] += prices[1];
        if (prices[0] > money)
            return money;
        return money - prices[0];
    }
};
// @lc code=end

// Note: sorting