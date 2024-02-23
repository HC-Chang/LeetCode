/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int nn = flights.size();
        if (k == 0)
        {
            for (int i = 0; i < nn; i++)
            {
                if (flights[i][0] == src && flights[i][1] == dst)
                    return flights[i][2];
            }
        }

        vector<int> dp(n);
        vector<int> pre(n);

        for (int i = 0; i < nn; i++)
        {
            if (src == flights[i][0])
            {
                dp[flights[i][1]] = flights[i][2];
                pre[flights[i][1]] = flights[i][2];
            }
        }

        int u, v, w;

        for (int x = 1; x < k + 1; x++)
        {
            for (int i = 0; i < nn; i++)
            {
                u = flights[i][0];
                v = flights[i][1];
                w = flights[i][2];

                if (pre[u] != 0)
                {
                    if (dp[v] == 0)
                        dp[v] = pre[u] + w;
                    else
                        dp[v] = min(dp[v], pre[u] + w);
                }
            }

            pre.assign(dp.begin(), dp.end());
        }

        if (dp[dst] == 0)
            return -1;
        return dp[dst];
    }
};
// @lc code=end

// DP

// Other Solution Reference:
// https://github.com/wisdompeak/LeetCode/tree/master/Graph/787.Cheapest-Flights-Within-K-Stops