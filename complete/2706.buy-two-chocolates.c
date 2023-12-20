/*
 * @lc app=leetcode id=2706 lang=c
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
int buyChoco(int *prices, int pricesSize, int money)
{
    int arr_lower[2] = {INT_MAX};
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < arr_lower[0])
        {
            arr_lower[1] = arr_lower[0];
            arr_lower[0] = prices[i];
        }
        else if (prices[i] < arr_lower[1])
            arr_lower[1] = prices[i];
    }
    arr_lower[0] += arr_lower[1];
    if (arr_lower[0] > money)
        return money;
    return money - arr_lower[0];
}
// @lc code=end

// Note: sorting