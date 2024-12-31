/*
 * @lc app=leetcode id=983 lang=c
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
int mincostTickets(int *days, int daysSize, int *costs, int costsSize)
{
    int total_day = days[daysSize - 1];
    int *dp_total_day = calloc(total_day + 1, sizeof(int));
    for (int i = 0; i <= total_day; i++)
        dp_total_day[i] = INT_MAX;
    for (int i = 0; i < daysSize; i++)
        dp_total_day[days[i]] = 0;

    dp_total_day[0] = 0;
    int cur, index7, index30;
    for (int i = 1; i <= total_day; i++)
    {
        if (!dp_total_day[i])
        {
            index7 = (i - 7 > 0 ? i - 7 : 0);
            index30 = (i - 30 > 0 ? i - 30 : 0);
            cur = dp_total_day[i - 1] + costs[0];
            cur = fmin(cur, dp_total_day[index7] + costs[1]);
            cur = fmin(cur, dp_total_day[index30] + costs[2]);
            dp_total_day[i] = cur;
        }
        else
            dp_total_day[i] = dp_total_day[i - 1];
    }

    int r = dp_total_day[total_day];
    free(dp_total_day);
    return r;
}

// @lc code=end

// Note: DP