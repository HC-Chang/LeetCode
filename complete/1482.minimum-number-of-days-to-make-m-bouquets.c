/*
 * @lc app=leetcode id=1482 lang=c
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
bool canMake(int *bloomDay, int bloomDaySize, int days, int m, int k)
{
    int bouquets = 0;
    int flowers = 0;
    int length = bloomDaySize;
    for (int i = 0; i < length && bouquets < m; i++)
    {
        if (bloomDay[i] <= days)
        {
            flowers++;
            if (flowers == k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        else
            flowers = 0;
    }
    return bouquets >= m;
}

int minDays(int *bloomDay, int bloomDaySize, int m, int k)
{
    if (m > bloomDaySize / k)
    {
        return -1;
    }
    int low = INT_MAX, high = 0;
    for (int i = 0; i < bloomDaySize; i++)
    {
        low = fmin(low, bloomDay[i]);
        high = fmax(high, bloomDay[i]);
    }
    while (low < high)
    {
        int days = (high - low) / 2 + low;
        if (canMake(bloomDay, bloomDaySize, days, m, k))
            high = days;
        else
            low = days + 1;
    }
    return low;
}
// @lc code=end
