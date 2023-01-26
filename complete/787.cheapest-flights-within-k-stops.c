/*
 * @lc app=leetcode id=787 lang=c
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
#define min(a, b) a < b ? a : b

int findCheapestPrice(int n, int **flights, int flightsSize, int *flightsColSize, int src, int dst, int k)
{
    if (k == 0)
    {
        for (int i = 0; i < flightsSize; i++)
        {
            if (flights[i][0] == src && flights[i][1] == dst)
                return flights[i][2];
        }
    }

    int *dp = calloc(n, sizeof(int));
    int *pre = calloc(n, sizeof(int));

    for (int i = 0; i < flightsSize; i++)
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
        for (int i = 0; i < flightsSize; i++)
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

        memcpy(pre, dp, sizeof(int) * n);
    }

    int r = dp[dst];
    free(dp);
    free(pre);
    return (r == 0 ? -1 : r);
}

// @lc code=end

// DP

// Other Solution Reference:
// https://github.com/wisdompeak/LeetCode/tree/master/Graph/787.Cheapest-Flights-Within-K-Stops