/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        int total_day = days[n - 1];
        vector<int> dp_total_day(total_day + 1, INT_MAX);
        for (int i = 0; i < n; i++)
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
                cur = min(cur, dp_total_day[index7] + costs[1]);
                cur = min(cur, dp_total_day[index30] + costs[2]);
                dp_total_day[i] = cur;
            }
            else
                dp_total_day[i] = dp_total_day[i - 1];
        }

        int r = dp_total_day[total_day];

        return r;
    }
};
// @lc code=end

// Note: DP