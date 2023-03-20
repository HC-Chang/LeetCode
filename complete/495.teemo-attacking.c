/*
 * @lc app=leetcode id=495 lang=c
 *
 * [495] Teemo Attacking
 */

// @lc code=start
int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration)
{
    if (timeSeriesSize == 1)
        return duration;
    int sum = duration;
    for (int i = 1; i < timeSeriesSize; i++)
    {
        if (timeSeries[i] - timeSeries[i - 1] > duration - 1)
            sum += duration;
        else
            sum += timeSeries[i] - timeSeries[i - 1];
    }
    return sum;
}
// @lc code=end
