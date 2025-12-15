/*
 * @lc app=leetcode id=2110 lang=c
 *
 * [2110] Number of Smooth Descent Periods of a Stock
 */

// @lc code=start
long long getDescentPeriods(int *prices, int pricesSize)
{
    long long cnt = 0;
    int r;
    for (int l = 0; l < pricesSize; l++)
    {
        r = l;
        while (r + 1 < pricesSize && prices[r] - prices[r + 1] == 1)
            r++;
        cnt += (long long)(r - l + 1) * (r - l + 2) / 2;
        l = r;
    }
    return cnt;
}
// @lc code=end

// Note: math + DP